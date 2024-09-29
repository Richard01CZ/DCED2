/****************************************************************************
** Form implementation generated from reading ui file 'addobjectwizard.ui'
**
** Created: Fr 6. Feb 13:19:52 2004
**	  by: The User Interface Compiler ($Id: qt/main.cpp   3.2.1   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "addobjecticons.h"
#include "addobjectwizard.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qwidget.h>
#include <qlabel.h>
#include <qtextedit.h>
#include <qheader.h>
#include <qlistview.h>
#include <qgroupbox.h>
#include <qframe.h>
#include <qcheckbox.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a AddObjectWizard as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The wizard will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal wizard.
 */
AddObjectWizard::AddObjectWizard( QWidget* parent, const char* name, bool modal, WFlags fl )
	: QWizard( parent, name, modal, fl ),
	  image0( (const char **) image0_data ),
	  image1( (const char **) image1_data ),
	  image2( (const char **) image2_data ),
	  image3( (const char **) image3_data ),
	  image4( (const char **) image4_data ),
	  image5( (const char **) image5_data ),
	  image6( (const char **) image6_data ),
	  image7( (const char **) image7_data ),
	  image8( (const char **) image8_data ),
	  image9( (const char **) image9_data ),
	  image10( (const char **) image10_data )
{
	if ( !name )
	setName( "AddObjectWizard" );
	setIcon( image0 );

	page1 = new QWidget( this, "page1" );

	page1TitleLabel = new QLabel( page1, "page1TitleLabel" );
	page1TitleLabel->setGeometry( QRect( 186, 1, 479, 30 ) );
	page1TitleLabel->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, page1TitleLabel->sizePolicy().hasHeightForWidth() ) );
	QFont page1TitleLabel_font(  page1TitleLabel->font() );
	page1TitleLabel_font.setFamily( "Arial" );
	page1TitleLabel_font.setPointSize( 18 );
	page1TitleLabel_font.setBold( TRUE );
	page1TitleLabel->setFont( page1TitleLabel_font ); 

	page1HelpBox = new QTextEdit( page1, "page1HelpBox" );
	page1HelpBox->setGeometry( QRect( 497, 36, 168, 375 ) );
	page1HelpBox->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)7, 0, 0, page1HelpBox->sizePolicy().hasHeightForWidth() ) );
	page1HelpBox->setWordWrap( QTextEdit::WidgetWidth );

	page1TypeList = new QListView( page1, "page1TypeList" );
	page1TypeList->addColumn( tr( "Type" ) );
	page1TypeList->header()->setClickEnabled( FALSE, page1TypeList->header()->count() - 1 );
	page1TypeList->header()->setResizeEnabled( FALSE, page1TypeList->header()->count() - 1 );
	page1TypeList->setGeometry( QRect( 186, 36, 306, 375 ) );
	page1TypeList->setResizeMode( QListView::AllColumns );

	page1Logo = new QLabel( page1, "page1Logo" );
	page1Logo->setGeometry( QRect( 1, 1, 180, 410 ) );
	page1Logo->setPixmap( image1 );
	addPage( page1, QString("") );

	page2 = new QWidget( this, "page2" );

	additionalBox = new QGroupBox( page2, "additionalBox" );
	additionalBox->setGeometry( QRect( 186, 168, 479, 111 ) );
	additionalBox->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)4, 0, 0, additionalBox->sizePolicy().hasHeightForWidth() ) );
	additionalBox->setMinimumSize( QSize( 0, 0 ) );
	additionalBox->setMaximumSize( QSize( 32767, 32767 ) );
	additionalBox->setColumnLayout(0, Qt::Vertical );
	additionalBox->layout()->setSpacing( 4 );
	additionalBox->layout()->setMargin( 7 );
	additionalBoxLayout = new QVBoxLayout( additionalBox->layout() );
	additionalBoxLayout->setAlignment( Qt::AlignTop );

	modelFrame = new QFrame( additionalBox, "modelFrame" );
	modelFrame->setFrameShape( QFrame::NoFrame );
	modelFrame->setFrameShadow( QFrame::Plain );
	modelFrameLayout = new QVBoxLayout( modelFrame, 0, 0, "modelFrameLayout"); 

	modelTitleLabel = new QLabel( modelFrame, "modelTitleLabel" );
	QFont modelTitleLabel_font(  modelTitleLabel->font() );
	modelTitleLabel_font.setFamily( "Arial" );
	modelTitleLabel_font.setPointSize( 10 );
	modelTitleLabel_font.setBold( TRUE );
	modelTitleLabel->setFont( modelTitleLabel_font ); 
	modelFrameLayout->addWidget( modelTitleLabel );

	modelInputLayout = new QHBoxLayout( 0, 0, 5, "modelInputLayout"); 
	QSpacerItem* spacer = new QSpacerItem( 10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
	modelInputLayout->addItem( spacer );

	modelCheckBox = new QCheckBox( modelFrame, "modelCheckBox" );
	modelInputLayout->addWidget( modelCheckBox );

	modelLineEdit = new QLineEdit( modelFrame, "modelLineEdit" );
	modelLineEdit->setEnabled( FALSE );
	modelLineEdit->setFrameShape( QLineEdit::LineEditPanel );
	modelInputLayout->addWidget( modelLineEdit );
	modelFrameLayout->addLayout( modelInputLayout );
	additionalBoxLayout->addWidget( modelFrame );

	sectorFrame = new QFrame( additionalBox, "sectorFrame" );
	sectorFrame->setFrameShape( QFrame::NoFrame );
	sectorFrame->setFrameShadow( QFrame::Plain );
	sectorFrameLayout = new QVBoxLayout( sectorFrame, 0, 0, "sectorFrameLayout"); 

	sectorTitleLabel = new QLabel( sectorFrame, "sectorTitleLabel" );
	QFont sectorTitleLabel_font(  sectorTitleLabel->font() );
	sectorTitleLabel_font.setFamily( "Arial" );
	sectorTitleLabel_font.setPointSize( 10 );
	sectorTitleLabel_font.setBold( TRUE );
	sectorTitleLabel->setFont( sectorTitleLabel_font ); 
	sectorFrameLayout->addWidget( sectorTitleLabel );

	sectorInputLayout = new QHBoxLayout( 0, 0, 5, "sectorInputLayout"); 
	QSpacerItem* spacer_2 = new QSpacerItem( 10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
	sectorInputLayout->addItem( spacer_2 );

	sectorCheckBox = new QCheckBox( sectorFrame, "sectorCheckBox" );
	sectorInputLayout->addWidget( sectorCheckBox );

	sectorComboBox = new QComboBox( FALSE, sectorFrame, "sectorComboBox" );
	sectorComboBox->setEnabled( FALSE );
	sectorComboBox->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, sectorComboBox->sizePolicy().hasHeightForWidth() ) );
	sectorComboBox->setEditable( TRUE );
	sectorComboBox->setAutoCompletion( TRUE );
	sectorComboBox->setDuplicatesEnabled( FALSE );
	sectorInputLayout->addWidget( sectorComboBox );
	sectorFrameLayout->addLayout( sectorInputLayout );
	additionalBoxLayout->addWidget( sectorFrame );

	rotationGroupBox = new QGroupBox( page2, "rotationGroupBox" );
	rotationGroupBox->setEnabled( TRUE );
	rotationGroupBox->setGeometry( QRect( 347, 31, 157, 132 ) );
	rotationGroupBox->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)4, 0, 0, rotationGroupBox->sizePolicy().hasHeightForWidth() ) );
	rotationGroupBox->setColumnLayout(0, Qt::Vertical );
	rotationGroupBox->layout()->setSpacing( 1 );
	rotationGroupBox->layout()->setMargin( 7 );
	rotationGroupBoxLayout = new QVBoxLayout( rotationGroupBox->layout() );
	rotationGroupBoxLayout->setAlignment( Qt::AlignTop );

	rotationXLayout = new QHBoxLayout( 0, 0, 5, "rotationXLayout"); 

	rotationXTitle = new QLabel( rotationGroupBox, "rotationXTitle" );
	rotationXTitle->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, rotationXTitle->sizePolicy().hasHeightForWidth() ) );
	rotationXTitle->setFrameShape( QLabel::Box );
	rotationXTitle->setPixmap( image2 );
	rotationXLayout->addWidget( rotationXTitle );

	rotationXInput = new QLineEdit( rotationGroupBox, "rotationXInput" );
	QFont rotationXInput_font(  rotationXInput->font() );
	rotationXInput_font.setPointSize( 10 );
	rotationXInput->setFont( rotationXInput_font ); 
	rotationXInput->setFrameShape( QLineEdit::LineEditPanel );
	rotationXLayout->addWidget( rotationXInput );
	rotationGroupBoxLayout->addLayout( rotationXLayout );

	rotationYLayout = new QHBoxLayout( 0, 0, 5, "rotationYLayout"); 

	rotationYTitle = new QLabel( rotationGroupBox, "rotationYTitle" );
	rotationYTitle->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, rotationYTitle->sizePolicy().hasHeightForWidth() ) );
	rotationYTitle->setFrameShape( QLabel::Box );
	rotationYTitle->setPixmap( image3 );
	rotationYLayout->addWidget( rotationYTitle );

	rotationYInput = new QLineEdit( rotationGroupBox, "rotationYInput" );
	QFont rotationYInput_font(  rotationYInput->font() );
	rotationYInput_font.setPointSize( 10 );
	rotationYInput->setFont( rotationYInput_font ); 
	rotationYInput->setFrameShape( QLineEdit::LineEditPanel );
	rotationYLayout->addWidget( rotationYInput );
	rotationGroupBoxLayout->addLayout( rotationYLayout );

	rotationZLayout = new QHBoxLayout( 0, 0, 5, "rotationZLayout"); 

	rotationZTitle = new QLabel( rotationGroupBox, "rotationZTitle" );
	rotationZTitle->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, rotationZTitle->sizePolicy().hasHeightForWidth() ) );
	rotationZTitle->setFrameShape( QLabel::Box );
	rotationZTitle->setPixmap( image4 );
	rotationZLayout->addWidget( rotationZTitle );

	rotationZInput = new QLineEdit( rotationGroupBox, "rotationZInput" );
	QFont rotationZInput_font(  rotationZInput->font() );
	rotationZInput_font.setPointSize( 10 );
	rotationZInput->setFont( rotationZInput_font ); 
	rotationZInput->setFrameShape( QLineEdit::LineEditPanel );
	rotationZLayout->addWidget( rotationZInput );
	rotationGroupBoxLayout->addLayout( rotationZLayout );

	positionGroupBox = new QGroupBox( page2, "positionGroupBox" );
	positionGroupBox->setGeometry( QRect( 186, 31, 156, 132 ) );
	positionGroupBox->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)4, 0, 0, positionGroupBox->sizePolicy().hasHeightForWidth() ) );
	QFont positionGroupBox_font(  positionGroupBox->font() );
	positionGroupBox->setFont( positionGroupBox_font ); 
	positionGroupBox->setColumnLayout(0, Qt::Vertical );
	positionGroupBox->layout()->setSpacing( 1 );
	positionGroupBox->layout()->setMargin( 7 );
	positionGroupBoxLayout = new QVBoxLayout( positionGroupBox->layout() );
	positionGroupBoxLayout->setAlignment( Qt::AlignTop );

	positionXLayout = new QHBoxLayout( 0, 0, 5, "positionXLayout"); 

	positionXTitle = new QLabel( positionGroupBox, "positionXTitle" );
	positionXTitle->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, positionXTitle->sizePolicy().hasHeightForWidth() ) );
	positionXTitle->setFrameShape( QLabel::Box );
	positionXTitle->setPixmap( image5 );
	positionXLayout->addWidget( positionXTitle );

	positionXInput = new QLineEdit( positionGroupBox, "positionXInput" );
	QFont positionXInput_font(  positionXInput->font() );
	positionXInput_font.setPointSize( 10 );
	positionXInput->setFont( positionXInput_font ); 
	positionXInput->setFrameShape( QLineEdit::LineEditPanel );
	positionXLayout->addWidget( positionXInput );
	positionGroupBoxLayout->addLayout( positionXLayout );

	positionYLayout = new QHBoxLayout( 0, 0, 5, "positionYLayout"); 

	positionYTitle = new QLabel( positionGroupBox, "positionYTitle" );
	positionYTitle->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, positionYTitle->sizePolicy().hasHeightForWidth() ) );
	positionYTitle->setFrameShape( QLabel::Box );
	positionYTitle->setPixmap( image6 );
	positionYLayout->addWidget( positionYTitle );

	positionYInput = new QLineEdit( positionGroupBox, "positionYInput" );
	QFont positionYInput_font(  positionYInput->font() );
	positionYInput_font.setPointSize( 10 );
	positionYInput->setFont( positionYInput_font ); 
	positionYInput->setFrameShape( QLineEdit::LineEditPanel );
	positionYLayout->addWidget( positionYInput );
	positionGroupBoxLayout->addLayout( positionYLayout );

	positionZLayout = new QHBoxLayout( 0, 0, 5, "positionZLayout"); 

	positionZTitle = new QLabel( positionGroupBox, "positionZTitle" );
	positionZTitle->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, positionZTitle->sizePolicy().hasHeightForWidth() ) );
	positionZTitle->setFrameShape( QLabel::Box );
	positionZTitle->setPixmap( image7 );
	positionZLayout->addWidget( positionZTitle );

	positionZInput = new QLineEdit( positionGroupBox, "positionZInput" );
	QFont positionZInput_font(  positionZInput->font() );
	positionZInput_font.setPointSize( 10 );
	positionZInput->setFont( positionZInput_font ); 
	positionZInput->setFrameShape( QLineEdit::LineEditPanel );
	positionZLayout->addWidget( positionZInput );
	positionGroupBoxLayout->addLayout( positionZLayout );

	QWidget* privateLayoutWidget = new QWidget( page2, "objectTitleLayout" );
	privateLayoutWidget->setGeometry( QRect( 186, 1, 479, 25 ) );
	objectTitleLayout = new QHBoxLayout( privateLayoutWidget, 0, 5, "objectTitleLayout"); 

	objectNameTitle = new QLabel( privateLayoutWidget, "objectNameTitle" );
	objectNameTitle->setMinimumSize( QSize( 0, 23 ) );
	objectNameTitle->setMaximumSize( QSize( 80, 23 ) );
	QFont objectNameTitle_font(  objectNameTitle->font() );
	objectNameTitle_font.setFamily( "Arial" );
	objectNameTitle_font.setPointSize( 12 );
	objectNameTitle_font.setBold( TRUE );
	objectNameTitle->setFont( objectNameTitle_font ); 
	objectNameTitle->setMargin( 2 );
	objectTitleLayout->addWidget( objectNameTitle );

	objectNameInput = new QLineEdit( privateLayoutWidget, "objectNameInput" );
	objectNameInput->setMinimumSize( QSize( 0, 23 ) );
	objectNameInput->setMaximumSize( QSize( 32767, 23 ) );
	QFont objectNameInput_font(  objectNameInput->font() );
	objectNameInput_font.setFamily( "Arial" );
	objectNameInput_font.setPointSize( 12 );
	objectNameInput->setFont( objectNameInput_font ); 
	objectNameInput->setFrameShape( QLineEdit::LineEditPanel );
	objectNameInput->setFrameShadow( QLineEdit::Sunken );
	objectTitleLayout->addWidget( objectNameInput );

	scalingGroupBox = new QGroupBox( page2, "scalingGroupBox" );
	scalingGroupBox->setGeometry( QRect( 509, 31, 156, 132 ) );
	scalingGroupBox->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)4, 0, 0, scalingGroupBox->sizePolicy().hasHeightForWidth() ) );
	scalingGroupBox->setColumnLayout(0, Qt::Vertical );
	scalingGroupBox->layout()->setSpacing( 1 );
	scalingGroupBox->layout()->setMargin( 7 );
	scalingGroupBoxLayout = new QVBoxLayout( scalingGroupBox->layout() );
	scalingGroupBoxLayout->setAlignment( Qt::AlignTop );

	scalingXLayout = new QHBoxLayout( 0, 0, 5, "scalingXLayout"); 

	scalingXTitle = new QLabel( scalingGroupBox, "scalingXTitle" );
	scalingXTitle->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, scalingXTitle->sizePolicy().hasHeightForWidth() ) );
	scalingXTitle->setFrameShape( QLabel::Box );
	scalingXTitle->setPixmap( image8 );
	scalingXLayout->addWidget( scalingXTitle );

	scalingXInput = new QLineEdit( scalingGroupBox, "scalingXInput" );
	scalingXInput->setFrameShape( QLineEdit::LineEditPanel );
	scalingXLayout->addWidget( scalingXInput );
	scalingGroupBoxLayout->addLayout( scalingXLayout );

	scalingYLayout = new QHBoxLayout( 0, 0, 5, "scalingYLayout"); 

	scalingYTitle = new QLabel( scalingGroupBox, "scalingYTitle" );
	scalingYTitle->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, scalingYTitle->sizePolicy().hasHeightForWidth() ) );
	scalingYTitle->setMinimumSize( QSize( 34, 34 ) );
	scalingYTitle->setFrameShape( QLabel::Box );
	scalingYTitle->setPixmap( image9 );
	scalingYLayout->addWidget( scalingYTitle );

	scalingYInput = new QLineEdit( scalingGroupBox, "scalingYInput" );
	QFont scalingYInput_font(  scalingYInput->font() );
	scalingYInput_font.setPointSize( 10 );
	scalingYInput->setFont( scalingYInput_font ); 
	scalingYInput->setFrameShape( QLineEdit::LineEditPanel );
	scalingYLayout->addWidget( scalingYInput );
	scalingGroupBoxLayout->addLayout( scalingYLayout );

	scalingZLayout = new QHBoxLayout( 0, 0, 5, "scalingZLayout"); 

	scalingZTitle = new QLabel( scalingGroupBox, "scalingZTitle" );
	scalingZTitle->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, scalingZTitle->sizePolicy().hasHeightForWidth() ) );
	scalingZTitle->setMinimumSize( QSize( 34, 34 ) );
	scalingZTitle->setFrameShape( QLabel::Box );
	scalingZTitle->setPixmap( image10 );
	scalingZLayout->addWidget( scalingZTitle );

	scalingZInput = new QLineEdit( scalingGroupBox, "scalingZInput" );
	QFont scalingZInput_font(  scalingZInput->font() );
	scalingZInput_font.setPointSize( 10 );
	scalingZInput->setFont( scalingZInput_font ); 
	scalingZInput->setFrameShape( QLineEdit::LineEditPanel );
	scalingZLayout->addWidget( scalingZInput );
	scalingGroupBoxLayout->addLayout( scalingZLayout );

	page2HelpBox = new QTextEdit( page2, "page2HelpBox" );
	page2HelpBox->setGeometry( QRect( 186, 284, 479, 127 ) );
	page2HelpBox->setReadOnly( TRUE );

	page2Logo = new QLabel( page2, "page2Logo" );
	page2Logo->setGeometry( QRect( 1, 1, 180, 410 ) );
	page2Logo->setPixmap( image1 );
	addPage( page2, QString("") );
	languageChange();
	resize( QSize(678, 488).expandedTo(minimumSizeHint()) );
	clearWState( WState_Polished );
	helpButton()->hide();
	backButton()->hide();
	setNextEnabled( page1, FALSE );

	// signals and slots connections
	connect( page1TypeList, SIGNAL( selectionChanged(QListViewItem*) ), this, SLOT( setHelpBox(QListViewItem*) ) );
	connect( objectNameInput, SIGNAL( textChanged(const QString&) ), this, SLOT( setPage2BottomButtons(const QString&) ) );
	connect( page1TypeList, SIGNAL( selectionChanged(QListViewItem*) ), this, SLOT( setPage1BottomButtons(QListViewItem*) ) );
	connect( sectorCheckBox, SIGNAL( toggled(bool) ), sectorComboBox, SLOT( setEnabled(bool) ) );
	connect( modelCheckBox, SIGNAL( toggled(bool) ), modelLineEdit, SLOT( setEnabled(bool) ) );
	connect( nextButton(), SIGNAL( clicked() ), backButton(), SLOT( show() ) );
	connect( backButton(), SIGNAL( clicked() ), backButton(), SLOT( hide() ) );
}

