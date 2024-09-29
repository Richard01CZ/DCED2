#include "propertynamelist.h"

#include <qfontmetrics.h>
#include <qheader.h>
#include <qlayout.h>
#include <qpainter.h>
#include <qpushbutton.h>
#include <qtooltip.h>
#include <qvariant.h>
#include <qwhatsthis.h>

/*
 *	TrafficItem is a QListBoxItem class that can save all traffic properties in it.
 */

TrafficItem::TrafficItem( QListView * listview, const QString text )
			: QListViewItem( listview, text )
{
	color = 0;
	density = 0;
	flag2 = false;
	flag4 = false;
	gangster = false;
	police = false;

	nameChanged = false;
	colorChanged = false;
	densityChanged = false;
	flag2Changed = false;
	flag4Changed = false;
	gangsterChanged = false;
	policeChanged = false;
}

//---------------------------------------------------------------//

PedestrianItem::PedestrianItem( QListView * listview, const QString text )
			  : QListViewItem( listview, text )
{
	density = 0;
	nameChanged = false;
	densityChanged = false;
}

/*********************************************************************************
 *	PropertyNameList is a class that supports a listview with two buttons below, *
 *  "add item" and "delete item".                                                *
 *********************************************************************************/

PropertyNameList::PropertyNameList( QWidget* parent, const char * name /* = "PropertyNameList" */ )
				: QWidget( parent, name )
{
    layout = new QGridLayout( this, 1, 1, 0, 6, "layout"); 

    deleteItemButton = new QPushButton( this, "deleteItemButton" );
    deleteItemButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, deleteItemButton->sizePolicy().hasHeightForWidth() ) );

    layout->addWidget( deleteItemButton, 1, 0 );

    newItemButton = new QPushButton( this, "newItemButton" );
    newItemButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, newItemButton->sizePolicy().hasHeightForWidth() ) );

    layout->addWidget( newItemButton, 1, 1 );

    itemListView = new QListView( this, "itemListView" );
    itemListView->setSizePolicy( QSizePolicy( QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding, 0, 0, itemListView->sizePolicy().hasHeightForWidth() ) );
	itemListView->addColumn( tr( "Car Name" ) );
	itemListView->setResizeMode( QListView::AllColumns );
	itemListView->setAllColumnsShowFocus( true );
	itemListView->setSorting( 0 );

    layout->addMultiCellWidget( itemListView, 0, 0, 0, 1 );

	//connecting
	connect( newItemButton, SIGNAL( clicked() ), this, SLOT( addItem() ) );
	connect( deleteItemButton, SIGNAL( clicked() ), this, SLOT( deleteItem() ) );

    languageChange();
    resize( QSize(342, 346).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

PropertyNameList::~PropertyNameList()
{
	// no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void PropertyNameList::languageChange()
{
    deleteItemButton->setText( tr( "&Delete Item" ) );
    deleteItemButton->setAccel( QKeySequence( tr( "Alt+D" ) ) );
    newItemButton->setText( tr( "&New Item" ) );
    newItemButton->setAccel( QKeySequence( tr( "Alt+N" ) ) );
}

/*
 *	Insert functions
 */

QListViewItem * PropertyNameList::insertItem( QString name ) const
{
	QListViewItem * item = new QListViewItem( itemListView, name );
	itemListView->insertItem( item );
	return item;
}


void PropertyNameList::insertItem( QListViewItem * item )
{
	itemListView->insertItem( item );
}

/*
 *	Add, delete and rename item functions
 */

void PropertyNameList::addItem()
{
	itemListView->insertItem( new QListViewItem( itemListView, tr( "New Item" ) ) );
}

void PropertyNameList::deleteItem()
{
	itemListView->removeItem( itemListView->currentItem() );
	itemListView->setCurrentItem( itemListView->firstChild() );
}

void PropertyNameList::renameItem( const QVariant& v )
{
	itemListView->blockSignals( TRUE );
	itemListView->currentItem()->setText( 0, v.toString() );
	itemListView->blockSignals( FALSE );
}

/*****************************************************************
 *  Constructs a TrafficNameList as a child of 'parent', with the *
 *  name 'name' and widget flags set to 'f'.                     *
 *****************************************************************/
TrafficNameList::TrafficNameList( QWidget* parent )
    : PropertyNameList( parent, "TrafficNameList" )
{
	// Everything done in PropertyNameList::PropertyNameList(...)
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void TrafficNameList::languageChange()
{
    deleteItemButton->setText( tr( "&Delete Car" ) );
    deleteItemButton->setAccel( QKeySequence( tr( "Alt+D" ) ) );
	QWhatsThis::add( deleteItemButton, tr( "Click this button to delete the selected car" ) );
    newItemButton->setText( tr( "&New Car" ) );
    newItemButton->setAccel( QKeySequence( tr( "Alt+N" ) ) );
	QWhatsThis::add( newItemButton, tr( "Click this button to add a new car" ) );
	QWhatsThis::add( this,
		tr( "Here you can see all cars that appear in the traffic in game. You can add a new one "
			"by pressing <i>New Car</i>, and remove the selected by pressing <i>Delete Car</i>. "
			"To rename the selected car, take a look at the list on the right side." ) );
}

/*
 *	Insert functions
 */

QListViewItem * TrafficNameList::insertItem( QString name ) const
{
	TrafficItem * item = new TrafficItem( itemListView, name );
	itemListView->insertItem( item );
	return item;
}

/*
 *	Add, delete and rename item functions
 */

void TrafficNameList::addItem()
{
	itemListView->insertItem( new TrafficItem( itemListView, tr( "New Car" ) ) );
}

/************************************************************************/
/*                        PedestrianModelList                           */
/************************************************************************/

PedestrianModelList::PedestrianModelList( QWidget* parent )
					: PropertyNameList( parent, "PedestrianModelList" )
{
	itemListView->header()->setLabel( 0, "Pedestrian Name" );
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void PedestrianModelList::languageChange()
{
    deleteItemButton->setText( tr( "&Delete Model" ) );
    deleteItemButton->setAccel( QKeySequence( tr( "Alt+D" ) ) );
	QWhatsThis::add( deleteItemButton, tr( "Click this button to delete the selected pedestrian" ) );
    newItemButton->setText( tr( "&New Model" ) );
    newItemButton->setAccel( QKeySequence( tr( "Alt+N" ) ) );
	QWhatsThis::add( newItemButton, tr( "Click this button to add a new pedestrian" ) );
	QWhatsThis::add( this,
		tr( "Here you can see a list of models of the pedestrians that appear in game. You can add a new one "
			"by pressing <i>New Model</i>, and remove the selected by pressing <i>Delete Model</i>. "
			"To change selected model, take a look at the list on the right side." ) );
}

/*
 *	Insert functions
 */

QListViewItem * PedestrianModelList::insertItem( QString name ) const
{
	PedestrianItem * item = new PedestrianItem( itemListView, name );
	itemListView->insertItem( item );
	return item;
}

/*
 *	Add, delete and rename item functions
 */

void PedestrianModelList::addItem()
{
	itemListView->insertItem( new PedestrianItem( itemListView, tr( "New Model" ) ) );
}