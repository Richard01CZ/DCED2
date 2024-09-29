#include "propertylist.h"

#include "img/resetproperty.xpm"

#include <qapplication.h>
#include <qcolordialog.h>
#include <qcombobox.h>
#include <qhbox.h>
#include <qheader.h>
#include <qlayout.h>
#include <qlineedit.h>
#include <qmessagebox.h>
#include <qpushbutton.h>
#include <qstyle.h>
#include <qtooltip.h>
#include <qvalidator.h>
#include <qwhatsthis.h>

static QColor * backColor1 = new QColor(  250, 248, 235 );
static QColor * backColor2 = new QColor( 255, 255, 255 );
static QColor * selectedBack = new QColor( 230, 230, 230 );

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

PropertyItem::PropertyItem( PropertyList *l, PropertyItem *after, PropertyItem *prop, const QString &propName, QString wT )
    : QListViewItem( l, after ), listview( l ), property( prop ), propertyName( propName ), whatsThis( wT )
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
    }
	else
		backColor = *backColor1;

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
	indent = 2 + ( property ? 20 : 0 );
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

void PropertyItem::setValue( const QVariant &v, bool setOrig )
{
    val = v;
	if( setOrig )
	{
		originalValue = v;
		setChanged( FALSE );
	}
	else
	{
		setChanged( TRUE );
	}
}

QVariant PropertyItem::value() const
{
    return val;
}

bool PropertyItem::isChanged() const
{
    return changed;
}

