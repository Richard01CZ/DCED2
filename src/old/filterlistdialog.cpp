/****************************************************************************
** Form implementation generated from reading ui file 'filterlistdialog.ui'
**
** Created: Do 18. Dez 21:07:33 2003
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.2.1   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "documentwidget.h"
#include "filterlistdialog.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qbuttongroup.h>
#include <qcheckbox.h>
#include <qspinbox.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qradiobutton.h>
#include <qlineedit.h>
#include <qlistbox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>
#include <qmessagebox.h>
#include "img\filter.xpm"

/*
 *  Constructs a FilterListDialog as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
FilterListDialog::FilterListDialog( DocumentWidget* parentWidget, const char* name, bool modal, WFlags fl )
    : QDialog( parentWidget, name, modal, fl )
{
	parent = parentWidget;

    if ( !name )
	setName( "FilterListDialog" );
    setMinimumSize( QSize( 545, 275 ) );
	setMaximumSize( QSize( 545, 275 ) );
    setIcon( filter_xpm );
    FilterListDialogLayout = new QGridLayout( this, 1, 1, 11, 6, "FilterListDialogLayout"); 

    buttonGroupID = new QButtonGroup( this, "buttonGroupID" );
    buttonGroupID->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, buttonGroupID->sizePolicy().hasHeightForWidth() ) );
    buttonGroupID->setMaximumSize( QSize( 229, 78 ) );

    checkBoxIDMax = new QCheckBox( buttonGroupID, "checkBoxIDMax" );
    checkBoxIDMax->setGeometry( QRect( 9, 53, 80, 21 ) );

    checkBoxIDMin = new QCheckBox( buttonGroupID, "checkBoxIDMin" );
    checkBoxIDMin->setGeometry( QRect( 9, 23, 80, 21 ) );

    spinBoxIDMin = new QSpinBox( buttonGroupID, "spinBoxIDMin" );
    spinBoxIDMin->setEnabled( FALSE );
    spinBoxIDMin->setGeometry( QRect( 149, 23, 71, 21 ) );
    spinBoxIDMin->setMaxValue( 99999999 );

    spinBoxIDMax = new QSpinBox( buttonGroupID, "spinBoxIDMax" );
    spinBoxIDMax->setEnabled( FALSE );
    spinBoxIDMax->setGeometry( QRect( 149, 53, 71, 21 ) );
    spinBoxIDMax->setMaxValue( 99999999 );

    FilterListDialogLayout->addWidget( buttonGroupID, 1, 0 );

    groupBoxHint = new QGroupBox( this, "groupBoxHint" );
    groupBoxHint->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)3, 0, 0, groupBoxHint->sizePolicy().hasHeightForWidth() ) );
    groupBoxHint->setMinimumSize( QSize( 0, 81 ) );
    groupBoxHint->setBackgroundOrigin( QGroupBox::AncestorOrigin );
    groupBoxHint->setFrameShape( QGroupBox::TabWidgetPanel );
    groupBoxHint->setMidLineWidth( 0 );
    groupBoxHint->setFlat( FALSE );

    labelHint = new QLabel( groupBoxHint, "labelHint" );
    labelHint->setGeometry( QRect( 5, 5, 220, 70 ) );
    labelHint->setBackgroundMode( QLabel::PaletteBase );
    labelHint->setFrameShape( QLabel::NoFrame );
    labelHint->setAlignment( int( QLabel::AlignTop ) );

    FilterListDialogLayout->addMultiCellWidget( groupBoxHint, 2, 3, 0, 0 );

    bottomLayout = new QHBoxLayout( 0, 0, 6, "bottomLayout"); 
    QSpacerItem* spacer = new QSpacerItem( 251, 31, QSizePolicy::Expanding, QSizePolicy::Minimum );
    bottomLayout->addItem( spacer );

    buttonOK = new QPushButton( this, "buttonOK" );
    bottomLayout->addWidget( buttonOK );

    buttonCancel = new QPushButton( this, "buttonCancel" );
    bottomLayout->addWidget( buttonCancel );

    FilterListDialogLayout->addLayout( bottomLayout, 3, 1 );

    buttonGroupName = new QButtonGroup( this, "buttonGroupName" );
    buttonGroupName->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, buttonGroupName->sizePolicy().hasHeightForWidth() ) );
    buttonGroupName->setMaximumSize( QSize( 229, 92 ) );

    radioNameEndsWith = new QRadioButton( buttonGroupName, "radioNameEndsWith" );
    radioNameEndsWith->setGeometry( QRect( 154, 60, 67, 21 ) );

    radioNameStartsWith = new QRadioButton( buttonGroupName, "radioNameStartsWith" );
    radioNameStartsWith->setGeometry( QRect( 8, 60, 73, 21 ) );

    lineEditName = new QLineEdit( buttonGroupName, "lineEditName" );
    lineEditName->setGeometry( QRect( 10, 30, 210, 21 ) );
    lineEditName->setFrameShape( QLineEdit::LineEditPanel );
    lineEditName->setFrameShadow( QLineEdit::Sunken );

    radioNameContains = new QRadioButton( buttonGroupName, "radioNameContains" );
    radioNameContains->setGeometry( QRect( 84, 60, 63, 21 ) );
    radioNameContains->setChecked( TRUE );

    FilterListDialogLayout->addWidget( buttonGroupName, 0, 0 );

    buttonGroupType = new QButtonGroup( this, "buttonGroupType" );
    buttonGroupType->setMinimumSize( QSize( 288, 224 ) );
    buttonGroupType->setColumnLayout(0, Qt::Vertical );
    buttonGroupType->layout()->setSpacing( 6 );
    buttonGroupType->layout()->setMargin( 11 );
    buttonGroupTypeLayout = new QGridLayout( buttonGroupType->layout() );
    buttonGroupTypeLayout->setAlignment( Qt::AlignTop );
    QSpacerItem* spacer_2 = new QSpacerItem( 80, 31, QSizePolicy::Expanding, QSizePolicy::Minimum );
    //buttonGroupTypeLayout->addItem( spacer_2, 1, 2 );

//	buttonTypeSelectAll = new QPushButton( buttonGroupType, "buttonTypeSelectAll" );

//	buttonGroupTypeLayout->addWidget( buttonTypeSelectAll, 1, 0 );

//	buttonTypeClear = new QPushButton( buttonGroupType, "buttonTypeClear" );

//	buttonGroupTypeLayout->addWidget( buttonTypeClear, 1, 1 );

    listBoxType = new QListBox( buttonGroupType, "listBoxType" );
	listBoxType->setSelectionMode( QListBox::Multi );

    buttonGroupTypeLayout->addMultiCellWidget( listBoxType, 0, 0, 0, 2 );

    FilterListDialogLayout->addMultiCellWidget( buttonGroupType, 0, 2, 1, 1 );
    languageChange();
    resize( QSize(546, 279).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( buttonCancel, SIGNAL( clicked() ), this, SLOT( reject() ) );
    connect( buttonOK, SIGNAL( clicked() ), this, SLOT( accept() ) );
	connect( buttonOK, SIGNAL( clicked() ), this, SLOT( emitFilter() ) );
    connect( checkBoxIDMax, SIGNAL( toggled(bool) ), spinBoxIDMax, SLOT( setEnabled(bool) ) );
    connect( checkBoxIDMin, SIGNAL( toggled(bool) ), spinBoxIDMin, SLOT( setEnabled(bool) ) );
//	connect( buttonTypeSelectAll, SIGNAL( clicked() ), listBoxType, SLOT( invertSelection() ) );
//	connect( buttonTypeClear, SIGNAL( clicked() ), listBoxType, SLOT( clearSelection() ) );

    // tab order
    setTabOrder( lineEditName, radioNameContains );
    setTabOrder( radioNameContains, checkBoxIDMin );
    setTabOrder( checkBoxIDMin, spinBoxIDMin );
    setTabOrder( spinBoxIDMin, checkBoxIDMax );
    setTabOrder( checkBoxIDMax, spinBoxIDMax );
    setTabOrder( spinBoxIDMax, listBoxType );
/*	setTabOrder( listBoxType, buttonTypeSelectAll );
	setTabOrder( buttonTypeSelectAll, buttonTypeClear );
	setTabOrder( buttonTypeClear, buttonOK );*/
	setTabOrder( listBoxType, buttonOK );
    setTabOrder( buttonOK, buttonCancel );
}

