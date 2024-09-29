#include "listtab.h"
#include "Datablock.h"
#include <qmessagebox.h>
#include <qheader.h>

ListTab::ListTab( QWidget * parent, const char * name )
		: QTabWidget( parent, name )
{
	//Creating listview objectsTree
	objectsTree = new QListView( this, "ObjectsTree" );
	objectsTree->addColumn( tr( "Name" ), 156 );
	objectsTree->addColumn( tr( "Type" ), 50 );
	//objectsTree->addColumn( tr( "Sector" ), 100 );
	//objectsTree->addColumn( tr( "Model" ), 100 );
	objectsTree->header()->setMovingEnabled( false );
	objectsTree->setResizeMode( QListView::LastColumn );
	objectsTree->setSorting( 1 );
	objectsTree->setAllColumnsShowFocus( TRUE );
	
	//Creating listview objectDefinitionsTree
	objectDefinitionsTree = new QListView( this, "ObjectDefinitionsTree" );
	objectDefinitionsTree->addColumn( tr( "Name" ), 156 );
	objectDefinitionsTree->addColumn( tr( "Type" ), 50 );
	objectDefinitionsTree->header()->setMovingEnabled( false );
	objectDefinitionsTree->setResizeMode( QListView::LastColumn );
	objectDefinitionsTree->setSorting( 1 );
	objectDefinitionsTree->setAllColumnsShowFocus( TRUE );

	lightmapTree = new QListView( this, "LightmapTree" );
	lightmapTree->addColumn( tr( "Name" ), 156 );
	lightmapTree->setResizeMode( QListView::LastColumn );
	lightmapTree->setSorting( 0 );
	lightmapTree->setAllColumnsShowFocus( TRUE );

	sectorTree = new QListView( this, "SectorTree" );
	sectorTree->addColumn( tr( "Name" ), 156 );
	sectorTree->setResizeMode( QListView::LastColumn );
	sectorTree->setSorting( 0 );
	sectorTree->setAllColumnsShowFocus( TRUE );

	initScriptTree = new QListView( this, "InitScriptTree" );
	initScriptTree->addColumn( tr( "Name" ), 156 );
	initScriptTree->setResizeMode( QListView::LastColumn );
	initScriptTree->setSorting( 0 );
	initScriptTree->setAllColumnsShowFocus( TRUE );

	//Creating the tabs
	addTab( objectsTree, tr( "Objects" ) );
	addTab( objectDefinitionsTree, tr( "Object Definitions" ) );
	addTab( lightmapTree, tr( "Lightmaps" ) );
	addTab( sectorTree, tr( "Sectors" ) );
	addTab( initScriptTree, tr("Init Scripts" ) );
	
	//Setting the comments
	setTabToolTip( objectsTree,
		tr( "This is a list of all objects in this scene2.bin.\nTo change the properties of an object, select it and change the values shown in the right frame.\nTo rename an object, press F2." ) );
	setTabToolTip( objectDefinitionsTree,
		tr( "This is a list of all object definitions (scripts) in this scene2.bin.\nTo change a script, double click on it and a new window will be opened inside the workspace on the right.\nYou can change the name of a script by pressing F2." ) );
	setTabToolTip( lightmapTree,
		tr( "This is a list of all lightmaps in this scene2.bin." ) );
	setTabToolTip( sectorTree,
		tr( "This is a list of all sectors in this scene2.bin.\nSectors are a kind of frames. You can group some objects into sectors and make every of these objects move if one of them does.\nSectors are very important as soon as you use lightmaps.\nYou surely noticed that Yellow Pete's cellar in Freeride has another lights than outside. The sun doesn't shine in there.\n That's because of the sectors. Without sectors, the sun would still shine in there." ) );
}

void ListTab::addListItem( char * name, int type, short datablock )
{
	//Here I add several zeroes at the beginning of the type so that I can sort them.
	//Otherwise it would be like this:
	//1, 10, 11, 12, 13, ..., 19, 2, 20, 21, ... and so on.
	QString typeString;
	if( type < 10 )
		typeString = "0" + QString::number( type );
	else
		typeString = QString::number( type );

	QListView * parentList = 0;
	switch( datablock )
	{
	case NORMAL_MAIN:
		switch( type )
		{
		case NORMAL_OBJECT_TYPE_LIGHTMAP:
			parentList = lightmapTree;
			break;
		case NORMAL_OBJECT_TYPE_SECTOR:
			parentList = sectorTree;
			break;
		default:
			parentList = objectsTree;
			break;
		}
		break;

	case SPECIAL_MAIN:
		parentList = objectDefinitionsTree;
		break;

	case ADDITIONAL_MAIN:
		parentList = initScriptTree;
		break;

	/*default:
		QMessageBox::critical( this, "Error", QString( "Unknown object type %1 in datablock %2! Please contact writetotom@web.de and report this bug!").arg( QString::number( type ), QString::number( datablock ) ) );
		break;*/
	}

	if( parentList != 0 )
		new QListViewItem( parentList, QString( name ), typeString, QString( name ) );
}

void ListTab::keyPressEvent( QKeyEvent * eventKey )
{
	if( eventKey->key() == Qt::Key_F2 ) {
		currentTree->currentItem()->setRenameEnabled( 0, true );
		currentTree->currentItem()->startRename( 0 );
	}
}

void ListTab::filterCurrent( QString searchForName, int nameSearchMode, int minID, int maxID, QValueList<int> onlyType )
{
	QListViewItemIterator it( currentTree );
	
	while( it.current() )
	{
		//Hides all entries that begin with, contain or end with the string searchForName
		if( searchForName != "" && nameSearchMode != -1 )
		{
			switch( nameSearchMode )
			{
			case 0:
				if( !it.current()->text( 0 ).startsWith( searchForName ) )
					it.current()->setVisible( false );
					break;
			case 1:
				if( !it.current()->text( 0 ).contains( searchForName ) )
					it.current()->setVisible( false );
					break;
			case 2:			
				if( !it.current()->text( 0 ).endsWith( searchForName ) )
					it.current()->setVisible( false );
					break;
			}
		};

		//Hides all entries that have a lower ID than minID
		if( minID != -1 && it.current()->text( 2 ).toInt() < minID )
			it.current()->setVisible( false );

		//Hides all entries that have a higher ID than maxID
		if( maxID != -1 && it.current()->text( 2 ).toInt() > maxID )
			it.current()->setVisible( false );
	
		//Hides all entries that don't have the type specified in "type".
		if( onlyType.count() != 0)
		{
			it.current()->setVisible( false );
			for( ushort i = 0; i < onlyType.count(); i++ )
				if( onlyType[i] == it.current()->text( 3 ).toInt() )
					it.current()->setVisible( true );
		}

		++it;
	}
}