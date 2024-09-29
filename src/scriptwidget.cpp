 //Script Widget cpp file

#include "documentwidget.h"
#include "documentoverview.h"
#include "mainwidget.h"
#include "mafiasyntax.h"
#include "propertylist.h"
#include "propertynamelist.h"
#include "scriptmainwindow.h"
#include "scriptwidget.h"
#include "scriptworkspace.h"

#include "img/script.xpm"

#include <qlayout.h>
#include <qlistbox.h>
#include <qmessagebox.h>
#include <qscrollview.h>
#include <qsplitter.h>
#include <qtable.h>
#include <qtextstream.h>
#include <qvariant.h>

ScriptWidget::ScriptWidget( ScriptWorkspace* parentWidget, QString n, int t,
							QString s, bool i, ObjectInfo_t * objInfo /* = 0 */, WFlags fl /* = 0 */ )
			: QWidget( parentWidget, n.latin1(), fl ),
			  objectInfo( objInfo ),
			  script( s ),
			  init( i ),
			  type( t ),
			  name( n ),
			  parent( parentWidget )
{
	QGridLayout * enemyGrid = 0;
	enemyEditor = 0;
	movingBoxEditor = 0;
	scriptSV = 0;
	lineNumbers = 0;
	scriptInput = 0;
	scriptSyntax = 0;
	propertyEditor = 0;
	splitter = new QSplitter( Qt::Horizontal, this, "splitter" );

	setFocusPolicy( QWidget::StrongFocus );
	setIcon( script_xpm );
	settings.setPath( "DONCity", "DCED2", QSettings::User );

	grid = new QGridLayout( this, 1, 2, 5, 5 );

	if( type == 5 || type == 27 || init == true )
	{
		QFrame * inputFrame = new QFrame( splitter );
		inputFrame->setFrameStyle( QFrame::Box | QFrame::Plain );
		inputFrame->setLineWidth( 1 );

		QGridLayout * frameGrid = new QGridLayout( inputFrame, 1, 1, 1, 0 );

		scriptSV = new QScrollView( inputFrame, "ScriptScrollView" );
		scriptSV->setMinimumWidth( 32 );
		scriptSV->setMaximumWidth( 32 );
		scriptSV->setFrameStyle( QFrame::NoFrame );
		scriptSV->setVScrollBarMode( QScrollView::AlwaysOff );
		scriptSV->setHScrollBarMode( QScrollView::AlwaysOff );
		scriptSV->setSizePolicy( QSizePolicy::Minimum, QSizePolicy::Expanding );

		//lineNumbers declaration
		lineNumbers = new QTextEdit( scriptSV->viewport(), "LineNumbers");
		lineNumbers->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)7, 0, 0, lineNumbers->sizePolicy().hasHeightForWidth() ) );
		lineNumbers->setMinimumWidth( 32 );
		lineNumbers->setMaximumWidth( 32 );
		lineNumbers->setMinimumHeight( 31000 );
		lineNumbers->setReadOnly( true );
		lineNumbers->setFrameShape( QTextEdit::NoFrame );
		lineNumbers->setWordWrap( QTextEdit::NoWrap );
		lineNumbers->setPaletteBackgroundColor( QColor( 200, 200, 200 ) );
		lineNumbers->setAlignment( QTextEdit::AlignRight );
		lineNumbers->setVScrollBarMode( QScrollView::AlwaysOff );
		lineNumbers->setHScrollBarMode( QScrollView::AlwaysOff );
		scriptSV->addChild( lineNumbers );

		//scriptInput declaration
		scriptInput = new QTextEdit( inputFrame );
		scriptInput->setTextFormat( PlainText );
		scriptInput->setAutoFormatting( QTextEdit::AutoNone );
		scriptInput->setWordWrap( QTextEdit::NoWrap );
		scriptInput->setFrameShape( QTextEdit::NoFrame );
		scriptInput->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

		//scriptSyntax declaration and font settings
		scriptSyntax = new MafiaSyntax( scriptInput, MafiaSyntax::Edit );
		scriptInput->setFont( scriptSyntax->standardFont );
		lineNumbers->setFont( scriptSyntax->standardFont );

		frameGrid->addWidget( scriptSV, 0, 0 );
		frameGrid->addWidget( scriptInput, 0, 1 );
	
		//connecting
		connect( scriptInput, SIGNAL( textChanged() ), this, SLOT( setLineNumbers() ) );
		connect( scriptInput, SIGNAL( contentsMoving( int, int ) ), scriptSV, SLOT( setContentsPos( int, int ) ) );
	}


	//enemyEditor and enemyVisibleButton declaration
	if( type == 2 || type == 27 ) // Player or Enemy
	{

		enemyEditor = new EnemyEditor( splitter );
		enemyEditor->header()->setStretchEnabled( FALSE );
		enemyEditor->setColumnWidth( 0, 100 );
		enemyEditor->setColumnWidth( 1, 60 );
		enemyEditor->setup();

		enemyEditor->setResizeMode( EnemyEditor::AllColumns );

		propertyEditor = enemyEditor;
	}
	else if( type == 6 ) // Door
	{
		doorEditor = new DoorEditor( splitter );
		doorEditor->setup();

		propertyEditor = doorEditor;
	}
	else if( type == 12 ) // Traffic
	{
		trafficNameList = new TrafficNameList( splitter );
		trafficEditor = new TrafficEditor( splitter );
		trafficEditor->setFixedWidth( 200 );
		trafficEditor->setup();

		propertyEditor = trafficEditor;

		//connecting
		connect( trafficNameList->itemListView, SIGNAL( currentChanged( QListViewItem * ) ), this, SLOT( updateProperties() ) );
		connect( trafficEditor->curNameItem, SIGNAL( valueChanged( const QVariant& ) ), trafficNameList, SLOT( renameItem( const QVariant& ) ) );
		connect( trafficEditor->curNameItem, SIGNAL( valueReset( const QVariant& ) ), trafficNameList, SLOT( renameItem( const QVariant& ) ) );
	}
	else if( type == 18 ) // Pedestrian
	{
		pedestrianModelList = new PedestrianModelList( splitter );
		pedestrianEditor = new PedestrianEditor( splitter );
		pedestrianEditor->setFixedWidth( 200 );
		pedestrianEditor->setup();

		propertyEditor = pedestrianEditor;

		//connecting
		connect( pedestrianModelList->itemListView, SIGNAL( currentChanged( QListViewItem * ) ), this, SLOT( updateProperties() ) );
		connect( pedestrianEditor->curNameItem, SIGNAL( valueChanged( const QVariant& ) ), pedestrianModelList, SLOT( renameItem( const QVariant& ) ) );
		connect( pedestrianEditor->curNameItem, SIGNAL( valueReset( const QVariant& ) ), pedestrianModelList, SLOT( renameItem( const QVariant& ) ) );
	}
	else if( type == 35 ) // Moving Box
	{
		movingBoxEditor = new MovingBoxEditor( splitter );
		/*movingBoxEditor->header()->setStretchEnabled( FALSE );
		/*movingBoxEditor->setColumnWidth( 0, 100 );
		movingBoxEditor->setColumnWidth( 1, 60 );
		movingBoxEditor->setFixedWidth( 160 );*/
		movingBoxEditor->setup();

		propertyEditor = movingBoxEditor;
	}

	grid->addWidget( splitter, 0, 0 );

	if( type == 5 || type == 27 || type == 12 || type == 18 || init == true )
		resize( QSize( parent->width() / 2 - 8, parent->height() / 2 - 32 ) );
	else 
		resize( QSize( 200, propertyEditor->childCount() * 20 ) );
	
