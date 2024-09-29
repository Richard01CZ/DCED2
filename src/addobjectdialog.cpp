#include "addobjectdialog.h"
#include "globaldefs.h"
#include "objecttypes.h"
#include "documentoverview.h"
#include "documentwidget.h"
#include "objectlist.h"

#include "img/addobject.xpm"
#include "img/addobjectwizard.xpm"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qheader.h>
#include <qlistview.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

/*
 *  Constructs a AddObjectDialog as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
AddObjectDialog::AddObjectDialog( QWidget* parent )
    : QDialog( parent, "AddObjectDialog", true ),
      image0( (const char **) addobject_xpm ),
      image1( (const char **) addobjectwizard_xpm )
{
    setIcon( image0 );
    AddObjectDialogLayout = new QGridLayout( this, 1, 1, 7, 5, "AddObjectDialogLayout"); 

    objectTitleLayout = new QHBoxLayout( 0, 0, 6, "objectTitleLayout"); 

    nameTitle = new QLabel( this, "nameTitle" );
    nameTitle->setMinimumSize( QSize( 0, 23 ) );
    nameTitle->setMaximumSize( QSize( 80, 23 ) );
    QFont nameTitle_font(  nameTitle->font() );
    nameTitle_font.setFamily( "Arial" );
    nameTitle_font.setPointSize( 12 );
    nameTitle_font.setBold( TRUE );
    nameTitle->setFont( nameTitle_font ); 
    nameTitle->setMargin( 2 );
    objectTitleLayout->addWidget( nameTitle );

    nameInput = new QLineEdit( this, "nameInput" );
    nameInput->setMinimumSize( QSize( 0, 23 ) );
    nameInput->setMaximumSize( QSize( 32767, 23 ) );
    QFont nameInput_font(  nameInput->font() );
    nameInput_font.setFamily( "Arial" );
    nameInput_font.setPointSize( 12 );
    nameInput->setFont( nameInput_font ); 
    nameInput->setFrameShape( QLineEdit::LineEditPanel );
    nameInput->setFrameShadow( QLineEdit::Sunken );
    objectTitleLayout->addWidget( nameInput );

    AddObjectDialogLayout->addLayout( objectTitleLayout, 1, 1 );

    titleLabel = new QLabel( this, "titleLabel" );
    titleLabel->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, titleLabel->sizePolicy().hasHeightForWidth() ) );
    QFont titleLabel_font(  titleLabel->font() );
    titleLabel_font.setFamily( "Arial" );
    titleLabel_font.setPointSize( 14 );
    titleLabel_font.setBold( TRUE );
    titleLabel->setFont( titleLabel_font ); 

    AddObjectDialogLayout->addMultiCellWidget( titleLabel, 0, 0, 1, 2 );

    addLogo = new QLabel( this, "addLogo" );
    addLogo->setPixmap( image1 );

    AddObjectDialogLayout->addMultiCellWidget( addLogo, 0, 2, 0, 0 );

    typeList = new QListView( this, "typeList" );
    typeList->addColumn( tr( "Type" ) );
    typeList->header()->setClickEnabled( FALSE, typeList->header()->count() - 1 );
    typeList->header()->setResizeEnabled( FALSE, typeList->header()->count() - 1 );
    typeList->setRootIsDecorated( TRUE );
    typeList->setResizeMode( QListView::AllColumns );

    AddObjectDialogLayout->addWidget( typeList, 2, 1 );

    helpBox = new QTextEdit( this, "helpBox" );
    helpBox->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)7, 0, 0, helpBox->sizePolicy().hasHeightForWidth() ) );
    helpBox->setWordWrap( QTextEdit::WidgetWidth );
    helpBox->setReadOnly( TRUE );

    AddObjectDialogLayout->addMultiCellWidget( helpBox, 1, 2, 2, 2 );

    layout3 = new QHBoxLayout( 0, 0, 6, "layout3"); 
    QSpacerItem* spacer = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout3->addItem( spacer );

    okButton = new QPushButton( this, "okButton" );
    layout3->addWidget( okButton );

    cancelButton = new QPushButton( this, "cancelButton" );
    layout3->addWidget( cancelButton );

    AddObjectDialogLayout->addMultiCellLayout( layout3, 3, 3, 0, 2 );
    languageChange();
    resize( QSize(600, 451).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
	setOkButtonState();

    // signals and slots connections
    connect( okButton, SIGNAL( clicked() ), this, SLOT( accept() ) );
    connect( cancelButton, SIGNAL( clicked() ), this, SLOT( reject() ) );
	connect( nameInput, SIGNAL( textChanged( const QString & ) ), this, SLOT( setOkButtonState() ) );
	connect( typeList, SIGNAL( currentChanged( QListViewItem * ) ), this, SLOT( setOkButtonState() ) );
	connect( typeList, SIGNAL( currentChanged( QListViewItem * ) ), this, SLOT( setHelp( QListViewItem * ) ) );
}

/*
 *  Destroys the object and frees any allocated resources
 */
