/****************************************************************************
** Form implementation generated from reading ui file 'filterlistdialog.ui'
**
** Created: Fr 6. Feb 19:22:24 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.2.1   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "filterlistdialog.h"
#include "globaldefs.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtextedit.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
#include <qlineedit.h>
#include <qlistview.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>
#include <qheader.h>

/*
 *  Constructs a FilterListDialog as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
FilterListDialog::FilterListDialog( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "FilterListDialog" );
    setIcon( QPixmap::fromMimeSource( "filter.png" ) );
    FilterListDialogLayout = new QGridLayout( this, 1, 1, 11, 6, "FilterListDialogLayout"); 

    helpBox = new QTextEdit( this, "helpBox" );
    helpBox->setWordWrap( QTextEdit::WidgetWidth );

    FilterListDialogLayout->addWidget( helpBox, 1, 1 );

    buttonGroupName = new QButtonGroup( this, "buttonGroupName" );
    buttonGroupName->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)4, 0, 0, buttonGroupName->sizePolicy().hasHeightForWidth() ) );

    radioNameEndsWith = new QRadioButton( buttonGroupName, "radioNameEndsWith" );
    radioNameEndsWith->setGeometry( QRect( 154, 60, 67, 21 ) );

    radioNameStartsWith = new QRadioButton( buttonGroupName, "radioNameStartsWith" );
    radioNameStartsWith->setGeometry( QRect( 8, 60, 70, 21 ) );

    radioNameContains = new QRadioButton( buttonGroupName, "radioNameContains" );
    radioNameContains->setGeometry( QRect( 84, 60, 63, 21 ) );
    radioNameContains->setChecked( TRUE );

    lineEditName = new QLineEdit( buttonGroupName, "lineEditName" );
    lineEditName->setGeometry( QRect( 10, 30, 210, 21 ) );
    lineEditName->setFrameShape( QLineEdit::LineEditPanel );
    lineEditName->setFrameShadow( QLineEdit::Sunken );

    FilterListDialogLayout->addWidget( buttonGroupName, 0, 1 );

    bottomLayout = new QHBoxLayout( 0, 0, 6, "bottomLayout"); 
    QSpacerItem* spacer = new QSpacerItem( 10, 31, QSizePolicy::Expanding, QSizePolicy::Minimum );
    bottomLayout->addItem( spacer );

    buttonOK = new QPushButton( this, "buttonOK" );
    bottomLayout->addWidget( buttonOK );

    buttonCancel = new QPushButton( this, "buttonCancel" );
    bottomLayout->addWidget( buttonCancel );

    FilterListDialogLayout->addLayout( bottomLayout, 2, 1 );

    buttonGroupType = new QButtonGroup( this, "buttonGroupType" );
    buttonGroupType->setMinimumSize( QSize( 251, 0 ) );
    buttonGroupType->setColumnLayout(0, Qt::Vertical );
    buttonGroupType->layout()->setSpacing( 6 );
    buttonGroupType->layout()->setMargin( 11 );
    buttonGroupTypeLayout = new QGridLayout( buttonGroupType->layout() );
    buttonGroupTypeLayout->setAlignment( Qt::AlignTop );
    QSpacerItem* spacer_2 = new QSpacerItem( 10, 31, QSizePolicy::Expanding, QSizePolicy::Minimum );
    buttonGroupTypeLayout->addItem( spacer_2, 1, 2 );

    buttonTypeSelectAll = new QPushButton( buttonGroupType, "buttonTypeSelectAll" );

    buttonGroupTypeLayout->addWidget( buttonTypeSelectAll, 1, 0 );

    buttonTypeClear = new QPushButton( buttonGroupType, "buttonTypeClear" );

    buttonGroupTypeLayout->addWidget( buttonTypeClear, 1, 1 );

    listViewType = new QListView( buttonGroupType, "listViewType" );
	listViewType->addColumn( "Type" );
	listViewType->setResizeMode( QListView::AllColumns );
    listViewType->setSelectionMode( QListView::Multi );
	listViewType->header()->hide();

    buttonGroupTypeLayout->addMultiCellWidget( listViewType, 0, 0, 0, 2 );

    FilterListDialogLayout->addMultiCellWidget( buttonGroupType, 0, 2, 0, 0 );
    languageChange();
    resize( QSize(508, 249).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( buttonCancel, SIGNAL( clicked() ), this, SLOT( reject() ) );
    connect( buttonOK, SIGNAL( clicked() ), this, SLOT( emitFilter() ) );
    connect( buttonTypeSelectAll, SIGNAL( clicked() ), this, SLOT( selectAllTypes() ) );
    connect( buttonTypeClear, SIGNAL( clicked() ), listViewType, SLOT( clearSelection() ) );

    // tab order
    setTabOrder( lineEditName, radioNameContains );
    setTabOrder( radioNameContains, listViewType );
    setTabOrder( listViewType, buttonTypeSelectAll );
    setTabOrder( buttonTypeSelectAll, buttonTypeClear );
    setTabOrder( buttonTypeClear, buttonOK );
    setTabOrder( buttonOK, buttonCancel );
}

/*
 *  Destroys the object and frees any allocated resources
 */
