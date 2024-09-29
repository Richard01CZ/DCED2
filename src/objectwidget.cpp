/****************************************************************************
** Form implementation generated from reading ui file 'objectwidget.ui'
**
** Created: Mi 11. Feb 22:59:45 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.2.1   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "colorwidget.h"
#include "globaldefs.h"
#include "objecticons.h"
#include "objecttypes.h"
#include "objectwidget.h"
#include "img/cone.xpm"

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
#include <qmessagebox.h>
#include <qlistview.h>

/*
 *	Static functions
 */

static QStringList char2StringList( char sLightSectors[5000] )
{
	QStringList returnValue;
	int cur = 0;
	while( sLightSectors[cur]!=0 )
	{
		returnValue.append( QString( &sLightSectors[cur] ) );
		cur += strlen( &sLightSectors[cur] ) + 1;
	}
	return returnValue;
}

void stringList2Char( QStringList sectorList, char * sectorArray )
{
	int cur = 0;
	for( int i = 0; i < 5000; i++ )
		sectorArray[i] = 0;
	for( i = 0; i < sectorList.count(); i++ )
	{
		strcpy( &sectorArray[cur], ( char * )( sectorList[i].latin1() ) );
		cur += strlen( &sectorArray[cur] ) + 1;
	}
}

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
    objectNameInput->setMinimumSize( QSize( 0, 23 ) );
    objectNameInput->setMaximumSize( QSize( 32767, 23 ) );
    QFont objectNameInput_font(  objectNameInput->font() );
    objectNameInput_font.setFamily( "Arial" );
    objectNameInput_font.setPointSize( 12 );
    objectNameInput->setFont( objectNameInput_font ); 
    objectTitleLayout->addWidget( objectNameInput );

    ObjectWidgetLayout->addMultiCellLayout( objectTitleLayout, 0, 0, 0, 3 );

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

    helpTextEdit = new QTextEdit( this, "helpTextEdit" );
    helpTextEdit->setWordWrap( QTextEdit::WidgetWidth );
    helpTextEdit->setReadOnly( TRUE );
    helpTextEdit->setUndoRedoEnabled( FALSE );

    ObjectWidgetLayout->addMultiCellWidget( helpTextEdit, 5, 5, 0, 3 );

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
    QSpacerItem* spacer = new QSpacerItem( 10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    modelInputLayout->addItem( spacer );

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
    QSpacerItem* spacer_2 = new QSpacerItem( 10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    sectorInputLayout->addItem( spacer_2 );

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

    lightFrame = new QFrame( this, "lightFrame" );
    lightFrame->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)4, 0, 0, lightFrame->sizePolicy().hasHeightForWidth() ) );
    lightFrame->setMinimumSize( QSize( 0, 290 ) );
    lightFrame->setFrameShape( QFrame::NoFrame );
    lightFrame->setFrameShadow( QFrame::Plain );
    lightFrameLayout = new QHBoxLayout( lightFrame, 0, 5, "lightFrameLayout"); 

    lightColorBox = new QGroupBox( lightFrame, "lightColorBox" );
    lightColorBox->setSizePolicy( QSizePolicy::Maximum, QSizePolicy::Maximum );
    lightFrameLayout->addWidget( lightColorBox );

	lightColorWidget = new ColorWidget( lightColorBox );

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
    QSpacerItem* spacer_3 = new QSpacerItem( 161, 21, QSizePolicy::Expanding, QSizePolicy::Minimum );
    lightSectorBoxLayout->addItem( spacer_3, 2, 0 );
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
    languageChange();
    resize( QSize(795, 963).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( modelCheckBox, SIGNAL( toggled(bool) ), modelLineEdit, SLOT( setEnabled(bool) ) );
    connect( sectorCheckBox, SIGNAL( toggled(bool) ), sectorComboBox, SLOT( setEnabled(bool) ) );
	connect( addSectorButton, SIGNAL( clicked() ), this, SLOT( insertLightSector() ) );
	connect( removeSectorButton, SIGNAL( clicked() ), this, SLOT( removeLightSector() ) );
	connect( lightSectorComboBox, SIGNAL( textChanged( const QString & ) ), this, SLOT( changeLightSector( const QString & ) ) );

	/*
	 *  objectEdited() connections
	 */
	//--------------------standard widget------------------//
	connect( objectNameInput, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( positionXInput, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( positionYInput, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( positionZInput, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( rotationXInput, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( rotationYInput, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( rotationZInput, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( scalingXInput, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( scalingYInput, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( scalingZInput, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( additionalXInput, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( additionalYInput, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( additionalZInput, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( modelLineEdit, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( modelCheckBox, SIGNAL( clicked() ), this, SLOT( objectEdited() ) );
	connect( sectorComboBox, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( sectorComboBox, SIGNAL( highlighted( int ) ), this, SLOT( objectEdited() ) );
	connect( sectorCheckBox, SIGNAL( clicked() ), this, SLOT( objectEdited() ) );

	//----------------------Sector Widget------------------------//
	connect( sector1Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( sector2Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( sector3Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( sector4Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( sector5Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( sector6Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( sector7Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( sector8Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( sector9Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( sector10Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( sector11Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( sector12Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( sector13Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( sector14Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( sector15Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( sector16Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( sector17Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( sector18Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( sector19Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( sector20Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( sector21Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( sector22Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( sector23Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( sector24Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( sector25Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( sector26Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );

	//------------------------Light Widget-----------------------//
	connect( lightColorWidget->cs, SIGNAL( newCol( QRgb ) ), this, SLOT( objectEdited() ) );
	connect( flag1CheckBox, SIGNAL( clicked() ), this, SLOT( objectEdited() ) );
	connect( flag2CheckBox, SIGNAL( clicked() ), this, SLOT( objectEdited() ) );
	connect( flag3CheckBox, SIGNAL( clicked() ), this, SLOT( objectEdited() ) );
	connect( flag4CheckBox, SIGNAL( clicked() ), this, SLOT( objectEdited() ) );
	connect( flag5CheckBox, SIGNAL( clicked() ), this, SLOT( objectEdited() ) );
	connect( flag6CheckBox, SIGNAL( clicked() ), this, SLOT( objectEdited() ) );
	connect( flag7CheckBox, SIGNAL( clicked() ), this, SLOT( objectEdited() ) );
	connect( flag8CheckBox, SIGNAL( clicked() ), this, SLOT( objectEdited() ) );
	connect( nearRangeInput, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( farRangeInput, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( lightTypeComboBox, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( lightPowerInput, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( lightCone1Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( lightCone2Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( lightSectorComboBox, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( lightSectorComboBox, SIGNAL( highlighted( int ) ), this, SLOT( objectEdited() ) );
	connect( addSectorButton, SIGNAL( clicked() ), this, SLOT( objectEdited() ) );
	connect( removeSectorButton, SIGNAL( clicked() ), this, SLOT( objectEdited() ) );
	connect( lightColorWidget, SIGNAL( colorChanged( QColor ) ), this, SLOT( objectEdited() ) );

	//-----------------------Long Object 06----------------------//
	connect( longObject1Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( longObject2Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( longObject3Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( longObject4Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( longObject5Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );
	connect( longObject6Input, SIGNAL( textChanged( const QString & ) ), this, SLOT( objectEdited() ) );

    // tab order
    setTabOrder( objectNameInput, modelCheckBox );
    setTabOrder( modelCheckBox, modelLineEdit );
    setTabOrder( modelLineEdit, sectorCheckBox );
    setTabOrder( sectorCheckBox, sectorComboBox );
    setTabOrder( sectorComboBox, helpTextEdit );

	// hiding sector and light frames
	lightFrame->hide();
	sectorBox->hide();

	// initialising variables
	currentObject = 0;
	currentListItem = 0;
	edited = false;

}

/*
 *  Destroys the object and frees any allocated resources
 */
ObjectWidget::~ObjectWidget()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *	This function is called whenever the widget looses focus. In that function
 *  I save the object properties.
 */
void ObjectWidget::focusOutEvent( QFocusEvent * )
{
	this->saveObject();
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
    helpTextEdit->setText( "" );
    extraBox->setTitle( tr( "More" ) );
    modelTitleLabel->setText( tr( "Model:" ) );
    modelCheckBox->setText( QString::null );
    sectorTitleLabel->setText( tr( "Sector:" ) );
    sectorCheckBox->setText( QString::null );
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
    longObjectBox->setTitle( tr( "Long Object Properties" ) );
    longObject2Title->setText( tr( "Value 2:" ) );
    longObject3Title->setText( tr( "Value 3:" ) );
    longObject4Title->setText( tr( "Value 4:" ) );
    longObject1Title->setText( tr( "Value 1:" ) );
    longObject5Title->setText( tr( "Value 5:" ) );
    longObject6Title->setText( tr( "Value 6:" ) );

	QMimeSourceFactory::defaultFactory()->setPixmap( "cone_img", QPixmap( (const char **)(cone_xpm) ) );

	lightHint = trUtf8( "<font face=\"Arial\"><font size=\"+2\"><b>Help</b></font><br><br>"
						"<font size=\"+1\"><b>F</b></font>lags are booleans (TRUE/FALSE) that affect the behaviour of the "
						"light. For example, flag 5 defines wether the light is shown on dynamic objects like cars, and "
						" flag 6 is the same for static objects. I'd recommend you to try around a bit with the flags.<br>"
						"<font size=\"+1\"><b>T</b></font>he color shouldn't need any explanation, I guess.<br>"
						"<font size=\"+1\"><b>T</b></font>he sector list defines in which sectors the light is shown. For "
						"example, the sun isn't shown in Yellow Pete's gunshop which is indoor. This is done by removing "
						"the sector, where Yellow Pete's gunshop is in, from the list. If this list is empty, the light is "
						"never shown.<br>"
						"<font size=\"+1\"><b>R</b></font>ange values define the fading effect of the light. The "
						"near range is the radius where the fading starts, and the far range is where it ends.<br>"
						"<font size=\"+1\"><b>T</b></font>he light type should be pretty clear. Note that there are sometimes "
						"more entries of one type. Just try around to find what you need.<br>"
						"<font size=\"+1\"><b>T</b></font>he power shouldn't need any explanation, I guess.<br>"
						"<font size=\"+1\"><b>C</b></font>ones are pretty hard to explain, so just take a look at that "
						"picture:<br>"
						"<img src=\"cone_img\">"
						"</font>" );

	sectorHint = trUtf8( "<font face=\"Arial\"><font size=\"+2\"><b>Help</b></font><br><br>"
						 "<font size=\"+1\"><b>S</b></font>ectors are pretty undocumented. I'd recommend you to try around a bit with the values."
						 "</font>" );

	normalHint = trUtf8( "<font face=\"Arial\"><font size=\"+2\"><b>Help</b></font><br><br>"
						 "<font size=\"+1\"><b>I</b></font>n this dialog, you can change the general properties of an object. "
							"To change them, just click on the<i>Change</i> button in the lower right.<br>"
						 "<font size=\"+1\"><b>Y</b></font>ou can edit the name of an object in the line at the top, but also "
							"by selecting an item in the list at the left and pressing F2.<br>"
						 "<font size=\"+1\"><b>T</b></font>o change the position of an object, just edit the position values. "
							"There's nothing special on them. The same with the scaling values."
						 "<p><font size=\"+1\"><b>T</b></font>he rotation values are basically just like the position and "
							"scaling values, but there are some differences: The rotation unit is degree. That should make it "
							"easier for you to rotate an object. And another thing is, that changing the X and Y values for a "
							"human or a car doesn't effect anything because Mafia calculates the X and Y values for cars and "
							"humans itself. That's logic because a car always has to be on the ground with all of its four "
							"wheels. Mafia will always place it on the ground, even when you set the X- or Y-value to 180 "
							"degrees. The Z value of course does have an effect on cars and players, it changes the "
							"direction.</p>"
						 "<font size=\"+1\"><b>T</b></font>he model line shows the filename of the model this object loads.<br>"
						 "<font size=\"+1\"><b>T</b></font>he sector combobox shows a list of all sectors so you don't need to "
							"type the sector name in the line edit anymore. Of course, you still can do that, and the sector "
							"line will even help you with auto completion."
						 "</font>" );
}

void ObjectWidget::objectEdited()
{
	edited = true;
}

void ObjectWidget::saveObject()
{
	if( edited == true )
	{
		for( int i = 0; i < objectNameInput->text().length(); i++ )
			currentObject->sName[i] = objectNameInput->text()[i].latin1();
		currentObject->sName[++i] = 0;

		if( currentObject->lType == 2 ) //Lights
		{	
			//Translation
			currentObject->fPos[0] = positionXInput->text().toFloat();
			currentObject->fPos[1] = positionYInput->text().toFloat();
			currentObject->fPos[2] = positionZInput->text().toFloat();

			currentObject->fRot[3] = CHelper::Angle2XYRot( rotationXInput->text().toFloat() );
			currentObject->fRot[1] = CHelper::Angle2XYRot( rotationYInput->text().toFloat() );
			currentObject->fRot[0] = CHelper::Angle2ZRotCos( rotationZInput->text().toFloat() );
			currentObject->fRot[2] = CHelper::Angle2ZRotSin( rotationZInput->text().toFloat() );

			currentObject->fSize[0] = scalingXInput->text().toFloat();
			currentObject->fSize[1] = scalingYInput->text().toFloat();
			currentObject->fSize[2] = scalingZInput->text().toFloat();

			currentObject->fAddTrans[0] = additionalXInput->text().toFloat();
			currentObject->fAddTrans[1] = additionalYInput->text().toFloat();
			currentObject->fAddTrans[2] = additionalZInput->text().toFloat();

			currentObject->fLightNear = nearRangeInput->text().toFloat();
			currentObject->fLightFar = farRangeInput->text().toFloat();
			currentObject->fRed = ( float )( QColor( lightColorWidget->currentColor() ).red() ) / 255.0;
			currentObject->fGreen = ( float )( QColor( lightColorWidget->currentColor() ).green() ) / 255.0;
			currentObject->fBlue = ( float )( QColor( lightColorWidget->currentColor() ).blue() ) / 255.0;

            //Flags
            currentObject->lLightFlags = 0;
            if( flag1CheckBox->isChecked() ) currentObject->lLightFlags |= 0x00000001;
            if( flag2CheckBox->isChecked() ) currentObject->lLightFlags |= 0x00000002;
            if( flag3CheckBox->isChecked() ) currentObject->lLightFlags |= 0x00000004;
            if( flag4CheckBox->isChecked() ) currentObject->lLightFlags |= 0x00000008;
            if( flag5CheckBox->isChecked() ) currentObject->lLightFlags |= 0x0000000F;
            if( flag6CheckBox->isChecked() ) currentObject->lLightFlags |= 0x00000020;
            if( flag7CheckBox->isChecked() ) currentObject->lLightFlags |= 0x00000040;
            if( flag8CheckBox->isChecked() ) currentObject->lLightFlags |= 0x00000080;
				
			currentObject->lLightType = lightTypeComboBox->currentItem() + 1;
			currentObject->fPower = lightPowerInput->text().toFloat();
			currentObject->fLightUnk1 = lightCone1Input->text().toFloat();
			currentObject->fLightUnk2 = lightCone2Input->text().toFloat();

			QStringList sectorList;
			for( int i = 0; i < lightSectorListBox->count(); i++ )
				sectorList.append( lightSectorListBox->item( i )->text() );
			stringList2Char( sectorList, currentObject->sLightSectors );
		}
		else if( currentObject->lType == 153 ) //Sectors
		{
			currentObject->fSectorVal1 = sector1Input->text().toFloat();
			currentObject->fSectorVal2 = sector1Input->text().toFloat();
			currentObject->fSectorVal3 = sector1Input->text().toFloat();
			currentObject->fSectorVal4 = sector1Input->text().toFloat();
			currentObject->lSectorVal5 = sector1Input->text().toLong();
			currentObject->fSectorVal6 = sector1Input->text().toFloat();
			currentObject->lSectorVal7 = sector1Input->text().toLong();
			currentObject->fSectorVal8 = sector1Input->text().toFloat();
			currentObject->lSectorVal9 = sector1Input->text().toLong();
			currentObject->fSectorVal10 = sector1Input->text().toFloat();
			currentObject->fSectorVal11 = sector1Input->text().toFloat();
			currentObject->lSectorVal12 = sector1Input->text().toLong();
			currentObject->lSectorVal13 = sector1Input->text().toLong();
			currentObject->lSectorVal14 = sector1Input->text().toLong();
			currentObject->lSectorVal15 = sector1Input->text().toLong();
			currentObject->fSectorVal16 = sector1Input->text().toFloat();
			currentObject->lSectorVal17 = sector1Input->text().toLong();
			currentObject->fSectorVal18 = sector1Input->text().toFloat();
			currentObject->fSectorVal19 = sector1Input->text().toFloat();
			currentObject->lSectorVal20 = sector1Input->text().toLong();
			currentObject->lSectorVal21[0] = sector1Input->text().toLong();
			currentObject->lSectorVal21[1] = sector1Input->text().toLong();
			currentObject->lSectorVal21[2] = sector1Input->text().toLong();
			currentObject->lSectorVal22[0] = sector1Input->text().toLong();
			currentObject->lSectorVal22[1] = sector1Input->text().toLong();
			currentObject->lSectorVal22[2] = sector1Input->text().toLong();
		}
		else
		{
			currentObject->fPos[0] = positionXInput->text().toFloat();
			currentObject->fPos[1] = positionYInput->text().toFloat();
			currentObject->fPos[2] = positionZInput->text().toFloat();

			currentObject->fRot[3] = CHelper::Angle2XYRot( rotationXInput->text().toFloat() );
			currentObject->fRot[1] = CHelper::Angle2XYRot( rotationYInput->text().toFloat() );
			currentObject->fRot[0] = CHelper::Angle2ZRotCos( rotationZInput->text().toFloat() );
			currentObject->fRot[2] = CHelper::Angle2ZRotSin( rotationZInput->text().toFloat() );

			currentObject->fSize[0] = scalingXInput->text().toFloat();
			currentObject->fSize[1] = scalingYInput->text().toFloat();
			currentObject->fSize[2] = scalingZInput->text().toFloat();

			currentObject->fAddTrans[0] = additionalXInput->text().toFloat();
			currentObject->fAddTrans[1] = additionalYInput->text().toFloat();
			currentObject->fAddTrans[2] = additionalZInput->text().toFloat();

			currentObject->bUseModel = modelCheckBox->isChecked();

			if( currentObject->lType == 6 ) // longObject
			{
				currentObject->fVal[0] = longObject1Input->text().toFloat();
				currentObject->fVal[1] = longObject2Input->text().toFloat();
				currentObject->fVal[2] = longObject3Input->text().toFloat();
				currentObject->fVal[3] = longObject4Input->text().toFloat();
				currentObject->fVal[4] = longObject5Input->text().toFloat();
				currentObject->fVal[5] = longObject6Input->text().toFloat();
			}

			if( currentObject->bUseModel )
			{
				for( int i = 0; i < modelLineEdit->text().length(); i++ )
					currentObject->sModelName[i] = modelLineEdit->text()[i].latin1();
				currentObject->sModelName[++i] = 0;
			}

			if( sectorCheckBox->isChecked() )
			{
				for( int i = 0; i < sectorComboBox->currentText().length(); i++ )
					currentObject->sSectorName[i] = sectorComboBox->currentText().latin1()[i];
				for( i; i < 256; i++ )
					currentObject->sSectorName[i] = 0;
			}
			else
				for( int i = 0; i < 256; i++ )
					currentObject->sSectorName[i] = 0;
		}; 
		sceneWrapper->SaveObject( currentObject, oldName.latin1() );
		status_bar->message( tr( "Object saved." ), 3000 );
	}; 
}

void ObjectWidget::setInputFields( ObjectInfo_t * newObject, QListViewItem * item /* = 0 */ )
{
	if( currentObject != 0 )
	{
		saveObject();
		if( currentListItem )
			currentListItem->setText( 0, objectNameInput->text() );
		delete currentObject;
	}

	currentObject = newObject;
	currentListItem = item;

	oldName = QString( currentObject->sName );

	objectNameInput->setText( QString( currentObject->sName ) );



		// Hide model line
	if( currentObject->lType == 9 && !modelFrame->isVisible() ) // Model object
		modelFrame->show();
	else if( currentObject->lType != 9 && modelFrame->isVisible() )
		modelFrame->hide();

	if( currentObject->lType == 2 ) //Lights
	{
		if( sectorBox->isShown() )
			sectorBox->hide();
		if( longObjectBox->isShown() )
			longObjectBox->hide();

		if( lightFrame->isHidden() )
			lightFrame->show();
		if( positionGroupBox->isHidden() )
			positionGroupBox->show();
		if( rotationGroupBox->isHidden() )
			rotationGroupBox->show();
		if( scalingGroupBox->isHidden() )
			scalingGroupBox->show();
		if( additionalBox->isHidden() )
			additionalBox->show();
		if( extraBox->isHidden() )
			extraBox->show();
		
		nearRangeInput->setText( QString::number( currentObject->fLightNear ) );
		farRangeInput->setText( QString::number( currentObject->fLightFar ) );
		lightColorWidget->setCurrentColor( qRgb( currentObject->fRed * 255.0, currentObject->fGreen * 255.0, currentObject->fBlue * 255.0 ) );

		positionXInput->setText( QString::number( currentObject->fPos[0] ) );
		positionYInput->setText( QString::number( currentObject->fPos[1] ) );
		positionZInput->setText( QString::number( currentObject->fPos[2] ) );

		rotationXInput->setText( QString::number( CHelper::XYRot2Angle( currentObject->fRot[3] ) ) );
		rotationYInput->setText( QString::number( CHelper::XYRot2Angle( currentObject->fRot[1] ) ) );
		rotationZInput->setText( QString::number( CHelper::ZRot2Angle ( currentObject->fRot[0] ) ) );

		scalingXInput->setText( QString::number( currentObject->fSize[0] ) );
		scalingYInput->setText( QString::number( currentObject->fSize[1] ) );
		scalingZInput->setText( QString::number( currentObject->fSize[2] ) );

		additionalXInput->setText( QString::number( currentObject->fAddTrans[0] ) );
		additionalYInput->setText( QString::number( currentObject->fAddTrans[1] ) );
		additionalZInput->setText( QString::number( currentObject->fAddTrans[2] ) );

		if( ( currentObject->lLightFlags&1 ) == 1 ) flag1CheckBox->setChecked( true );
		else flag1CheckBox->setChecked( false );
		if( ( currentObject->lLightFlags&2 ) == 2 ) flag2CheckBox->setChecked( true );
		else flag2CheckBox->setChecked( false );
		if( ( currentObject->lLightFlags&4 ) == 4 ) flag3CheckBox->setChecked( true );
		else flag3CheckBox->setChecked( false );
		if( ( currentObject->lLightFlags&8 ) == 8 ) flag4CheckBox->setChecked( true );
		else flag4CheckBox->setChecked( false );
		if( ( currentObject->lLightFlags&16 ) == 16 ) flag5CheckBox->setChecked( true );
		else flag5CheckBox->setChecked( false );
		if( ( currentObject->lLightFlags&32 ) == 32 ) flag6CheckBox->setChecked( true );
		else flag6CheckBox->setChecked( false );
		if( ( currentObject->lLightFlags&64 ) == 64 ) flag7CheckBox->setChecked( true );
		else flag7CheckBox->setChecked( false );
		if( ( currentObject->lLightFlags&128 ) == 128 ) flag8CheckBox->setChecked( true );
		else flag8CheckBox->setChecked( false );

		lightSectorListBox->clear();
		lightSectorListBox->insertStringList( char2StringList( currentObject->sLightSectors ) );

		lightTypeComboBox->setCurrentItem( currentObject->lLightType - 1 );
		lightPowerInput->setText( QString::number( currentObject->fPower ) );
		lightCone1Input->setText( QString::number( currentObject->fLightUnk1 ) );
		lightCone2Input->setText( QString::number( currentObject->fLightUnk2 ) );
	}
	else if( currentObject->lType == 153 ) //Sectors
	{
		if( positionGroupBox->isShown() )
			positionGroupBox->hide();
		if( rotationGroupBox->isShown() )
			rotationGroupBox->hide();
		if( scalingGroupBox->isShown() )
			scalingGroupBox->hide();
		if( additionalBox->isShown() )
			additionalBox->hide();
		if( extraBox->isShown() )
			extraBox->hide();
		if( lightFrame->isShown() )
			lightFrame->hide();
		if( longObjectBox->isShown() )
			longObjectBox->hide();

		if( sectorBox->isHidden() )
			sectorBox->show();

		sector1Input->setText( QString::number( currentObject->fSectorVal1 ) );
		sector2Input->setText( QString::number( currentObject->fSectorVal2 ) );
		sector3Input->setText( QString::number( currentObject->fSectorVal3 ) );
		sector4Input->setText( QString::number( currentObject->fSectorVal4 ) );
		sector5Input->setText( QString::number( currentObject->lSectorVal5 ) );
		sector6Input->setText( QString::number( currentObject->fSectorVal6 ) );
		sector7Input->setText( QString::number( currentObject->lSectorVal7 ) );
		sector8Input->setText( QString::number( currentObject->fSectorVal8 ) );
		sector9Input->setText( QString::number( currentObject->lSectorVal9 ) );
		sector10Input->setText( QString::number( currentObject->fSectorVal10 ) );
		sector11Input->setText( QString::number( currentObject->fSectorVal11 ) );
		sector12Input->setText( QString::number( currentObject->lSectorVal12 ) );
		sector13Input->setText( QString::number( currentObject->lSectorVal13 ) );
		sector14Input->setText( QString::number( currentObject->lSectorVal14 ) );
		sector15Input->setText( QString::number( currentObject->lSectorVal15 ) );
		sector16Input->setText( QString::number( currentObject->fSectorVal16 ) );
		sector17Input->setText( QString::number( currentObject->lSectorVal17 ) );
		sector18Input->setText( QString::number( currentObject->fSectorVal18 ) );
		sector19Input->setText( QString::number( currentObject->fSectorVal19 ) );
		sector20Input->setText( QString::number( currentObject->lSectorVal20 ) );
		sector21Input->setText( QString::number( currentObject->lSectorVal21[0] ) );
		sector22Input->setText( QString::number( currentObject->lSectorVal21[1] ) );
		sector23Input->setText( QString::number( currentObject->lSectorVal21[2] ) );
		sector24Input->setText( QString::number( currentObject->lSectorVal22[0] ) );
		sector25Input->setText( QString::number( currentObject->lSectorVal22[1] ) );
		sector26Input->setText( QString::number( currentObject->lSectorVal22[2] ) );
	}
	else //All other objects
	{
		if( lightFrame->isShown() )
			lightFrame->hide();
		
		if( positionGroupBox->isHidden() )
			positionGroupBox->show();
		if( rotationGroupBox->isHidden() )
			rotationGroupBox->show();
		if( scalingGroupBox->isHidden() )
			scalingGroupBox->show();
		if( additionalBox->isHidden() )
			additionalBox->show();
		if( extraBox->isHidden() )
			extraBox->show();

		if( currentObject->lType == 6)
		{
			if( extraBox->isShown() )
				extraBox->hide();
			if( longObjectBox->isHidden() )
				longObjectBox->show();
		}
		else
		{
			if( longObjectBox->isShown() )
				longObjectBox->hide();
			if( extraBox->isHidden() )
				extraBox->show();
		}

		positionXInput->setText( QString::number( currentObject->fPos[0] ) );
		positionYInput->setText( QString::number( currentObject->fPos[1] ) );
		positionZInput->setText( QString::number( currentObject->fPos[2] ) );

		rotationXInput->setText( QString::number( CHelper::XYRot2Angle( currentObject->fRot[3] ) ) );
		rotationYInput->setText( QString::number( CHelper::XYRot2Angle( currentObject->fRot[1] ) ) );
		rotationZInput->setText( QString::number( CHelper::ZRot2Angle ( currentObject->fRot[0] ) ) );

		scalingXInput->setText( QString::number( currentObject->fSize[0] ) );
		scalingYInput->setText( QString::number( currentObject->fSize[1] ) );
		scalingZInput->setText( QString::number( currentObject->fSize[2] ) );

		additionalXInput->setText( QString::number( currentObject->fAddTrans[0] ) );
		additionalYInput->setText( QString::number( currentObject->fAddTrans[1] ) );
		additionalZInput->setText( QString::number( currentObject->fAddTrans[2] ) );

		if( currentObject->lType == 6)
		{
			longObject1Input->setText( QString::number( currentObject->fVal[0] ) );
			longObject2Input->setText( QString::number( currentObject->fVal[1] ) );
			longObject3Input->setText( QString::number( currentObject->fVal[2] ) );
			longObject4Input->setText( QString::number( currentObject->fVal[3] ) );
			longObject5Input->setText( QString::number( currentObject->fVal[4] ) );
			longObject6Input->setText( QString::number( currentObject->fVal[5] ) );
		}

		if( currentObject->bUseModel == true )
		{
			modelLineEdit->setText( QString( currentObject->sModelName ) );
			modelCheckBox->setChecked( true );
		}
		else
		{
			modelLineEdit->setText( "" );
			modelCheckBox->setChecked( false );
		}

		if( currentObject->sSectorName[0] != 0 )
		{
			sectorComboBox->setCurrentText( QString( currentObject->sSectorName ) );
			sectorCheckBox->setChecked( true );
		}
		else
		{
			sectorComboBox->setCurrentText( "" );
			sectorCheckBox->setChecked( false );
		}
	}

	helpTextEdit->setText( ObjectTypes::getDescription( currentObject->lType, Object ) );

	edited = false;
}

void ObjectWidget::insertLightSector()
{
	lightSectorListBox->insertItem( lightSectorComboBox->currentText() );
}

void ObjectWidget::removeLightSector()
{
	lightSectorListBox->removeItem( lightSectorListBox->currentItem() );
}

void ObjectWidget::changeLightSector( const QString & text /* = QString::null  */ )
{
	lightSectorListBox->changeItem( text, lightSectorListBox->currentItem() );
}