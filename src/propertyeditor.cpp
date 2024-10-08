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

#include <qvariant.h> // HP-UX compiler needs this here

#include "asciivalidator.h"
#include "propertyeditor.h"
#include "propertyobject.h"
//#include <widgetdatabase.h>
#include "globaldefs.h"
#include "defs.h"

#include <qpainter.h>
#include <qpalette.h>
#include <qapplication.h>
#include <qheader.h>
#include <qlineedit.h>
#include <qstrlist.h>
#include <qmetaobject.h>
#include <qcombobox.h>
#include <qpushbutton.h>
#include <qhbox.h>
#include <qfontdialog.h>
#include <qspinbox.h>
#include <qevent.h>
#include <qobjectlist.h>
#include <qlistbox.h>
#include <qfontdatabase.h>
#include <qcolor.h>
#include <qcolordialog.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qsizepolicy.h>
#include <qbitmap.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qaccel.h>
#include <qworkspace.h>
#include <qtimer.h>
#include <qdragobject.h>
#include <qdom.h>
#include <qprocess.h>
#include <qstyle.h>
#include <qdatetimeedit.h>
#include <qassistantclient.h>
#include <qdrawutil.h>

#include <limits.h>

static QFontDatabase *fontDataBase = 0;
QString assistantPath();

#ifdef Q_WS_MAC
#include <qwindowsstyle.h>
static void setupStyle(QWidget *w)
{
    static QStyle *windowsStyle = 0;
    if(!windowsStyle)
	windowsStyle = new QWindowsStyle;
    w->setStyle(windowsStyle);
}
#else
#define setupStyle(x)
#endif

static void cleanupFontDatabase()
{
    delete fontDataBase;
    fontDataBase = 0;
}

static QStringList getFontList()
{
    if ( !fontDataBase ) {
	fontDataBase = new QFontDatabase;
	qAddPostRoutine( cleanupFontDatabase );
    }
    return fontDataBase->families();
}


class PropertyWhatsThis : public QWhatsThis
{
public:
    PropertyWhatsThis( PropertyList *l );
    QString text( const QPoint &pos );
    bool clicked( const QString& href );

private:
    PropertyList *propertyList;

};

PropertyWhatsThis::PropertyWhatsThis( PropertyList *l )
    : QWhatsThis( l->viewport() ), propertyList( l )
{
}

QString PropertyWhatsThis::text( const QPoint &pos )
{
//    return propertyList->whatsThisAt( pos );
	return QString::null;
}

bool PropertyWhatsThis::clicked( const QString& href )
{
    return FALSE; // do not hide window
}


/*!
  \class PropertyItem propertyeditor.h
  \brief Base class for all property items

  This is the base class for each property item for the
  PropertyList. A simple property item has just a name and a value to
  provide an editor for a datatype. But more complex datatypes might
  provide an expandable item for editing single parts of the
  datatype. See hasSubItems(), initChildren() for that.
*/

/*!  If this item should be a child of another property item, specify
  \a prop as the parent item.
*/

PropertyItem::PropertyItem( PropertyList *l, PropertyItem *after, PropertyItem *prop, const QString &propName )
    : QListViewItem( l, after ), listview( l ), property( prop ), propertyName( propName )
{
    setSelectable( FALSE );
    open = FALSE;
    setText( 0, propertyName );
    changed = FALSE;
    setText( 1, "" );
    resetButton = 0;
}

PropertyItem::~PropertyItem()
{
    if ( resetButton )
	delete resetButton->parentWidget();
    resetButton = 0;
}

void PropertyItem::toggle()
{
}

void PropertyItem::updateBackColor()
{
    if ( itemAbove() && this != listview->firstChild() ) {
	if ( ( ( PropertyItem*)itemAbove() )->backColor == *backColor1 )
	    backColor = *backColor2;
	else
	    backColor = *backColor1;
    } else {
	backColor = *backColor1;
    }
    if ( listview->firstChild() == this )
	backColor = *backColor1;
}

QColor PropertyItem::backgroundColor()
{
    updateBackColor();
    if ( (QListViewItem*)this == listview->currentItem() )
	return *selectedBack;
    return backColor;
}

/*!  If a subclass is a expandable item, this is called when the child
items should be created.
*/

void PropertyItem::createChildren()
{
}

/*!  If a subclass is a expandable item, this is called when the child
items should be initialized.
*/

void PropertyItem::initChildren()
{
}

void PropertyItem::paintCell( QPainter *p, const QColorGroup &cg, int column, int width, int align )
{
    QColorGroup g( cg );
    g.setColor( QColorGroup::Base, backgroundColor() );
    g.setColor( QColorGroup::Foreground, Qt::black );
    g.setColor( QColorGroup::Text, Qt::black );
    int indent = 0;
    if ( column == 0 ) {
	indent = 20 + ( property ? 20 : 0 );
	p->fillRect( 0, 0, width, height(), backgroundColor() );
	p->save();
	p->translate( indent, 0 );
    }

    if ( isChanged() && column == 0 ) {
	p->save();
	QFont f = p->font();
	f.setBold( TRUE );
	p->setFont( f );
    }

    if ( !hasCustomContents() || column != 1 ) {
	QListViewItem::paintCell( p, g, column, width - indent, align  );
    } else {
	p->fillRect( 0, 0, width, height(), backgroundColor() );
	drawCustomContents( p, QRect( 0, 0, width, height() ) );
    }

    if ( isChanged() && column == 0 )
	p->restore();
    if ( column == 0 )
	p->restore();
    if ( hasSubItems() && column == 0 ) {
	p->save();
	p->setPen( cg.foreground() );
	p->setBrush( cg.base() );
	p->drawRect( 5, height() / 2 - 4, 9, 9 );
	p->drawLine( 7, height() / 2, 11, height() / 2 );
	if ( !isOpen() )
	    p->drawLine( 9, height() / 2 - 2, 9, height() / 2 + 2 );
	p->restore();
    }
    p->save();
    p->setPen( QPen( cg.dark(), 1 ) );
    p->drawLine( 0, height() - 1, width, height() - 1 );
    p->drawLine( width - 1, 0, width - 1, height() );
    p->restore();

    if ( listview->currentItem() == this && column == 0 &&
	 !listview->hasFocus() && !listview->viewport()->hasFocus() )
	paintFocus( p, cg, QRect( 0, 0, width, height() ) );
}

void PropertyItem::paintBranches( QPainter * p, const QColorGroup & cg,
				  int w, int y, int h )
{
    QColorGroup g( cg );
    g.setColor( QColorGroup::Base, backgroundColor() );
    QListViewItem::paintBranches( p, g, w, y, h );
}

void PropertyItem::paintFocus( QPainter *p, const QColorGroup &cg, const QRect &r )
{
    p->save();
    QApplication::style().drawPrimitive(QStyle::PE_Panel, p, r, cg,
					QStyle::Style_Sunken, QStyleOption(1,1) );
    p->restore();
}

/*!  Subclasses which are expandable items have to return TRUE
  here. Default is FALSE.
*/

bool PropertyItem::hasSubItems() const
{
    return FALSE;
}

/*!  Returns the parent property item here if this is a child or 0
 otherwise.
 */

PropertyItem *PropertyItem::propertyParent() const
{
    return property;
}

bool PropertyItem::isOpen() const
{
    return open;
}

void PropertyItem::setOpen( bool b )
{
    if ( b == open )
	return;
    open = b;

    if ( !open ) {
	children.setAutoDelete( TRUE );
	children.clear();
	children.setAutoDelete( FALSE );
	qApp->processEvents();
//	listview->updateEditorSize();
	return;
    }

    createChildren();
    initChildren();
    qApp->processEvents();
//    listview->updateEditorSize();
}

/*!  Subclasses have to show the editor of the item here
*/

void PropertyItem::showEditor()
{
    createResetButton();
    resetButton->parentWidget()->show();
}

/*!  Subclasses have to hide the editor of the item here
*/

void PropertyItem::hideEditor()
{
    createResetButton();
    resetButton->parentWidget()->hide();
}

/*!  This is called to init the value of the item. Reimplement in
  subclasses to init the editor
*/

void PropertyItem::setValue( const QVariant &v )
{
    val = v;
}

QVariant PropertyItem::value() const
{
    return val;
}

bool PropertyItem::isChanged() const
{
    return changed;
}

void PropertyItem::setChanged( bool b, bool updateDb )
{
    if ( propertyParent() )
	return;
    if ( changed == b )
	return;
    changed = b;
    repaint();
/*	if ( updateDb ) {
		MetaDataBase::setPropertyChanged( listview->propertyEditor()->widget(), name(), changed );
    } */
    updateResetButtonState();
}

QString PropertyItem::name() const
{
    return propertyName;
}

void PropertyItem::createResetButton()
{
    if ( resetButton ) {
	resetButton->parentWidget()->lower();
	return;
    }
    QHBox *hbox = new QHBox( listview->viewport() );
    hbox->setFrameStyle( QFrame::StyledPanel | QFrame::Sunken );
    hbox->setLineWidth( 1 );
    resetButton = new QPushButton( hbox );
    setupStyle( resetButton );
    resetButton->setPixmap( QPixmap::fromMimeSource( "designer_resetproperty.png" ) );
    resetButton->setFixedWidth( resetButton->sizeHint().width() );
    hbox->layout()->setAlignment( Qt::AlignRight );
    listview->addChild( hbox );
    hbox->hide();
    QObject::connect( resetButton, SIGNAL( clicked() ),
		      listview, SLOT( resetProperty() ) );
    QToolTip::add( resetButton, PropertyList::tr( "Reset the property to its default value" ) );
    QWhatsThis::add( resetButton, PropertyList::tr( "Click this button to reset the property to its default value" ) );
    updateResetButtonState();
}

void PropertyItem::updateResetButtonState()
{
    if ( !resetButton )
	return;
    if ( propertyParent() )
	resetButton->setEnabled( FALSE );
    else
	resetButton->setEnabled( isChanged() );
}

/*!  Call this to place/resize the item editor correctly (normally
  call it from showEditor())
*/

void PropertyItem::placeEditor( QWidget *w )
{
    createResetButton();
    QRect r = listview->itemRect( this );
    if ( !r.size().isValid() ) {
	listview->ensureItemVisible( this );
#if defined(Q_WS_WIN)
	listview->repaintContents( FALSE );
#endif
	r = listview->itemRect( this );
    }
    r.setX( listview->header()->sectionPos( 1 ) );
    r.setWidth( listview->header()->sectionSize( 1 ) - 1 );
    r.setWidth( r.width() - resetButton->width() - 2 );
    r = QRect( listview->viewportToContents( r.topLeft() ), r.size() );
    w->resize( r.size() );
    listview->moveChild( w, r.x(), r.y() );
    resetButton->parentWidget()->resize( resetButton->sizeHint().width() + 10, r.height() );
    listview->moveChild( resetButton->parentWidget(), r.x() + r.width() - 8, r.y() );
    resetButton->setFixedHeight( QMAX( 0, r.height() - 3 ) );
}

