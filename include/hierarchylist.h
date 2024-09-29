  /**********************************************************************
** Copyright (C) 2000 Trolltech AS.  All rights reserved.
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

#ifndef HIRARCHYVIEW_H
#define HIRARCHYVIEW_H

#include <qvariant.h>
#include <qlistview.h>
#include <qtabwidget.h>
#include <qguardedptr.h>
#include <private/qcom_p.h>

class QCloseEvent;
class QPopupMenu;
class QKeyEvent;
class QMouseEvent;
class QWizard;

class HierarchyItem : public QListViewItem
{
public:
    enum Type {
	Widget,
	SlotParent,
	SlotPublic,
	SlotProtected,
	SlotPrivate,
	Slot,
	DefinitionParent,
	Definition,
	Event,
	EventFunction,
	FunctParent,
	FunctPublic,
	FunctProtected,
	FunctPrivate,
	Function,
	VarParent,
	VarPublic,
	VarProtected,
	VarPrivate,
	Variable
    };

    HierarchyItem( Type type, QListViewItem *parent, QListViewItem *after,
		   const QString &txt1, const QString &txt2, const QString &txt3 );
    HierarchyItem( Type type, QListView *parent, QListViewItem *after,
		   const QString &txt1, const QString &txt2, const QString &txt3 );

    void paintCell( QPainter *p, const QColorGroup &cg, int column, int width, int align );
    void updateBackColor();

    void setObject( QObject *o );
    QObject *object() const;

    void setText( int col, const QString &txt ) { if ( !txt.isEmpty() ) QListViewItem::setText( col, txt ); }

    int rtti() const { return (int)typ; }

private:
    void okRename( int col );
    void cancelRename( int col );

private:
    QColor backgroundColor();
    QColor backColor;
    QObject *obj;
    Type typ;

};

class HierarchyList : public QListView
{
    Q_OBJECT

public:
    HierarchyList( QWidget *parent, bool doConnects = TRUE );

    virtual void setup();
    virtual void setCurrent( QObject *o );
    void setOpen( QListViewItem *i, bool b );
    void changeNameOf( QObject *o, const QString &name );
    void drawContentsOffset( QPainter *p, int ox, int oy,
			     int cx, int cy, int cw, int ch ) {
	setUpdatesEnabled( FALSE );
	triggerUpdate();
	setUpdatesEnabled( TRUE );
	QListView::drawContentsOffset( p, ox, oy, cx, cy, cw, ch );
    }

    void insertEntry( QListViewItem *i, const QPixmap &pix = QPixmap(), const QString &s = QString::null );

protected:
    void keyPressEvent( QKeyEvent *e );
    void keyReleaseEvent( QKeyEvent *e );
    void viewportMousePressEvent( QMouseEvent *e );
    void viewportMouseReleaseEvent( QMouseEvent *e );

private:
    QObject *findObject( QListViewItem *i );
    QListViewItem *findItem( QObject *o );
    QObject *current() const;
    QObject *handleObjectClick( QListViewItem *i );

private slots:
    virtual void showRMBMenu( QListViewItem *, const QPoint & );

protected:
    QPopupMenu *normalMenu, *tabWidgetMenu;
    bool deselect;

};

#endif