FilterListDialog::~FilterListDialog()
{
    // no need to delete child widgets, Qt does it all for us
}

void FilterListDialog::emitFilter()
{
	int nameMode = -1;
	QValueList<int> typeList;

	if( radioNameStartsWith->isOn() )
		nameMode = 0;
	else if( radioNameContains->isOn() )
		nameMode = 1;
	else if( radioNameEndsWith->isOn() )
		nameMode = 2;

	for( QListViewItemIterator it( listViewType ); it.current(); it++ )
		if( it.current()->isSelected() )
			typeList.append( it.current()->text( 1 ).toInt() );

	emit filterCurrentList( lineEditName->text(), nameMode, typeList );
	accept();
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void FilterListDialog::languageChange()
{
    setCaption( tr( "Filter current list" ) );
    buttonGroupName->setTitle( tr( "Filter by Name" ) );
    radioNameEndsWith->setText( tr( "ends with" ) );
    radioNameStartsWith->setText( tr( "starts with" ) );
    radioNameContains->setText( tr( "contains" ) );
    buttonOK->setText( tr( "Ok" ) );
    buttonCancel->setText( tr( "Cancel" ) );
    buttonGroupType->setTitle( tr( "Filter by Type" ) );
    buttonTypeSelectAll->setText( tr( "Select All" ) );
    buttonTypeClear->setText( tr( "Clear Selection" ) );
}

void FilterListDialog::selectAllTypes()
{
	listViewType->selectAll( true );
}

void FilterListDialog::setDatablock( Datablock db )
{
	datablock = db;
	switch( db ) {
	case ObjDef:
		setCaption( tr( "Filter Objects" ) );
		helpBox->setText( tr( "In this dialog you can filter the list so that, for example, "
				"only items with type 05 are shown. You can also hide all items that don't start "
				"with, contain or end with the string you've typed into the line above before." ) );
		listViewType->clear();
		new QListViewItem( listViewType, tr( "Non-solid, visible object" ), "01" );
		new QListViewItem( listViewType, tr( "Player" ), "02" );
		new QListViewItem( listViewType, tr( "Car" ), "04" );
		new QListViewItem( listViewType, tr( "Standart script" ), "05" );
		new QListViewItem( listViewType, tr( "Door definitions" ), "06" );
		new QListViewItem( listViewType, tr( "Trolley" ), "08" );
		new QListViewItem( listViewType, tr( "A chair in the villa-mission" ), "09" );
		new QListViewItem( listViewType, tr( "List of traffic car names" ), "12" );
		new QListViewItem( listViewType, tr( "List of names of human models" ), "18" );
		new QListViewItem( listViewType, tr( "Part of the scene.4ds" ), "20" );
		new QListViewItem( listViewType, tr( "Dogs" ), "21" );
		new QListViewItem( listViewType, tr( "Plane" ), "22" );
		new QListViewItem( listViewType, tr( "Solid Objects (with Clipping)" ), "23" );
		new QListViewItem( listViewType, tr( "Rail route (\"lucky bastard\" mission only)" ), "24" );
		new QListViewItem( listViewType, tr( "Pumpar" ), "25" );
		new QListViewItem( listViewType, tr( "Enemy with script" ), "27" );
		new QListViewItem( listViewType, tr( "Race cameras" ), "28" );
		new QListViewItem( listViewType, tr( "Wagons (\"lucky bastard\" mission only)" ), "30" );
		new QListViewItem( listViewType, tr( "Clocks" ), "34" );
		new QListViewItem( listViewType, tr( "Boxes" ), "35" );
		new QListViewItem( listViewType, tr( "Truck" ), "36" );
		buttonGroupType->setEnabled( TRUE );
		//resize( QSize(508, 249).expandedTo(minimumSizeHint()) );
		break;
	case Object:
		setCaption( tr( "Filter Object Definitions" ) );
		helpBox->setText( tr( "In this dialog you can filter the list so that, for example, "
				"only items with type 05 are shown. You can also hide all items that don't start "
				"with, contain or end with the string you've typed into the line above before." ) );
		listViewType->clear();
		new QListViewItem( listViewType, tr( "Light" ), "02" );
		buttonGroupType->setEnabled( TRUE );
		//resize( QSize(508, 249).expandedTo(minimumSizeHint()) );
		break;
	case Init:
		setCaption( tr( "Filter Init Scripts" ) );
		helpBox->setText( tr( "Init Scripts" ) );
		listViewType->clear();
		buttonGroupType->setEnabled( FALSE );
		//resize( QSize(258, 249) );
		break;
	}
}