/*!  This should be called by subclasses if the user changed the value
  of the property and this value should be applied to the widget property
*/

void PropertyItem::notifyValueChange()
{
    if ( !propertyParent() ) {
//	listview->valueChanged( this );
	setChanged( TRUE );
	if ( hasSubItems() )
	    initChildren();
    } else {
	propertyParent()->childValueChanged( this );
	setChanged( TRUE );
    }
}

/*!  If a subclass is a expandable item reimplement this as this is
  always called if a child item changed its value. So update the
  display of the item here then.
*/

void PropertyItem::childValueChanged( PropertyItem * )
{
}

/*!  When adding a child item, call this (normally from addChildren()
*/

void PropertyItem::addChild( PropertyItem *i )
{
    children.append( i );
}

int PropertyItem::childCount() const
{
    return children.count();
}

PropertyItem *PropertyItem::child( int i ) const
{
    // ARRRRRRRRG
    return ( (PropertyItem*)this )->children.at( i );
}

/*!  If the contents of the item is not displayable with a text, but
  you want to draw it yourself (using drawCustomContents()), return
  TRUE here.
*/

bool PropertyItem::hasCustomContents() const
{
    return FALSE;
}

/*!
  \sa hasCustomContents()
*/

void PropertyItem::drawCustomContents( QPainter *, const QRect & )
{
}

QString PropertyItem::currentItem() const
{
    return QString::null;
}

int PropertyItem::currentIntItem() const
{
    return -1;
}

void PropertyItem::setCurrentItem( const QString & )
{
}

void PropertyItem::setCurrentItem( int )
{
}

int PropertyItem::currentIntItemFromObject() const
{
    return -1;
}

QString PropertyItem::currentItemFromObject() const
{
    return QString::null;
}

void PropertyItem::setFocus( QWidget *w )
{
    /*if ( !qApp->focusWidget() ||
	 listview->propertyEditor()->formWindow() &&
	 ( !MainWindow::self->isAFormWindowChild( qApp->focusWidget() ) &&
	   !qApp->focusWidget()->inherits( "Editor" ) ) )
	w->setFocus();*/
}

void PropertyItem::setText( int col, const QString &t )
{
    QString txt( t );
    if ( col == 1 )
	txt = txt.replace( "\n", " " );
    QListViewItem::setText( col, txt );
}

// --------------------------------------------------------------

PropertyTextItem::PropertyTextItem( PropertyList *l, PropertyItem *after, PropertyItem *prop,
				    const QString &propName, bool comment, bool multiLine, bool ascii, bool a )
    : PropertyItem( l, after, prop, propName ), withComment( comment ),
      hasMultiLines( multiLine ), asciiOnly( ascii ), accel( a )
{
    lin = 0;
    box = 0;
}

QLineEdit *PropertyTextItem::lined()
{
    if ( lin )
	return lin;
    if ( hasMultiLines ) {
	box = new QHBox( listview->viewport() );
	box->setFrameStyle( QFrame::StyledPanel | QFrame::Sunken );
	box->setLineWidth( 2 );
	box->hide();
    }

    lin = 0;
    if ( hasMultiLines )
	lin = new QLineEdit( box );
    else
	lin = new QLineEdit( listview->viewport() );

    if ( asciiOnly ) {
	if ( PropertyItem::name() == "name" ) {
	    lin->setValidator( new AsciiValidator( QString(":"), lin, "ascii_validator" ) );
	    //if ( listview->propertyEditor()->formWindow()->isFake() )
		//lin->setEnabled( FALSE );
	} else {
	    lin->setValidator( new AsciiValidator( QString("!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"
							   "\xa1\xa2\xa3\xa4\xa5\xa6\xa7\xa8\xa9"
							   "\xaa\xab\xac\xad\xae\xaf\xb1\xb2\xb3"
							   "\xb4\xb5\xb6\xb7\xb8\xb9\xba\xbb\xbc"
							   "\xbd\xbe\xbf"), lin, "ascii_validator" ) );
	}
    } if ( !hasMultiLines ) {
	lin->hide();
    } else {
	button = new QPushButton( tr("..."), box );
	setupStyle( button );
	button->setFixedWidth( 20 );
	connect( button, SIGNAL( clicked() ),
		 this, SLOT( getText() ) );
	lin->setFrame( FALSE );
    }
    connect( lin, SIGNAL( returnPressed() ),
	     this, SLOT( setValue() ) );
    connect( lin, SIGNAL( textChanged( const QString & ) ),
	     this, SLOT( setValue() ) );
    if ( PropertyItem::name() == "name" || PropertyItem::name() == "itemName" )
/*	connect( lin, SIGNAL( returnPressed() ),
		 listview->propertyEditor()->formWindow()->commandHistory(),
		 SLOT( checkCompressedCommand() ) );*/
    lin->installEventFilter( listview );
    return lin;
}

PropertyTextItem::~PropertyTextItem()
{
    delete (QLineEdit*)lin;
    lin = 0;
    delete (QHBox*)box;
    box = 0;
}

void PropertyTextItem::setChanged( bool b, bool updateDb )
{
    PropertyItem::setChanged( b, updateDb );
    if ( withComment && childCount() > 0 )
	( (PropertyTextItem*)PropertyItem::child( 0 ) )->lined()->setEnabled( b );
}

bool PropertyTextItem::hasSubItems() const
{
    return withComment;
}

void PropertyTextItem::childValueChanged( PropertyItem *child )
{
/*    if ( PropertyItem::name() != "name" )
	MetaDataBase::setPropertyComment( listview->propertyEditor()->widget(),
					  PropertyItem::name(), child->value().toString() );
    else
	MetaDataBase::setExportMacro( listview->propertyEditor()->widget(), child->value().toString() );
    listview->propertyEditor()->formWindow()->commandHistory()->setModified( TRUE );*/
}

void PropertyTextItem::showEditor()
{
    PropertyItem::showEditor();
    if ( !lin || lin->text().length() == 0 ) {
	lined()->blockSignals( TRUE );
	lined()->setText( value().toString() );
	lined()->blockSignals( FALSE );
    }

    QWidget* w;
    if ( hasMultiLines )
	w = box;
    else
	w= lined();

    placeEditor( w );
    if ( !w->isVisible() || !lined()->hasFocus() ) {
	w->show();
	setFocus( lined() );
    }
}

void PropertyTextItem::createChildren()
{
    PropertyTextItem *i = new PropertyTextItem( listview, this, this,
						PropertyItem::name() == "name" ?
						"export macro" : "comment", FALSE, FALSE,
						PropertyItem::name() == "name" );
    i->lined()->setEnabled( isChanged() );
    addChild( i );
}

void PropertyTextItem::initChildren()
{
    if ( !childCount() )
	return;
    PropertyItem *item = PropertyItem::child( 0 );
    if ( item ) {
/*	if ( PropertyItem::name() != "name" )
	    item->setValue( MetaDataBase::propertyComment( listview->propertyEditor()->widget(),
							   PropertyItem::name() ) );
	else
	    item->setValue( MetaDataBase::exportMacro( listview->propertyEditor()->widget() ) );*/
    }
}

void PropertyTextItem::hideEditor()
{
    PropertyItem::hideEditor();
    QWidget* w;
    if ( hasMultiLines )
	w = box;
    else
	w = lined();

    w->hide();
}

void PropertyTextItem::setValue( const QVariant &v )
{
    if ( ( !hasSubItems() || !isOpen() )
	 && value() == v )
	return;
    if ( lin ) {
	lined()->blockSignals( TRUE );
	int oldCursorPos;
	oldCursorPos = lin->cursorPosition();
	lined()->setText( v.toString() );
	if ( oldCursorPos < (int)lin->text().length() )
	    lin->setCursorPosition( oldCursorPos );
	lined()->blockSignals( FALSE );
    }
    setText( 1, v.toString() );
    PropertyItem::setValue( v );
}

void PropertyTextItem::setValue()
{
    setText( 1, lined()->text() );
    QVariant v;
    if ( accel ) {
	v = QVariant( QKeySequence( lined()->text() ) );
	if ( v.toString().isNull() )
	    return; // not yet valid input
    } else {
	v = lined()->text();
    }
    PropertyItem::setValue( v );
    notifyValueChange();
}

void PropertyTextItem::getText()
{
    /*bool richText = !listview->propertyEditor()->widget()->inherits( "QButton" ) ||
		    ( text( 0 ) == "whatsThis" );
    bool doWrap = FALSE;
    QString txt = MultiLineEditor::getText( listview, value().toString(), richText, &doWrap );
    if ( !txt.isEmpty() ) {
	setText( 1, txt );
	PropertyItem::setValue( txt );
	notifyValueChange();
	lined()->blockSignals( TRUE );
	lined()->setText( txt );
	lined()->blockSignals( FALSE );
    }*/
}

// --------------------------------------------------------------

PropertyDoubleItem::PropertyDoubleItem( PropertyList *l, PropertyItem *after, PropertyItem *prop,
				    const QString &propName )
    : PropertyItem( l, after, prop, propName )
{
    lin = 0;
}

QLineEdit *PropertyDoubleItem::lined()
{
    if ( lin )
	return lin;
    lin = new QLineEdit( listview->viewport() );
    lin->setValidator( new QDoubleValidator( lin, "double_validator" ) );

    connect( lin, SIGNAL( returnPressed() ),
	     this, SLOT( setValue() ) );
    connect( lin, SIGNAL( textChanged( const QString & ) ),
	     this, SLOT( setValue() ) );
    lin->installEventFilter( listview );
    return lin;
}

PropertyDoubleItem::~PropertyDoubleItem()
{
    delete (QLineEdit*)lin;
    lin = 0;
}

void PropertyDoubleItem::showEditor()
{
    PropertyItem::showEditor();
    if ( !lin ) {
	lined()->blockSignals( TRUE );
	lined()->setText( QString::number( value().toDouble() ) );
	lined()->blockSignals( FALSE );
    }
    QWidget* w = lined();

    placeEditor( w );
    if ( !w->isVisible() || !lined()->hasFocus() ) {
	w->show();
	setFocus( lined() );
    }
}


void PropertyDoubleItem::hideEditor()
{
    PropertyItem::hideEditor();
    QWidget* w = lined();
    w->hide();
}

void PropertyDoubleItem::setValue( const QVariant &v )
{
    if ( value() == v )
	return;
    if ( lin ) {
	lined()->blockSignals( TRUE );
	int oldCursorPos;
	oldCursorPos = lin->cursorPosition();
	lined()->setText( QString::number( v.toDouble() ) );
	if ( oldCursorPos < (int)lin->text().length() )
	    lin->setCursorPosition( oldCursorPos );
	lined()->blockSignals( FALSE );
    }
    setText( 1, QString::number( v.toDouble() ) );
    PropertyItem::setValue( v );
}

void PropertyDoubleItem::setValue()
{
    setText( 1, lined()->text() );
    QVariant v = lined()->text().toDouble();
    PropertyItem::setValue( v );
    notifyValueChange();
}


