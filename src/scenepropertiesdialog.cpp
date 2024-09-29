/****************************************************************************
** Form implementation generated from reading ui file 'scenepropertiesdialog.ui'
**
** Created: Mi 24. Mrz 16:30:14 2004
**	  by: The User Interface Compiler ($Id: qt/main.cpp   3.2.1   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "scenepropertiesdialog.h"
#include "globaldefs.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qgroupbox.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ScenePropertiesDialog as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ScenePropertiesDialog::ScenePropertiesDialog( QWidget* parent, bool modal, WFlags fl )
	: QDialog( parent, "ScenePropertiesDialog", modal, fl )
{
	ScenePropertiesDialogLayout = new QGridLayout( this, 1, 1, 11, 6, "ScenePropertiesDialogLayout"); 

	worldDimension1Title = new QLabel( this, "worldDimension1Title" );

	ScenePropertiesDialogLayout->addWidget( worldDimension1Title, 2, 0 );

	worldDimension2Title = new QLabel( this, "worldDimension2Title" );

	ScenePropertiesDialogLayout->addWidget( worldDimension2Title, 3, 0 );

	viewDistanceTitle = new QLabel( this, "viewDistanceTitle" );

	ScenePropertiesDialogLayout->addWidget( viewDistanceTitle, 0, 0 );

	cameraDistanceTitle = new QLabel( this, "cameraDistanceTitle" );

	ScenePropertiesDialogLayout->addWidget( cameraDistanceTitle, 1, 0 );

	worldDimension1Input = new QLineEdit( this, "worldDimension1Input" );
	QFont worldDimension1Input_font(  worldDimension1Input->font() );
	worldDimension1Input_font.setPointSize( 10 );
	worldDimension1Input->setFont( worldDimension1Input_font ); 

	ScenePropertiesDialogLayout->addWidget( worldDimension1Input, 2, 1 );

	worldDimension2Input = new QLineEdit( this, "worldDimension2Input" );
	QFont worldDimension2Input_font(  worldDimension2Input->font() );
	worldDimension2Input_font.setPointSize( 10 );
	worldDimension2Input->setFont( worldDimension2Input_font ); 

	ScenePropertiesDialogLayout->addWidget( worldDimension2Input, 3, 1 );

	cameraDistanceInput = new QLineEdit( this, "cameraDistanceInput" );
	QFont cameraDistanceInput_font(  cameraDistanceInput->font() );
	cameraDistanceInput_font.setPointSize( 10 );
	cameraDistanceInput->setFont( cameraDistanceInput_font ); 

	ScenePropertiesDialogLayout->addWidget( cameraDistanceInput, 1, 1 );

	viewDistanceInput = new QLineEdit( this, "viewDistanceInput" );
	QFont viewDistanceInput_font(  viewDistanceInput->font() );
	viewDistanceInput_font.setPointSize( 10 );
	viewDistanceInput->setFont( viewDistanceInput_font ); 

	ScenePropertiesDialogLayout->addWidget( viewDistanceInput, 0, 1 );

	buttonLayout = new QGridLayout( 0, 0, 6, "buttonLayout" );

	QSpacerItem* rightSpacer = new QSpacerItem( 10, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum );
	buttonLayout->addItem( rightSpacer, 0, 0 );
    QSpacerItem* leftSpacer = new QSpacerItem( 10, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum );
    buttonLayout->addItem( leftSpacer, 0, 3 );

	okButton = new QPushButton( this, "okButton" );
	okButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)4, (QSizePolicy::SizeType)0, 0, 0, okButton->sizePolicy().hasHeightForWidth() ) );

	buttonLayout->addWidget( okButton, 0, 1 );

    abortButton = new QPushButton( this, "abortButton" );
    abortButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)4, (QSizePolicy::SizeType)0, 0, 0, abortButton->sizePolicy().hasHeightForWidth() ) );

    buttonLayout->addWidget( abortButton, 0, 2 );

	ScenePropertiesDialogLayout->addMultiCellLayout( buttonLayout, 5, 5, 0, 1 );

	//connecting
	connect( okButton, SIGNAL( clicked() ), this, SLOT( accept() ) );
	connect( abortButton, SIGNAL( clicked() ), this, SLOT( reject() ) );

	languageChange();
	resize( QSize(300, 150).expandedTo(minimumSizeHint()) );
	clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ScenePropertiesDialog::~ScenePropertiesDialog()
{
	// no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ScenePropertiesDialog::languageChange()
{
	setCaption( tr( "General Scene Properties" ) );
	worldDimension1Title->setText( tr( "Near Clipping Range" ) );
	worldDimension2Title->setText( tr( "Far Clipping Range" ) );
	viewDistanceTitle->setText( tr( "View Distance" ) );
	cameraDistanceTitle->setText( tr( "Camera Distance" ) );
	okButton->setText( tr( "OK" ) );
	abortButton->setText( tr( "Cancel" ) );
	QWhatsThis::add( worldDimension1Title, tr( "Distance to the camera wherefrom DirectX begins to draw the scene" ) );
	QWhatsThis::add( worldDimension2Title, tr( "Distance to the camera where DirectX stops to to draw the scene " ) );
	QWhatsThis::add( viewDistanceTitle, tr( "The view distance defines how far you can look. A higher view distance "
											"will result in buildings appearing much earlier and a bigger skyline, but "
											"may slow down the game." ) );
	QWhatsThis::add( cameraDistanceTitle, tr( "The camera distance defines the distance between the camera and Tommy." ) );
}

/*
 *	Accept function
 *	This function is called when the user clicks OK
 */

void ScenePropertiesDialog::accept()
{
	sceneWrapper->SetViewDist( viewDistanceInput->text().toFloat() );
	sceneWrapper->SetCamDist( cameraDistanceInput->text().toFloat() );
	sceneWrapper->SetWorldDim( worldDimension1Input->text().toFloat(), worldDimension2Input->text().toFloat() );

	QDialog::accept();

	status_bar->message( tr( "General scene properties set." ), 3000 );
}

/*
 *	Show function
 *	This function shows the dialog and sets the input fields
 */

void ScenePropertiesDialog::show()
{
	viewDistanceInput->setText( QString::number( sceneWrapper->GetViewDist() ) );
	cameraDistanceInput->setText( QString::number( sceneWrapper->GetCamDist() ) );
	worldDimension1Input->setText( QString::number( sceneWrapper->GetWorldDim( TRUE ) ) );
	worldDimension2Input->setText( QString::number( sceneWrapper->GetWorldDim( FALSE ) ) );

	QDialog::show();
}