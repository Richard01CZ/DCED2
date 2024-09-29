/****************************************************************************
** Form implementation generated from reading ui file 'carlistdialog.ui'
**
** Created: Mo 15. Mrz 16:28:57 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.2.1   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "carlistdialog.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlistbox.h>
#include <qgroupbox.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

static const char* const image0_data[] = { 
"16 16 64 1",
". c None",
"c c #000000",
"9 c #000000",
"l c #646464",
"h c #000000",
"7 c #565656",
"i c #7e7e7e",
"d c #808080",
"p c #747474",
"t c #787878",
"y c #7a7a7a",
"L c #7c7c7c",
"Y c #7e7e7e",
"# c #545454",
"a c #8b8b8b",
"b c #969696",
"8 c #9a9a9a",
"F c #858585",
"K c #868686",
"0 c #878787",
"I c #8f8f8f",
"2 c #919191",
"C c #989898",
"X c #9b9b9b",
"E c #a1a1a1",
"W c #a4a4a4",
"1 c #a5a5a5",
"D c #aaaaaa",
"J c #ababab",
"3 c #aeaeae",
"x c #b1b1b1",
"w c #bababa",
"f c #bebebe",
"S c #c0c0c0",
"U c #c1c1c1",
"j c #c3c3c3",
"A c #c6c6c6",
"Q c #cacaca",
"n c #cdcdcd",
"B c #cfcfcf",
"H c #d0d0d0",
"O c #d3d3d3",
"V c #d4d4d4",
"m c #d5d5d5",
"q c #d9d9d9",
"R c #dddddd",
"v c #dfdfdf",
"g c #e4e4e4",
"r c #e5e5e5",
"P c #e6e6e6",
"k c #e8e8e8",
"o c #ebebeb",
"e c #ececec",
"s c #eeeeee",
"u c #f1f1f1",
"z c #f4f4f4",
"G c #f6f6f6",
"M c #f8f8f8",
"N c #fafafa",
"T c #fbfbfb",
"Z c #fcfcfc",
"4 c #fdfdfd",
"5 c #fefefe",
"6 c #ffffff",
"....#abbbbbbbbc.",
"...defggggggggh.",
"..ieejkkkkkkkkh.",
".leemnooooooooh.",
".pqmmrssssssssh.",
".tujvwjxjwvxnuh.",
".yzABCDEEABDFzh.",
".yGHHCCIJHHKJGh.",
".LMMMMMMMMMMMMh.",
".LNOPQQQPQRSNNh.",
".LTUVWWUVWXWTTh.",
".YZmm01mm2X3ZZh.",
".Y444444444444h.",
".Y555555555555h.",
".Y666666666666h.",
".78888888888889."};


/*
 *  Constructs a CarListDialog as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CarListDialog::CarListDialog( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl ),
      image0( (const char **) image0_data )
{
    if ( !name )
	setName( "CarListDialog" );
    setIcon( image0 );
    setSizeGripEnabled( TRUE );
    setModal( TRUE );
    CarListDialogLayout = new QGridLayout( this, 1, 1, 11, 6, "CarListDialogLayout"); 

    newCarButton = new QPushButton( this, "newCarButton" );
    newCarButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, newCarButton->sizePolicy().hasHeightForWidth() ) );

    CarListDialogLayout->addWidget( newCarButton, 0, 1 );

    deleteCarButton = new QPushButton( this, "deleteCarButton" );
    deleteCarButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, deleteCarButton->sizePolicy().hasHeightForWidth() ) );

    CarListDialogLayout->addWidget( deleteCarButton, 1, 1 );

    carListBox = new QListBox( this, "carListBox" );
    carListBox->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, carListBox->sizePolicy().hasHeightForWidth() ) );

    CarListDialogLayout->addMultiCellWidget( carListBox, 0, 2, 0, 0 );

    bottomLayout = new QHBoxLayout( 0, 0, 6, "bottomLayout"); 
    QSpacerItem* spacer = new QSpacerItem( 261, 21, QSizePolicy::Expanding, QSizePolicy::Minimum );
    bottomLayout->addItem( spacer );

    okButton = new QPushButton( this, "okButton" );
    bottomLayout->addWidget( okButton );

    cancelButton = new QPushButton( this, "cancelButton" );
    bottomLayout->addWidget( cancelButton );

    CarListDialogLayout->addMultiCellLayout( bottomLayout, 3, 3, 0, 1 );

    carPropertiesBox = new QGroupBox( this, "carPropertiesBox" );
    carPropertiesBox->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, carPropertiesBox->sizePolicy().hasHeightForWidth() ) );
    carPropertiesBox->setMinimumSize( QSize( 163, 0 ) );
    carPropertiesBox->setFlat( FALSE );
    carPropertiesBox->setColumnLayout(0, Qt::Vertical );
    carPropertiesBox->layout()->setSpacing( 6 );
    carPropertiesBox->layout()->setMargin( 11 );
    carPropertiesBoxLayout = new QGridLayout( carPropertiesBox->layout() );
    carPropertiesBoxLayout->setAlignment( Qt::AlignTop );

    carNameInput = new QLineEdit( carPropertiesBox, "carNameInput" );
    QFont carNameInput_font(  carNameInput->font() );
    carNameInput_font.setPointSize( 10 );
    carNameInput->setFont( carNameInput_font ); 

    carPropertiesBoxLayout->addWidget( carNameInput, 0, 1 );

    carNameLabel = new QLabel( carPropertiesBox, "carNameLabel" );

    carPropertiesBoxLayout->addWidget( carNameLabel, 0, 0 );

    CarListDialogLayout->addWidget( carPropertiesBox, 2, 1 );
    languageChange();
    resize( QSize(484, 230).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( okButton, SIGNAL( clicked() ), this, SLOT( accept() ) );
    connect( cancelButton, SIGNAL( clicked() ), this, SLOT( reject() ) );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CarListDialog::~CarListDialog()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CarListDialog::languageChange()
{
    setCaption( tr( "Traffic Car List" ) );
    newCarButton->setText( tr( "&New Car" ) );
    newCarButton->setAccel( QKeySequence( tr( "Alt+N" ) ) );
    deleteCarButton->setText( tr( "&Delete Car" ) );
    deleteCarButton->setAccel( QKeySequence( tr( "Alt+D" ) ) );
    okButton->setText( tr( "&OK" ) );
    okButton->setAccel( QKeySequence( tr( "Alt+O" ) ) );
    cancelButton->setText( tr( "&Cancel" ) );
    cancelButton->setAccel( QKeySequence( tr( "Alt+C" ) ) );
    carPropertiesBox->setTitle( tr( "Car &Properties" ) );
    carNameLabel->setText( tr( "Name:" ) );
}