// --------------------------------------------------------------

PropertyDateItem::PropertyDateItem( PropertyList *l, PropertyItem *after, PropertyItem *prop, const QString &propName )
    : PropertyItem( l, after, prop, propName )
{
    lin = 0;
}

QDateEdit *PropertyDateItem::lined()
{
    if ( lin )
	return lin;
    lin = new QDateEdit( listview->viewport() );
    QObjectList *l = lin->queryList( "QLineEdit" );
    for ( QObject *o = l->first(); o; o = l->next() )
	o->installEventFilter( listview );
    delete l;
    connect( lin, SIGNAL( valueChanged( const QDate & ) ),
	     this, SLOT( setValue() ) );
    return lin;
}

PropertyDateItem::~PropertyDateItem()
{
    delete (QDateEdit*)lin;
    lin = 0;
}

void PropertyDateItem::showEditor()
{
    PropertyItem::showEditor();
    if ( !lin ) {
	lined()->blockSignals( TRUE );
	lined()->setDate( value().toDate() );
	lined()->blockSignals( FALSE );
    }
    placeEditor( lin );
    if ( !lin->isVisible() ) {
	lin->show();
	setFocus( lin );
    }
}

void PropertyDateItem::hideEditor()
{
    PropertyItem::hideEditor();
    if ( lin )
	lin->hide();
}

void PropertyDateItem::setValue( const QVariant &v )
{
    if ( ( !hasSubItems() || !isOpen() )
	 && value() == v )
	return;

    if ( lin ) {
	lined()->blockSignals( TRUE );
	if ( lined()->date() != v.toDate() )
	    lined()->setDate( v.toDate() );
	lined()->blockSignals( FALSE );
    }
    setText( 1, v.toDate().toString( ::Qt::ISODate ) );
    PropertyItem::setValue( v );
}

void PropertyDateItem::setValue()
{
    setText( 1, lined()->date().toString( ::Qt::ISODate ) );
    QVariant v;
    v = lined()->date();
    PropertyItem::setValue( v );
    notifyValueChange();
}

// --------------------------------------------------------------

PropertyTimeItem::PropertyTimeItem( PropertyList *l, PropertyItem *after, PropertyItem *prop, const QString &propName )
    : PropertyItem( l, after, prop, propName )
{
    lin = 0;
}

QTimeEdit *PropertyTimeItem::lined()
{
    if ( lin )
	return lin;
    lin = new QTimeEdit( listview->viewport() );
    connect( lin, SIGNAL( valueChanged( const QTime & ) ),
	     this, SLOT( setValue() ) );
    QObjectList *l = lin->queryList( "QLineEdit" );
    for ( QObject *o = l->first(); o; o = l->next() )
	o->installEventFilter( listview );
    delete l;
    return lin;
}

PropertyTimeItem::~PropertyTimeItem()
{
    delete (QTimeEdit*)lin;
    lin = 0;
}

void PropertyTimeItem::showEditor()
{
    PropertyItem::showEditor();
    if ( !lin ) {
	lined()->blockSignals( TRUE );
	lined()->setTime( value().toTime() );
	lined()->blockSignals( FALSE );
    }
    placeEditor( lin );
    if ( !lin->isVisible() ) {
	lin->show();
	setFocus( lin );
    }
}

void PropertyTimeItem::hideEditor()
{
    PropertyItem::hideEditor();
    if ( lin )
	lin->hide();
}

void PropertyTimeItem::setValue( const QVariant &v )
{
    if ( ( !hasSubItems() || !isOpen() )
	 && value() == v )
	return;

    if ( lin ) {
	lined()->blockSignals( TRUE );
	if ( lined()->time() != v.toTime() )
	    lined()->setTime( v.toTime() );
	lined()->blockSignals( FALSE );
    }
    setText( 1, v.toTime().toString( ::Qt::ISODate ) );
    PropertyItem::setValue( v );
}

void PropertyTimeItem::setValue()
{
    setText( 1, lined()->time().toString( ::Qt::ISODate ) );
    QVariant v;
    v = lined()->time();
    PropertyItem::setValue( v );
    notifyValueChange();
}

// --------------------------------------------------------------

PropertyDateTimeItem::PropertyDateTimeItem( PropertyList *l, PropertyItem *after, PropertyItem *prop, const QString &propName )
    : PropertyItem( l, after, prop, propName )
{
    lin = 0;
}

QDateTimeEdit *PropertyDateTimeItem::lined()
{
    if ( lin )
	return lin;
    lin = new QDateTimeEdit( listview->viewport() );
    connect( lin, SIGNAL( valueChanged( const QDateTime & ) ),
	     this, SLOT( setValue() ) );
    QObjectList *l = lin->queryList( "QLineEdit" );
    for ( QObject *o = l->first(); o; o = l->next() )
	o->installEventFilter( listview );
    delete l;
    return lin;
}

PropertyDateTimeItem::~PropertyDateTimeItem()
{
    delete (QDateTimeEdit*)lin;
    lin = 0;
}

void PropertyDateTimeItem::showEditor()
{
    PropertyItem::showEditor();
    if ( !lin ) {
	lined()->blockSignals( TRUE );
	lined()->setDateTime( value().toDateTime() );
	lined()->blockSignals( FALSE );
    }
    placeEditor( lin );
    if ( !lin->isVisible() ) {
	lin->show();
	setFocus( lin );
    }
}

void PropertyDateTimeItem::hideEditor()
{
    PropertyItem::hideEditor();
    if ( lin )
	lin->hide();
}

void PropertyDateTimeItem::setValue( const QVariant &v )
{
    if ( ( !hasSubItems() || !isOpen() )
	 && value() == v )
	return;

    if ( lin ) {
	lined()->blockSignals( TRUE );
	if ( lined()->dateTime() != v.toDateTime() )
	    lined()->setDateTime( v.toDateTime() );
	lined()->blockSignals( FALSE );
    }
    setText( 1, v.toDateTime().toString( ::Qt::ISODate ) );
    PropertyItem::setValue( v );
}

void PropertyDateTimeItem::setValue()
{
    setText( 1, lined()->dateTime().toString( ::Qt::ISODate ) );
    QVariant v;
    v = lined()->dateTime();
    PropertyItem::setValue( v );
    notifyValueChange();
}

// --------------------------------------------------------------

PropertyBoolItem::PropertyBoolItem( PropertyList *l, PropertyItem *after, PropertyItem *prop, const QString &propName )
    : PropertyItem( l, after, prop, propName )
{
    comb = 0;
}

QComboBox *PropertyBoolItem::combo()
{
    if ( comb )
	return comb;
    comb = new QComboBox( FALSE, listview->viewport() );
    comb->hide();
    comb->insertItem( tr( "False" ) );
    comb->insertItem( tr( "True" ) );
    connect( comb, SIGNAL( activated( int ) ),
	     this, SLOT( setValue() ) );
    comb->installEventFilter( listview );
    return comb;
}

PropertyBoolItem::~PropertyBoolItem()
{
    delete (QComboBox*)comb;
    comb = 0;
}

void PropertyBoolItem::toggle()
{
    bool b = value().toBool();
    setValue( QVariant( !b, 0 ) );
    setValue();
}

void PropertyBoolItem::showEditor()
{
    PropertyItem::showEditor();
    if ( !comb ) {
	combo()->blockSignals( TRUE );
	if ( value().toBool() )
	    combo()->setCurrentItem( 1 );
	else
	    combo()->setCurrentItem( 0 );
	combo()->blockSignals( FALSE );
    }
    placeEditor( combo() );
    if ( !combo()->isVisible()  || !combo()->hasFocus() ) {
	combo()->show();
	setFocus( combo() );
    }
}

void PropertyBoolItem::hideEditor()
{
    PropertyItem::hideEditor();
    combo()->hide();
}

void PropertyBoolItem::setValue( const QVariant &v )
{
    if ( ( !hasSubItems() || !isOpen() )
	 && value() == v )
	return;

    if ( comb ) {
	combo()->blockSignals( TRUE );
	if ( v.toBool() )
	    combo()->setCurrentItem( 1 );
	else
	    combo()->setCurrentItem( 0 );
	combo()->blockSignals( FALSE );
    }
    QString tmp = tr( "True" );
    if ( !v.toBool() )
	tmp = tr( "False" );
    setText( 1, tmp );
    PropertyItem::setValue( v );
}

void PropertyBoolItem::setValue()
{
    if ( !comb )
	return;
    setText( 1, combo()->currentText() );
    bool b = combo()->currentItem() == 0 ? (bool)FALSE : (bool)TRUE;
    PropertyItem::setValue( QVariant( b, 0 ) );
    notifyValueChange();
}

// --------------------------------------------------------------

PropertyIntItem::PropertyIntItem( PropertyList *l, PropertyItem *after, PropertyItem *prop,
				  const QString &propName, bool s )
    : PropertyItem( l, after, prop, propName ), signedValue( s )
{
    spinBx = 0;
}

QSpinBox *PropertyIntItem::spinBox()
{
    if ( spinBx )
	return spinBx;
    if ( signedValue )
	spinBx = new QSpinBox( -INT_MAX, INT_MAX, 1, listview->viewport() );
    else
	spinBx = new QSpinBox( 0, INT_MAX, 1, listview->viewport() );
    spinBx->hide();
    spinBx->installEventFilter( listview );
    QObjectList *ol = spinBx->queryList( "QLineEdit" );
    if ( ol && ol->first() )
	ol->first()->installEventFilter( listview );
    delete ol;
    connect( spinBx, SIGNAL( valueChanged( int ) ),
	     this, SLOT( setValue() ) );
    return spinBx;
}

PropertyIntItem::~PropertyIntItem()
{
    delete (QSpinBox*)spinBx;
    spinBx = 0;
}

void PropertyIntItem::showEditor()
{
    PropertyItem::showEditor();
    if ( !spinBx ) {
	spinBox()->blockSignals( TRUE );
	if ( signedValue )
	    spinBox()->setValue( value().toInt() );
	else
	    spinBox()->setValue( value().toUInt() );
	spinBox()->blockSignals( FALSE );
    }
    placeEditor( spinBox() );
    if ( !spinBox()->isVisible()  || !spinBox()->hasFocus()  ) {
	spinBox()->show();
	setFocus( spinBox() );
    }
}

void PropertyIntItem::hideEditor()
{
    PropertyItem::hideEditor();
    spinBox()->hide();
}

void PropertyIntItem::setValue( const QVariant &v )
{
    if ( ( !hasSubItems() || !isOpen() )
	 && value() == v )
	return;

    if ( spinBx ) {
	spinBox()->blockSignals( TRUE );
	if ( signedValue )
	    spinBox()->setValue( v.toInt() );
	else
	    spinBox()->setValue( v.toUInt() );
	spinBox()->blockSignals( FALSE );
    }

    if ( signedValue )
	    setText( 1, QString::number( v.toInt() ) );
    else
	    setText( 1, QString::number( v.toUInt() ) );
    PropertyItem::setValue( v );
}