AddObjectDialog::~AddObjectDialog()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void AddObjectDialog::languageChange()
{
    setCaption( tr( "Add Object" ) );
    nameTitle->setText( tr( "Name:" ) );
    nameInput->setText( QString::null );
    titleLabel->setText( tr( "Add Object" ) );
    typeList->header()->setLabel( 0, tr( "Type" ) );
    typeList->clear();

	objectsTree = new ObjectsTree( typeList, tr( "Objects" ) );
	objectDefinitionsTree = new ObjectDefinitionsTree( typeList, tr( "Object Definitions" ) );
	initTree = new InitTree( typeList, tr( "Init Script" ) );

	objectsTree->setText( 1, "object" );
	objectDefinitionsTree->setText( 1, "objdef" );
	initTree->setText( 1, "init" );

	typeList->insertItem( objectsTree );
	typeList->insertItem( objectDefinitionsTree );
	typeList->insertItem( initTree );

	/************************************************************************/
	/* Inserting object types                                               */
	/************************************************************************/

	QStringList::Iterator olIt;
	QStringList ol;

	//Objects
	for( ol = ObjectTypes::objectStringList( Object, TRUE ), olIt = ol.begin(); olIt != ol.end(); olIt++ )
		new QListViewItem( objectsTree, (*olIt) );

	//Object Definitions
	for( ol = ObjectTypes::objectStringList( ObjDef, TRUE ), olIt = ol.begin(); olIt != ol.end(); olIt++ )
		new QListViewItem( objectDefinitionsTree, (*olIt) );

	helpBox->setText( QString::null );
	okButton->setText( tr( "&OK" ) );
	okButton->setAccel( QKeySequence( tr( "Alt+O" ) ) );
	cancelButton->setText( tr( "&Cancel" ) );
	cancelButton->setAccel( QKeySequence( tr( "Alt+C" ) ) );
}

Type AddObjectDialog::getCurrentDatablock()
{
	Type type;

	if( typeList->currentItem()->parent() )
		type = ((ObjectTypeTree*)(typeList->currentItem()->parent()))->type;
	else 
		type = Init;

	return type;
}

void AddObjectDialog::accept()
{
	Type type = getCurrentDatablock();
	sceneWrapper->CreateObject( nameInput->text(),
			ObjectTypes::textToInt( typeList->currentItem()->text( 0 ), type ),
			eType2sType( type ) );
	QDialog::accept();
}

void AddObjectDialog::setOkButtonState()
{
	Type type = getCurrentDatablock();
	
	if( ( nameInput->text() != "" && nameInput->text() != QString::null )
	 && ( typeList->currentItem()->parent() || typeList->currentItem() == initTree )
	 && !main_widget->mySceneOverview->currentDocument()->myObjectList->exists( eType2sType( type ), nameInput->text() ) )
		okButton->setEnabled( TRUE );
	else
		okButton->setEnabled( FALSE );
}

void AddObjectDialog::setHelp( QListViewItem * item )
{
	if( item == initTree )
		helpBox->setText( ObjectTypes::intToText( 155, Init ) );
	else if( item == objectsTree )
		helpBox->setText( tr( "Objects" ) );
	else if( item == objectDefinitionsTree )
		helpBox->setText( tr( "Object Definitions" ) );
	else
		helpBox->setText( ObjectTypes::getDescription( item->text( 0 ), ((ObjectsTree *)(item->parent()))->type ) );
}
