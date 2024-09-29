/****************************************************************************
** Form implementation generated from reading ui file 'objectwidget.ui'
**
** Created: Mi 30. Jun 17:21:21 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.2.3   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "objectwidget.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qframe.h>
#include <qcheckbox.h>
#include <qcombobox.h>
#include <qlistbox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

/*
 *  Constructs a ObjectWidget as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ObjectWidget::ObjectWidget( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl ),
      image0( (const char **) image0_data ),
      image1( (const char **) image1_data ),
      image2( (const char **) image2_data ),
      image3( (const char **) image3_data ),
      image4( (const char **) image4_data ),
      image5( (const char **) image5_data ),
      image6( (const char **) image6_data ),
      image7( (const char **) image7_data ),
      image8( (const char **) image8_data ),
      image9( (const char **) image9_data )
{
    if ( !name )
	setName( "ObjectWidget" );
    ObjectWidgetLayout = new QGridLayout( this, 1, 1, 8, 7, "ObjectWidgetLayout"); 

    positionGroupBox = new QGroupBox( this, "positionGroupBox" );
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
    positionXTitle->setPixmap( image0 );
    positionXLayout->addWidget( positionXTitle );

    positionXInput = new QLineEdit( positionGroupBox, "positionXInput" );
    positionXInput->setEnabled( TRUE );
    QFont positionXInput_font(  positionXInput->font() );
    positionXInput_font.setPointSize( 10 );
    positionXInput->setFont( positionXInput_font ); 
    positionXInput->setFrameShape( QLineEdit::LineEditPanel );
    positionXInput->setFrameShadow( QLineEdit::Sunken );
    positionXLayout->addWidget( positionXInput );
    positionGroupBoxLayout->addLayout( positionXLayout );

    positionYLayout = new QHBoxLayout( 0, 0, 5, "positionYLayout"); 

    positionYTitle = new QLabel( positionGroupBox, "positionYTitle" );
    positionYTitle->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, positionYTitle->sizePolicy().hasHeightForWidth() ) );
    positionYTitle->setFrameShape( QLabel::Box );
    positionYTitle->setPixmap( image1 );
    positionYLayout->addWidget( positionYTitle );

    positionYInput = new QLineEdit( positionGroupBox, "positionYInput" );
    positionYInput->setEnabled( TRUE );
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
    positionZTitle->setPixmap( image2 );
    positionZLayout->addWidget( positionZTitle );

    positionZInput = new QLineEdit( positionGroupBox, "positionZInput" );
    positionZInput->setEnabled( TRUE );
    QFont positionZInput_font(  positionZInput->font() );
    positionZInput_font.setPointSize( 10 );
    positionZInput->setFont( positionZInput_font ); 
    positionZInput->setFrameShape( QLineEdit::LineEditPanel );
    positionZLayout->addWidget( positionZInput );
    positionGroupBoxLayout->addLayout( positionZLayout );

    ObjectWidgetLayout->addWidget( positionGroupBox, 1, 0 );

    rotationGroupBox = new QGroupBox( this, "rotationGroupBox" );
    rotationGroupBox->setEnabled( TRUE );
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
    rotationXTitle->setPixmap( image3 );
    rotationXLayout->addWidget( rotationXTitle );

    rotationXInput = new QLineEdit( rotationGroupBox, "rotationXInput" );
    rotationXInput->setEnabled( TRUE );
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
    rotationYTitle->setPixmap( image4 );
    rotationYLayout->addWidget( rotationYTitle );

    rotationYInput = new QLineEdit( rotationGroupBox, "rotationYInput" );
    rotationYInput->setEnabled( TRUE );
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
    rotationZTitle->setPixmap( image5 );
    rotationZLayout->addWidget( rotationZTitle );

    rotationZInput = new QLineEdit( rotationGroupBox, "rotationZInput" );
    rotationZInput->setEnabled( TRUE );
    QFont rotationZInput_font(  rotationZInput->font() );
    rotationZInput_font.setPointSize( 10 );
    rotationZInput->setFont( rotationZInput_font ); 
    rotationZInput->setFrameShape( QLineEdit::LineEditPanel );
    rotationZLayout->addWidget( rotationZInput );
    rotationGroupBoxLayout->addLayout( rotationZLayout );

    ObjectWidgetLayout->addWidget( rotationGroupBox, 1, 1 );

    scalingGroupBox = new QGroupBox( this, "scalingGroupBox" );
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
    scalingXTitle->setPixmap( image6 );
    scalingXLayout->addWidget( scalingXTitle );

    scalingXInput = new QLineEdit( scalingGroupBox, "scalingXInput" );
    scalingXInput->setEnabled( TRUE );
    QFont scalingXInput_font(  scalingXInput->font() );
    scalingXInput_font.setPointSize( 10 );
    scalingXInput->setFont( scalingXInput_font ); 
    scalingXInput->setFrameShape( QLineEdit::LineEditPanel );
    scalingXLayout->addWidget( scalingXInput );
    scalingGroupBoxLayout->addLayout( scalingXLayout );

    scalingYLayout = new QHBoxLayout( 0, 0, 5, "scalingYLayout"); 

    scalingYTitle = new QLabel( scalingGroupBox, "scalingYTitle" );
    scalingYTitle->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, scalingYTitle->sizePolicy().hasHeightForWidth() ) );
    scalingYTitle->setMinimumSize( QSize( 34, 34 ) );
    scalingYTitle->setFrameShape( QLabel::Box );
    scalingYTitle->setPixmap( image7 );
    scalingYLayout->addWidget( scalingYTitle );

    scalingYInput = new QLineEdit( scalingGroupBox, "scalingYInput" );
    scalingYInput->setEnabled( TRUE );
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
    scalingZTitle->setPixmap( image8 );
    scalingZLayout->addWidget( scalingZTitle );

    scalingZInput = new QLineEdit( scalingGroupBox, "scalingZInput" );
    scalingZInput->setEnabled( TRUE );
    QFont scalingZInput_font(  scalingZInput->font() );
    scalingZInput_font.setPointSize( 10 );
    scalingZInput->setFont( scalingZInput_font ); 
    scalingZInput->setFrameShape( QLineEdit::LineEditPanel );
    scalingZInput->setFrameShadow( QLineEdit::Sunken );
    scalingZLayout->addWidget( scalingZInput );
    scalingGroupBoxLayout->addLayout( scalingZLayout );

    ObjectWidgetLayout->addWidget( scalingGroupBox, 1, 2 );

    additionalBox = new QGroupBox( this, "additionalBox" );
    additionalBox->setColumnLayout(0, Qt::Vertical );
    additionalBox->layout()->setSpacing( 1 );
    additionalBox->layout()->setMargin( 7 );
    additionalBoxLayout = new QVBoxLayout( additionalBox->layout() );
    additionalBoxLayout->setAlignment( Qt::AlignTop );

    additionalXLayout = new QHBoxLayout( 0, 0, 5, "additionalXLayout"); 

    additionalXTitle = new QLabel( additionalBox, "additionalXTitle" );
    additionalXTitle->setFrameShape( QLabel::Box );
    additionalXTitle->setPixmap( image9 );
    additionalXLayout->addWidget( additionalXTitle );

    additionalXInput = new QLineEdit( additionalBox, "additionalXInput" );
    QFont additionalXInput_font(  additionalXInput->font() );
    additionalXInput_font.setPointSize( 10 );
    additionalXInput->setFont( additionalXInput_font ); 
    additionalXLayout->addWidget( additionalXInput );
    additionalBoxLayout->addLayout( additionalXLayout );

    additionalYLayout = new QHBoxLayout( 0, 0, 5, "additionalYLayout"); 

    additionalYTitle = new QLabel( additionalBox, "additionalYTitle" );
    additionalYTitle->setFrameShape( QLabel::Box );
    additionalYTitle->setPixmap( image9 );
    additionalYLayout->addWidget( additionalYTitle );

    additionalYInput = new QLineEdit( additionalBox, "additionalYInput" );
    QFont additionalYInput_font(  additionalYInput->font() );
    additionalYInput_font.setPointSize( 10 );
    additionalYInput->setFont( additionalYInput_font ); 
    additionalYLayout->addWidget( additionalYInput );
    additionalBoxLayout->addLayout( additionalYLayout );

    additionalZLayout = new QHBoxLayout( 0, 0, 5, "additionalZLayout"); 

    additionalZTitle = new QLabel( additionalBox, "additionalZTitle" );
    additionalZTitle->setFrameShape( QLabel::Box );
    additionalZTitle->setPixmap( image9 );
    additionalZLayout->addWidget( additionalZTitle );

    additionalZInput = new QLineEdit( additionalBox, "additionalZInput" );
    QFont additionalZInput_font(  additionalZInput->font() );
    additionalZInput_font.setPointSize( 10 );
    additionalZInput->setFont( additionalZInput_font ); 
    additionalZLayout->addWidget( additionalZInput );
    additionalBoxLayout->addLayout( additionalZLayout );

    ObjectWidgetLayout->addWidget( additionalBox, 1, 3 );

    objectTitleLayout = new QHBoxLayout( 0, 0, 0, "objectTitleLayout"); 

    objectNameTitle = new QLabel( this, "objectNameTitle" );
    objectNameTitle->setMinimumSize( QSize( 0, 23 ) );
    objectNameTitle->setMaximumSize( QSize( 80, 23 ) );
    QFont objectNameTitle_font(  objectNameTitle->font() );
    objectNameTitle_font.setFamily( "Arial" );
    objectNameTitle_font.setPointSize( 12 );
    objectNameTitle_font.setBold( TRUE );
    objectNameTitle->setFont( objectNameTitle_font ); 
    objectNameTitle->setMargin( 2 );
    objectTitleLayout->addWidget( objectNameTitle );

    objectNameInput = new QLineEdit( this, "objectNameInput" );
    objectNameInput->setEnabled( TRUE );
    objectNameInput->setMinimumSize( QSize( 0, 23 ) );
    objectNameInput->setMaximumSize( QSize( 32767, 23 ) );
    QFont objectNameInput_font(  objectNameInput->font() );
    objectNameInput_font.setFamily( "Arial" );
    objectNameInput_font.setPointSize( 12 );
    objectNameInput->setFont( objectNameInput_font ); 
    objectNameInput->setFrameShape( QLineEdit::LineEditPanel );
    objectNameInput->setFrameShadow( QLineEdit::Sunken );
    objectNameInput->setFrame( TRUE );
    objectTitleLayout->addWidget( objectNameInput );

    ObjectWidgetLayout->addMultiCellLayout( objectTitleLayout, 0, 0, 0, 3 );

    helpTextEdit = new QTextEdit( this, "helpTextEdit" );
    helpTextEdit->setWordWrap( QTextEdit::WidgetWidth );
    helpTextEdit->setReadOnly( TRUE );
    helpTextEdit->setUndoRedoEnabled( FALSE );

    ObjectWidgetLayout->addMultiCellWidget( helpTextEdit, 5, 5, 0, 3 );

    lightFrame = new QFrame( this, "lightFrame" );
    lightFrame->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, lightFrame->sizePolicy().hasHeightForWidth() ) );
    lightFrame->setMinimumSize( QSize( 0, 290 ) );
    lightFrame->setFrameShape( QFrame::NoFrame );
    lightFrame->setFrameShadow( QFrame::Plain );
    lightFrameLayout = new QHBoxLayout( lightFrame, 0, 5, "lightFrameLayout"); 

    lightColorBox = new QGroupBox( lightFrame, "lightColorBox" );
    lightColorBox->setMinimumSize( QSize( 250, 287 ) );
    lightFrameLayout->addWidget( lightColorBox );

    layout25 = new QVBoxLayout( 0, 0, 5, "layout25"); 

    lightFlagBox = new QGroupBox( lightFrame, "lightFlagBox" );
    lightFlagBox->setColumnLayout(0, Qt::Vertical );
    lightFlagBox->layout()->setSpacing( 5 );
    lightFlagBox->layout()->setMargin( 7 );
    lightFlagBoxLayout = new QGridLayout( lightFlagBox->layout() );
    lightFlagBoxLayout->setAlignment( Qt::AlignTop );

    flag4CheckBox = new QCheckBox( lightFlagBox, "flag4CheckBox" );

    lightFlagBoxLayout->addWidget( flag4CheckBox, 3, 0 );

    flag3CheckBox = new QCheckBox( lightFlagBox, "flag3CheckBox" );

    lightFlagBoxLayout->addWidget( flag3CheckBox, 2, 0 );

    flag2CheckBox = new QCheckBox( lightFlagBox, "flag2CheckBox" );

    lightFlagBoxLayout->addWidget( flag2CheckBox, 1, 0 );

    flag1CheckBox = new QCheckBox( lightFlagBox, "flag1CheckBox" );

    lightFlagBoxLayout->addWidget( flag1CheckBox, 0, 0 );

    flag8CheckBox = new QCheckBox( lightFlagBox, "flag8CheckBox" );

    lightFlagBoxLayout->addWidget( flag8CheckBox, 7, 0 );

    flag6CheckBox = new QCheckBox( lightFlagBox, "flag6CheckBox" );

    lightFlagBoxLayout->addWidget( flag6CheckBox, 5, 0 );

    flag5CheckBox = new QCheckBox( lightFlagBox, "flag5CheckBox" );

    lightFlagBoxLayout->addWidget( flag5CheckBox, 4, 0 );

    flag7CheckBox = new QCheckBox( lightFlagBox, "flag7CheckBox" );

    lightFlagBoxLayout->addWidget( flag7CheckBox, 6, 0 );
    layout25->addWidget( lightFlagBox );

    lightRangeBox = new QGroupBox( lightFrame, "lightRangeBox" );
    lightRangeBox->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)4, (QSizePolicy::SizeType)5, 0, 0, lightRangeBox->sizePolicy().hasHeightForWidth() ) );
    lightRangeBox->setColumnLayout(0, Qt::Vertical );
    lightRangeBox->layout()->setSpacing( 5 );
    lightRangeBox->layout()->setMargin( 7 );
    lightRangeBoxLayout = new QGridLayout( lightRangeBox->layout() );
    lightRangeBoxLayout->setAlignment( Qt::AlignTop );

    nearRangeTitle = new QLabel( lightRangeBox, "nearRangeTitle" );

    lightRangeBoxLayout->addWidget( nearRangeTitle, 0, 0 );

    farRangeTitle = new QLabel( lightRangeBox, "farRangeTitle" );

    lightRangeBoxLayout->addWidget( farRangeTitle, 1, 0 );

    nearRangeInput = new QLineEdit( lightRangeBox, "nearRangeInput" );

    lightRangeBoxLayout->addWidget( nearRangeInput, 0, 1 );

    farRangeInput = new QLineEdit( lightRangeBox, "farRangeInput" );

    lightRangeBoxLayout->addWidget( farRangeInput, 1, 1 );
    layout25->addWidget( lightRangeBox );
    lightFrameLayout->addLayout( layout25 );

    layout26 = new QVBoxLayout( 0, 0, 5, "layout26"); 

    lightSectorBox = new QGroupBox( lightFrame, "lightSectorBox" );
    lightSectorBox->setColumnLayout(0, Qt::Vertical );
    lightSectorBox->layout()->setSpacing( 5 );
    lightSectorBox->layout()->setMargin( 7 );
    lightSectorBoxLayout = new QGridLayout( lightSectorBox->layout() );
    lightSectorBoxLayout->setAlignment( Qt::AlignTop );

    lightSectorComboBox = new QComboBox( FALSE, lightSectorBox, "lightSectorComboBox" );
    QFont lightSectorComboBox_font(  lightSectorComboBox->font() );
    lightSectorComboBox_font.setPointSize( 10 );
    lightSectorComboBox->setFont( lightSectorComboBox_font ); 
    lightSectorComboBox->setEditable( TRUE );
    lightSectorComboBox->setAutoCompletion( TRUE );
    lightSectorComboBox->setDuplicatesEnabled( FALSE );

    lightSectorBoxLayout->addMultiCellWidget( lightSectorComboBox, 0, 0, 0, 2 );

    lightSectorListBox = new QListBox( lightSectorBox, "lightSectorListBox" );

    lightSectorBoxLayout->addMultiCellWidget( lightSectorListBox, 1, 1, 0, 2 );

    addSectorButton = new QPushButton( lightSectorBox, "addSectorButton" );

    lightSectorBoxLayout->addWidget( addSectorButton, 2, 1 );

    removeSectorButton = new QPushButton( lightSectorBox, "removeSectorButton" );

    lightSectorBoxLayout->addWidget( removeSectorButton, 2, 2 );
    QSpacerItem* spacer = new QSpacerItem( 161, 21, QSizePolicy::Expanding, QSizePolicy::Minimum );
    lightSectorBoxLayout->addItem( spacer, 2, 0 );
    layout26->addWidget( lightSectorBox );

    lightOtherBox = new QGroupBox( lightFrame, "lightOtherBox" );
    lightOtherBox->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)4, 0, 0, lightOtherBox->sizePolicy().hasHeightForWidth() ) );
    lightOtherBox->setColumnLayout(0, Qt::Vertical );
    lightOtherBox->layout()->setSpacing( 5 );
    lightOtherBox->layout()->setMargin( 7 );
    lightOtherBoxLayout = new QGridLayout( lightOtherBox->layout() );
    lightOtherBoxLayout->setAlignment( Qt::AlignTop );

    lightTypeComboBox = new QComboBox( FALSE, lightOtherBox, "lightTypeComboBox" );
    lightTypeComboBox->setEditable( TRUE );
    lightTypeComboBox->setInsertionPolicy( QComboBox::NoInsertion );
    lightTypeComboBox->setAutoCompletion( TRUE );

    lightOtherBoxLayout->addWidget( lightTypeComboBox, 0, 1 );

    lightTypeTitle = new QLabel( lightOtherBox, "lightTypeTitle" );

    lightOtherBoxLayout->addWidget( lightTypeTitle, 0, 0 );

    lightPowerTitle = new QLabel( lightOtherBox, "lightPowerTitle" );

    lightOtherBoxLayout->addWidget( lightPowerTitle, 1, 0 );

    lightCone1Title = new QLabel( lightOtherBox, "lightCone1Title" );

    lightOtherBoxLayout->addWidget( lightCone1Title, 2, 0 );

    lightPowerInput = new QLineEdit( lightOtherBox, "lightPowerInput" );

    lightOtherBoxLayout->addWidget( lightPowerInput, 1, 1 );

    lightCone1Input = new QLineEdit( lightOtherBox, "lightCone1Input" );

    lightOtherBoxLayout->addWidget( lightCone1Input, 2, 1 );

    lightCone2Input = new QLineEdit( lightOtherBox, "lightCone2Input" );

    lightOtherBoxLayout->addWidget( lightCone2Input, 3, 1 );

    lightCone2Title = new QLabel( lightOtherBox, "lightCone2Title" );

    lightOtherBoxLayout->addWidget( lightCone2Title, 3, 0 );
    layout26->addWidget( lightOtherBox );
    lightFrameLayout->addLayout( layout26 );

    ObjectWidgetLayout->addMultiCellWidget( lightFrame, 4, 4, 0, 3 );

    sectorBox = new QGroupBox( this, "sectorBox" );
    sectorBox->setColumnLayout(0, Qt::Vertical );
    sectorBox->layout()->setSpacing( 5 );
    sectorBox->layout()->setMargin( 7 );
    sectorBoxLayout = new QGridLayout( sectorBox->layout() );
    sectorBoxLayout->setAlignment( Qt::AlignTop );

    sector22Title = new QLabel( sectorBox, "sector22Title" );

    sectorBoxLayout->addWidget( sector22Title, 0, 6 );

    sector25Title = new QLabel( sectorBox, "sector25Title" );

    sectorBoxLayout->addWidget( sector25Title, 3, 6 );

    sector26Title = new QLabel( sectorBox, "sector26Title" );

    sectorBoxLayout->addWidget( sector26Title, 4, 6 );

    sector23Title = new QLabel( sectorBox, "sector23Title" );

    sectorBoxLayout->addWidget( sector23Title, 1, 6 );

    sector26Input = new QLineEdit( sectorBox, "sector26Input" );
    QFont sector26Input_font(  sector26Input->font() );
    sector26Input_font.setPointSize( 10 );
    sector26Input->setFont( sector26Input_font ); 

    sectorBoxLayout->addWidget( sector26Input, 4, 7 );

    sector24Title = new QLabel( sectorBox, "sector24Title" );

    sectorBoxLayout->addWidget( sector24Title, 2, 6 );

    sector25Input = new QLineEdit( sectorBox, "sector25Input" );
    QFont sector25Input_font(  sector25Input->font() );
    sector25Input_font.setPointSize( 10 );
    sector25Input->setFont( sector25Input_font ); 

    sectorBoxLayout->addWidget( sector25Input, 3, 7 );

    sector22Input = new QLineEdit( sectorBox, "sector22Input" );
    QFont sector22Input_font(  sector22Input->font() );
    sector22Input_font.setPointSize( 10 );
    sector22Input->setFont( sector22Input_font ); 

    sectorBoxLayout->addWidget( sector22Input, 0, 7 );

    sector23Input = new QLineEdit( sectorBox, "sector23Input" );
    QFont sector23Input_font(  sector23Input->font() );
    sector23Input_font.setPointSize( 10 );
    sector23Input->setFont( sector23Input_font ); 

    sectorBoxLayout->addWidget( sector23Input, 1, 7 );

    sector24Input = new QLineEdit( sectorBox, "sector24Input" );
    QFont sector24Input_font(  sector24Input->font() );
    sector24Input_font.setPointSize( 10 );
    sector24Input->setFont( sector24Input_font ); 

    sectorBoxLayout->addWidget( sector24Input, 2, 7 );

    sector16Title = new QLabel( sectorBox, "sector16Title" );

    sectorBoxLayout->addWidget( sector16Title, 1, 4 );

    sector15Title = new QLabel( sectorBox, "sector15Title" );

    sectorBoxLayout->addWidget( sector15Title, 0, 4 );

    sector18Title = new QLabel( sectorBox, "sector18Title" );

    sectorBoxLayout->addWidget( sector18Title, 3, 4 );

    sector17Title = new QLabel( sectorBox, "sector17Title" );

    sectorBoxLayout->addWidget( sector17Title, 2, 4 );

    sector19Title = new QLabel( sectorBox, "sector19Title" );

    sectorBoxLayout->addWidget( sector19Title, 4, 4 );

    sector21Title = new QLabel( sectorBox, "sector21Title" );

    sectorBoxLayout->addWidget( sector21Title, 6, 4 );

    sector20Title = new QLabel( sectorBox, "sector20Title" );

    sectorBoxLayout->addWidget( sector20Title, 5, 4 );

    sector18Input = new QLineEdit( sectorBox, "sector18Input" );
    QFont sector18Input_font(  sector18Input->font() );
    sector18Input_font.setPointSize( 10 );
    sector18Input->setFont( sector18Input_font ); 

    sectorBoxLayout->addWidget( sector18Input, 3, 5 );

    sector16Input = new QLineEdit( sectorBox, "sector16Input" );
    QFont sector16Input_font(  sector16Input->font() );
    sector16Input_font.setPointSize( 10 );
    sector16Input->setFont( sector16Input_font ); 

    sectorBoxLayout->addWidget( sector16Input, 1, 5 );

    sector17Input = new QLineEdit( sectorBox, "sector17Input" );
    QFont sector17Input_font(  sector17Input->font() );
    sector17Input_font.setPointSize( 10 );
    sector17Input->setFont( sector17Input_font ); 

    sectorBoxLayout->addWidget( sector17Input, 2, 5 );

    sector15Input = new QLineEdit( sectorBox, "sector15Input" );
    QFont sector15Input_font(  sector15Input->font() );
    sector15Input_font.setPointSize( 10 );
    sector15Input->setFont( sector15Input_font ); 

    sectorBoxLayout->addWidget( sector15Input, 0, 5 );

    sector20Input = new QLineEdit( sectorBox, "sector20Input" );
    QFont sector20Input_font(  sector20Input->font() );
    sector20Input_font.setPointSize( 10 );
    sector20Input->setFont( sector20Input_font ); 

    sectorBoxLayout->addWidget( sector20Input, 5, 5 );

    sector21Input = new QLineEdit( sectorBox, "sector21Input" );
    QFont sector21Input_font(  sector21Input->font() );
    sector21Input_font.setPointSize( 10 );
    sector21Input->setFont( sector21Input_font ); 

    sectorBoxLayout->addWidget( sector21Input, 6, 5 );

    sector19Input = new QLineEdit( sectorBox, "sector19Input" );
    QFont sector19Input_font(  sector19Input->font() );
    sector19Input_font.setPointSize( 10 );
    sector19Input->setFont( sector19Input_font ); 

    sectorBoxLayout->addWidget( sector19Input, 4, 5 );

    sector9Title = new QLabel( sectorBox, "sector9Title" );

    sectorBoxLayout->addWidget( sector9Title, 1, 2 );

    sector13Title = new QLabel( sectorBox, "sector13Title" );

    sectorBoxLayout->addWidget( sector13Title, 5, 2 );

    sector8Title = new QLabel( sectorBox, "sector8Title" );

    sectorBoxLayout->addWidget( sector8Title, 0, 2 );

    sector10Title = new QLabel( sectorBox, "sector10Title" );

    sectorBoxLayout->addWidget( sector10Title, 2, 2 );

    sector14Title = new QLabel( sectorBox, "sector14Title" );

    sectorBoxLayout->addWidget( sector14Title, 6, 2 );

    sector11Title = new QLabel( sectorBox, "sector11Title" );

    sectorBoxLayout->addWidget( sector11Title, 3, 2 );

    sector12Title = new QLabel( sectorBox, "sector12Title" );

    sectorBoxLayout->addWidget( sector12Title, 4, 2 );

    sector12Input = new QLineEdit( sectorBox, "sector12Input" );
    QFont sector12Input_font(  sector12Input->font() );
    sector12Input_font.setPointSize( 10 );
    sector12Input->setFont( sector12Input_font ); 

    sectorBoxLayout->addWidget( sector12Input, 4, 3 );

    sector10Input = new QLineEdit( sectorBox, "sector10Input" );
    QFont sector10Input_font(  sector10Input->font() );
    sector10Input_font.setPointSize( 10 );
    sector10Input->setFont( sector10Input_font ); 

    sectorBoxLayout->addWidget( sector10Input, 2, 3 );

    sector9Input = new QLineEdit( sectorBox, "sector9Input" );
    QFont sector9Input_font(  sector9Input->font() );
    sector9Input_font.setPointSize( 10 );
    sector9Input->setFont( sector9Input_font ); 

    sectorBoxLayout->addWidget( sector9Input, 1, 3 );

    sector13Input = new QLineEdit( sectorBox, "sector13Input" );
    QFont sector13Input_font(  sector13Input->font() );
    sector13Input_font.setPointSize( 10 );
    sector13Input->setFont( sector13Input_font ); 

    sectorBoxLayout->addWidget( sector13Input, 5, 3 );

    sector14Input = new QLineEdit( sectorBox, "sector14Input" );
    QFont sector14Input_font(  sector14Input->font() );
    sector14Input_font.setPointSize( 10 );
    sector14Input->setFont( sector14Input_font ); 

    sectorBoxLayout->addWidget( sector14Input, 6, 3 );

    sector11Input = new QLineEdit( sectorBox, "sector11Input" );
    QFont sector11Input_font(  sector11Input->font() );
    sector11Input_font.setPointSize( 10 );
    sector11Input->setFont( sector11Input_font ); 

    sectorBoxLayout->addWidget( sector11Input, 3, 3 );

    sector8Input = new QLineEdit( sectorBox, "sector8Input" );
    QFont sector8Input_font(  sector8Input->font() );
    sector8Input_font.setPointSize( 10 );
    sector8Input->setFont( sector8Input_font ); 

    sectorBoxLayout->addWidget( sector8Input, 0, 3 );

    sector2Title = new QLabel( sectorBox, "sector2Title" );

    sectorBoxLayout->addWidget( sector2Title, 1, 0 );

    sector4Title = new QLabel( sectorBox, "sector4Title" );

    sectorBoxLayout->addWidget( sector4Title, 3, 0 );

    sector1Title = new QLabel( sectorBox, "sector1Title" );

    sectorBoxLayout->addWidget( sector1Title, 0, 0 );

    sector7Title = new QLabel( sectorBox, "sector7Title" );

    sectorBoxLayout->addWidget( sector7Title, 6, 0 );

    sector5Title = new QLabel( sectorBox, "sector5Title" );

    sectorBoxLayout->addWidget( sector5Title, 4, 0 );

    sector6Title = new QLabel( sectorBox, "sector6Title" );

    sectorBoxLayout->addWidget( sector6Title, 5, 0 );

    sector4Input = new QLineEdit( sectorBox, "sector4Input" );
    QFont sector4Input_font(  sector4Input->font() );
    sector4Input_font.setPointSize( 10 );
    sector4Input->setFont( sector4Input_font ); 

    sectorBoxLayout->addWidget( sector4Input, 3, 1 );

    sector1Input = new QLineEdit( sectorBox, "sector1Input" );
    QFont sector1Input_font(  sector1Input->font() );
    sector1Input_font.setPointSize( 10 );
    sector1Input->setFont( sector1Input_font ); 

    sectorBoxLayout->addWidget( sector1Input, 0, 1 );

    sector5Input = new QLineEdit( sectorBox, "sector5Input" );
    QFont sector5Input_font(  sector5Input->font() );
    sector5Input_font.setPointSize( 10 );
    sector5Input->setFont( sector5Input_font ); 

    sectorBoxLayout->addWidget( sector5Input, 4, 1 );

    sector3Title = new QLabel( sectorBox, "sector3Title" );

    sectorBoxLayout->addWidget( sector3Title, 2, 0 );

    sector7Input = new QLineEdit( sectorBox, "sector7Input" );
    QFont sector7Input_font(  sector7Input->font() );
    sector7Input_font.setPointSize( 10 );
    sector7Input->setFont( sector7Input_font ); 

    sectorBoxLayout->addWidget( sector7Input, 6, 1 );

    sector2Input = new QLineEdit( sectorBox, "sector2Input" );
    QFont sector2Input_font(  sector2Input->font() );
    sector2Input_font.setPointSize( 10 );
    sector2Input->setFont( sector2Input_font ); 

    sectorBoxLayout->addWidget( sector2Input, 1, 1 );

    sector3Input = new QLineEdit( sectorBox, "sector3Input" );
    QFont sector3Input_font(  sector3Input->font() );
    sector3Input_font.setPointSize( 10 );
    sector3Input->setFont( sector3Input_font ); 

    sectorBoxLayout->addWidget( sector3Input, 2, 1 );

    sector6Input = new QLineEdit( sectorBox, "sector6Input" );
    QFont sector6Input_font(  sector6Input->font() );
    sector6Input_font.setPointSize( 10 );
    sector6Input->setFont( sector6Input_font ); 

    sectorBoxLayout->addWidget( sector6Input, 5, 1 );

    ObjectWidgetLayout->addMultiCellWidget( sectorBox, 3, 3, 0, 3 );

    layout18 = new QHBoxLayout( 0, 0, 7, "layout18"); 

    extraBox = new QGroupBox( this, "extraBox" );
    extraBox->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)4, 0, 0, extraBox->sizePolicy().hasHeightForWidth() ) );
    extraBox->setMinimumSize( QSize( 0, 0 ) );
    extraBox->setMaximumSize( QSize( 32767, 32767 ) );
    extraBox->setColumnLayout(0, Qt::Vertical );
    extraBox->layout()->setSpacing( 4 );
    extraBox->layout()->setMargin( 7 );
    extraBoxLayout = new QVBoxLayout( extraBox->layout() );
    extraBoxLayout->setAlignment( Qt::AlignTop );

    modelFrame = new QFrame( extraBox, "modelFrame" );
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

    modelInputLayout = new QHBoxLayout( 0, 0, 0, "modelInputLayout"); 
    QSpacerItem* spacer_2 = new QSpacerItem( 10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    modelInputLayout->addItem( spacer_2 );

    modelCheckBox = new QCheckBox( modelFrame, "modelCheckBox" );
    modelInputLayout->addWidget( modelCheckBox );

    modelLineEdit = new QLineEdit( modelFrame, "modelLineEdit" );
    modelLineEdit->setEnabled( FALSE );
    modelLineEdit->setPaletteForegroundColor( QColor( 0, 0, 0 ) );
    modelLineEdit->setFrameShape( QLineEdit::LineEditPanel );
    modelInputLayout->addWidget( modelLineEdit );
    modelFrameLayout->addLayout( modelInputLayout );
    extraBoxLayout->addWidget( modelFrame );

    sectorFrame = new QFrame( extraBox, "sectorFrame" );
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

    sectorInputLayout = new QHBoxLayout( 0, 0, 0, "sectorInputLayout"); 
    QSpacerItem* spacer_3 = new QSpacerItem( 10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    sectorInputLayout->addItem( spacer_3 );

    sectorCheckBox = new QCheckBox( sectorFrame, "sectorCheckBox" );
    sectorInputLayout->addWidget( sectorCheckBox );

    sectorComboBox = new QComboBox( FALSE, sectorFrame, "sectorComboBox" );
    sectorComboBox->setEnabled( FALSE );
    sectorComboBox->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, sectorComboBox->sizePolicy().hasHeightForWidth() ) );
    sectorComboBox->setPaletteForegroundColor( QColor( 0, 0, 0 ) );
    sectorComboBox->setEditable( TRUE );
    sectorComboBox->setAutoCompletion( TRUE );
    sectorComboBox->setDuplicatesEnabled( FALSE );
    sectorInputLayout->addWidget( sectorComboBox );
    sectorFrameLayout->addLayout( sectorInputLayout );
    extraBoxLayout->addWidget( sectorFrame );
    layout18->addWidget( extraBox );

    longObjectBox = new QGroupBox( this, "longObjectBox" );
    longObjectBox->setColumnLayout(0, Qt::Vertical );
    longObjectBox->layout()->setSpacing( 5 );
    longObjectBox->layout()->setMargin( 7 );
    longObjectBoxLayout = new QGridLayout( longObjectBox->layout() );
    longObjectBoxLayout->setAlignment( Qt::AlignTop );

    longObject2Title = new QLabel( longObjectBox, "longObject2Title" );

    longObjectBoxLayout->addWidget( longObject2Title, 1, 0 );

    longObject3Title = new QLabel( longObjectBox, "longObject3Title" );

    longObjectBoxLayout->addWidget( longObject3Title, 2, 0 );

    longObject4Title = new QLabel( longObjectBox, "longObject4Title" );

    longObjectBoxLayout->addWidget( longObject4Title, 0, 2 );

    longObject1Title = new QLabel( longObjectBox, "longObject1Title" );

    longObjectBoxLayout->addWidget( longObject1Title, 0, 0 );

    longObject1Input = new QLineEdit( longObjectBox, "longObject1Input" );
    QFont longObject1Input_font(  longObject1Input->font() );
    longObject1Input_font.setPointSize( 10 );
    longObject1Input->setFont( longObject1Input_font ); 

    longObjectBoxLayout->addWidget( longObject1Input, 0, 1 );

    longObject5Title = new QLabel( longObjectBox, "longObject5Title" );

    longObjectBoxLayout->addWidget( longObject5Title, 1, 2 );

    longObject2Input = new QLineEdit( longObjectBox, "longObject2Input" );
    QFont longObject2Input_font(  longObject2Input->font() );
    longObject2Input_font.setPointSize( 10 );
    longObject2Input->setFont( longObject2Input_font ); 

    longObjectBoxLayout->addWidget( longObject2Input, 1, 1 );

    longObject3Input = new QLineEdit( longObjectBox, "longObject3Input" );
    QFont longObject3Input_font(  longObject3Input->font() );
    longObject3Input_font.setPointSize( 10 );
    longObject3Input->setFont( longObject3Input_font ); 

    longObjectBoxLayout->addWidget( longObject3Input, 2, 1 );

    longObject4Input = new QLineEdit( longObjectBox, "longObject4Input" );
    QFont longObject4Input_font(  longObject4Input->font() );
    longObject4Input_font.setPointSize( 10 );
    longObject4Input->setFont( longObject4Input_font ); 

    longObjectBoxLayout->addWidget( longObject4Input, 0, 3 );

    longObject5Input = new QLineEdit( longObjectBox, "longObject5Input" );
    QFont longObject5Input_font(  longObject5Input->font() );
    longObject5Input_font.setPointSize( 10 );
    longObject5Input->setFont( longObject5Input_font ); 

    longObjectBoxLayout->addWidget( longObject5Input, 1, 3 );

    longObject6Input = new QLineEdit( longObjectBox, "longObject6Input" );

    longObjectBoxLayout->addWidget( longObject6Input, 2, 3 );

    longObject6Title = new QLabel( longObjectBox, "longObject6Title" );

    longObjectBoxLayout->addWidget( longObject6Title, 2, 2 );
    layout18->addWidget( longObjectBox );

    ObjectWidgetLayout->addMultiCellLayout( layout18, 2, 2, 0, 3 );
    languageChange();
    resize( QSize(749, 963).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( modelCheckBox, SIGNAL( toggled(bool) ), modelLineEdit, SLOT( setEnabled(bool) ) );
    connect( sectorCheckBox, SIGNAL( toggled(bool) ), sectorComboBox, SLOT( setEnabled(bool) ) );

    // tab order
    setTabOrder( objectNameInput, modelCheckBox );
    setTabOrder( modelCheckBox, modelLineEdit );
    setTabOrder( modelLineEdit, sectorCheckBox );
    setTabOrder( sectorCheckBox, sectorComboBox );
    setTabOrder( sectorComboBox, helpTextEdit );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ObjectWidget::~ObjectWidget()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ObjectWidget::languageChange()
{
    setCaption( tr( "Preview" ) );
    positionGroupBox->setTitle( tr( "Position" ) );
    rotationGroupBox->setTitle( tr( "Rotation" ) );
    scalingGroupBox->setTitle( tr( "Scaling" ) );
    additionalBox->setTitle( tr( "Additional" ) );
    objectNameTitle->setText( tr( "Object " ) );
    objectNameInput->setText( QString::null );
    helpTextEdit->setText( trUtf8( "\x3c\x66\x6f\x6e\x74\x20\x66\x61\x63\x65\x3d\x22\x41\x72\x69\x61\x6c\x22\x3e\x3c\x66\x6f\x6e\x74\x20\x73\x69\x7a\x65\x3d\x22\x2b\x32\x22\x3e\x3c\x62\x3e\x48\x65\x6c\x70\x3c\x2f\x62\x3e\x3c\x2f\x66\x6f\x6e\x74\x3e\x3c\x62\x72\x3e\xd\xd\xd\xd\xd\xd\xd\xa\x3c\x66\x6f\x6e\x74\x20\x73\x69\x7a\x65\x3d\x22\x2b\x31\x22\x3e\x3c\x62\x3e\x49\x3c\x2f\x62\x3e\x3c\x2f\x66\x6f\x6e\x74\x3e\x6e\x20\x74\x68\x69\x73\x20\x64\x69\x61\x6c\x6f\x67\x2c\x20\x79\x6f\x75\x20\x63\x61\x6e\x20\x63\x68\x61\x6e\x67\x65\x20\x74\x68\x65\x20\x67\x65\x6e\x65\x72\x61\x6c\x20\x70\x72\x6f\x70\x65\x72\x74\x69\x65\x73\x20\x6f\x66\x20\x61\x6e\x20\x6f\x62\x6a\x65\x63\x74\x2e\x20\x54\x6f\x20\x63\x68\x61\x6e\x67\x65\x20\x74\x68\x65\x6d\x2c\x20\x6a\x75\x73\x74\x20\x63\x6c\x69\x63\x6b\x20\x6f\x6e\x20\x74\x68\x65\x3c\x69\x3e\x43\x68\x61\x6e\x67\x65\x3c\x2f\x69\x3e\x20\x62\x75\x74\x74\x6f\x6e\x20\x69\x6e\x20\x74\x68\x65\x20\x6c\x6f\x77\x65\x72\x20\x72\x69\x67\x68\x74\x2e\x3c\x62\x72\x3e\xd\xd\xd\xd\xd\xd\xd\xa\x3c\x66\x6f\x6e\x74\x20\x73\x69\x7a\x65\x3d\x22\x2b\x31\x22\x3e\x3c\x62\x3e\x59\x3c\x2f\x62\x3e\x3c\x2f\x66\x6f\x6e\x74\x3e\x6f\x75\x20\x63\x61\x6e\x20\x65\x64\x69\x74\x20\x74\x68\x65\x20\x6e\x61\x6d\x65\x20\x6f\x66\x20\x61\x6e\x20\x6f\x62\x6a\x65\x63\x74\x20\x69\x6e\x20\x74\x68\x65\x20\x6c\x69\x6e\x65\x20\x61\x74\x20\x74\x68\x65\x20\x74\x6f\x70\x2c\x20\x62\x75\x74\x20\x61\x6c\x73\x6f\x20\x62\x79\x20\x73\x65\x6c\x65\x63\x74\x69\x6e\x67\x20\x61\x6e\x20\x69\x74\x65\x6d\x20\x69\x6e\x20\x74\x68\x65\x20\x6c\x69\x73\x74\x20\x61\x74\x20\x74\x68\x65\x20\x6c\x65\x66\x74\x20\x61\x6e\x64\x20\x70\x72\x65\x73\x73\x69\x6e\x67\x20\x46\x32\x2e\x3c\x62\x72\x3e\xd\xd\xd\xd\xd\xd\xd\xa\x3c\x66\x6f\x6e\x74\x20\x73\x69\x7a\x65\x3d\x22\x2b\x31\x22\x3e\x3c\x62\x3e\x54\x3c\x2f\x62\x3e\x3c\x2f\x66\x6f\x6e\x74\x3e\x6f\x20\x63\x68\x61\x6e\x67\x65\x20\x74\x68\x65\x20\x70\x6f\x73\x69\x74\x69\x6f\x6e\x20\x6f\x66\x20\x61\x6e\x20\x6f\x62\x6a\x65\x63\x74\x2c\x20\x6a\x75\x73\x74\x20\x65\x64\x69\x74\x20\x74\x68\x65\x20\x70\x6f\x73\x69\x74\x69\x6f\x6e\x20
\x76\x61\x6c\x75\x65\x73\x2e\x20\x54\x68\x65\x72\x65\x27\x73\x20\x6e\x6f\x74\x68\x69\x6e\x67\x20\x73\x70\x65\x63\x69\x61\x6c\x20\x6f\x6e\x20\x74\x68\x65\x6d\x2e\x20\x54\x68\x65\x20\x73\x61\x6d\x65\x20\x77\x69\x74\x68\x20\x74\x68\x65\x20\x73\x63\x61\x6c\x69\x6e\x67\x20\x76\x61\x6c\x75\x65\x73\x2e\xd\xd\xd\xd\xd\xd\xd\xa\x3c\x70\x3e\x3c\x66\x6f\x6e\x74\x20\x73\x69\x7a\x65\x3d\x22\x2b\x31\x22\x3e\x3c\x62\x3e\x54\x3c\x2f\x62\x3e\x3c\x2f\x66\x6f\x6e\x74\x3e\x68\x65\x20\x72\x6f\x74\x61\x74\x69\x6f\x6e\x20\x76\x61\x6c\x75\x65\x73\x20\x61\x72\x65\x20\x62\x61\x73\x69\x63\x61\x6c\x6c\x79\x20\x6a\x75\x73\x74\x20\x6c\x69\x6b\x65\x20\x74\x68\x65\x20\x70\x6f\x73\x69\x74\x69\x6f\x6e\x20\x61\x6e\x64\x20\x73\x63\x61\x6c\x69\x6e\x67\x20\x76\x61\x6c\x75\x65\x73\x2c\x20\x62\x75\x74\x20\x74\x68\x65\x72\x65\x20\x61\x72\x65\x20\x73\x6f\x6d\x65\x20\x64\x69\x66\x66\x65\x72\x65\x6e\x63\x65\x73\x3a\x20\x54\x68\x65\x20\x72\x6f\x74\x61\x74\x69\x6f\x6e\x20\x75\x6e\x69\x74\x20\x69\x73\x20\x64\x65\x67\x72\x65\x65\x2e\x20\x54\x68\x61\x74\x20\x73\x68\x6f\x75\x6c\x64\x20\x6d\x61\x6b\x65\x20\x69\x74\x20\x65\x61\x73\x69\x65\x72\x20\x66\x6f\x72\x20\x79\x6f\x75\x20\x74\x6f\x20\x72\x6f\x74\x61\x74\x65\x20\x61\x6e\x20\x6f\x62\x6a\x65\x63\x74\x2e\x20\x41\x6e\x64\x20\x61\x6e\x6f\x74\x68\x65\x72\x20\x74\x68\x69\x6e\x67\x20\x69\x73\x2c\x20\x74\x68\x61\x74\x20\x63\x68\x61\x6e\x67\x69\x6e\x67\x20\x74\x68\x65\x20\x58\x20\x61\x6e\x64\x20\x59\x20\x76\x61\x6c\x75\x65\x73\x20\x66\x6f\x72\x20\x61\x20\x68\x75\x6d\x61\x6e\x20\x6f\x72\x20\x61\x20\x63\x61\x72\x20\x64\x6f\x65\x73\x6e\x27\x74\x20\x65\x66\x66\x65\x63\x74\x20\x61\x6e\x79\x74\x68\x69\x6e\x67\x20\x62\x65\x63\x61\x75\x73\x65\x20\x4d\x61\x66\x69\x61\x20\x63\x61\x6c\x63\x75\x6c\x61\x74\x65\x73\x20\x74\x68\x65\x20\x58\x20\x61\x6e\x64\x20\x59\x20\x76\x61\x6c\x75\x65\x73\x20\x66\x6f\x72\x20\x63\x61\x72\x73\x20\x61\x6e\x64\x20\x68\x75\x6d\x61\x6e\x73\x20\x69\x74\x73\x65\x6c\x66\x2e\x20\x54\x68\x61\x74\x27\x73\x20\x6c\x6f\x67\x69\x63\x20\x62\x65\x63\x61\x75\x73\x65\x20\x61\x20\x63\x61\x72\x20\x61\x6c\x77\x61\x79\x73
\x20\x68\x61\x73\x20\x74\x6f\x20\x62\x65\x20\x6f\x6e\x20\x74\x68\x65\x20\x67\x72\x6f\x75\x6e\x64\x20\x77\x69\x74\x68\x20\x61\x6c\x6c\x20\x6f\x66\x20\x69\x74\x73\x20\x66\x6f\x75\x72\x20\x77\x68\x65\x65\x6c\x73\x2e\x20\x4d\x61\x66\x69\x61\x20\x77\x69\x6c\x6c\x20\x61\x6c\x77\x61\x79\x73\x20\x70\x6c\x61\x63\x65\x20\x69\x74\x20\x6f\x6e\x20\x74\x68\x65\x20\x67\x72\x6f\x75\x6e\x64\x2c\x20\x65\x76\x65\x6e\x20\x77\x68\x65\x6e\x20\x79\x6f\x75\x20\x73\x65\x74\x20\x74\x68\x65\x20\x58\x2d\x20\x6f\x72\x20\x59\x2d\x76\x61\x6c\x75\x65\x20\x74\x6f\x20\x31\x38\x30\xc2\xb0\x2e\x20\x54\x68\x65\x20\x5a\x20\x76\x61\x6c\x75\x65\x20\x6f\x66\x20\x63\x6f\x75\x72\x73\x65\x20\x64\x6f\x65\x73\x20\x68\x61\x76\x65\x20\x61\x6e\x20\x65\x66\x66\x65\x63\x74\x20\x6f\x6e\x20\x63\x61\x72\x73\x20\x61\x6e\x64\x20\x70\x6c\x61\x79\x65\x72\x73\x2c\x20\x69\x74\x20\x63\x68\x61\x6e\x67\x65\x73\x20\x74\x68\x65\x20\x64\x69\x72\x65\x63\x74\x69\x6f\x6e\x2e\x3c\x2f\x70\x3e\xd\xd\xd\xd\xd\xd\xd\xa\x3c\x66\x6f\x6e\x74\x20\x73\x69\x7a\x65\x3d\x22\x2b\x31\x22\x3e\x3c\x62\x3e\x54\x3c\x2f\x62\x3e\x3c\x2f\x66\x6f\x6e\x74\x3e\x68\x65\x20\x6d\x6f\x64\x65\x6c\x20\x6c\x69\x6e\x65\x20\x73\x68\x6f\x77\x73\x20\x74\x68\x65\x20\x66\x69\x6c\x65\x6e\x61\x6d\x65\x20\x6f\x66\x20\x74\x68\x65\x20\x6d\x6f\x64\x65\x6c\x20\x74\x68\x69\x73\x20\x6f\x62\x6a\x65\x63\x74\x20\x6c\x6f\x61\x64\x73\x2e\x3c\x62\x72\x3e\xd\xd\xd\xd\xd\xd\xd\xa\x3c\x66\x6f\x6e\x74\x20\x73\x69\x7a\x65\x3d\x22\x2b\x31\x22\x3e\x3c\x62\x3e\x54\x3c\x2f\x62\x3e\x3c\x2f\x66\x6f\x6e\x74\x3e\x68\x65\x20\x73\x65\x63\x74\x6f\x72\x20\x63\x6f\x6d\x62\x6f\x62\x6f\x78\x20\x73\x68\x6f\x77\x73\x20\x61\x20\x6c\x69\x73\x74\x20\x6f\x66\x20\x61\x6c\x6c\x20\x73\x65\x63\x74\x6f\x72\x73\x20\x73\x6f\x20\x79\x6f\x75\x20\x64\x6f\x6e\x27\x74\x20\x6e\x65\x65\x64\x20\x74\x6f\x20\x74\x79\x70\x65\x20\x74\x68\x65\x20\x73\x65\x63\x74\x6f\x72\x20\x6e\x61\x6d\x65\x20\x69\x6e\x20\x74\x68\x65\x20\x6c\x69\x6e\x65\x20\x65\x64\x69\x74\x20\x61\x6e\x79\x6d\x6f\x72\x65\x2e\x20\x4f\x66\x20\x63\x6f\x75\x72\x73\x65\x2c\x20\x79\x6f\x75\x20\x73\x74\x69\x6c\x6c\x20
\x63\x61\x6e\x20\x64\x6f\x20\x74\x68\x61\x74\x2c\x20\x61\x6e\x64\x20\x74\x68\x65\x20\x73\x65\x63\x74\x6f\x72\x20\x6c\x69\x6e\x65\x20\x77\x69\x6c\x6c\x20\x65\x76\x65\x6e\x20\x68\x65\x6c\x70\x20\x79\x6f\x75\x20\x77\x69\x74\x68\x20\x61\x75\x74\x6f\x20\x63\x6f\x6d\x70\x6c\x65\x74\x69\x6f\x6e\x2e\xd\xd\xd\xd\xd\xd\xd\xa\x3c\x2f\x66\x6f\x6e\x74\x3e" ) );
    lightColorBox->setTitle( tr( "Color" ) );
    lightFlagBox->setTitle( tr( "Flags" ) );
    flag4CheckBox->setText( tr( "Flag 4" ) );
    flag3CheckBox->setText( tr( "Flag 3" ) );
    flag2CheckBox->setText( tr( "Flag 2" ) );
    flag1CheckBox->setText( tr( "Flag 1" ) );
    flag8CheckBox->setText( tr( "Flag 8" ) );
    flag6CheckBox->setText( tr( "Flag 6" ) );
    flag5CheckBox->setText( tr( "Flag 5" ) );
    flag7CheckBox->setText( tr( "Flag 7" ) );
    lightRangeBox->setTitle( tr( "Range" ) );
    nearRangeTitle->setText( tr( "Near:" ) );
    farRangeTitle->setText( tr( "Far:" ) );
    lightSectorBox->setTitle( tr( "Sectors" ) );
    addSectorButton->setText( tr( "Add" ) );
    removeSectorButton->setText( tr( "Remove" ) );
    lightOtherBox->setTitle( tr( "Other" ) );
    lightTypeComboBox->clear();
    lightTypeComboBox->insertItem( tr( "Point" ) );
    lightTypeComboBox->insertItem( tr( "Directional" ) );
    lightTypeComboBox->insertItem( tr( "Ambient" ) );
    lightTypeComboBox->insertItem( tr( "Ambient" ) );
    lightTypeComboBox->insertItem( tr( "Fog" ) );
    lightTypeComboBox->insertItem( tr( "Fog" ) );
    lightTypeTitle->setText( tr( "Light Type:" ) );
    lightPowerTitle->setText( tr( "Power:" ) );
    lightCone1Title->setText( tr( "Cone 1:" ) );
    lightCone2Title->setText( tr( "Cone 2:" ) );
    sectorBox->setTitle( tr( "Sector Values" ) );
    sector22Title->setText( tr( "Value 22:" ) );
    sector25Title->setText( tr( "Value 25:" ) );
    sector26Title->setText( tr( "Value 26:" ) );
    sector23Title->setText( tr( "Value 23:" ) );
    sector24Title->setText( tr( "Value 24:" ) );
    sector16Title->setText( tr( "Value 16:" ) );
    sector15Title->setText( tr( "Value 15:" ) );
    sector18Title->setText( tr( "Value 18:" ) );
    sector17Title->setText( tr( "Value 17:" ) );
    sector19Title->setText( tr( "Value 19:" ) );
    sector21Title->setText( tr( "Value 21:" ) );
    sector20Title->setText( tr( "Value 20:" ) );
    sector9Title->setText( tr( "Value 9:" ) );
    sector13Title->setText( tr( "Value 13:" ) );
    sector8Title->setText( tr( "Value 8:" ) );
    sector10Title->setText( tr( "Value 10:" ) );
    sector14Title->setText( tr( "Value 14:" ) );
    sector11Title->setText( tr( "Value 11:" ) );
    sector12Title->setText( tr( "Value 12:" ) );
    sector2Title->setText( tr( "Value 2:" ) );
    sector4Title->setText( tr( "Value 4:" ) );
    sector1Title->setText( tr( "Value 1:" ) );
    sector7Title->setText( tr( "Value 7:" ) );
    sector5Title->setText( tr( "Value 5:" ) );
    sector6Title->setText( tr( "Value 6:" ) );
    sector3Title->setText( tr( "Value 3:" ) );
    extraBox->setTitle( tr( "More" ) );
    modelTitleLabel->setText( tr( "Model:" ) );
    modelCheckBox->setText( QString::null );
    sectorTitleLabel->setText( tr( "Sector:" ) );
    sectorCheckBox->setText( QString::null );
    longObjectBox->setTitle( tr( "Long Object Properties" ) );
    longObject2Title->setText( tr( "Value 2:" ) );
    longObject3Title->setText( tr( "Value 3:" ) );
    longObject4Title->setText( tr( "Value 4:" ) );
    longObject1Title->setText( tr( "Value 1:" ) );
    longObject5Title->setText( tr( "Value 5:" ) );
    longObject6Title->setText( tr( "Value 6:" ) );
}