void PropertyIntItem::setValue()
{
    if ( !spinBx )
	return;
    setText( 1, QString::number( spinBox()->value() ) );
    if ( signedValue )
	PropertyItem::setValue( spinBox()->value() );
    else
	PropertyItem::setValue( (uint)spinBox()->value() );
    notifyValueChange();
}

// --------------------------------------------------------------

PropertyLayoutItem::PropertyLayoutItem( PropertyList *l, PropertyItem *after, PropertyItem *prop,
		  const QString &propName )
    : PropertyItem( l, after, prop, propName )
{
    spinBx = 0;
}

PropertyLayoutItem::~PropertyLayoutItem()
{
    delete (QSpinBox*)spinBx;
    spinBx = 0;
}

QSpinBox* PropertyLayoutItem::spinBox()
{
    if ( spinBx )
	return spinBx;
    spinBx = new QSpinBox( -1, INT_MAX, 1, listview->viewport() );
    spinBx->setSpecialValueText( tr( "default" ) );
    spinBx->hide();
    spinBx->installEventFilter( listview );
    QObjectList *ol = spinBx->queryList( "QLineEdit" );
    if ( ol && ol->first() )
	ol->first()->installEventFilter( listview );
    delete ol;
    connect( spinBx, SIGNAL( valueChanged( int ) ),
	     this, SLOT( setValue() ) );
    return spinBx;
}

void PropertyLayoutItem::showEditor()
{
    PropertyItem::showEditor();
    if ( !spinBx ) {
	spinBox()->blockSignals( TRUE );
	spinBox()->setValue( value().toInt() );
	spinBox()->blockSignals( TRUE );
    }
    placeEditor( spinBox() );
    if ( !spinBox()->isVisible() || !spinBox()->hasFocus() ) {
	spinBox()->show();
	setFocus( spinBox() );
    }
}

void PropertyLayoutItem::hideEditor()
{
    PropertyItem::hideEditor();
    spinBox()->hide();
}

void PropertyLayoutItem::setValue( const QVariant &v )
{
    if ( spinBx ) {
	spinBox()->blockSignals( TRUE );
	spinBox()->setValue( v.toInt() );
	spinBox()->blockSignals( FALSE );
    }
    QString s = v.toString();
    if ( v.toInt() == -1 )
	s = spinBox()->specialValueText();
    setText( 1, s );
    PropertyItem::setValue( v );
}

void PropertyLayoutItem::setValue()
{
    if ( !spinBx )
	return;
    PropertyItem::setValue( spinBox()->value() );
    notifyValueChange();
}


// --------------------------------------------------------------

PropertyListItem::PropertyListItem( PropertyList *l, PropertyItem *after, PropertyItem *prop,
				    const QString &propName, bool e )
    : PropertyItem( l, after, prop, propName ), editable( e )
{
    comb = 0;
    oldInt = -1;
}

QComboBox *PropertyListItem::combo()
{
    if ( comb )
	return comb;
    comb = new QComboBox( editable, listview->viewport() );
    comb->hide();
    connect( comb, SIGNAL( activated( int ) ),
	     this, SLOT( setValue() ) );
    comb->installEventFilter( listview );
    if ( editable ) {
	QObjectList *ol = comb->queryList( "QLineEdit" );
	if ( ol && ol->first() )
	    ol->first()->installEventFilter( listview );
	delete ol;
    }
    return comb;
}

PropertyListItem::~PropertyListItem()
{
    delete (QComboBox*)comb;
    comb = 0;
}

void PropertyListItem::showEditor()
{
    PropertyItem::showEditor();
    if ( !comb ) {
	combo()->blockSignals( TRUE );
	combo()->clear();
	combo()->insertStringList( value().toStringList() );
	combo()->blockSignals( FALSE );
    }
    placeEditor( combo() );
    if ( !combo()->isVisible()  || !combo()->hasFocus() ) {
	combo()->show();
	setFocus( combo() );
    }
}

void PropertyListItem::hideEditor()
{
    PropertyItem::hideEditor();
    combo()->hide();
}

void PropertyListItem::setValue( const QVariant &v )
{
    if ( comb ) {
	combo()->blockSignals( TRUE );
	combo()->clear();
	combo()->insertStringList( v.toStringList() );
	combo()->blockSignals( FALSE );
    }
    setText( 1, v.toStringList().first() );
    PropertyItem::setValue( v );
}

void PropertyListItem::setValue()
{
    if ( !comb )
	return;
    setText( 1, combo()->currentText() );
    QStringList lst;
    for ( uint i = 0; i < combo()->listBox()->count(); ++i )
	lst << combo()->listBox()->item( i )->text();
    PropertyItem::setValue( lst );
    notifyValueChange();
    oldInt = currentIntItem();
    oldString = currentItem();
}

QString PropertyListItem::currentItem() const
{
    return ( (PropertyListItem*)this )->combo()->currentText();
}

void PropertyListItem::setCurrentItem( const QString &s )
{
    if ( comb && currentItem().lower() == s.lower() )
	return;

    if ( !comb ) {
	combo()->blockSignals( TRUE );
	combo()->clear();
	combo()->insertStringList( value().toStringList() );
	combo()->blockSignals( FALSE );
    }
    for ( uint i = 0; i < combo()->listBox()->count(); ++i ) {
	if ( combo()->listBox()->item( i )->text().lower() == s.lower() ) {
	    combo()->setCurrentItem( i );
	    setText( 1, combo()->currentText() );
	    break;
	}
    }
    oldInt = currentIntItem();
    oldString = currentItem();
}

void PropertyListItem::addItem( const QString &s )
{
    combo()->insertItem( s );
}

void PropertyListItem::setCurrentItem( int i )
{
    if ( comb && i == combo()->currentItem() )
	return;

    if ( !comb ) {
	combo()->blockSignals( TRUE );
	combo()->clear();
	combo()->insertStringList( value().toStringList() );
	combo()->blockSignals( FALSE );
    }
    combo()->setCurrentItem( i );
    setText( 1, combo()->currentText() );
    oldInt = currentIntItem();
    oldString = currentItem();
}

int PropertyListItem::currentIntItem() const
{
    return ( (PropertyListItem*)this )->combo()->currentItem();
}

int PropertyListItem::currentIntItemFromObject() const
{
    return oldInt;
}

QString PropertyListItem::currentItemFromObject() const
{
    return oldString;
}

// --------------------------------------------------------------

PropertyCoordItem::PropertyCoordItem( PropertyList *l, PropertyItem *after, PropertyItem *prop,
				    const QString &propName, Type t )
    : PropertyItem( l, after, prop, propName ), typ( t )
{
    lin = 0;

}

QLineEdit *PropertyCoordItem::lined()
{
    if ( lin )
	return lin;
    lin = new QLineEdit( listview->viewport() );
    lin->setReadOnly( TRUE );
    lin->installEventFilter( listview );
    lin->hide();
    return lin;
}

void PropertyCoordItem::createChildren()
{
    PropertyItem *i = this;
    if ( typ == Rect || typ == Point ) {
	i = new PropertyIntItem( listview, i, this, tr( "x" ), TRUE );
	addChild( i );
	i = new PropertyIntItem( listview, i, this, tr( "y" ), TRUE );
	addChild( i );
    }
    if ( typ == Rect || typ == Size ) {
	i = new PropertyIntItem( listview, i, this, tr( "width" ), TRUE );
	addChild( i );
	i = new PropertyIntItem( listview, i, this, tr( "height" ), TRUE );
	addChild( i );
    }
}

void PropertyCoordItem::initChildren()
{
    PropertyItem *item = 0;
    for ( int i = 0; i < childCount(); ++i ) {
	item = PropertyItem::child( i );
	if ( item->name() == tr( "x" ) ) {
	    if ( typ == Rect )
		item->setValue( val.toRect().x() );
	    else if ( typ == Point )
		item->setValue( val.toPoint().x() );
	} else if ( item->name() == tr( "y" ) ) {
	    if ( typ == Rect )
		item->setValue( val.toRect().y() );
	    else if ( typ == Point )
		item->setValue( val.toPoint().y() );
	} else if ( item->name() == tr( "width" ) ) {
	    if ( typ == Rect )
		item->setValue( val.toRect().width() );
	    else if ( typ == Size )
		item->setValue( val.toSize().width() );
	} else if ( item->name() == tr( "height" ) ) {
	    if ( typ == Rect )
		item->setValue( val.toRect().height() );
	    else if ( typ == Size )
		item->setValue( val.toSize().height() );
	}
    }
}

PropertyCoordItem::~PropertyCoordItem()
{
    delete (QLineEdit*)lin;
    lin = 0;
}

void PropertyCoordItem::showEditor()
{
    PropertyItem::showEditor();
    if ( !lin )
	lined()->setText( text( 1 ) );
    placeEditor( lined() );
    if ( !lined()->isVisible() || !lined()->hasFocus()  ) {
	lined()->show();
	setFocus( lined() );
    }
}

void PropertyCoordItem::hideEditor()
{
    PropertyItem::hideEditor();
    lined()->hide();
}

void PropertyCoordItem::setValue( const QVariant &v )
{
    if ( ( !hasSubItems() || !isOpen() )
	 && value() == v )
	return;

    QString s;
    if ( typ == Rect )
	s = "[ " + QString::number( v.toRect().x() ) + ", " + QString::number( v.toRect().y() ) + ", " +
	    QString::number( v.toRect().width() ) + ", " + QString::number( v.toRect().height() ) + " ]";
    else if ( typ == Point )
	s = "[ " + QString::number( v.toPoint().x() ) + ", " +
	    QString::number( v.toPoint().y() ) + " ]";
    else if ( typ == Size )
	s = "[ " + QString::number( v.toSize().width() ) + ", " +
	    QString::number( v.toSize().height() ) + " ]";
    setText( 1, s );
    if ( lin )
	lined()->setText( s );
    PropertyItem::setValue( v );
}

bool PropertyCoordItem::hasSubItems() const
{
    return TRUE;
}

void PropertyCoordItem::childValueChanged( PropertyItem *child )
{
    if ( typ == Rect ) {
	QRect r = value().toRect();
	if ( child->name() == tr( "x" ) )
	    r.moveBy( -r.x() + child->value().toInt(), 0 );
	else if ( child->name() == tr( "y" ) )
	    r.moveBy( 0, -r.y() + child->value().toInt() );
	else if ( child->name() == tr( "width" ) )
	    r.setWidth( child->value().toInt() );
	else if ( child->name() == tr( "height" ) )
	    r.setHeight( child->value().toInt() );
	setValue( r );
    } else if ( typ == Point ) {
	QPoint r = value().toPoint();
	if ( child->name() == tr( "x" ) )
	    r.setX( child->value().toInt() );
	else if ( child->name() == tr( "y" ) )
	    r.setY( child->value().toInt() );
	setValue( r );
    } else if ( typ == Size ) {
	QSize r = value().toSize();
	if ( child->name() == tr( "width" ) )
	    r.setWidth( child->value().toInt() );
	else if ( child->name() == tr( "height" ) )
	    r.setHeight( child->value().toInt() );
	setValue( r );
    }
    notifyValueChange();
}

