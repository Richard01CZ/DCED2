/****************************************************************************
** Form implementation generated from reading ui file 'objectpreview.ui'
**
** Created: Mi 21. Jan 23:24:52 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.2.1   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "objectpreview.h"

#include <qapp.h>
#include <qframe.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qpushbutton.h>
#include <qtooltip.h>
#include <qvariant.h>
#include <qwhatsthis.h>
#include "img/rotX.xpm"

/*
 *  Constructs a ObjectPreview as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ObjectPreview::ObjectPreview( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ObjectPreview" );
    ObjectPreviewLayout = new QGridLayout( this, 1, 1, 10, 0, "ObjectPreviewLayout"); 

    layout1 = new QHBoxLayout( 0, 0, 0, "layout1"); 
    QSpacerItem* spacer = new QSpacerItem( 500, 31, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout1->addItem( spacer );

    changeButton = new QPushButton( this, "changeButton" );
    layout1->addWidget( changeButton );

    ObjectPreviewLayout->addLayout( layout1, 4, 0 );

    translationBox = new QGroupBox( this, "translationBox" );
    translationBox->setMinimumSize( QSize( 0, 195 ) );
    translationBox->setMaximumSize( QSize( 32767, 195 ) );
    QFont translationBox_font(  translationBox->font() );
    translationBox_font.setFamily( "Arial" );
    translationBox_font.setPointSize( 12 );
    translationBox_font.setBold( TRUE );
    translationBox->setFont( translationBox_font ); 
	translationBox->setFrameStyle( QFrame::NoFrame );

    scalingTitleLabel = new QLabel( translationBox, "scalingTitleLabel" );
    scalingTitleLabel->setGeometry( QRect( 20, 100, 101, 21 ) );
    QFont scalingTitleLabel_font(  scalingTitleLabel->font() );
    scalingTitleLabel_font.setPointSize( 10 );
    scalingTitleLabel->setFont( scalingTitleLabel_font ); 

    rotationTitleLabel = new QLabel( translationBox, "rotationTitleLabel" );
    rotationTitleLabel->setGeometry( QRect( 0, 59, 101, 22 ) );
    QFont rotationTitleLabel_font(  rotationTitleLabel->font() );
    rotationTitleLabel_font.setPointSize( 10 );
    rotationTitleLabel->setFont( rotationTitleLabel_font ); 

    positionTitleLabel = new QLabel( translationBox, "positionTitleLabel" );
    positionTitleLabel->setGeometry( QRect( 20, 20, 101, 21 ) );
    QFont positionTitleLabel_font(  positionTitleLabel->font() );
    positionTitleLabel_font.setPointSize( 10 );
    positionTitleLabel->setFont( positionTitleLabel_font ); 

    scalingValueLabel = new QLabel( translationBox, "scalingValueLabel" );
    scalingValueLabel->setGeometry( QRect( 30, 120, 270, 20 ) );
    QFont scalingValueLabel_font(  scalingValueLabel->font() );
    scalingValueLabel_font.setFamily( "MS Sans Serif" );
    scalingValueLabel_font.setPointSize( 8 );
    scalingValueLabel_font.setBold( FALSE );
    scalingValueLabel->setFont( scalingValueLabel_font ); 

    positionValueLabel = new QLabel( translationBox, "positionValueLabel" );
    positionValueLabel->setGeometry( QRect( 30, 40, 260, 20 ) );
    QFont positionValueLabel_font(  positionValueLabel->font() );
    positionValueLabel_font.setFamily( "MS Sans Serif" );
    positionValueLabel_font.setPointSize( 8 );
    positionValueLabel_font.setBold( FALSE );
    positionValueLabel->setFont( positionValueLabel_font ); 

    rotationValueLabel = new QLabel( translationBox, "rotationValueLabel" );
    rotationValueLabel->setGeometry( QRect( 30, 80, 270, 20 ) );
    QFont rotationValueLabel_font(  rotationValueLabel->font() );
    rotationValueLabel_font.setFamily( "MS Sans Serif" );
    rotationValueLabel_font.setPointSize( 8 );
    rotationValueLabel_font.setBold( FALSE );
    rotationValueLabel->setFont( rotationValueLabel_font ); 

    extraValueLabel = new QLabel( translationBox, "extraValueLabel" );
    extraValueLabel->setEnabled( TRUE );
    extraValueLabel->setGeometry( QRect( 30, 160, 270, 20 ) );
    QFont extraValueLabel_font(  extraValueLabel->font() );
    extraValueLabel_font.setFamily( "MS Sans Serif" );
    extraValueLabel_font.setPointSize( 8 );
    extraValueLabel_font.setBold( FALSE );
    extraValueLabel->setFont( extraValueLabel_font ); 

    extraTitleLabel = new QLabel( translationBox, "extraTitleLabel" );
    extraTitleLabel->setGeometry( QRect( 20, 140, 101, 21 ) );
    QFont extraTitleLabel_font(  extraTitleLabel->font() );
    extraTitleLabel_font.setPointSize( 10 );
    extraTitleLabel->setFont( extraTitleLabel_font ); 

    ObjectPreviewLayout->addWidget( translationBox, 1, 0 );

    objectNameLabel = new QLabel( this, "objectNameLabel" );
    QFont objectNameLabel_font(  objectNameLabel->font() );
    objectNameLabel_font.setFamily( "Arial" );
    objectNameLabel_font.setPointSize( 12 );
    objectNameLabel->setFont( objectNameLabel_font ); 
    objectNameLabel->setFrameShape( QLabel::TabWidgetPanel );
    objectNameLabel->setTextFormat( QLabel::RichText );

    ObjectPreviewLayout->addWidget( objectNameLabel, 0, 0 );
    QSpacerItem* spacer_2 = new QSpacerItem( 31, 60, QSizePolicy::Minimum, QSizePolicy::Expanding );
    ObjectPreviewLayout->addItem( spacer_2, 3, 0 );

    additionalBox = new QGroupBox( this, "additionalBox" );
    additionalBox->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)4, 0, 0, additionalBox->sizePolicy().hasHeightForWidth() ) );
    additionalBox->setMinimumSize( QSize( 0, 105 ) );
    additionalBox->setMaximumSize( QSize( 32767, 32767 ) );
    QFont additionalBox_font(  additionalBox->font() );
    additionalBox_font.setFamily( "Arial" );
    additionalBox_font.setPointSize( 12 );
    additionalBox_font.setBold( TRUE );
    additionalBox->setFont( additionalBox_font ); 
    additionalBox->setColumnLayout(0, Qt::Vertical );
    additionalBox->layout()->setSpacing( 0 );
    additionalBox->layout()->setMargin( 10 );
    additionalBoxLayout = new QVBoxLayout( additionalBox->layout() );
    additionalBoxLayout->setAlignment( Qt::AlignTop );
	additionalBox->setFrameStyle( QFrame::NoFrame );

    modelFrame = new QFrame( additionalBox, "modelFrame" );
    modelFrame->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, modelFrame->sizePolicy().hasHeightForWidth() ) );
    modelFrame->setFrameShape( QFrame::StyledPanel );
    modelFrame->setFrameShadow( QFrame::Raised );

    modelValueLabel = new QLabel( modelFrame, "modelValueLabel" );
    modelValueLabel->setGeometry( QRect( 20, 21, 540, 20 ) );
    QFont modelValueLabel_font(  modelValueLabel->font() );
    modelValueLabel_font.setFamily( "MS Sans Serif" );
    modelValueLabel_font.setPointSize( 8 );
    modelValueLabel_font.setBold( FALSE );
    modelValueLabel->setFont( modelValueLabel_font ); 

    modelTitleLabel = new QLabel( modelFrame, "modelTitleLabel" );
    modelTitleLabel->setGeometry( QRect( 10, 1, 542, 20 ) );
    QFont modelTitleLabel_font(  modelTitleLabel->font() );
    modelTitleLabel_font.setPointSize( 10 );
    modelTitleLabel->setFont( modelTitleLabel_font ); 
    additionalBoxLayout->addWidget( modelFrame );

    sectorFrame = new QFrame( additionalBox, "sectorFrame" );
    sectorFrame->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, sectorFrame->sizePolicy().hasHeightForWidth() ) );
    sectorFrame->setFrameShape( QFrame::StyledPanel );
    sectorFrame->setFrameShadow( QFrame::Raised );

    sectorTitleLabel = new QLabel( sectorFrame, "sectorTitleLabel" );
    sectorTitleLabel->setGeometry( QRect( 10, 0, 548, 20 ) );
    QFont sectorTitleLabel_font(  sectorTitleLabel->font() );
    sectorTitleLabel_font.setPointSize( 10 );
    sectorTitleLabel->setFont( sectorTitleLabel_font ); 

    sectorValueLabel = new QLabel( sectorFrame, "sectorValueLabel" );
    sectorValueLabel->setGeometry( QRect( 20, 20, 540, 20 ) );
    QFont sectorValueLabel_font(  sectorValueLabel->font() );
    sectorValueLabel_font.setFamily( "MS Sans Serif" );
    sectorValueLabel_font.setPointSize( 8 );
    sectorValueLabel_font.setBold( FALSE );
    sectorValueLabel->setFont( sectorValueLabel_font ); 
    additionalBoxLayout->addWidget( sectorFrame );

    ObjectPreviewLayout->addWidget( additionalBox, 2, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
	clearWState( WState_Polished );


	// signals and slots connections
	connect( changeButton, SIGNAL( clicked() ), this, SLOT( changeObject() ) );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ObjectPreview::~ObjectPreview()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *	This is the slot that opens the ObjectWidget widget to
 *  edit an object.
 */