//	showMaximized();

	setInputFields( name, type, script, objectInfo );
}

void ScriptWidget::closeEvent( QCloseEvent * ev )
{
	save();
	closeSignal( this );
}

void ScriptWidget::save()
{
	if( ( type == 2 || type == 27 ) && enemyEditor->isChanged() )
	{
		objectInfo->fStrenght = enemyEditor->strengthItem->value().toDouble();
		objectInfo->fEnergy = enemyEditor->energyItem->value().toDouble();
			objectInfo->fEnergy_HANDL = enemyEditor->energyLeftHandItem->value().toDouble();
			objectInfo->fEnergy_HANDR = enemyEditor->energyRightHandItem->value().toDouble();
			objectInfo->fEnergy_LEGL = enemyEditor->energyLeftLegItem->value().toDouble();
			objectInfo->fEnergy_LEGR = enemyEditor->energyRightLegItem->value().toDouble();
		objectInfo->fReactions = enemyEditor->reactionsItem->value().toDouble();
		objectInfo->fSpeed = enemyEditor->speedItem->value().toDouble();
		objectInfo->fAggr = enemyEditor->aggressivityItem->value().toDouble();
		objectInfo->fInt = enemyEditor->intelligenceItem->value().toDouble();
		objectInfo->fShooting = enemyEditor->shootingItem->value().toDouble();
		objectInfo->fSight = enemyEditor->sightItem->value().toDouble();
		objectInfo->fHearing = enemyEditor->hearingItem->value().toDouble();
		objectInfo->fDriving = enemyEditor->drivingItem->value().toDouble();
		objectInfo->fMass = enemyEditor->massItem->value().toDouble();
		objectInfo->fBehaviour = enemyEditor->behaviour2Item->value().toDouble();
		objectInfo->cBehaviour = (char)(enemyEditor->behaviour1Item->value().toInt());
		objectInfo->cVoice = (char)(enemyEditor->voiceItem->value().toInt());
	}
	else if( type == 6 && doorEditor->isChanged() )
	{
		objectInfo->bOpen1 = doorEditor->openDirection1Item->value().toBool();
		objectInfo->bOpen2 = doorEditor->openDirection2Item->value().toBool();
		objectInfo->fMoveAngle = CHelper::DoorAngleToVal( doorEditor->moveAngleItem->value().toDouble() );
		objectInfo->bOpen = doorEditor->isOpenItem->value().toBool();
		objectInfo->bLocked = doorEditor->isLockedItem->value().toBool();
		objectInfo->fCloseSpeed = doorEditor->closeSpeedItem->value().toDouble();
		objectInfo->fOpenSpeed = doorEditor->openSpeedItem->value().toDouble();
		objectInfo->bDoorFlag = doorEditor->flagItem->value().toBool();

		int i;
		for( i = 0; i < doorEditor->openSoundItem->value().toString().length(); i++ )
			objectInfo->sOpenSound[i] = doorEditor->openSoundItem->value().toString()[i];
		objectInfo->sOpenSound[++i] = 0;
		for( i = 0; i < doorEditor->closeSoundItem->value().toString().length(); i++ )
			objectInfo->sOpenSound[i] = doorEditor->closeSoundItem->value().toString()[i];
		objectInfo->sCloseSound[++i] = 0;
		for( i = 0; i < doorEditor->lockedSoundItem->value().toString().length(); i++ )
			objectInfo->sOpenSound[i] = doorEditor->lockedSoundItem->value().toString()[i];
		objectInfo->sLockedSound[++i] = 0;
	}
	else if( type == 12 && ( trafficEditor->isChanged() || trafficNameList->itemListView->childCount() != objectInfo->lNumOfCars ) )
	{
		TrafficItem * item = (TrafficItem*)(trafficNameList->itemListView->currentItem());
		if( item != 0 )
		{
			item->color = trafficEditor->curColorItem->value().toInt();
			item->density = trafficEditor->curDensityItem->value().toDouble();
			item->flag2 = trafficEditor->curFlag2Item->value().toBool();
			item->flag4 = trafficEditor->curFlag4Item->value().toBool();
			item->gangster = trafficEditor->curGangsterItem->value().toBool();
			item->police = trafficEditor->curPoliceItem->value().toBool();
		}

		for( int i = 0; i < objectInfo->lNumOfCars; i++ )
			for( int j = 0; j < 20; j++ )
				objectInfo->sCarname[i][j] = 0;

		i = 0;
		QListViewItemIterator it( trafficNameList->itemListView );
		while( it.current() )
		{
			item = (TrafficItem*)(it.current());

			for( int j = 0; j < item->text( 0 ).length(); j++ )
				objectInfo->sCarname[i][j] = item->text( 0 )[j].latin1();
			
			objectInfo->lColor[i] = item->color;
			objectInfo->fDensity[i] = item->density;
			objectInfo->bFlag2[i] = item->flag2;
			objectInfo->bFlag4[i] = item->flag4;
			objectInfo->bGangster[i] = item->gangster;
			objectInfo->bPolice[i] = item->police;
			objectInfo->bDel[i] = false;
			i++;
			it++;
		}

		objectInfo->fTrafficVal[0] = trafficEditor->trafficVal1Item->value().toDouble();
		objectInfo->fTrafficVal[1] = trafficEditor->trafficVal2Item->value().toDouble();
		objectInfo->fTrafficVal[2] = trafficEditor->trafficVal3Item->value().toDouble();
		objectInfo->lDensity = trafficEditor->densityItem->value().toInt();
		objectInfo->lNumOfCars = trafficNameList->itemListView->childCount();
	}
	else if( type == 18 && ( pedestrianEditor->isChanged() || pedestrianModelList->itemListView->childCount() != objectInfo->lNumOfPeds ) )
	{
		PedestrianItem * item = (PedestrianItem*)(pedestrianModelList->itemListView->currentItem());
		if( item != 0 )
		{
			item->density = pedestrianEditor->curDensityItem->value().toInt();
		}

		objectInfo->fPedVal[0] = pedestrianEditor->val1Item->value().toDouble();
		objectInfo->fPedVal[1] = pedestrianEditor->val2Item->value().toDouble();
		objectInfo->fPedVal[2] = pedestrianEditor->val3Item->value().toDouble();
		objectInfo->fPedVal[3] = pedestrianEditor->val4Item->value().toDouble();
		objectInfo->fPedVal[4] = pedestrianEditor->val5Item->value().toDouble();
		objectInfo->lGlobalPedDensity = pedestrianEditor->densityItem->value().toInt();
		objectInfo->lNumOfPeds = pedestrianModelList->itemListView->childCount();
		
		for( int i = 0; i < objectInfo->lNumOfPeds; i++ )
			for( int j = 0; j < 17; j++ )
				objectInfo->sPedname[i][j] = 0;

		i = 0;
		QListViewItemIterator it( pedestrianModelList->itemListView );
		while( it.current() )
		{
			item = (PedestrianItem*)(it.current());

			for( int j = 0; j < item->text( 0 ).length(); j++ )
				objectInfo->sPedname[i][j] = item->text( 0 )[j].latin1();

			objectInfo->lLocalPedDensity[i] = item->density;
			objectInfo->bDel[i] = false;
			i++;
			it++;
		}
	}
	else if( type == 35 && movingBoxEditor->isChanged() )
	{
		objectInfo->lSound = movingBoxEditor->soundItem->value().toInt();
		objectInfo->fMovVal1 = movingBoxEditor->value1Item->value().toDouble();
		objectInfo->fMovVal2 = movingBoxEditor->value2Item->value().toDouble();
		objectInfo->fMovVal3 = movingBoxEditor->frictionItem->value().toDouble();
		objectInfo->fMovVal4 = movingBoxEditor->value4Item->value().toDouble();
		objectInfo->lMovVal5 = movingBoxEditor->value5Item->value().toInt();
		objectInfo->fWeight = movingBoxEditor->weightItem->value().toDouble();
	}

	if( type == 5 || type == 27 || init == true )
	{
		sceneWrapper->SaveObjectScript( name, scriptInput->text(), init );
		main_widget->mySceneOverview->currentDocument()->myScriptMainWindow->previewScriptTextEdit->setText( script );
		status_bar->message( tr( "Object definition saved." ), 3000 );
	}
	
	switch( type )
	{
	case 2:
		objectInfo->lType = SPECIAL_OBJECT_TYPE_PLAYER;
		break;
	case 6:
		objectInfo->lType = SPECIAL_OBJECT_TYPE_DOOR;
		break;
	case 12:
		objectInfo->lType = SPECIAL_OBJECT_TYPE_TRAFFIC;
		break;
	case 18:
		objectInfo->lType = SPECIAL_OBJECT_TYPE_PEDS;
		break;
	case 27:
		objectInfo->lType = SPECIAL_OBJECT_TYPE_CHARACTER;
		break;
	case 35:
		objectInfo->lType = SPECIAL_OBJECT_TYPE_SHOOTABLE;
		break;
	default:
		return;
	}

	sceneWrapper->SaveObject( objectInfo, name, FALSE );
	delete objectInfo;
	status_bar->message( tr( "Object definition saved." ), 3000 );
}