// --------------------------------------------------------------

PropertyPixmapItem::PropertyPixmapItem( PropertyList *l, PropertyItem *after, PropertyItem *prop,
					const QString &propName, Type t )
    : PropertyItem( l, after, prop, propName ), type( t )
{
    box = new QHBox( listview->viewport() );
    box->hide();
    pixPrev = new QLabel( box );
    pixPrev->setSizePolicy( QSizePolicy( QSizePolicy::Ignored, QSizePolicy::Minimum ) );
    pixPrev->setBackgroundColor( pixPrev->colorGroup().color( QColorGroup::Base ) );
    button = new QPushButton( "...", box );
    setupStyle( button );
    button->setFixedWidth( 20 );
    box->setFrameStyle( QFrame::StyledPanel | QFrame::Sunken );
    box->setLineWidth( 2 );
    pixPrev->setFrameStyle( QFrame::NoFrame );
    box->installEventFilter( listview );
    connect( button, SIGNAL( clicked() ),
	     this, SLOT( getPixmap() ) );
}

PropertyPixmapItem::~PropertyPixmapItem()
{
    delete (QHBox*)box;
}

void PropertyPixmapItem::showEditor()
{
    PropertyItem::showEditor();
    placeEditor( box );
    if ( !box->isVisible() ) {
	box->show();
	listView()->viewport()->setFocus();
    }
}

void PropertyPixmapItem::hideEditor()
{
    PropertyItem::hideEditor();
    box->hide();
}

void PropertyPixmapItem::setValue( const QVariant &v )
{
    QString s;
    if ( type == Pixmap )
	pixPrev->setPixmap( v.toPixmap() );
    else if ( type == IconSet )
	pixPrev->setPixmap( v.toIconSet().pixmap() );
    else
	pixPrev->setPixmap( v.toImage() );
    PropertyItem::setValue( v );
    repaint();
}

void PropertyPixmapItem::getPixmap()
{
/*    QPixmap pix = qChoosePixmap( listview, listview->propertyEditor()->formWindow(), value().toPixmap() );
    if ( !pix.isNull() ) {
	if ( type == Pixmap )
	    setValue( pix );
	else if ( type == IconSet )
	    setValue( QIconSet( pix ) );
	else
	    setValue( pix.convertToImage() );

	notifyValueChange();
    }*/
}

bool PropertyPixmapItem::hasCustomContents() const
{
    return TRUE;
}

void PropertyPixmapItem::drawCustomContents( QPainter *p, const QRect &r )
{
    QPixmap pix;
    if ( type == Pixmap )
	pix = value().toPixmap();
    else if ( type == IconSet )
	pix = value().toIconSet().pixmap();
    else
	pix = value().toImage();

    if ( !pix.isNull() ) {
	p->save();
	p->setClipRect( QRect( QPoint( (int)(p->worldMatrix().dx() + r.x()),
				       (int)(p->worldMatrix().dy() + r.y()) ),
			       r.size() ) );
	p->drawPixmap( r.x(), r.y() + ( r.height() - pix.height() ) / 2, pix );
	p->restore();
    }
}


// --------------------------------------------------------------

PropertyColorItem::PropertyColorItem( PropertyList *l, PropertyItem *after, PropertyItem *prop,
				      const QString &propName, bool children )
    : PropertyItem( l, after, prop, propName ), withChildren( children )
{
    box = new QHBox( listview->viewport() );
    box->hide();
    colorPrev = new QFrame( box );
    button = new QPushButton( "...", box );
    setupStyle( button );
    button->setFixedWidth( 20 );
    box->setFrameStyle( QFrame::StyledPanel | QFrame::Sunken );
    box->setLineWidth( 2 );
    colorPrev->setFrameStyle( QFrame::Plain | QFrame::Box );
    colorPrev->setLineWidth( 2 );
    QPalette pal = colorPrev->palette();
    QColorGroup cg = pal.active();
    cg.setColor( QColorGroup::Foreground, cg.color( QColorGroup::Base ) );
    pal.setActive( cg );
    pal.setInactive( cg );
    pal.setDisabled( cg );
    colorPrev->setPalette( pal );
    box->installEventFilter( listview );
    connect( button, SIGNAL( clicked() ),
	     this, SLOT( getColor() ) );
}

void PropertyColorItem::createChildren()
{
    PropertyItem *i = this;
    i = new PropertyIntItem( listview, i, this, tr( "Red" ), TRUE );
    addChild( i );
    i = new PropertyIntItem( listview, i, this, tr( "Green" ), TRUE );
    addChild( i );
    i = new PropertyIntItem( listview, i, this, tr( "Blue" ), TRUE );
    addChild( i );
}

void PropertyColorItem::initChildren()
{
    PropertyItem *item = 0;
    for ( int i = 0; i < childCount(); ++i ) {
	item = PropertyItem::child( i );
	if ( item->name() == tr( "Red" ) )
	    item->setValue( val.toColor().red() );
	else if ( item->name() == tr( "Green" ) )
	    item->setValue( val.toColor().green() );
	else if ( item->name() == tr( "Blue" ) )
	    item->setValue( val.toColor().blue() );
    }
}

PropertyColorItem::~PropertyColorItem()
{
    delete (QHBox*)box;
}

void PropertyColorItem::showEditor()
{
    PropertyItem::showEditor();
    placeEditor( box );
    if ( !box->isVisible() ) {
	box->show();
	listView()->viewport()->setFocus();
    }
}

void PropertyColorItem::hideEditor()
{
    PropertyItem::hideEditor();
    box->hide();
}

void PropertyColorItem::setValue( const QVariant &v )
{
    if ( ( !hasSubItems() || !isOpen() )
	 && value() == v )
	return;

    QString s;
    setText( 1, v.toColor().name() );
    colorPrev->setBackgroundColor( v.toColor() );
    PropertyItem::setValue( v );
}

bool PropertyColorItem::hasSubItems() const
{
    return withChildren;
}

void PropertyColorItem::childValueChanged( PropertyItem *child )
{
    QColor c( val.toColor() );
    if ( child->name() == tr( "Red" ) )
	c.setRgb( child->value().toInt(), c.green(), c.blue() );
    else if ( child->name() == tr( "Green" ) )
	c.setRgb( c.red(), child->value().toInt(), c.blue() );
    else if ( child->name() == tr( "Blue" ) )
	c.setRgb( c.red(), c.green(), child->value().toInt() );
    setValue( c );
    notifyValueChange();
}

void PropertyColorItem::getColor()
{
    QColor c = QColorDialog::getColor( val.asColor(), listview );
    if ( c.isValid() ) {
	setValue( c );
	notifyValueChange();
    }
}

bool PropertyColorItem::hasCustomContents() const
{
    return TRUE;
}

void PropertyColorItem::drawCustomContents( QPainter *p, const QRect &r )
{
    p->save();
    p->setPen( QPen( black, 1 ) );
    p->setBrush( val.toColor() );
    p->drawRect( r.x() + 2, r.y() + 2, r.width() - 5, r.height() - 5 );
    p->restore();
}

// --------------------------------------------------------------

PropertyFontItem::PropertyFontItem( PropertyList *l, PropertyItem *after, PropertyItem *prop, const QString &propName )
    : PropertyItem( l, after, prop, propName )
{
    box = new QHBox( listview->viewport() );
    box->hide();
    lined = new QLineEdit( box );
    button = new QPushButton( "...", box );
    setupStyle( button );
    button->setFixedWidth( 20 );
    box->setFrameStyle( QFrame::StyledPanel | QFrame::Sunken );
    box->setLineWidth( 2 );
    lined->setFrame( FALSE );
    lined->setReadOnly( TRUE );
    box->setFocusProxy( lined );
    box->installEventFilter( listview );
    lined->installEventFilter( listview );
    button->installEventFilter( listview );
    connect( button, SIGNAL( clicked() ),
	     this, SLOT( getFont() ) );
}

void PropertyFontItem::createChildren()
{
    PropertyItem *i = this;
    i = new PropertyListItem( listview, i, this, tr( "Family" ), FALSE );
    addChild( i );
    i = new PropertyIntItem( listview, i, this, tr( "Point Size" ), TRUE );
    addChild( i );
    i = new PropertyBoolItem( listview, i, this, tr( "Bold" ) );
    addChild( i );
    i = new PropertyBoolItem( listview, i, this, tr( "Italic" ) );
    addChild( i );
    i = new PropertyBoolItem( listview, i, this, tr( "Underline" ) );
    addChild( i );
    i = new PropertyBoolItem( listview, i, this, tr( "Strikeout" ) );
    addChild( i );
}

void PropertyFontItem::initChildren()
{
    PropertyItem *item = 0;
    for ( int i = 0; i < childCount(); ++i ) {
	item = PropertyItem::child( i );
	if ( item->name() == tr( "Family" ) ) {
	    ( (PropertyListItem*)item )->setValue( getFontList() );
	    ( (PropertyListItem*)item )->setCurrentItem( val.toFont().family() );
	} else if ( item->name() == tr( "Point Size" ) )
	    item->setValue( val.toFont().pointSize() );
	else if ( item->name() == tr( "Bold" ) )
	    item->setValue( QVariant( val.toFont().bold(), 0 ) );
	else if ( item->name() == tr( "Italic" ) )
	    item->setValue( QVariant( val.toFont().italic(), 0 ) );
	else if ( item->name() == tr( "Underline" ) )
	    item->setValue( QVariant( val.toFont().underline(), 0 ) );
	else if ( item->name() == tr( "Strikeout" ) )
	    item->setValue( QVariant( val.toFont().strikeOut(), 0 ) );
    }
}

PropertyFontItem::~PropertyFontItem()
{
    delete (QHBox*)box;
}

void PropertyFontItem::showEditor()
{
    PropertyItem::showEditor();
    placeEditor( box );
    if ( !box->isVisible() || !lined->hasFocus() ) {
	box->show();
	setFocus( lined );
    }
}

void PropertyFontItem::hideEditor()
{
    PropertyItem::hideEditor();
    box->hide();
}

void PropertyFontItem::setValue( const QVariant &v )
{
    if ( value() == v )
	return;

    setText( 1, v.toFont().family() + "-" + QString::number( v.toFont().pointSize() ) );
    lined->setText( v.toFont().family() + "-" + QString::number( v.toFont().pointSize() ) );
    PropertyItem::setValue( v );
}

void PropertyFontItem::getFont()
{
    bool ok = FALSE;
    QFont f = QFontDialog::getFont( &ok, val.toFont(), listview );
    if ( ok && f != val.toFont() ) {
	setValue( f );
	notifyValueChange();
    }
}

bool PropertyFontItem::hasSubItems() const
{
    return TRUE;
}