void ObjectPreview::changeObject()
{
	emit editObject( inputFields );
	hide();
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ObjectPreview::languageChange()
{
    setCaption( tr( "ObjectPreview" ) );
    changeButton->setText( tr( "Change" ) );
    translationBox->setTitle( tr( "Translation" ) );
    scalingTitleLabel->setText( tr( "Scaling:" ) );
    rotationTitleLabel->setPixmap( QPixmap( rotX_xpm ) );//Text( tr( "Rotation:" ) );
    positionTitleLabel->setText( tr( "Position:" ) );
    scalingValueLabel->setText( tr( "X = 0; Y = 0; Z = 0" ) );
    positionValueLabel->setText( tr( "X = 0; Y = 0; Z = 0" ) );
    rotationValueLabel->setText( trUtf8( "\x58\x2f\x59\x20\x3d\x20\x30\xc2\xb0\x3b\x20\x58\x2f\x5a\x20\x3d\x20\x30\xc2\xb0\x3b\x20\x59\x2f\x5a\x20\x3d\x20\x30\xc2\xb0" ) );
    extraValueLabel->setText( tr( "X = 0; Y = 0; Z = 0" ) );
    extraTitleLabel->setText( tr( "Extra:" ) );
    objectNameLabel->setText( tr( "<b>No object selected</b>" ) );
    additionalBox->setTitle( tr( "Additional" ) );
    modelValueLabel->setText( tr( "none" ) );
    modelTitleLabel->setText( tr( "Model:" ) );
    sectorTitleLabel->setText( tr( "Sector:" ) );
    sectorValueLabel->setText( tr( "none" ) );
}

void ObjectPreview::setInputFields( ObjectInfo_t * currentObject )
{
	delete inputFields;
	qApp->processEvents();
	inputFields = currentObject;

	objectNameLabel->setText( tr( "<b>Object </b>") + QString( currentObject->sName ) );
	objectNameLabel->update();

	bool hasAdditional = false;
	int additionalHeight = 30; //It is set to 20 because margin top = 15 and margin bottom = 15.

	positionValueLabel->setText( "X = " + QString::number( currentObject->fPos[1] ) +
								"; Y = " + QString::number( currentObject->fPos[2] ) +
								"; Z = " + QString::number( currentObject->fPos[3] )+ ";" );

	rotationValueLabel->setText( "X = " + QString::number( CHelper::XYRot2Angle( currentObject->fRot[4] ) ) + "°" +
								"; Y = " + QString::number( CHelper::XYRot2Angle( currentObject->fRot[2] ) ) + "°" +
								"; Z = " + QString::number( CHelper::ZRot2Angle( currentObject->fRot[1] ) ) + "°;" );

	scalingValueLabel->setText( "X = " + QString::number( currentObject->fSize[1] ) +
								"; Y = " + QString::number( currentObject->fSize[2] ) +
								"; Z = " + QString::number( currentObject->fSize[3] ) + ";" );

	if( currentObject->bUseModel == true )
	{
		modelValueLabel->setText( QString( currentObject->sModelName ) );
		modelFrame->show();
		hasAdditional = true;
		additionalHeight += 38;
	}
	else
		modelFrame->hide();

	if( currentObject->sSectorName != 0 && currentObject->sSectorName != "" )
	{
		sectorValueLabel->setText( QString( currentObject->sSectorName ) );
		sectorFrame->show();
		hasAdditional = true;
		additionalHeight += 37;
	}
	else
		sectorFrame->hide();

	if( hasAdditional = false )
		additionalBox->hide();
	else
	{
		additionalBox->show();
		additionalBox->setMinimumHeight( additionalHeight );
	}
}
