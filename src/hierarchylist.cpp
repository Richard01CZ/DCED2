/**********************************************************************
** Copyright (C) 2000-2001 Trolltech AS.  All rights reserved.
**
** This file is part of Qt Designer.
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** Licensees holding valid Qt Enterprise Edition or Qt Professional Edition
** licenses may use this file in accordance with the Qt Commercial License
** Agreement provided with the Software.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.trolltech.com/gpl/ for GPL licensing information.
** See http://www.trolltech.com/pricing.html or email sales@trolltech.com for
**   information about Qt Commercial License Agreements.
**
** Contact info@trolltech.com if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

#include "hierarchylist.h"
#include "globaldefs.h"

#include <qpainter.h>
#include <qpalette.h>
#include <qobjectlist.h>
#include <qheader.h>
#include <qpopupmenu.h>
#include <qtabwidget.h>
#include <qwizard.h>
#include <qwidgetstack.h>
#include <qtabbar.h>
#include <qfeatures.h>
#include <qapplication.h>
#include <qtimer.h>
#include <qworkspace.h>
#include <qaccel.h>
#include <qmessagebox.h>
#include <qmainwindow.h>

#include <stdlib.h>

QListViewItem *newItem = 0;

HierarchyItem::HierarchyItem( Type type, QListViewItem *parent, QListViewItem *after,
			      const QString &txt1, const QString &txt2, const QString &txt3 )
    : QListViewItem( parent, after, txt1, txt2, txt3 ), typ( type )
{
}

HierarchyItem::HierarchyItem( Type type, QListView *parent, QListViewItem *after,
			      const QString &txt1, const QString &txt2, const QString &txt3 )
    : QListViewItem( parent, after, txt1, txt2, txt3 ), typ( type )
{
}

void HierarchyItem::paintCell( QPainter *p, const QColorGroup &cg, int column, int width, int align )
{
    QColorGroup g( cg );
    g.setColor( QColorGroup::Base, backgroundColor() );
    g.setColor( QColorGroup::Foreground, Qt::black );
    g.setColor( QColorGroup::Text, Qt::black );
    QString txt = text( 0 );
    if ( rtti() == Function && ( txt == "init()" || txt == "destroy()" ) ) {
	listView()->setUpdatesEnabled( FALSE );
	if ( txt == "init()" )
	    setText( 0, txt + " " + "(Constructor)" );
	else
	    setText( 0, txt + " " + "(Destructor)" );
	QListViewItem::paintCell( p, g, column, width, align );
	setText( 0, txt );
	listView()->setUpdatesEnabled( TRUE );
    } else {
	QListViewItem::paintCell( p, g, column, width, align );
    }
    p->save();
    p->setPen( QPen( cg.dark(), 1 ) );
    if ( column == 0 )
	p->drawLine( 0, 0, 0, height() - 1 );
    if ( listView()->firstChild() != this ) {
	if ( nextSibling() != itemBelow() && itemBelow()->depth() < depth() ) {
	    int d = depth() - itemBelow()->depth();
	    p->drawLine( -listView()->treeStepSize() * d, height() - 1, 0, height() - 1 );
	}
    }
    p->drawLine( 0, height() - 1, width, height() - 1 );
    p->drawLine( width - 1, 0, width - 1, height() );
    p->restore();
}

QColor HierarchyItem::backgroundColor()
{
    updateBackColor();
    return backColor;
}

void HierarchyItem::updateBackColor()
{
    if ( listView()->firstChild() == this ) {
	backColor = *backColor1;
	return;
    }

    QListViewItemIterator it( this );
    --it;
    if ( it.current() ) {
	if ( ( ( HierarchyItem*)it.current() )->backColor == *backColor1 )
	    backColor = *backColor2;
	else
	    backColor = *backColor1;
    } else {
	backColor = *backColor1;
    }
}

void HierarchyItem::setObject( QObject *o )
{
    obj = o;
}

QObject *HierarchyItem::object() const
{
    return obj;
}

void HierarchyItem::okRename( int col )
{
    if ( newItem == this )
	newItem = 0;
    QListViewItem::okRename( col );
}

void HierarchyItem::cancelRename( int col )
{
    if ( newItem == this ) {
	newItem = 0;
	QListViewItem::cancelRename( col );
	delete this;
	return;
    }
    QListViewItem::cancelRename( col );
}




HierarchyList::HierarchyList( QWidget *parent, bool doConnects )
    : QListView( parent )
{
    init_colors();

    setDefaultRenameAction( Accept );
    header()->setMovingEnabled( FALSE );
    header()->setStretchEnabled( TRUE );
    normalMenu = 0;
    tabWidgetMenu = 0;
    addColumn( tr( "Name" ) );
    addColumn( tr( "Value" ) );
    QPalette p( palette() );
    p.setColor( QColorGroup::Base, QColor( *backColor2 ) );
    (void)*selectedBack; // hack
    setPalette( p );
    disconnect( header(), SIGNAL( sectionClicked( int ) ),
		this, SLOT( changeSortColumn( int ) ) );
    setSorting( -1 );
    setHScrollBarMode( AlwaysOff );
    setVScrollBarMode( AlwaysOn );
    if ( doConnects ) {
	connect( this, SIGNAL( clicked( QListViewItem * ) ),
		 this, SLOT( objectClicked( QListViewItem * ) ) );
	connect( this, SIGNAL( doubleClicked( QListViewItem * ) ),
		 this, SLOT( objectDoubleClicked( QListViewItem * ) ) );
	connect( this, SIGNAL( returnPressed( QListViewItem * ) ),
		 this, SLOT( objectClicked( QListViewItem * ) ) );
	connect( this, SIGNAL( contextMenuRequested( QListViewItem *, const QPoint&, int ) ),
		 this, SLOT( showRMBMenu( QListViewItem *, const QPoint & ) ) );
    }
    deselect = TRUE;
    setColumnWidthMode( 1, Manual );
}

void HierarchyList::keyPressEvent( QKeyEvent *e )
{
    if ( e->key() == Key_Shift || e->key() == Key_Control )
	deselect = FALSE;
    else
	deselect = TRUE;
    QListView::keyPressEvent( e );
}

void HierarchyList::keyReleaseEvent( QKeyEvent *e )
{
    deselect = TRUE;
    QListView::keyReleaseEvent( e );
}

void HierarchyList::viewportMousePressEvent( QMouseEvent *e )
{
    if ( e->state() & ShiftButton || e->state() & ControlButton )
	deselect = FALSE;
    else
	deselect = TRUE;
    QListView::viewportMousePressEvent( e );
}

void HierarchyList::viewportMouseReleaseEvent( QMouseEvent *e )
{
    QListView::viewportMouseReleaseEvent( e );
}


QObject *HierarchyList::findObject( QListViewItem *i )
{
    return ( (HierarchyItem*)i )->object();
}

QListViewItem *HierarchyList::findItem( QObject *o )
{
    QListViewItemIterator it( this );
    while ( it.current() ) {
	if ( ( (HierarchyItem*)it.current() )->object() == o )
	    return it.current();
	++it;
    }
    return 0;
}

QObject *HierarchyList::current() const
{
    if ( currentItem() )
	return ( (HierarchyItem*)currentItem() )->object();
    return 0;
}

void HierarchyList::changeNameOf( QObject *o, const QString &name )
{
    QListViewItem *item = findItem( o );
    if ( !item )
	return;
    item->setText( 0, name );
}


static QPtrList<QWidgetStack> *widgetStacks = 0;

void HierarchyList::setup()
{
	return;
}

void HierarchyList::setOpen( QListViewItem *i, bool b )
{
    QListView::setOpen( i, b );
}

void HierarchyList::setCurrent( QObject *o )
{
    QListViewItemIterator it( this );
    while ( it.current() ) {
	if ( ( (HierarchyItem*)it.current() )->object() == o ) {
	    blockSignals( TRUE );
	    setCurrentItem( it.current() );
	    ensureItemVisible( it.current() );
	    blockSignals( FALSE );
	    return;
	}
	++it;
    }
}

void HierarchyList::showRMBMenu( QListViewItem *i, const QPoint & p )
{
    if ( !i )
	return;
}

// ------------------------------------------------------------

static HierarchyItem::Type getChildType( int type )
{
    switch ( (HierarchyItem::Type)type ) {
    case HierarchyItem::Widget:
	qWarning( "getChildType: Inserting childs dynamically to Widget or SlotParent is not allowed!" );
	break;
    case HierarchyItem::SlotParent:
    case HierarchyItem::SlotPublic:
    case HierarchyItem::SlotProtected:
    case HierarchyItem::SlotPrivate:
    case HierarchyItem::Slot:
	return HierarchyItem::Slot;
    case HierarchyItem::DefinitionParent:
    case HierarchyItem::Definition:
	return HierarchyItem::Definition;
    case HierarchyItem::Event:
    case HierarchyItem::EventFunction:
	return HierarchyItem::Event;
    case HierarchyItem::FunctParent:
    case HierarchyItem::FunctPublic:
    case HierarchyItem::FunctProtected:
    case HierarchyItem::FunctPrivate:
    case HierarchyItem::Function:
	return HierarchyItem::Function;
    case HierarchyItem::VarParent:
    case HierarchyItem::VarPublic:
    case HierarchyItem::VarProtected:
    case HierarchyItem::VarPrivate:
    case HierarchyItem::Variable:
	return HierarchyItem::Variable;
    }
    return (HierarchyItem::Type)type;
}

void HierarchyList::insertEntry( QListViewItem *i, const QPixmap &pix, const QString &s )
{
    QListViewItem *after = i->firstChild();
    while ( after && after->nextSibling() )
	after = after->nextSibling();
    HierarchyItem *item = new HierarchyItem( getChildType( i->rtti() ), i, after, s,
					     QString::null, QString::null );
    if ( !pix.isNull() )
	item->setPixmap( 0, pix );
    item->setRenameEnabled( 0, TRUE );
    setCurrentItem( item );
    ensureItemVisible( item );
    qApp->processEvents();
    newItem = item;
    item->startRename( 0 );
}

// ------------------------------------------------------------