void PropertyItem::setChanged( bool b )
{
	if( b == false && hasSubItems() )
	{
		for( int i = 0; i < childCount(); i ++ )
			if( child( i )->isChanged() )
			{
				b = true;
				return;
			};
	}

	if( b == false )
		originalValue = val;

    changed = b;
    repaint();
    updateResetButtonState();
    if ( propertyParent() )
		propertyParent()->setChanged( b );
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
    resetButton->setPixmap( QPixmap( resetproperty_xpm ) );
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
    if ( !propertyParent() )
	{
		setChanged( TRUE );
		if ( hasSubItems() )
			initChildren();
		listview->valueChanged( this );
	} else {
		propertyParent()->childValueChanged( this );
		setChanged( TRUE );
		listview->valueChanged( this );
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
	w->setFocus();
}

void PropertyItem::setText( int col, const QString &t )
{
    QString txt( t );
    if ( col == 1 )
	txt = txt.replace( "\n", " " );
    QListViewItem::setText( col, txt );
}

void PropertyItem::resetProperty()
{
	val = originalValue;
	listview->valueReset( this );
	if( childCount() > 0 )
		for( int i = 0; i < childCount(); i++ )
			child( i )->resetProperty();
}

void PropertyItem::setWhatsThisText( const QString &s ) { whatsThis = QString( s ); }
const QString PropertyItem::whatsThisText() { return whatsThis; }

// --------------------------------------------------------------

PropertyTextItem::PropertyTextItem( PropertyList *l, PropertyItem *after, PropertyItem *prop, const QString &propName,
								   QString &val, QString wT )
    : PropertyItem( l, after, prop, propName, wT )
{
    lin = 0;
	originalValue = val;
	lined()->blockSignals( TRUE );
	if( val != QString::null )
	{
		lined()->setText( val );
		setText( 1, val );
	}
	lined()->blockSignals( FALSE );
}

QLineEdit *PropertyTextItem::lined()
{
    if ( lin )
		return lin;

	// else
	lin = new QLineEdit( listview->viewport() );

	//lin->setValidator( new AsciiValidator( QString(""), lin, "ascii_validator" ) );
	lin->hide();

    connect( lin, SIGNAL( returnPressed() ),
		this, SLOT( setValue() ) );
    connect( lin, SIGNAL( textChanged( const QString & ) ),
		this, SLOT( setValue() ) );

    lin->installEventFilter( listview );
    return lin;
}

PropertyTextItem::~PropertyTextItem()
{
    delete (QLineEdit*)lin;
    lin = 0;
}

void PropertyTextItem::setChanged( bool b )
{
    PropertyItem::setChanged( b );
}

bool PropertyTextItem::hasSubItems() const
{
    return false;
}

void PropertyTextItem::childValueChanged( PropertyItem *child )
{
	//Not implemented
}

void PropertyTextItem::showEditor()
{
    PropertyItem::showEditor();
    if ( !lin || lin->text().length() == 0 ) {
	lined()->blockSignals( TRUE );
	lined()->setText( value().toString() );
	lined()->blockSignals( FALSE );
    }

    QWidget* w = lined();

    placeEditor( w );
    if ( !w->isVisible() || !lined()->hasFocus() ) {
		w->show();
		setFocus( w );
    }
}

void PropertyTextItem::createChildren( QString name )
{
    PropertyTextItem *i = new PropertyTextItem( listview, this, this, name );
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
    QWidget* w = lined();
    lined()->hide();
}

void PropertyTextItem::setValue( const QVariant &v, bool setOrig )
{
    if ( ( !hasSubItems() || !isOpen() ) && value() == v )
		return;

    if ( lin ) {
		lined()->blockSignals( TRUE );
		int oldCursorPos = lin->cursorPosition();
		lined()->setText( v.toString() );
		if ( oldCursorPos < (int)lin->text().length() )
			lin->setCursorPosition( oldCursorPos );
		lined()->blockSignals( FALSE );
    }

    setText( 1, v.toString() );
    PropertyItem::setValue( v, setOrig );
}

void PropertyTextItem::setValue()
{
    setText( 1, lined()->text() );
    QVariant v = lined()->text();
    PropertyItem::setValue( v );
    notifyValueChange();
	emit valueChanged( v );
}

const QString PropertyTextItem::getText()
{
	return lined()->text();
}

void PropertyTextItem::resetProperty()
{
	lined()->blockSignals( TRUE );
	lined()->setText( originalValue.toString() );
	setText( 1, originalValue.toString() );
	lined()->blockSignals( FALSE );
	setChanged( FALSE );
	PropertyItem::resetProperty();
	emit valueReset( originalValue );
}

void PropertyTextItem::setMaxLength( int l )
{
	lined()->setMaxLength( l );
}

// --------------------------------------------------------------

PropertyDoubleItem::PropertyDoubleItem( PropertyList *l, PropertyItem *after, PropertyItem *prop,
				    const QString &propName, double val, QString wT )
    : PropertyItem( l, after, prop, propName, wT )
{
    lin = 0;
	originalValue = val;
	lined()->blockSignals( TRUE );
	lined()->setText( QString::number( val ) );
	setText( 1, QString::number( val ) );
	lined()->blockSignals( FALSE );
	hideEditor();
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

void PropertyDoubleItem::setValue( const QVariant &v, bool setOrig )
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
    PropertyItem::setValue( v, setOrig );
}

void PropertyDoubleItem::setValue()
{
    setText( 1, lined()->text() );
    QVariant v = lined()->text().toDouble();
    PropertyItem::setValue( v );
    notifyValueChange();
}

void PropertyDoubleItem::resetProperty()
{
	lined()->blockSignals( TRUE );
	lined()->setText( originalValue.toString() );
	setText( 1, originalValue.toString() );
	lined()->blockSignals( FALSE );
	setChanged( FALSE );
	PropertyItem::resetProperty();
}

// --------------------------------------------------------------

PropertyIntItem::PropertyIntItem( PropertyList *l, PropertyItem *after, PropertyItem *prop,
				    const QString &propName, int val, QString wT )
    : PropertyItem( l, after, prop, propName, wT )
{
    lin = 0;
	originalValue = val;
	lined()->blockSignals( TRUE );
	lined()->setText( QString::number( val ) );
	setText( 1, QString::number( val ) );
	lined()->blockSignals( FALSE );
	hideEditor();
}

QLineEdit *PropertyIntItem::lined()
{
    if ( lin )
	return lin;
    lin = new QLineEdit( listview->viewport() );
    lin->setValidator( new QIntValidator( lin, "Int_validator" ) );

    connect( lin, SIGNAL( returnPressed() ),
	     this, SLOT( setValue() ) );
    connect( lin, SIGNAL( textChanged( const QString & ) ),
	     this, SLOT( setValue() ) );
    lin->installEventFilter( listview );
    return lin;
}

PropertyIntItem::~PropertyIntItem()
{
    delete (QLineEdit*)lin;
    lin = 0;
}

void PropertyIntItem::showEditor()
{
    PropertyItem::showEditor();
    if ( !lin ) {
		lined()->blockSignals( TRUE );
		lined()->setText( QString::number( value().toInt() ) );
		lined()->blockSignals( FALSE );
    }
    QWidget* w = lined();

    placeEditor( w );
    if ( !w->isVisible() || !lined()->hasFocus() ) {
		w->show();
	setFocus( lined() );
    }
}


void PropertyIntItem::hideEditor()
{
    PropertyItem::hideEditor();
    QWidget* w = lined();
    w->hide();
}

void PropertyIntItem::setValue( const QVariant &v, bool setOrig )
{
    if ( value() == v )
	return;
    if ( lin ) {
	lined()->blockSignals( TRUE );
	int oldCursorPos;
	oldCursorPos = lin->cursorPosition();
	lined()->setText( QString::number( v.toInt() ) );
	if ( oldCursorPos < (int)lin->text().length() )
	    lin->setCursorPosition( oldCursorPos );
	lined()->blockSignals( FALSE );
    }
    setText( 1, QString::number( v.toInt() ) );
    PropertyItem::setValue( v, setOrig );
}

void PropertyIntItem::setValue()
{
    setText( 1, lined()->text() );
    QVariant v = lined()->text().toInt();
    PropertyItem::setValue( v );
    notifyValueChange();
}

void PropertyIntItem::resetProperty()
{
	lined()->blockSignals( TRUE );
	lined()->setText( originalValue.toString() );
	setText( 1, originalValue.toString() );
	lined()->blockSignals( FALSE );
	setChanged( FALSE );
	PropertyItem::resetProperty();
}

// --------------------------------------------------------------

PropertyBoolItem::PropertyBoolItem( PropertyList *l, PropertyItem *after, PropertyItem *prop, const QString &propName, bool checked, QString wT )
    : PropertyItem( l, after, prop, propName, wT )
{
    comb = 0;
	setValue( checked, TRUE );
}

QComboBox *PropertyBoolItem::combo()
{
    if ( comb )
	return comb;
    comb = new QComboBox( FALSE, listview->viewport() );
    comb->hide();
    comb->insertItem( tr( "False" ) );
    comb->insertItem( tr( "True" ) );
    connect( comb, SIGNAL( activated( int ) ), this, SLOT( setValue() ) );
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

void PropertyBoolItem::setValue( const QVariant &v, bool setOrig )
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
    PropertyItem::setValue( v, setOrig );
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

void PropertyBoolItem::resetProperty()
{
	combo()->blockSignals( TRUE );
	if ( originalValue.toBool() )
		combo()->setCurrentItem( 1 );
	else
		combo()->setCurrentItem( 0 );
	combo()->blockSignals( FALSE );
	setChanged( FALSE );
	PropertyItem::resetProperty();
}

// --------------------------------------------------------------

PropertyColorItem::PropertyColorItem( PropertyList *l, PropertyItem *after, PropertyItem *prop,
				      const QString &propName, bool children, QColor color, QString wT )
    : PropertyItem( l, after, prop, propName, wT ), withChildren( children )
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
	setValue( color );
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

void PropertyColorItem::setValue( const QVariant &v, bool setOrig )
{
    if ( ( !hasSubItems() || !isOpen() )
	 && value() == v )
	return;

    QString s;
    setText( 1, v.toColor().name() );
    colorPrev->setBackgroundColor( v.toColor() );
    PropertyItem::setValue( v, setOrig );
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

void PropertyColorItem::resetProperty()
{
	setChanged( FALSE );
	PropertyItem::resetProperty();
}

/****************************************************************************
**                             PropertyWhatsThis                           **
****************************************************************************/

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
    return propertyList->whatsThisAt( pos );
}

bool PropertyWhatsThis::clicked( const QString& href )
{
    return FALSE; // do not hide window
}

/****************************************************************************
**                               PropertyList                              **
****************************************************************************/

PropertyList::PropertyList( QWidget * parent )
			: QListView( parent, "PropertyList" )
{
	whatsThis = new PropertyWhatsThis( this );

	setResizeMode( QListView::AllColumns );
	//init_colors();
    header()->setMovingEnabled( FALSE );
    header()->setStretchEnabled( TRUE );
    setResizePolicy( QScrollView::Manual );
    viewport()->setAcceptDrops( TRUE );
    viewport()->installEventFilter( this );
	addColumn( tr( "Name" ) );
	addColumn( tr( "Value" ) );
	connect( header(), SIGNAL( sizeChange( int, int, int ) ),
		this, SLOT( updateEditorSize() ) );
    setHScrollBarMode( AlwaysOff );
    setVScrollBarMode( Auto );
    setColumnWidthMode( 0, Manual );
    setColumnWidthMode( 1, Manual );
    header()->installEventFilter( this );
	languageChange();
}

void PropertyList::languageChange()
{
	header()->setLabel( 0, tr( "Name" ) );
	header()->setLabel( 1, tr( "Value" ) );
}

void PropertyList::resetProperty()
{
	if ( !currentItem() )
		return;

	PropertyItem *i = (PropertyItem*)currentItem();
	i->resetProperty();
	valueReset( i );
}

void PropertyList::updateEditorSize()
{
    if ( currentItem() )
		( ( PropertyItem* )currentItem() )->showEditor();
	this->repaintContents( FALSE );
}

void PropertyList::setCurrentItem( QListViewItem *item )
{
    if( !item )
		return;
	
	if( currentItem() )
		( (PropertyItem*)currentItem() )->hideEditor();

	QListView::setCurrentItem( item );
    ( (PropertyItem*)currentItem() )->showEditor();
}

void PropertyList::valueChanged( PropertyItem *item )
{
	emit valueChanged( item->value() );
}

void PropertyList::valueReset( PropertyItem *item )
{
	emit valueReset( item->value() );
}

bool PropertyList::isChanged()
{
	return false;
}

/*
 *	What's this
 */

QString PropertyList::whatsThisAt( const QPoint &p )
{
    return whatsThisText( itemAt( p ) );
}

void PropertyList::showCurrentWhatsThis()
{
    if ( !currentItem() )
		return;
    QPoint p( 0, currentItem()->itemPos() );
    p = viewport()->mapToGlobal( contentsToViewport( p ) );
    QWhatsThis::display( whatsThisText( currentItem() ), p, viewport() );
}

QString PropertyList::whatsThisText( QListViewItem *i )
{
    if( !i )
		return QString::null;

	PropertyItem * p = (PropertyItem *)(i);
	if( p->whatsThisText() == QString::null )
		return tr( "<p><b>%1:</b></p><p>There is no documentation available for this property.</p>" ).arg( p->name() );
	return QString( "<p><b>%1:</b></p><P>%2</p>" ).arg( p->name() ).arg( p->whatsThisText() );
}

/****************************************************************************
**                              EnemyEditor                                **
****************************************************************************/

EnemyEditor::EnemyEditor( QWidget *parent )
			  : PropertyList( parent )
{
    disconnect( header(), SIGNAL( sectionClicked( int ) ),
		this, SLOT( changeSortColumn( int ) ) );

    setSorting( -1 );

	header()->hide();
	
	strengthItem = 0;
	energyItem = 0;
		energyLeftHandItem = 0;
		energyRightHandItem = 0;
		energyLeftLegItem = 0;
		energyRightLegItem = 0;
	reactionsItem = 0;
	speedItem = 0;
	aggressivityItem = 0;
	intelligenceItem = 0;
	shootingItem = 0;
	sightItem = 0;
	hearingItem = 0;
	drivingItem = 0;
	massItem = 0;
	behaviour1Item = 0;
	behaviour2Item = 0;
	voiceItem = 0;
}

EnemyEditor::~EnemyEditor()
{
	clear();
}

void EnemyEditor::clear()
{
	if( strengthItem )
	{
		delete strengthItem;
		delete energyItem;
			delete energyLeftHandItem;
			delete energyRightHandItem;
			delete energyLeftLegItem;
			delete energyRightLegItem;
		delete reactionsItem;
		delete speedItem;
		delete aggressivityItem;
		delete intelligenceItem;
		delete shootingItem;
		delete sightItem;
		delete hearingItem;
		delete drivingItem;
		delete massItem;
		delete behaviour1Item;
		delete behaviour2Item;

		strengthItem = 0;
		energyItem = 0;
			energyLeftHandItem = 0;
			energyRightHandItem = 0;
			energyLeftLegItem = 0;
			energyRightLegItem = 0;
		reactionsItem = 0;
		speedItem = 0;
		aggressivityItem = 0;
		intelligenceItem = 0;
		shootingItem = 0;
		sightItem = 0;
		hearingItem = 0;
		drivingItem = 0;
		massItem = 0;
		behaviour1Item = 0;
		behaviour2Item = 0;
		voiceItem = 0;
	}
}

bool EnemyEditor::isChanged()
{
	if( strengthItem->isChanged() ||
		energyItem->isChanged() ||
		energyLeftHandItem->isChanged() || 
		energyRightHandItem->isChanged() || 
		energyLeftLegItem->isChanged() || 
		energyRightLegItem->isChanged() || 
		reactionsItem->isChanged() || 
		speedItem->isChanged() || 
		aggressivityItem->isChanged() || 
		intelligenceItem->isChanged() || 
		shootingItem->isChanged() || 
		sightItem->isChanged() || 
		hearingItem->isChanged() || 
		drivingItem->isChanged() || 
		massItem->isChanged() || 
		behaviour1Item->isChanged() ||
		behaviour2Item->isChanged() ||
		voiceItem->isChanged() )
		return true;
	else
		return false;
}

void EnemyEditor::setup()
{
	clear();

	voiceItem = new PropertyIntItem( this, 0, 0, tr( "Voice" ), 0,
		tr( "This is the voice of the enemy you can hear e.g. when you hit him (Ouch, ahh!).<br>"
			"The first values are characters like Paulie, Tommy or Luigi. "
			"Use higher values for the voice of some normal enemies.") );
	strengthItem = new PropertyDoubleItem( this, 0, 0, tr( "Strength" ), 0,
		tr( "The strength sets how much energy a hit by the fist of that person costs."
			"It is not counted in the energy values that are displayed in game but in the real energy values (See <i>What's This -> Energy</i>)." ) );
	speedItem = new PropertyDoubleItem( this, 0, 0, tr( "Speed" ), 0,
		tr( "This value defines how fast the character runs. The normal value is 1, but you can of course increase it." ) );
	sightItem = new PropertyDoubleItem( this, 0, 0, tr( "Sight" ), 0,
		tr( "This value defines how good a character can notice enemies. 1 means 100% (also notices everything behind himself), 0 means 0% (is stupid and doesn't notice anything)." ) );
	shootingItem = new PropertyDoubleItem( this, 0, 0, tr( "Shooting" ), 0,
		tr( "This value should be pretty perspicious. Possible values are between 0 and 1." ) );
	reactionsItem = new PropertyDoubleItem( this, 0, 0, tr( "Reactions" ), 0,
		tr( "This value indicates how fast the character reacts. Set this between 0 and 1 whereat 1 means direct reaction." ) );
	massItem = new PropertyDoubleItem( this, 0, 0, tr( "Mass" ), 0,
		tr( "This is the mass in kilogram/kg. It's used by the physics engine, e.g. for calculating how fast the person falls. Standard value is 80." ) );
	intelligenceItem = new PropertyDoubleItem( this, 0, 0, tr( "Intelligence" ), 0,
		tr( "The intelligence value sets the artificial intelligence (e.g. how good a player can follow you). Possible values are between 0 and 1." ) );
	hearingItem = new PropertyDoubleItem( this, 0, 0, tr( "Hearing" ), 0,
		tr( "This value is similar to the sight:<br>it defines how good a character can notive enemies. Possible values are between 0 and 1." ) );
	energyItem = new PropertyDoubleItem( this, 0, 0, tr( "Energy" ), 0,
		tr( "The Energy sets the health points of the player. In Mafia, you will always see 100, but this value sets the real number of health points. "
			"Or how can you explain to yourself that Tommy needs much more shots than other enemies until he's dead?") );
		energyLeftHandItem = new PropertyDoubleItem( this, energyItem, energyItem, tr( "Left Hand" ), 0,
			tr( "This value has no effect in game." ) );
		energyItem->addChild( energyLeftHandItem );
		energyRightHandItem = new PropertyDoubleItem( this, energyLeftHandItem, energyItem, tr( "Right Hand" ), 0,
			tr( "This value has no effect in game." ) );
		energyItem->addChild( energyRightHandItem );
		energyLeftLegItem = new PropertyDoubleItem( this, energyRightHandItem, energyItem, tr( "Left Leg" ), 0,
			tr( "This value has no effect in game." ) );
		energyItem->addChild( energyLeftLegItem );
		energyRightLegItem = new PropertyDoubleItem( this, energyLeftLegItem, energyItem, tr( "Right Leg" ), 0,
			tr( "This value has no effect in game." ) );
		energyItem->addChild( energyRightLegItem );
	drivingItem = new PropertyDoubleItem( this, 0, 0, tr( "Driving" ), 0,
		tr( "This value should be pretty perspicious. Possible values are between 0 and 1." ) );
	behaviour2Item = new PropertyDoubleItem( this, 0, 0, tr( "Behaviour 2" ), 0,
		tr( "Set value between 0 and 1. Experimentate how you like it. If you want to use a"
			"special behavior of a person of the game, just use their Behavior1 and Behavior2 values." ) );
	behaviour1Item = new PropertyIntItem( this, 0, 0, tr( "Behaviour 1" ), 0,
		tr( "<table width=\"358\" cellpadding=\"0\" cellspacing=\"2\">"
			"<tr><td width=\"31\">0</td><td width=\"311\">Reacts on attacks, shots. Ducks only, moves away if char was hit multiple times.</td></tr>"
			"<tr><td>1</td><td>Reacts on attacks, shots. Ducks only, moves away if char was hit multiple times.</td></tr>"
			"<tr><td>2</td><td>Does not react on anything. Guards the player</td></tr>"
			"<tr><td>4</td><td>Does not react on anything.</td></tr>"
			"<tr><td>8</td><td>Reacts on hits, only moves away.</td></tr>"
			"<tr><td>16</td><td>Reacts on player, moves away.</span></td></tr>"
			"<tr><td>32</td><td>Reacts on attacks to other characters. He either moves away or attacks attacker.</td></tr>"
			"<tr><td>64</td><td>Reacts on attacks to other characters. Attacks attacker.</td></tr>"
			"<tr><td>128</td><td>Used for Little Joe in mission 9.</td></tr>"
			"</table>" ) );
	aggressivityItem = new PropertyDoubleItem( this, 0, 0, tr( "Agressivity" ), 0,
		tr( "This value should be pretty perspicious. Possible values are between 0 and 1." ) );
	
	setCurrentItem( aggressivityItem );
}

/****************************************************************************
**                             MovingBoxEditor                             **
****************************************************************************/

MovingBoxEditor::MovingBoxEditor( QWidget *parent )
			  : PropertyList( parent )
{
    disconnect( header(), SIGNAL( sectionClicked( int ) ),
		this, SLOT( changeSortColumn( int ) ) );

    setSorting( -1 );

	header()->hide();
	
	soundItem = 0;
	value1Item = 0;
	value2Item = 0;
	frictionItem = 0;
	value4Item = 0;
	value5Item = 0;
	weightItem = 0;
}

MovingBoxEditor::~MovingBoxEditor()
{
	clear();
}

void MovingBoxEditor::clear()
{
	if( soundItem )
	{
		delete soundItem;
		delete value1Item;
		delete value2Item;
		delete frictionItem;
		delete value4Item;
		delete value5Item;
		delete weightItem;

		soundItem = 0;
		value1Item = 0;
		value2Item = 0;
		frictionItem = 0;
		value4Item = 0;
		value5Item = 0;
		weightItem = 0;
	}
}

bool MovingBoxEditor::isChanged()
{
	if( soundItem->isChanged() ||
		value1Item->isChanged() ||
		value2Item->isChanged() || 
		frictionItem->isChanged() || 
		value4Item->isChanged() || 
		value5Item->isChanged() ||
		weightItem->isChanged() )
		return true;
	else
		return false;
}

void MovingBoxEditor::setup()
{
	clear();

	weightItem = new PropertyDoubleItem( this, 0, 0, tr( "Weight" ), 0,
		tr( "This is the mass of the object in kilogram/kg" ) );
	value5Item = new PropertyIntItem( this, 0, 0, tr( "Value 5" ), 0 );
	value4Item = new PropertyDoubleItem( this, 0, 0, tr( "Value 4" ), 0 );
	value2Item = new PropertyDoubleItem( this, 0, 0, tr( "Value 2" ), 0,
		tr( "This property isn't documentated yet. Default value is 1." ) );
	value1Item = new PropertyDoubleItem( this, 0, 0, tr( "Value 1" ), 0,
		tr( "This property isn't documentated yet. Default value is 1." ) );
	soundItem = new PropertyIntItem( this, 0, 0, tr( "Sound" ), 0,
		tr( "This is the sound of the object it makes when it e.g. draggles.<br>"
			"Possible values are:<br>"
			"<table cellpadding=\"0\" cellspacing=\"2\" width=\"80\">"
			"<tr><td width=\"10\">0</td><td width=\"70\">Crate</td></tr>"
			"<tr><td>1</td><td>Crate1</td></tr>"
			"<tr><td>2</td><td>Barrel</td></tr>"
			"<tr><td>3</td><td>Barrel1</td></tr>"
			"<tr><td>4</td><td>Label</td></tr>"
			"<tr><td>5</td><td>Box</td></tr>"
			"<tr><td>6</td><td>Wood</td></tr>"
			"<tr><td>7</td><td>Plate</td></tr>"
			"<tr><td>8</td><td>No sound</td></tr>"
			"</table" ) );
	frictionItem = new PropertyDoubleItem( this, 0, 0, tr( "Friction" ), 0,
		tr( "This property is the friction of the surface." ) );
	
	setCurrentItem( frictionItem );
}

/****************************************************************************
**                              TrafficEditor                              **
****************************************************************************/

TrafficEditor::TrafficEditor( QWidget *parent )
			  : PropertyList( parent )
{
    disconnect( header(), SIGNAL( sectionClicked( int ) ),
		this, SLOT( changeSortColumn( int ) ) );

    setSorting( -1 );

	header()->hide();
	
	trafficVal1Item = 0;
	trafficVal2Item = 0;
	trafficVal3Item = 0;
	densityItem = 0;
	curNameItem = 0;
	curDensityItem = 0;
	curColorItem = 0;
	curPoliceItem = 0;
	curFlag2Item = 0;
	curGangsterItem = 0;
	curFlag4Item = 0;
}

TrafficEditor::~TrafficEditor()
{
	clear();
}

void TrafficEditor::clear()
{
	if( trafficVal1Item )
	{
		delete trafficVal1Item;
		delete trafficVal2Item;
		delete trafficVal3Item;
		delete densityItem;
		delete curNameItem;
		delete curDensityItem;
		delete curColorItem;
		delete curPoliceItem;
		delete curFlag2Item;
		delete curGangsterItem;
		delete curFlag4Item;

		trafficVal1Item = 0;
		trafficVal2Item = 0;
		trafficVal3Item = 0;
		densityItem = 0;
		curNameItem = 0;
		curDensityItem = 0;
		curColorItem = 0;
		curPoliceItem = 0;
		curFlag2Item = 0;
		curGangsterItem = 0;
		curFlag4Item = 0;
	}
}

bool TrafficEditor::isChanged()
{
	if( trafficVal1Item->isChanged() ||
		trafficVal2Item->isChanged() ||
		trafficVal3Item->isChanged() ||
		densityItem->isChanged() ||
		curNameItem->isChanged() ||
		curDensityItem->isChanged() ||
		curColorItem->isChanged() ||
		curPoliceItem->isChanged() ||
		curFlag2Item->isChanged() ||
		curGangsterItem->isChanged() ||
		curFlag4Item->isChanged() )
		return true;
	else
		return false;
}

void TrafficEditor::setup()
{
	clear();

	trafficVal3Item = new PropertyDoubleItem(this, 0, 0, tr( "Traffic 3" ), 0,
		tr( "This property isn't documentated yet. Default values are between 150 and 200, or just use those of Mafia." ) );
	trafficVal2Item = new PropertyDoubleItem( this, 0, 0, tr( "Traffic 2" ), 0,
		tr( "This property isn't documentated yet. Default values are between 150 and 200, or just use those of Mafia." ) );
	trafficVal1Item = new PropertyDoubleItem( this, 0, 0, tr( "Traffic 1" ), 0,
		tr( "This property isn't documentated yet. Default values are between 150 and 200, or just use those of Mafia." ) );
	densityItem = new PropertyIntItem(this, 0, 0, tr( "Density" ), 0,
		tr( "The density defines how much cars will be created. A higher density will mean more traffic, "
			"but also cost performance." ) );
	curNameItem = new PropertyTextItem(this, 0, 0, tr( "Car" ), QString::null,
		tr( "This is the name of the car you selected in the list on the left.<br>"
			"The name doesn't contain the color code. Example: merced500K" ) );
		curDensityItem = new PropertyDoubleItem(this, curNameItem, curNameItem, tr( "Density" ), 0,
			tr( "The density of the selected car defines how often a car will appear in the traffic. "
				"The value is relative to the values of the other cars." ) );
		curColorItem = new PropertyIntItem(this, curDensityItem, curNameItem, tr( "Color" ), 0,
			tr( "This is the color of the selected car. Note that this isn't a RGB or hexadecimal value "
				"but a simple number like 0 or 1 which defines the skin to choose. If you're uncertain "
				"wether the car has several skins or not, type 0." ) );
		curPoliceItem = new PropertyBoolItem(this, curColorItem, curNameItem, tr( "Police" ), 0,
			tr( "This boolean defines wether this car is a police car or not. "
				"Police cars are those that appear blue on the radar in Mafia.") );
		curFlag2Item = new PropertyBoolItem(this, curPoliceItem, curNameItem, tr( "Co-driver" ), 0,
			tr( "This boolean takes only effect in police or gangster cars. If enabled, there is a "
				"co-driver in the car so that you have two guys in the car." ) );
		curGangsterItem = new PropertyBoolItem(this, curFlag2Item, curNameItem, tr( "Gangster" ), 0,
			tr( "This boolean defines wether this car is a gangster car or not. "
				"Gangster cars are those that appear orange on the radar in Mafia." ) );
		curFlag4Item = new PropertyBoolItem(this, curGangsterItem, curNameItem, tr( "Flag4" ), 0 );

	curNameItem->setMaxLength( 19 );
}

/****************************************************************************
**                            PedestrianEditor                             **
****************************************************************************/

PedestrianEditor::PedestrianEditor( QWidget * parent )
				: PropertyList( parent )
{
    disconnect( header(), SIGNAL( sectionClicked( int ) ),
		this, SLOT( changeSortColumn( int ) ) );

    setSorting( -1 );

	header()->hide();
	
	val1Item = 0;
	val2Item = 0;
	val3Item = 0;
	val4Item = 0;
	val5Item = 0;
	densityItem = 0;
	curNameItem = 0;
	curDensityItem = 0;
}

PedestrianEditor::~PedestrianEditor()
{
	clear();
}

void PedestrianEditor::clear()
{
	if( val1Item )
	{
		delete val1Item;
		delete val2Item;
		delete val3Item;
		delete val4Item;
		delete val5Item;
		delete densityItem;
		delete curNameItem;
		delete curDensityItem;
	
		val1Item = 0;
		val2Item = 0;
		val3Item = 0;
		val4Item = 0;
		val5Item = 0;
		densityItem = 0;
		curNameItem = 0;
		curDensityItem = 0;
	}
}

bool PedestrianEditor::isChanged()
{
	if( val1Item->isChanged() ||
		val2Item->isChanged() ||
		val3Item->isChanged() ||
		val4Item->isChanged() ||
		val5Item->isChanged() ||
		densityItem->isChanged() ||
		curNameItem->isChanged() ||
		curDensityItem->isChanged() )
		return true;
	else
		return false;
}

void PedestrianEditor::setup()
{
	clear();

	val5Item = new PropertyDoubleItem( this, 0, 0, tr( "Value 5" ), 0 );
	val4Item = new PropertyDoubleItem( this, 0, 0, tr( "Value 4" ), 0 );
	val3Item = new PropertyDoubleItem( this, 0, 0, tr( "Value 3" ), 0 );
	val2Item = new PropertyDoubleItem( this, 0, 0, tr( "Value 2" ), 0 );
	val1Item = new PropertyDoubleItem( this, 0, 0, tr( "Value 1" ), 0 );
	densityItem = new PropertyIntItem( this, 0, 0, tr( "Density" ), 0,
		tr( "The density defines how much pedestrians will be created. A higher density will mean more pedestrians, "
			"but also cost performance." ) );
	curNameItem = new PropertyTextItem( this, 0, 0, tr( "Model" ), QString::null,
		tr( "This is the name of the car you selected in the list on the left.<br>"
			"The name doesn't contain the color code. Example: merced500K" ) );
		curDensityItem = new PropertyIntItem( this, curNameItem, curNameItem, tr( "Density" ), 0,
			tr( "The density of the selected pedestrian defines how often this pedestrian will appear in the city."
				"This value is relative to the density values of the other pedestrians." ) );

	curNameItem->setMaxLength( 16 );
}

/****************************************************************************
**                                DoorEditor                               **
****************************************************************************/

DoorEditor::DoorEditor( QWidget * parent )
				: PropertyList( parent )
{
    disconnect( header(), SIGNAL( sectionClicked( int ) ),
		this, SLOT( changeSortColumn( int ) ) );

    setSorting( -1 );

	header()->hide();
	
	openDirection1Item = 0;
	openDirection2Item = 0;
	moveAngleItem = 0;
	isOpenItem = 0;
	isLockedItem = 0;
	closeSpeedItem = 0;
	openSpeedItem = 0;
	openSoundItem = 0;
	closeSoundItem = 0;
	lockedSoundItem = 0;
	flagItem = 0;
}

DoorEditor::~DoorEditor()
{
	clear();
}

void DoorEditor::clear()
{
	if( openDirection1Item )
	{
		delete openDirection1Item;
		delete openDirection2Item;
		delete moveAngleItem;
		delete isOpenItem;
		delete isLockedItem;
		delete closeSpeedItem;
		delete openSpeedItem;
		delete openSoundItem;
		delete closeSoundItem;
		delete lockedSoundItem;
		delete flagItem;
	
		openDirection1Item = 0;
		openDirection2Item = 0;
		moveAngleItem = 0;
		isOpenItem = 0;
		isLockedItem = 0;
		closeSpeedItem = 0;
		openSpeedItem = 0;
		openSoundItem = 0;
		closeSoundItem = 0;
		lockedSoundItem = 0;
		flagItem = 0;
	}
}

bool DoorEditor::isChanged()
{
	if( openDirection1Item->isChanged() ||
		openDirection2Item->isChanged() ||
		moveAngleItem->isChanged() ||
		isOpenItem->isChanged() ||
		isLockedItem->isChanged() ||
		closeSpeedItem->isChanged() ||
		openSpeedItem->isChanged() ||
		openSoundItem->isChanged() ||
		closeSoundItem->isChanged() ||
		lockedSoundItem->isChanged() ||
		flagItem->isChanged() )
		return true;
	else
		return false;
}

void DoorEditor::setup()
{
	clear();

	openDirection1Item = new PropertyBoolItem( this, 0, 0, tr( "Open Direction 1" ), 0,
		tr( "Via the open direction you can make the door only accessable from one side." ) );
	openDirection2Item = new PropertyBoolItem( this, 0, 0, tr( "Open Direction 2" ), 0,
		tr( "Via the open direction you can make the door only accessable from one side." ) );
	moveAngleItem = new PropertyDoubleItem( this, 0, 0, tr( "Move Angle" ), 0,
		tr( "The angle specifies how far a door will open. The standard value is 72.999." ) );

	isOpenItem = new PropertyBoolItem( this, 0, 0, tr( "Opened" ), 0,
		tr( "This boolean defines wether the door is opened when the mission starts." ) );
	isLockedItem = new PropertyBoolItem( this, 0, 0, tr( "Locked" ), 0,
		tr( "This boolean defines wether the door is locked when the mission starts. Note that you have to unlock it with "
			" some scripting commands later in game if you want the player to use this door." ) );

	openSpeedItem = new PropertyDoubleItem( this, 0, 0, tr( "Open Speed" ), 0,
		tr( "The open speed specifies how fast the door opens. A value like 0.0015708 is normal." ) );
	closeSpeedItem = new PropertyDoubleItem( this, 0, 0, tr( "Close Speed" ), 0,
		tr( "The close speed specifies how fast the door closes. A value like 0.0015708 is normal." ) );

	openSoundItem = new PropertyTextItem( this, 0, 0, tr( "Open Sound" ), QString::null,
		tr( "Here you can enter the sound you can hear when opening the door." ) );
	closeSoundItem = new PropertyTextItem( this, 0, 0, tr( "Close Sound" ), QString::null,
		tr( "Here you can enter the sound you can hear when closing the door." ) );
	lockedSoundItem = new PropertyTextItem( this, 0, 0, tr( "Locked Sound" ), QString::null,
		tr( "Here you can enter the sound you can hear when trying to open the door while it's locked." ) );

	flagItem = new PropertyBoolItem( this, 0, 0, tr( "Flag" ), 0 );

	openSoundItem->setMaxLength( 15 );
	closeSoundItem->setMaxLength( 15 );
	lockedSoundItem->setMaxLength( 15 );
}