/*
 *  Destroys the object and frees any allocated resources
 */
AddObjectWizard::~AddObjectWizard()
{
	// no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void AddObjectWizard::languageChange()
{
	setCaption( tr( "Add Object" ) );
	page1TitleLabel->setText( tr( "Add Object" ) );
	page1HelpBox->setText( tr( "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\"font-size:8pt;font-family:MS Shell Dlg\">\n"
"<p style=\"margin-top:16px\"><span style=\"font-size:12pt;font-weight:600\">Select an item</span></p>\n"
"<p>...in the list to the left to get more information.</p>\n"
"</body></html>\n"
"" ) );

	/*
	 *	Type list
	 */
	page1TypeList->header()->setLabel( 0, tr( "Type" ) );
	page1TypeList->clear();

	//---------Toplevel entries---------//
	objectsItem = new QListViewItem( page1TypeList, 0, tr( "Objects" ) );
	objectsItem->setOpen( TRUE );
	objectDefinitionsItem = new QListViewItem( page1TypeList, objectsItem, tr( "Object Definitions" ) );
	objectDefinitionsItem->setOpen( TRUE );
	initScriptsItem = new QListViewItem( page1TypeList, objectDefinitionsItem, tr( "INIT Script" ) );
	
	//------------Subentries------------//
	new QListViewItem( objectsItem, tr( "Light" ) );
	new QListViewItem( objectsItem, tr( "Model" ) );
	new QListViewItem( objectsItem, tr( "Occluder" ) );
	new QListViewItem( objectsItem, tr( "Sector" ) );
	new QListViewItem( objectsItem, tr( "Sound" ) );
	new QListViewItem( objectsItem, tr( "Special Object" ) );

	new QListViewItem( objectDefinitionsItem, tr( "Non-solid, visible object" ) );
	new QListViewItem( objectDefinitionsItem, tr( "Player" ) );
	new QListViewItem( objectDefinitionsItem, tr( "Car" ) );
	new QListViewItem( objectDefinitionsItem, tr( "Standard Script" ) );
	new QListViewItem( objectDefinitionsItem, tr( "Door Definitions" ) );
	new QListViewItem( objectDefinitionsItem, tr( "Trolley" ) );
	new QListViewItem( objectDefinitionsItem, tr( "Chair" ) );
	new QListViewItem( objectDefinitionsItem, tr( "List of Traffic Car Names" ) );
	new QListViewItem( objectDefinitionsItem, tr( "List of Names of Human Models" ) );
	new QListViewItem( objectDefinitionsItem, tr( "Part of the scene.4ds" ) );
	new QListViewItem( objectDefinitionsItem, tr( "Dog" ) );
	new QListViewItem( objectDefinitionsItem, tr( "Plane" ) );
	new QListViewItem( objectDefinitionsItem, tr( "Solid Object" ) );
	new QListViewItem( objectDefinitionsItem, tr( "Rail route" ) );
	new QListViewItem( objectDefinitionsItem, tr( "Pumpar" ) );
	new QListViewItem( objectDefinitionsItem, tr( "Enemy with Script" ) );
	new QListViewItem( objectDefinitionsItem, tr( "Race Camera" ) );
	new QListViewItem( objectDefinitionsItem, tr( "Wagon" ) );
	new QListViewItem( objectDefinitionsItem, tr( "Clock" ) );
	new QListViewItem( objectDefinitionsItem, tr( "Box" ) );
	new QListViewItem( objectDefinitionsItem, tr( "Truck" ) );
	//----------------------------Items Ende-----------------------------//

	setTitle( page1, tr( "Step 1: Select object type" ) );
	additionalBox->setTitle( tr( "Additional" ) );
	modelTitleLabel->setText( tr( "Model:" ) );
	modelCheckBox->setText( QString::null );
	sectorTitleLabel->setText( tr( "Sector:" ) );
	sectorCheckBox->setText( QString::null );
	rotationGroupBox->setTitle( tr( "Rotation" ) );
	rotationXInput->setText( tr( "0" ) );
	rotationYInput->setText( tr( "0" ) );
	rotationZInput->setText( tr( "0" ) );
	positionGroupBox->setTitle( tr( "Position" ) );
	positionXInput->setText( tr( "0" ) );
	positionYInput->setText( tr( "0" ) );
	positionZInput->setText( tr( "0" ) );
	objectNameTitle->setText( tr( "Name:" ) );
	objectNameInput->setText( QString::null );
	scalingGroupBox->setTitle( tr( "Scaling" ) );
	scalingXInput->setText( tr( "0" ) );
	scalingYInput->setText( tr( "0" ) );
	scalingZInput->setText( tr( "0" ) );
	setTitle( page2, tr( "Step 2: Define object options" ) );
}

void AddObjectWizard::open()
{
	languageChange();
	show();
}

void AddObjectWizard::setPage2BottomButtons(const QString& name)
{
	backButton()->show();
	if( name != "" )
		setFinishEnabled( page2, true );
	else
		setFinishEnabled( page2, false );
}

void AddObjectWizard::setPage1BottomButtons(QListViewItem*)
{
	backButton()->hide();
	if( page1TypeList->selectedItem() != 0
		&& page1TypeList->selectedItem() != objectsItem
		&& page1TypeList->selectedItem() != objectDefinitionsItem )
	{
		if( page1TypeList->selectedItem() == initScriptsItem )
		{
			setAppropriate( page2, false );
			setFinishEnabled( page1, true );
		}
		else if( page1TypeList->selectedItem()->parent() == objectsItem )
		{
			setAppropriate( page2, true );
			setFinishEnabled( page1, false );
			setNextEnabled( page1, true );
		}
		else if( page1TypeList->selectedItem()->parent() == objectDefinitionsItem )
		{
			setAppropriate( page2, false );
			setFinishEnabled( page1, true );
		}
	}
	else
	{	
		setNextEnabled( page1, false );
		setFinishEnabled( page1, false );
	};
}

void AddObjectWizard::setHelpBox(QListViewItem*)
{
	qWarning( "AddObjectWizard::setHelpBox(QListViewItem*): Not implemented yet" );
}