bool ScriptWidget::isChanged()
{
	if( ( type == 5 || type == 27 || init == true ) && scriptInput->isModified() )
		return true;
	if( type != 5 && init == false )
		return propertyEditor->isChanged();
	return false;
}

void ScriptWidget::setInputFields( const char * nName, int nType, QString nScript, ObjectInfo_t * nObjectInfo /* = 0 */ )
{
	name = nName;
	type = nType;
	if( type == 5 || type == 27 || init == true )
	{
		script = nScript;
		scriptInput->setText( script.stripWhiteSpace() );
		setLineNumbers();
		scriptInput->setFocus();
		scriptInput->setCursorPosition( 0, 0 );
	}

	setCaption( QString::number( type ) + " - " + name );

	if( type == 2 || type == 27 )
	{
		enemyEditor->strengthItem->setValue( objectInfo->fStrenght, TRUE );
		enemyEditor->energyItem->setValue( objectInfo->fEnergy, TRUE );
			enemyEditor->energyLeftHandItem->setValue( objectInfo->fEnergy_HANDL, TRUE );
			enemyEditor->energyRightHandItem->setValue( objectInfo->fEnergy_HANDR, TRUE );
			enemyEditor->energyLeftLegItem->setValue( objectInfo->fEnergy_LEGL, TRUE );
			enemyEditor->energyRightLegItem->setValue( objectInfo->fEnergy_LEGR, TRUE );
		enemyEditor->reactionsItem->setValue( objectInfo->fReactions, TRUE );
		enemyEditor->speedItem->setValue( objectInfo->fSpeed, TRUE );
		enemyEditor->aggressivityItem->setValue( objectInfo->fAggr, TRUE );
		enemyEditor->intelligenceItem->setValue( objectInfo->fInt, TRUE );
		enemyEditor->shootingItem->setValue( objectInfo->fShooting, TRUE );
		enemyEditor->sightItem->setValue( objectInfo->fSight, TRUE );
		enemyEditor->hearingItem->setValue( objectInfo->fHearing, TRUE );
		enemyEditor->drivingItem->setValue( objectInfo->fDriving, TRUE );
		enemyEditor->massItem->setValue( objectInfo->fMass, TRUE );
		enemyEditor->behaviour2Item->setValue( objectInfo->fBehaviour, TRUE );
		enemyEditor->behaviour1Item->setValue( (int)(objectInfo->cBehaviour), TRUE );
		enemyEditor->voiceItem->setValue( (int)(objectInfo->cVoice), TRUE );
	}
	else if( type == 6 )
	{
		doorEditor->openDirection1Item->setValue( objectInfo->bOpen1, TRUE );
		doorEditor->openDirection1Item->setValue( objectInfo->bOpen2, TRUE );
		doorEditor->moveAngleItem->setValue( CHelper::DoorValToAngle( objectInfo->fMoveAngle ), TRUE );
		doorEditor->isOpenItem->setValue( objectInfo->bOpen, TRUE );
		doorEditor->isLockedItem->setValue( objectInfo->bLocked, TRUE );
		doorEditor->openSpeedItem->setValue( objectInfo->fOpenSpeed, TRUE );
		doorEditor->closeSpeedItem->setValue( objectInfo->fCloseSpeed, TRUE );
		doorEditor->openSoundItem->setValue( QString( objectInfo->sOpenSound ), TRUE );
		doorEditor->closeSoundItem->setValue( QString( objectInfo->sCloseSound ), TRUE );
		doorEditor->lockedSoundItem->setValue( QString( objectInfo->sLockedSound ), TRUE );
		doorEditor->flagItem->setValue( objectInfo->bDoorFlag, TRUE );
	}
	else if( type == 12 )
	{
		trafficEditor->trafficVal1Item->setValue( objectInfo->fTrafficVal[0], TRUE );
		trafficEditor->trafficVal2Item->setValue( objectInfo->fTrafficVal[1], TRUE );
		trafficEditor->trafficVal3Item->setValue( objectInfo->fTrafficVal[2], TRUE );
		trafficEditor->densityItem->setValue( objectInfo->lDensity, TRUE );
		trafficNameList->itemListView->clear();
		for( int i = 0; i < objectInfo->lNumOfCars; i++ )
		{			
			TrafficItem * item = (TrafficItem*)(trafficNameList->insertItem( QString( objectInfo->sCarname[i] ) ));
			item->color = objectInfo->lColor[i];
			item->density = objectInfo->fDensity[i];
			item->flag2 = objectInfo->bFlag2[i];
			item->flag4 = objectInfo->bFlag4[i];
			item->gangster = objectInfo->bGangster[i];
			item->police = objectInfo->bPolice[i];
		}
		trafficNameList->itemListView->setCurrentItem( trafficNameList->itemListView->lastItem() );
		trafficNameList->itemListView->setCurrentItem( trafficNameList->itemListView->firstChild() );
	}
	else if( type == 18 )
	{
		pedestrianEditor->val1Item->setValue( objectInfo->fPedVal[0], TRUE );
		pedestrianEditor->val2Item->setValue( objectInfo->fPedVal[1], TRUE );
		pedestrianEditor->val3Item->setValue( objectInfo->fPedVal[2], TRUE );
		pedestrianEditor->val4Item->setValue( objectInfo->fPedVal[3], TRUE );
		pedestrianEditor->val5Item->setValue( objectInfo->fPedVal[4], TRUE );
		pedestrianEditor->densityItem->setValue( objectInfo->lGlobalPedDensity, TRUE );
		pedestrianModelList->itemListView->clear();
		for( int i = 0; i < objectInfo->lNumOfPeds; i++ )
		{
			PedestrianItem * item = (PedestrianItem*)(pedestrianModelList->insertItem( QString( objectInfo->sPedname[i] ) ));
			item->density = objectInfo->lLocalPedDensity[i];
		}

		pedestrianModelList->itemListView->setCurrentItem( pedestrianModelList->itemListView->lastItem() );
		pedestrianModelList->itemListView->setCurrentItem( pedestrianModelList->itemListView->firstChild() );
	}
	else if( type == 35 )
	{
		movingBoxEditor->soundItem->setValue( objectInfo->lSound, TRUE );
		movingBoxEditor->value1Item->setValue( objectInfo->fMovVal1, TRUE );
		movingBoxEditor->value2Item->setValue( objectInfo->fMovVal2, TRUE );
		movingBoxEditor->frictionItem->setValue( objectInfo->fMovVal3, TRUE );
		movingBoxEditor->value4Item->setValue( objectInfo->fMovVal4, TRUE );
		movingBoxEditor->value5Item->setValue( objectInfo->lMovVal5, TRUE );
		movingBoxEditor->weightItem->setValue( objectInfo->fWeight, TRUE );
	}
}