void PropertyFontItem::childValueChanged( PropertyItem *child )
{
    QFont f = val.toFont();
    if ( child->name() == tr( "Family" ) )
	f.setFamily( ( (PropertyListItem*)child )->currentItem() );
    else if ( child->name() == tr( "Point Size" ) )
	f.setPointSize( child->value().toInt() );
    else if ( child->name() == tr( "Bold" ) )
	f.setBold( child->value().toBool() );
    else if ( child->name() == tr( "Italic" ) )
	f.setItalic( child->value().toBool() );
    else if ( child->name() == tr( "Underline" ) )
	f.setUnderline( child->value().toBool() );
    else if ( child->name() == tr( "Strikeout" ) )
	f.setStrikeOut( child->value().toBool() );
    setValue( f );
    notifyValueChange();
}

// --------------------------------------------------------------

PropertyDatabaseItem::PropertyDatabaseItem( PropertyList *l, PropertyItem *after, PropertyItem *prop,
					    const QString &propName, bool wField )
    : PropertyItem( l, after, prop, propName ), withField( wField )
{
    box = new QHBox( listview->viewport() );
    box->hide();
    lined = new QLineEdit( box );
    button = new QPushButton( "...", box );
    setupStyle( button );
    button->setFixedWidth( 20 );
    box->setFrameStyle( QFrame::StyledPanel | QFrame::Sunken );
    box->setLineWidth( 2 );
    lined->setFrame( FALSE );
    lined->setReadOnly( TRUE );
    box->setFocusProxy( lined );
    box->installEventFilter( listview );
    lined->installEventFilter( listview );
    button->installEventFilter( listview );
}

void PropertyDatabaseItem::createChildren()
{
    PropertyItem *i = this;
    i = new PropertyListItem( listview, i, this, tr( "Connection" ), TRUE );
    addChild( i );
    i = new PropertyListItem( listview, i, this, tr( "Table" ), TRUE );
    addChild( i );
    if ( withField ) {
	i = new PropertyListItem( listview, i, this, tr( "Field" ), TRUE );
	addChild( i );
    }
}

void PropertyDatabaseItem::initChildren()
{
#ifndef QT_NO_SQL
    PropertyItem *item = 0;
    QStringList lst = value().toStringList();
    QString conn, table;
    for ( int i = 0; i < childCount(); ++i ) {
	item = PropertyItem::child( i );
	if ( item->name() == tr( "Connection" ) ) {
	    QStringList cl = listview->propertyEditor()->formWindow()->project()->databaseConnectionList();
	    if ( !cl.isEmpty() )
		item->setValue( cl );
	    else if ( lst.count() > 0 )
		item->setValue( QStringList( lst[ 0 ] ) );
	    else if ( withField )
		item->setValue( QStringList( MetaDataBase::fakeProperty( listview->propertyEditor()->formWindow()->mainContainer(),
									 "database" ).toStringList()[ 0 ] ) );

	    if ( lst.count() > 0 && !lst[ 0 ].isEmpty() )
		item->setCurrentItem( lst[ 0 ] );
	    else if ( !isChanged() && withField )
		item->setCurrentItem( MetaDataBase::fakeProperty( listview->propertyEditor()->formWindow()->mainContainer(),
								  "database" ).toStringList()[ 0 ] );
	    else
		item->setCurrentItem( 0 );
	    conn = item->currentItem();
	} else if ( item->name() == tr( "Table" ) ) {
	    QStringList cl = listview->propertyEditor()->formWindow()->project()->databaseTableList( conn );
	    if ( !cl.isEmpty() )
		item->setValue( cl );
	    else if ( lst.count() > 1 )
		item->setValue( QStringList( lst[ 1 ] ) );
	    else if ( withField ) {
		QStringList fakeLst = MetaDataBase::fakeProperty( listview->propertyEditor()->formWindow()->mainContainer(), "database" ).toStringList();
		if ( fakeLst.count() > 1 )
		    item->setValue( fakeLst[ 1 ] );
	    }

	    if ( lst.count() > 1 && !lst[ 1 ].isEmpty() )
		item->setCurrentItem( lst[ 1 ] );
	    else if ( !isChanged() && withField ) {
		QStringList fakeLst = MetaDataBase::fakeProperty( listview->propertyEditor()->formWindow()->mainContainer(), "database" ).toStringList();
		if ( fakeLst.count() > 1 )
		    item->setCurrentItem( fakeLst[ 1 ] );
	        else
	            item->setCurrentItem( 0 );
	    } else
		item->setCurrentItem( 0 );
	    table = item->currentItem();
	} else if ( item->name() == tr( "Field" ) ) {
	    QStringList cl = listview->propertyEditor()->formWindow()->project()->databaseFieldList( conn, table );
	    if ( !cl.isEmpty() )
		item->setValue( cl );
	    else if ( lst.count() > 2 )
		item->setValue( QStringList( lst[ 2 ] ) );
	    if ( lst.count() > 2 && !lst[ 2 ].isEmpty() )
		item->setCurrentItem( lst[ 2 ] );
	    else
		item->setCurrentItem( 0 );
	}
    }
#endif
}

PropertyDatabaseItem::~PropertyDatabaseItem()
{
    delete (QHBox*)box;
}

void PropertyDatabaseItem::showEditor()
{
    PropertyItem::showEditor();
    placeEditor( box );
    if ( !box->isVisible() || !lined->hasFocus() ) {
	box->show();
	setFocus( lined );
    }
}

void PropertyDatabaseItem::hideEditor()
{
    PropertyItem::hideEditor();
    box->hide();
}

void PropertyDatabaseItem::setValue( const QVariant &v )
{
    if ( value() == v )
	return;

    QStringList lst = v.toStringList();
    QString s = lst.join( "." );
    setText( 1, s );
    lined->setText( s );
    PropertyItem::setValue( v );
}

bool PropertyDatabaseItem::hasSubItems() const
{
    return TRUE;
}

void PropertyDatabaseItem::childValueChanged( PropertyItem *c )
{
#ifndef QT_NO_SQL
    QStringList lst;
    lst << ( (PropertyListItem*)PropertyItem::child( 0 ) )->currentItem()
	<< ( (PropertyListItem*)PropertyItem::child( 1 ) )->currentItem();
    if ( withField )
	lst << ( (PropertyListItem*)PropertyItem::child( 2 ) )->currentItem();
    if ( c == PropertyItem::child( 0 ) ) { // if the connection changed
	lst[ 0 ] = ( (PropertyListItem*)c )->currentItem();
	PropertyItem::child( 1 )->setValue( listview->propertyEditor()->formWindow()->project()->databaseTableList( lst[ 0 ] ) );
	if ( withField )
	    PropertyItem::child( 2 )->setValue( listview->propertyEditor()->formWindow()->project()->databaseFieldList( lst[ 0 ], lst[ 1 ] ) );
    } else if ( withField && c == PropertyItem::child( 1 ) ) { // if the table changed
	lst[ 1 ] = ( (PropertyListItem*)c )->currentItem();
	if ( withField )
	    PropertyItem::child( 2 )->setValue( listview->propertyEditor()->formWindow()->project()->databaseFieldList( lst[ 0 ], lst[ 1 ] ) );
    }
    lst.clear();
    lst << ( (PropertyListItem*)PropertyItem::child( 0 ) )->currentItem()
	<< ( (PropertyListItem*)PropertyItem::child( 1 ) )->currentItem();
    if ( withField )
	lst << ( (PropertyListItem*)PropertyItem::child( 2 ) )->currentItem();
    setValue( lst );
    notifyValueChange();
#else
    Q_UNUSED( c );
#endif
}

// --------------------------------------------------------------

PropertySizePolicyItem::PropertySizePolicyItem( PropertyList *l, PropertyItem *after, PropertyItem *prop,
						const QString &propName )
    : PropertyItem( l, after, prop, propName )
{
    lin = 0;
}

QLineEdit *PropertySizePolicyItem::lined()
{
    if ( lin )
	return lin;
    lin = new QLineEdit( listview->viewport() );
    lin->hide();
    lin->setReadOnly( TRUE );
    return lin;
}

void PropertySizePolicyItem::createChildren()
{
    QStringList lst;
    lst << "Fixed" << "Minimum" << "Maximum" << "Preferred" << "MinimumExpanding" << "Expanding" << "Ignored";

    PropertyItem *i = this;
    i = new PropertyListItem( listview, i, this, tr( "hSizeType" ), FALSE );
    i->setValue( lst );
    addChild( i );
    i = new PropertyListItem( listview, i, this, tr( "vSizeType" ), FALSE );
    i->setValue( lst );
    addChild( i );
    i = new PropertyIntItem( listview, i, this, tr( "horizontalStretch" ), TRUE );
    addChild( i );
    i = new PropertyIntItem( listview, i, this, tr( "verticalStretch" ), TRUE );
    addChild( i );
}

void PropertySizePolicyItem::initChildren()
{
    PropertyItem *item = 0;
    QSizePolicy sp = val.toSizePolicy();
    for ( int i = 0; i < childCount(); ++i ) {
	item = PropertyItem::child( i );
	if ( item->name() == tr( "hSizeType" ) )
	    ( (PropertyListItem*)item )->setCurrentItem( size_type_to_int( sp.horData() ) );
	else if ( item->name() == tr( "vSizeType" ) )
	    ( (PropertyListItem*)item )->setCurrentItem( size_type_to_int( sp.verData() ) );
	else if ( item->name() == tr( "horizontalStretch" ) )
	    ( (PropertyIntItem*)item )->setValue( sp.horStretch() );
	else if ( item->name() == tr( "verticalStretch" ) )
	    ( (PropertyIntItem*)item )->setValue( sp.verStretch() );
    }
}

PropertySizePolicyItem::~PropertySizePolicyItem()
{
    delete (QLineEdit*)lin;
}

void PropertySizePolicyItem::showEditor()
{
    PropertyItem::showEditor();
    placeEditor( lined() );
    if ( !lined()->isVisible() || !lined()->hasFocus() ) {
	lined()->show();
	listView()->viewport()->setFocus();
    }
}

void PropertySizePolicyItem::hideEditor()
{
    PropertyItem::hideEditor();
    lined()->hide();
}

void PropertySizePolicyItem::setValue( const QVariant &v )
{
    if ( value() == v )
	return;

    QString s = tr( "%1/%2/%2/%2" );
    s = s.arg( size_type_to_string( v.toSizePolicy().horData() ) ).
	arg( size_type_to_string( v.toSizePolicy().verData() ) ).
	arg( v.toSizePolicy().horStretch() ).
	arg( v.toSizePolicy().verStretch() );
    setText( 1, s );
    lined()->setText( s );
    PropertyItem::setValue( v );
}