/*
 *  Destroys the object and frees any allocated resources
 */
FilterListDialog::~FilterListDialog()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void FilterListDialog::languageChange()
{
    setCaption( tr( "Filter current list" ) );
    buttonGroupID->setTitle( tr( "Filter by ID" ) );
    checkBoxIDMax->setText( tr( "Highest ID" ) );
    checkBoxIDMin->setText( tr( "Lowest ID" ) );
    groupBoxHint->setTitle( QString::null );
    labelHint->setText( tr( "In this dialog you can filter the list so that only\n"
"items with, for example, type 05 are shown.\n"
"You can also hide all items that don't start with,\n"
"contain or end with the string you've typed into\n"
"the line above before or search by ID." ) );
    buttonOK->setText( tr( "Ok" ) );
    buttonCancel->setText( tr( "Cancel" ) );
    buttonGroupName->setTitle( tr( "Filter by Name" ) );
    radioNameEndsWith->setText( tr( "ends with" ) );
    radioNameStartsWith->setText( tr( "starts with" ) );
    radioNameContains->setText( tr( "contains" ) );
    buttonGroupType->setTitle( tr( "Filter by Type" ) );
//	buttonTypeSelectAll->setText( tr( "Select All" ) );
//	buttonTypeClear->setText( tr( "Clear Selection" ) );
    listBoxType->clear();
//	listBoxType->insertItem( tr( "All Types" ) );
    listBoxType->insertItem( tr( "01: Non-solid, visible object" ) );
    listBoxType->insertItem( tr( "02: Player" ) );
    listBoxType->insertItem( tr( "04: Car" ) );
    listBoxType->insertItem( tr( "05: Standart script" ) );
    listBoxType->insertItem( tr( "06: Door definitions" ) );
    listBoxType->insertItem( tr( "08: Trolley" ) );
    listBoxType->insertItem( tr( "09: A chair in the villa-mission" ) );
    listBoxType->insertItem( tr( "12: List of traffic car names" ) );
    listBoxType->insertItem( tr( "18: List of names of human models" ) );
    listBoxType->insertItem( tr( "20: Part of the scene.4ds" ) );
    listBoxType->insertItem( tr( "21: Dogs" ) );
    listBoxType->insertItem( tr( "22: Plane" ) );
    listBoxType->insertItem( tr( "23: Solid Objects (with Clipping)" ) );
    listBoxType->insertItem( tr( "24: Rail route (\"lucky bastard\" mission only)" ) );
    listBoxType->insertItem( tr( "25: Pumpar" ) );
    listBoxType->insertItem( tr( "27: Enemy with script" ) );
    listBoxType->insertItem( tr( "28: Race cameras" ) );
    listBoxType->insertItem( tr( "30: Wagons (\"lucky bastard\" mission only)" ) );
    listBoxType->insertItem( tr( "34: Clocks" ) );
    listBoxType->insertItem( tr( "35: Boxes" ) );
    listBoxType->insertItem( tr( "36: Truck" ) );
}

void FilterListDialog::emitFilter()
{
	int nameMode = -1;
	QValueList<int> type;

	if( radioNameStartsWith->isOn() )
		nameMode = 0;
	else if( radioNameContains->isOn() )
		nameMode = 1;
	else if( radioNameEndsWith->isOn() )
		nameMode = 2;

	for( uint i = 1; i < listBoxType->count(); ++i )
		if( listBoxType->item( i )->selected() )
			type.append( listBoxType->item( i )->text().left( 2 ).toInt() );

	//if( listBoxType->currentItem() == -1 || listBoxType->currentText() == tr( "All Types" ) )
	//	type = -1;
	//else
	//	type = listBoxType->currentText().left( 2 ).toInt();

	emit filterCurrentList( lineEditName->text(), nameMode, type );
}