void ScriptWidget::setLineNumbers( int i )
{
	QString lineString;
	for( int lines = 1; lines <= scriptInput->paragraphs() + i; lines++ )
	{
		lineString.append( QString::number( lines ) + "\n" );
	}
	lineNumbers->setText( lineString );
}

void ScriptWidget::updateProperties()
{
	if( type == 12 )
	{
		TrafficItem * item = (TrafficItem*)(trafficNameList->itemListView->findItem( trafficEditor->curNameItem->value().toString(), 0 ));

		if( item != 0 )
		{
			item->color = trafficEditor->curColorItem->value().toInt();
			item->density = trafficEditor->curDensityItem->value().toDouble();
			item->flag2 = trafficEditor->curFlag2Item->value().toBool();
			item->flag4 = trafficEditor->curFlag4Item->value().toBool();
			item->gangster = trafficEditor->curGangsterItem->value().toBool();
			item->police = trafficEditor->curPoliceItem->value().toBool();

			item->nameChanged = trafficEditor->curNameItem->isChanged();
			item->colorChanged = trafficEditor->curColorItem->isChanged();
			item->densityChanged = trafficEditor->curDensityItem->isChanged();
			item->flag2Changed = trafficEditor->curFlag2Item->isChanged();
			item->flag4Changed = trafficEditor->curFlag4Item->isChanged();
			item->gangsterChanged = trafficEditor->curGangsterItem->isChanged();
			item->policeChanged = trafficEditor->curPoliceItem->isChanged();
		}
		
		item = (TrafficItem*)(trafficNameList->itemListView->currentItem());
		trafficEditor->curColorItem->setValue( item->color, !item->colorChanged );
		trafficEditor->curDensityItem->setValue( item->density, !item->densityChanged );
		trafficEditor->curFlag2Item->setValue( item->flag2, !item->flag2Changed );
		trafficEditor->curFlag4Item->setValue( item->flag4, !item->flag4Changed );
		trafficEditor->curGangsterItem->setValue( item->gangster, !item->gangsterChanged );
		trafficEditor->curNameItem->setValue( item->text( 0 ), !item->nameChanged );
		trafficEditor->curPoliceItem->setValue( item->police, !item->policeChanged );
	}
	else if( type == 18 )
	{
		PedestrianItem * item = (PedestrianItem*)(pedestrianModelList->itemListView->findItem( pedestrianEditor->curNameItem->value().toString(), 0 ));
		if( item != 0 )
		{
			item->density = pedestrianEditor->curDensityItem->value().toInt();

			item->densityChanged = pedestrianEditor->curDensityItem->isChanged();
			item->nameChanged = pedestrianEditor->curNameItem->isChanged();
		}

		item = (PedestrianItem*)(pedestrianModelList->itemListView->currentItem());
		pedestrianEditor->curDensityItem->setValue( item->density, !item->densityChanged );
		pedestrianEditor->curNameItem->setValue( item->text( 0 ), !item->nameChanged );
	}
}