void PropertySizePolicyItem::childValueChanged( PropertyItem *child )
{
    QSizePolicy sp = val.toSizePolicy();
    if ( child->name() == tr( "hSizeType" ) )
	sp.setHorData( int_to_size_type( ( ( PropertyListItem*)child )->currentIntItem() ) );
    else if ( child->name() == tr( "vSizeType" ) )
	sp.setVerData( int_to_size_type( ( ( PropertyListItem*)child )->currentIntItem() ) );
    else if ( child->name() == tr( "horizontalStretch" ) )
	sp.setHorStretch( ( ( PropertyIntItem*)child )->value().toInt() );
    else if ( child->name() == tr( "verticalStretch" ) )
	sp.setVerStretch( ( ( PropertyIntItem*)child )->value().toInt() );
    setValue( sp );
    notifyValueChange();
}

bool PropertySizePolicyItem::hasSubItems() const
{
    return TRUE;
}

// --------------------------------------------------------------

PropertyPaletteItem::PropertyPaletteItem( PropertyList *l, PropertyItem *after, PropertyItem *prop,
				      const QString &propName )
    : PropertyItem( l, after, prop, propName )
{
    box = new QHBox( listview->viewport() );
    box->hide();
    palettePrev = new QLabel( box );
    button = new QPushButton( "...", box );
    setupStyle( button );
    button->setFixedWidth( 20 );
    box->setFrameStyle( QFrame::StyledPanel | QFrame::Sunken );
    box->setLineWidth( 2 );
    palettePrev->setFrameStyle( QFrame::NoFrame );
    box->installEventFilter( listview );
    connect( button, SIGNAL( clicked() ),
	     this, SLOT( getPalette() ) );
}
PropertyPaletteItem::~PropertyPaletteItem()
{
    delete (QHBox*)box;
}

void PropertyPaletteItem::showEditor()
{
    PropertyItem::showEditor();
    placeEditor( box );
    if ( !box->isVisible() ) {
	box->show();
	listView()->viewport()->setFocus();
    }
}

void PropertyPaletteItem::hideEditor()
{
    PropertyItem::hideEditor();
    box->hide();
}

void PropertyPaletteItem::setValue( const QVariant &v )
{
    QString s;
    palettePrev->setPalette( v.toPalette() );
    PropertyItem::setValue( v );
    repaint();
}

void PropertyPaletteItem::getPalette()
{
    /*if ( !listview->propertyEditor()->widget()->isWidgetType() )
	return;
    bool ok = FALSE;
    QWidget *w = (QWidget*)listview->propertyEditor()->widget();
    if ( w->inherits( "QScrollView" ) )
	w = ( (QScrollView*)w )->viewport();
    QPalette pal = PaletteEditor::getPalette( &ok, val.toPalette(),
#if defined(QT_NON_COMMERCIAL)
					      w->backgroundMode(), listview->topLevelWidget(),
#else
					      w->backgroundMode(), listview,
#endif
 					      "choose_palette", listview->propertyEditor()->formWindow() );
    if ( !ok )
	return;
    setValue( pal );
    notifyValueChange();*/
}

bool PropertyPaletteItem::hasCustomContents() const
{
    return TRUE;
}

void PropertyPaletteItem::drawCustomContents( QPainter *p, const QRect &r )
{
    QPalette pal( value().toPalette() );
    p->save();
    p->setClipRect( QRect( QPoint( (int)(p->worldMatrix().dx() + r.x()),
				   (int)(p->worldMatrix().dy() + r.y()) ),
			   r.size() ) );
    QRect r2( r );
    r2.setX( r2.x() + 2 );
    r2.setY( r2.y() + 2 );
    r2.setWidth( r2.width() - 3 );
    r2.setHeight( r2.height() - 3 );
    p->setPen( QPen( black, 1 ) );
    p->setBrush( pal.active().background() );
    p->drawRect( r2 );
    p->restore();
}

// --------------------------------------------------------------

PropertyCursorItem::PropertyCursorItem( PropertyList *l, PropertyItem *after, PropertyItem *prop,
					const QString &propName )
    : PropertyItem( l, after, prop, propName )
{
    comb = 0;
}

QComboBox *PropertyCursorItem::combo()
{
    if ( comb )
	return comb;
    comb = new QComboBox( FALSE, listview->viewport() );
    comb->hide();
    QBitmap cur;

    comb->insertItem( QPixmap::fromMimeSource( "designer_arrow.png" ), tr("Arrow"), QObject::ArrowCursor);
    comb->insertItem( QPixmap::fromMimeSource( "designer_uparrow.png" ), tr("Up-Arrow"), QObject::UpArrowCursor );
    comb->insertItem( QPixmap::fromMimeSource( "designer_cross.png" ), tr("Cross"), QObject::CrossCursor );
    comb->insertItem( QPixmap::fromMimeSource( "designer_wait.png" ), tr("Waiting"), QObject::WaitCursor );
    comb->insertItem( QPixmap::fromMimeSource( "designer_ibeam.png" ), tr("iBeam"), QObject::IbeamCursor );
    comb->insertItem( QPixmap::fromMimeSource( "designer_sizev.png" ), tr("Size Vertical"), QObject::SizeVerCursor );
    comb->insertItem( QPixmap::fromMimeSource( "designer_sizeh.png" ), tr("Size Horizontal"), QObject::SizeHorCursor );
    comb->insertItem( QPixmap::fromMimeSource( "designer_sizef.png" ), tr("Size Slash"), QObject::SizeBDiagCursor );
    comb->insertItem( QPixmap::fromMimeSource( "designer_sizeb.png" ), tr("Size Backslash"), QObject::SizeFDiagCursor );
    comb->insertItem( QPixmap::fromMimeSource( "designer_sizeall.png" ), tr("Size All"), QObject::SizeAllCursor );
    cur = QBitmap( 25, 25, 1 );
    cur.setMask( cur );
    comb->insertItem( cur, tr("Blank"), QObject::BlankCursor );
    comb->insertItem( QPixmap::fromMimeSource( "designer_vsplit.png" ), tr("Split Vertical"), QObject::SplitVCursor );
    comb->insertItem( QPixmap::fromMimeSource( "designer_hsplit.png" ), tr("Split Horizontal"), QObject::SplitHCursor );
    comb->insertItem( QPixmap::fromMimeSource( "designer_hand.png" ), tr("Pointing Hand"), QObject::PointingHandCursor );
    comb->insertItem( QPixmap::fromMimeSource( "designer_no.png" ), tr("Forbidden"), QObject::ForbiddenCursor );

    connect( comb, SIGNAL( activated( int ) ),
	     this, SLOT( setValue() ) );
    comb->installEventFilter( listview );
    return comb;
}

PropertyCursorItem::~PropertyCursorItem()
{
    delete (QComboBox*)comb;
}

void PropertyCursorItem::showEditor()
{
    PropertyItem::showEditor();
    if ( !comb ) {
	combo()->blockSignals( TRUE );
	combo()->setCurrentItem( (int)value().toCursor().shape() );
	combo()->blockSignals( FALSE );
    }
    placeEditor( combo() );
    if ( !combo()->isVisible() || !combo()->hasFocus() ) {
	combo()->show();
	setFocus( combo() );
    }
}

void PropertyCursorItem::hideEditor()
{
    PropertyItem::hideEditor();
    combo()->hide();
}

void PropertyCursorItem::setValue( const QVariant &v )
{
    if ( ( !hasSubItems() || !isOpen() )
	 && value() == v )
	return;

    combo()->blockSignals( TRUE );
    combo()->setCurrentItem( (int)v.toCursor().shape() );
    combo()->blockSignals( FALSE );
    setText( 1, combo()->currentText() );
    PropertyItem::setValue( v );
}

void PropertyCursorItem::setValue()
{
    if ( !comb )
	return;
    if ( QVariant( QCursor( combo()->currentItem() ) ) == val )
	return;
    setText( 1, combo()->currentText() );
    PropertyItem::setValue( QCursor( combo()->currentItem() ) );
    notifyValueChange();
}

// --------------------------------------------------------------

PropertyKeysequenceItem::PropertyKeysequenceItem( PropertyList *l,
						  PropertyItem *after,
						  PropertyItem *prop,
						  const QString &propName )
    : PropertyItem( l, after, prop, propName ),
      k1( 0 ), k2( 0 ), k3( 0 ), k4( 0 ), num( 0 ), mouseEnter( FALSE )
{
    box = new QHBox( listview->viewport() );
    box->hide();
    sequence = new QLineEdit( box );
    connect( sequence, SIGNAL(textChanged( const QString & )),
	     this, SLOT(setValue()) );
    sequence->installEventFilter( this );
}

PropertyKeysequenceItem::~PropertyKeysequenceItem()
{
    delete (QHBox*)box;
}

void PropertyKeysequenceItem::showEditor()
{
    PropertyItem::showEditor();
    placeEditor( box );
    if ( !box->isVisible() ) {
	box->show();
	sequence->setFocus();
    }
}

void PropertyKeysequenceItem::hideEditor()
{
    PropertyItem::hideEditor();
    box->hide();
}

bool PropertyKeysequenceItem::eventFilter( QObject *o, QEvent *e )
{
    Q_UNUSED( o );
    if ( e->type() == QEvent::KeyPress ) {
        QKeyEvent *k = (QKeyEvent *)e;
	if ( !mouseEnter &&
	    (k->key() == QObject::Key_Up ||
	     k->key() == QObject::Key_Down) )
	    return FALSE;
        handleKeyEvent( k );
        return TRUE;
    } else if ( (e->type() == QEvent::FocusIn) ||
		(e->type() == QEvent::MouseButtonPress) ) {
//	mouseEnter = ( listview->lastEvent() == PropertyList::MouseEvent ) ||
//		     (e->type() == QEvent::MouseButtonPress);
	return TRUE;
    }

    // Lets eat accelerators now..
    if ( e->type() == QEvent::Accel ||
	 e->type() == QEvent::AccelOverride  ||
	 e->type() == QEvent::KeyRelease )
	return TRUE;
    return FALSE;
}

void PropertyKeysequenceItem::handleKeyEvent( QKeyEvent *e )
{
    int nextKey = e->key();

    if ( num > 3 ||
	 nextKey == QObject::Key_Control ||
	 nextKey == QObject::Key_Shift ||
	 nextKey == QObject::Key_Meta ||
	 nextKey == QObject::Key_Alt )
	 return;

    nextKey |= translateModifiers( e->state() );
    switch( num ) {
	case 0:
	    k1 = nextKey;
	    break;
	case 1:
	    k2 = nextKey;
	    break;
	case 2:
	    k3 = nextKey;
	    break;
	case 3:
	    k4 = nextKey;
	    break;
	default:
	    break;
    }
    num++;
    QKeySequence ks( k1, k2, k3, k4 );
    sequence->setText( ks );
}

int PropertyKeysequenceItem::translateModifiers( int state )
{
    int result = 0;
    if ( state & QObject::ShiftButton )
	result |= QObject::SHIFT;
    if ( state & QObject::ControlButton )
	result |= QObject::CTRL;
    if ( state & QObject::MetaButton )
	result |= QObject::META;
    if ( state & QObject::AltButton )
	result |= QObject::ALT;
    return result;
}

void PropertyKeysequenceItem::setValue()
{
    QVariant v;
    v = QVariant( QKeySequence(sequence->text()) );
    if ( v.toString().isNull() )
	return;
    setText( 1, sequence->text() );
    PropertyItem::setValue( v );
    if ( sequence->hasFocus() )
	notifyValueChange();
    setChanged( TRUE );
}

void PropertyKeysequenceItem::setValue( const QVariant &v )
{
    QKeySequence ks = v.toKeySequence();
    if ( sequence ) {
	sequence->setText( ks );
    }
    num = ks.count();
    k1 = ks[0];
    k2 = ks[1];
    k3 = ks[2];
    k4 = ks[3];
    setText( 1, ks );
    PropertyItem::setValue( v );
}

// --------------------------------------------------------------

EnumPopup::EnumPopup( QWidget *parent, const char *name, WFlags f )
    : QFrame( parent, name, f )
{
    setLineWidth( 1 );
    setFrameStyle( Panel | Plain );
    setPaletteBackgroundColor( Qt::white );
    popLayout = new QVBoxLayout( this, 3 );
    checkBoxList.setAutoDelete( TRUE );
}

EnumPopup::~EnumPopup()
{
}

void EnumPopup::insertEnums( QValueList<EnumItem> lst )
{
    while ( checkBoxList.count() )
	checkBoxList.removeFirst();

    itemList = lst;
    QCheckBox *cb;
    QValueListConstIterator<EnumItem> it = itemList.begin();
    for ( ; it != itemList.end(); ++it ) {
	cb = new QCheckBox( this );
	cb->setText( (*it).key );
	cb->setChecked( (*it).selected );
	if ( it == itemList.begin() )
	    cb->setFocus();
	checkBoxList.append( cb );
	cb->resize( width(), cb->height() );
	popLayout->addWidget( cb );
    }
}

void EnumPopup::keyPressEvent( QKeyEvent *e )
{
    if ( e->key() == Key_Escape ) {
	hide();
	emit hidden();
    } else if ( e->key() == Key_Enter || e->key() == Key_Return ) {
	closeWidget();
    }
}

void EnumPopup::closeWidget()
{
    QPtrListIterator<QCheckBox> it( checkBoxList );
    int i = 0;
    while ( it.current() != 0 ) {
	itemList[i].selected = (*it)->isChecked();
	++it;
	++i;
    }
    close();
    emit closed();
}

QValueList<EnumItem> EnumPopup::enumList() const
{
    return itemList;
}

EnumBox::EnumBox( QWidget *parent, const char *name )
    : QComboBox( parent, name )
{
    pop = new EnumPopup( this, "popup", QObject::WType_Popup );
    connect( pop, SIGNAL( hidden() ), this, SLOT( popupHidden() ) );
    connect( pop, SIGNAL( closed() ), this, SLOT( popupClosed() ) );
    popupShown = FALSE;
    arrowDown = FALSE;
}

void EnumBox::popupHidden()
{
    popupShown = FALSE;
}

void EnumBox::popupClosed()
{
    popupShown = FALSE;
    emit valueChanged();
}

void EnumBox::paintEvent( QPaintEvent * )
{
    QPainter p( this );
    const QColorGroup & g = colorGroup();
    p.setPen(g.text());

    QStyle::SFlags flags = QStyle::Style_Default;
    if (isEnabled())
	flags |= QStyle::Style_Enabled;
    if (hasFocus())
	flags |= QStyle::Style_HasFocus;

    if ( width() < 5 || height() < 5 ) {
	qDrawShadePanel( &p, rect().x(), rect().y(), rect().width(), rect().height(), g, FALSE, 2,
		&g.brush( QColorGroup::Button ) );
	return;
    }
    style().drawComplexControl( QStyle::CC_ComboBox, &p, this, rect(), g,
				    flags, QStyle::SC_All,
				    (arrowDown ?
				     QStyle::SC_ComboBoxArrow :
				     QStyle::SC_None ));

    QRect re = style().querySubControlMetrics( QStyle::CC_ComboBox, this,
	    QStyle::SC_ComboBoxEditField );
    re = QStyle::visualRect(re, this);
    p.setClipRect( re );

    if ( !str.isNull() ) {
	p.save();
	p.setFont(font());
	QFontMetrics fm(font());
	int x = re.x(), y = re.y() + fm.ascent();
	p.drawText( x, y, str );
	p.restore();
    }
}

void EnumBox::insertEnums( QValueList<EnumItem> lst )
{
    pop->insertEnums( lst );
}

QValueList<EnumItem> EnumBox::enumList() const
{
    return pop->enumList();
}

void EnumBox::popup()
{
    if ( popupShown ) {
	pop->closeWidget();
	popupShown = FALSE;
	return;
    }
    pop->move( ((QWidget*)parent())->mapToGlobal( geometry().bottomLeft() ) );
    pop->setMinimumWidth( width() );
    emit aboutToShowPopup();
    pop->show();
    popupShown = TRUE;
}

void EnumBox::mousePressEvent( QMouseEvent *e )
{
    if ( e->button() != LeftButton )
	return;

    QRect arrowRect = style().querySubControlMetrics( QStyle::CC_ComboBox, this,
						      QStyle::SC_ComboBoxArrow);
    arrowRect = QStyle::visualRect(arrowRect, this);

    arrowRect.setHeight( QMAX(  height() - (2 * arrowRect.y()), arrowRect.height() ) );

    if ( arrowRect.contains( e->pos() ) ) {
	arrowDown = TRUE;
	repaint( FALSE );
    }

    popup();
    QTimer::singleShot( 100, this, SLOT( restoreArrow() ) );
}

void EnumBox::keyPressEvent( QKeyEvent *e )
{
    if ( e->key() == Key_Space ) {
	popup();
	QTimer::singleShot( 100, this, SLOT( restoreArrow() ) );
    } else if ( e->key() == Key_Enter || e->key() == Key_Return ) {
	popup();
    }
}

void EnumBox::restoreArrow()
{
    arrowDown = FALSE;
    repaint( FALSE );
}

void EnumBox::setText( const QString &text )
{
    str = text;
    repaint( FALSE );
}



PropertyEnumItem::PropertyEnumItem( PropertyList *l,
				    PropertyItem *after,
				    PropertyItem *prop,
				    const QString &propName )
    : PropertyItem( l, after, prop, propName )
{
    box = new EnumBox( listview->viewport() );
    box->hide();
    box->installEventFilter( listview );
    connect( box, SIGNAL( aboutToShowPopup() ), this, SLOT( insertEnums() ) );
    connect( box, SIGNAL( valueChanged() ), this, SLOT( setValue() ) );
}

PropertyEnumItem::~PropertyEnumItem()
{
    delete (EnumBox*)box;
}

void PropertyEnumItem::showEditor()
{
    PropertyItem::showEditor();
    placeEditor( box );
    if ( !box->isVisible() ) {
	box->show();
	box->setText( enumString );
	listView()->viewport()->setFocus();
    }
    box->setFocus();
}

void PropertyEnumItem::hideEditor()
{
    PropertyItem::hideEditor();
    box->hide();
}

void PropertyEnumItem::setValue( const QVariant &v )
{
    enumString = "";
    enumList.clear();
    QStringList lst = v.toStringList();
    QValueListConstIterator<QString> it = lst.begin();
    for ( ; it != lst.end(); ++it )
	enumList.append( EnumItem( *it, FALSE ) );
    enumList.first().selected = TRUE;
    enumString = enumList.first().key;
    box->setText( enumString );
    setText( 1, enumString );
    PropertyItem::setValue( v );
}

void PropertyEnumItem::insertEnums()
{
    box->insertEnums( enumList );
}

void PropertyEnumItem::setValue()
{
    enumList = box->enumList();
    enumString = "";
    QValueListConstIterator<EnumItem> it = enumList.begin();
    for ( ; it != enumList.end(); ++it ) {
	if ( (*it).selected )
	    enumString += "|" + (*it).key;
    }
    if ( !enumString.isEmpty() )
	enumString.replace( 0, 1, "" );

    box->setText( enumString );
    setText( 1, enumString );
    notifyValueChange();
}

void PropertyEnumItem::setCurrentValues( QStrList lst )
{
    enumString ="";
    QStrList::ConstIterator it = lst.begin();
    QValueList<EnumItem>::Iterator eit = enumList.begin();
    for ( ; eit != enumList.end(); ++eit ) {
	(*eit).selected = FALSE;
	for ( it = lst.begin(); it != lst.end(); ++it ) {
	    if ( QString( *it ) == (*eit).key ) {
		(*eit).selected = TRUE;
		enumString += "|" + (*eit).key;
		break;
	    }
	}
    }
    if ( !enumString.isEmpty() )
	enumString.replace( 0, 1, "" );
    box->setText( enumString );
    setText( 1, enumString );
}

QString PropertyEnumItem::currentItem() const
{
    return enumString;
}

QString PropertyEnumItem::currentItemFromObject() const
{
    return enumString;
}

// --------------------------------------------------------------

/*!
  \class PropertyList propertyeditor.h
  \brief PropertyList is a QListView derived class which is used for editing widget properties

  This class is used for widget properties. It has to be child of a
  PropertyEditor.

  To initialize it for editing a widget call setupProperties() which
  iterates through the properties of the current widget (see
  PropertyEditor::widget()) and builds the list.

  To update the item values, refetchData() can be called.

  If the value of an item has been changed by the user, and this
  change should be applied to the widget's property, valueChanged()
  has to be called.

  To set the value of an item, setPropertyValue() has to be called.
*/

PropertyList::PropertyList( QWidget *e )
    : QListView( e )
{
    init_colors();

    whatsThis = new PropertyWhatsThis( this );
    showSorted = FALSE;
    header()->setMovingEnabled( FALSE );
    header()->setStretchEnabled( TRUE );
    setResizePolicy( QScrollView::Manual );
    viewport()->setAcceptDrops( TRUE );
    viewport()->installEventFilter( this );
    addColumn( tr( "Property" ) );
    addColumn( tr( "Value" ) );
    connect( header(), SIGNAL( sizeChange( int, int, int ) ),
	     this, SLOT( updateEditorSize() ) );
    disconnect( header(), SIGNAL( sectionClicked( int ) ),
		this, SLOT( changeSortColumn( int ) ) );
    connect( header(), SIGNAL( sectionClicked( int ) ),
	     this, SLOT( toggleSort() ) );
    connect( this, SIGNAL( pressed( QListViewItem *, const QPoint &, int ) ),
	     this, SLOT( itemPressed( QListViewItem *, const QPoint &, int ) ) );
    connect( this, SIGNAL( doubleClicked( QListViewItem * ) ),
	     this, SLOT( toggleOpen( QListViewItem * ) ) );
    setSorting( -1 );
    setHScrollBarMode( AlwaysOff );
    setVScrollBarMode( AlwaysOn );
    setColumnWidthMode( 1, Manual );
    mousePressed = FALSE;
    pressItem = 0;
    theLastEvent = MouseEvent;
    header()->installEventFilter( this );
}
