#include <qapplication.h>
#include <qcombobox.h>
#include <qdir.h>
#include <qfiledialog.h>
#include <qframe.h>
#include <qinputdialog.h>
#include <qlistview.h>
#include <qmessagebox.h>
#include <qstringlist.h>

#include "addobjectdialog.h"
#include "documentwidget.h"
#include "documentoverview.h"
#include "filterlistdialog.h"
#include "mafiasyntax.h"
#include "mainwidget.h"
#include "objectlist.h"
#include "objectwidget.h"
#include "questiondialog.h"
#include "scenepropertiesdialog.h"
#include "scriptmainwindow.h"
#include "scriptworkspace.h"

DocumentOverview::DocumentOverview( QWidget * parent, const char * name )
				: QVBox( parent, name )
{
	tabOverview = 0;
	documentWorkspace = new QWorkspace( this, "documentWorkspace" );
	documentWorkspace->setScrollBarsEnabled( true );
	documentWorkspace->setChangeTopLevelCaption( TRUE );
	documentList.setAutoDelete( true );

	QFrame * myFrame = new QFrame( this );
	myFrame->setFrameShape( QFrame::TabWidgetPanel );
	
	documentTabBar = new QTabBar( this, "documentTabBar" );
	documentTabBar->setShape( QTabBar::RoundedBelow );
	documentTabBar->show();

	connect( documentTabBar, SIGNAL( selected( int ) ), this, SLOT( changeDocument( int ) ) );
	connect( documentWorkspace, SIGNAL( windowActivated( QWidget * ) ), this, SLOT( changeDocument( QWidget * ) ) );
}

DocumentOverview::~DocumentOverview()
{
	closeAll();
}

void DocumentOverview::changeDocument( int number )
{
	for( uint i = 0; i < documentList.count(); i++ )
		if( documentList.at( i )->tabId == documentTabBar->currentTab() )
		{
			documentList.at( i )->setFocus();
			return;
		}
}


void DocumentOverview::changeDocument( QWidget * widget )
{
	for( uint i = 0; i < documentList.count(); i++ )
		if( documentList.at( i ) == widget )
		{
			documentTabBar->setCurrentTab( documentList.at( i )->tabId );
			return;
		}
}

void DocumentOverview::closeAll()
{
	for( uint i = 0; i < documentList.count(); i++ )
	{
		documentList.at( i )->setFocus();
		((MainWidget*)parent())->CloseFile();
		qApp->processEvents();
	}
}

void DocumentOverview::closeDocument()
{
	documentTabBar->removeTab( documentTabBar->tab( currentDocument()->tabId ) );
	documentList.remove( documentList.at() );
	documentTabBar->update();

	status_bar->message( tr( "File closed." ), 5000 );
}

int DocumentOverview::count()
{
	return documentList.count();
}

DocumentWidget * DocumentOverview::currentDocument()
{
	return documentList.current();
}

DocumentWidget * DocumentOverview::findDocument( QString name )
{
	for( uint i = 0; i < documentList.count(); i++ )
		if( documentList.at( i )->name() == name )
			return documentList.at( i );
	return 0;
}

bool DocumentOverview::openDocument( QFileInfo file ) 
{
	if( file.exists() == FALSE )
		return TRUE;

	if( findDocument( file.absFilePath() ) == 0 )
	{
		documentTabBar->insertTab( new QTab( file.dir().dirName() + "\\" + file.fileName() ), documentTabBar->count() );
		documentTabBar->update();
		documentTabBar->setCurrentTab( tabOverview );
		documentTabBar->currentTab();

		documentList.append( new DocumentWidget( documentWorkspace, file.absFilePath().latin1(), documentTabBar->currentTab() ) );

		currentDocument()->show();

		documentTabBar->update();
		documentTabBar->setCurrentTab( tabOverview );

		connect( currentDocument(), SIGNAL( closeSignal() ), (MainWidget*)(parent()), SLOT( CloseFile() ) );
		tabOverview++;	
		return FALSE;
	}
	else
	{
		changeDocument( findDocument( file.absFilePath() ) );
		return TRUE;
	}
}



/************************************************************************/
/*                                                                      */
/*                           SceneOverview                              */
/*                                                                      */
/************************************************************************/

SceneOverview::SceneOverview( QWidget * parent )
			 : DocumentOverview( parent, "SceneOverview" )
{
	addObjectDialog = new AddObjectDialog( this );
	addObjectDialog->hide();

	//connecting signals and slots
	connect( sceneWrapper, SIGNAL( addObjectToList( char *, int, short ) ), this, SLOT( addListItem( char *, int, short ) ) );
	connect( sceneWrapper, SIGNAL( objectCreated( char *, int, short ) ), this, SLOT( createListItem( char *, int, short ) ) );
}

SceneOverview::~SceneOverview()
{
}

void SceneOverview::addListItem( char * name, int type, short datablock )
{
	if( currentDocument() )
		currentDocument()->myObjectList->addListItem( QString( name ), type, datablock );
}

void SceneOverview::applySettings()
{
	for( uint i = 0; i < documentList.count(); i++ )
	{
		documentList.at( i )->myScriptMainWindow->myScriptWorkspace->applySettings();
		documentList.at( i )->myScriptMainWindow->scriptSyntax->reloadSettings();
		documentList.at( i )->myScriptMainWindow->scriptSyntax->reinitialise();
	}
}

void SceneOverview::changeDocument( QWidget * widget )
{
	DocumentOverview::changeDocument( widget );
	if( documentList.count() == 0 )
		return;
	sceneWrapper->CloseScene2Bin( false );
	sceneWrapper->LoadScene2Bin( QFileInfo( currentDocument()->name() ) );
}

void SceneOverview::closeDocument()
{
	bool askAgain = settings->readBoolEntry( "ask_again/close_document", TRUE );
	int question = QMessageBox::question( this, tr( "Save before closing?" ),
												tr( "Do you want to save this scene2.bin before you close it?" ),
												tr( "Yes" ), tr( "No" ), tr( "Cancel" ), 0, 2 );
		/*QuestionDialog::question( this, tr( "Save before closing?" ),
											 tr( "Do you want to save this scene2.bin before you close it?" ),
											 askAgain, TRUE );*/
	if( question == 2 )
		return;
	bool safe = FALSE;
	if( question == 0 )
		safe = TRUE;
	sceneWrapper->CloseScene2Bin( safe );

	disconnect( currentDocument(), SIGNAL( closeSignal() ), (MainWidget*)(parent()), SLOT( CloseFile() ) );
	disconnect( currentDocument()->myObjectList, SIGNAL( currentChanged( QListViewItem * ) ), this, SLOT( setPreview( QListViewItem * ) ) );
	disconnect( currentDocument()->myObjectList, SIGNAL( doubleClicked( QListViewItem *) ), this, SLOT( openObject( QListViewItem * ) ) );
	disconnect( currentDocument()->myObjectList, SIGNAL( returnPressed( QListViewItem *) ), this, SLOT( openObject( QListViewItem * ) ) );
	disconnect( currentDocument()->myObjectList, SIGNAL( itemRenamed( QString, QString, Type ) ), this, SLOT( renameObject( QString, QString, Type ) ) );
	disconnect( currentDocument()->myScriptMainWindow->myScriptWorkspace, SIGNAL( saveScript( char *, char *, int, bool ) ), sceneWrapper, SLOT( SaveObjectScript( char *, char *, int, bool ) ) );

	DocumentOverview::closeDocument();
}

void SceneOverview::createListItem( char * name, int type, short datablock )
{
	if( currentDocument() )
		currentDocument()->myObjectList->insertListItem( QString( name ), type, datablock );
}

void SceneOverview::createTemplate()
{
        if( QMessageBox::warning( this, tr( "Are you sure?"), tr( "Do you really want to make a template out of this scene2? "
                "This will mean that ALL cars, actors and scripts will be deleted! Note that this will take almost a minute!" ), tr( "Yes" ), tr( "No" ),
                QString::null, 1, 1 ) == 1 )
                return; // if the user pressed no, don't create a template.

        currentDocument()->myScriptMainWindow->myScriptWorkspace->closeAllWindows();
        currentDocument()->myObjectList->reset();
        sceneWrapper->NewTemplate();
        sceneWrapper->BuildObjectList();
}

void SceneOverview::deleteObject()
{
	currentDocument()->myObjectList->deleteItem();
}

void SceneOverview::exportObject()
{
	ObjectList * listView = currentDocument()->myObjectList;
	QListViewItem * item = listView->currentItem();
	Type type = listView->getItemDatablock( item );
	short nDatablockType = eType2sType( type );
	int group = listView->getItemGroup( item );
	QString * selectedFilter = new QString();
	QString filename;

	if( nDatablockType == 0 )
		return;

	/*
	 *	If the user selected an object definition with a script (or an INIT script), he has now the option to extract either
	 *	the script into a .txt text file or the whole object (including the script) into a .dnc file.
	 *	The .dnc file can only be read by DC||ED.
	 */
	if( ( type == ObjDef && ( group == 5 || group == 27 ) ) || type == Init )
	{
		QString filename = QFileDialog::getSaveFileName( "./save/" + item->text( 0 ), tr( "DC||ED files( *.dnc );;Text files( *.txt )" ), this, "Export Object File Dialog", "Export Object", selectedFilter );

		if( selectedFilter->compare( tr( "DC||ED files( *.dnc )" ) ) == 0 )
		{
			if( filename.right( 4 ).lower() != ".dnc" )
				filename += ".dnc";
			sceneWrapper->ExportObject( filename, item->text( 0 ), nDatablockType );
		}
		else
		{
			if( filename.right( 4 ).lower() != ".txt" )
				filename += ".txt";
			sceneWrapper->ExportObjectScript( filename, item->text( 0 ), nDatablockType );			
		}
	}
	/*
	 *	If the user didn't select an object definition with a script but an object or sth. else,
	 *	he can only export it into a .dnc file.
	 */
	else
	{
		QString filename = QFileDialog::getSaveFileName( "./save/" + item->text( 0 ), tr( "DC||ED files( *.dnc )" ), this, "Export Object File Dialog", "Export Object", selectedFilter );
		if( filename.right( 4 ) != ".dnc" )
			filename += ".dnc";
		
		sceneWrapper->ExportObject( filename, item->text( 0 ), nDatablockType );
	}
}

void SceneOverview::listInits( bool on )
{
	for( uint i = 0; i < documentList.count(); i++ )
		documentList.at( i )->myObjectList->initTree->setVisible( on );
}

void SceneOverview::listObjDefs( bool on )
{
	for( uint i = 0; i < documentList.count(); i++ )
		documentList.at( i )->myObjectList->objectDefinitionsTree->setVisible( on );
}

void SceneOverview::listObjects( bool on )
{
	for( uint i = 0; i < documentList.count(); i++ )
		documentList.at( i )->myObjectList->objectsTree->setVisible( on );
}

void SceneOverview::importObject()
{
	QString * selectedFilter = new QString();
	QString filename = QFileDialog::getOpenFileName( "./", tr( "DONCity Files( *.dnc );;Text files( *.txt )" ), this, "Import Object File Dialog", tr( "Import Object" ), selectedFilter );

	if( filename == "" || !filename )
		return;

	if( filename.right( 4 ).lower() == ".dnc" )
	{
		BasicObjectInfo_t * o = sceneWrapper->ReadObjectFile( filename );
		QString name = QString( o->name );

		for( bool exists = currentDocument()->myObjectList->exists( o->nDatablock, name );
			 exists == TRUE;
			 exists = currentDocument()->myObjectList->exists( o->nDatablock, name ) )
			name = QInputDialog::getText( tr( "Enter a name" ),
										  tr( "Sorry, this object name already exists. Please choose another one:" ) );

		currentDocument()->myObjectList->addListItem( name, o->iObjectType, o->nDatablock );
		sceneWrapper->ImportObject( filename );
		delete o;
	}
	else if( filename.right( 4 ).lower() == ".txt" )
	{
		QString name;
		for( bool exists = TRUE; exists; exists = currentDocument()->myObjectList->exists( SPECIAL_MAIN, name ) )
			name = QInputDialog::getText( tr( "Script Name" ), tr( "Please choose a name for the script to be imported" ) );;
	
		sceneWrapper->ImportObjectScript( name, filename );
	}
	else
	{
		QMessageBox::warning( this, tr( "Unknown file extension" ),
							  tr( "Unknown file extension" ) + " \"" + filename.right( 4 ) + "\"." );
		return;
	}

	currentDocument()->myObjectList->reset();
	sceneWrapper->BuildObjectList();
	status_bar->message( "Object from file " + QFileInfo( filename ).fileName() + " imported.", 5000 );
}

bool SceneOverview::openDocument( QFileInfo file )
{	
	bool exists = DocumentOverview::openDocument( file );
	if( exists )
		return TRUE;

	sceneWrapper->CloseScene2Bin();
	sceneWrapper->LoadScene2Bin( file );
	sceneWrapper->BuildObjectList();
	sceneWrapper->SetCopyrightText();

	//filling sector boxes 
    QStringList sectorList( sceneWrapper->getSectorList() ); 
    currentDocument()->myObjectWidget->sectorComboBox->insertStringList( sectorList ); 
    currentDocument()->myObjectWidget->lightSectorComboBox->insertStringList( sectorList );

	connect( currentDocument()->myObjectList, SIGNAL( currentChanged( QListViewItem * ) ), this, SLOT( setPreview( QListViewItem * ) ) );
	connect( currentDocument()->myObjectList, SIGNAL( clicked( QListViewItem *) ), this, SLOT( openObject( QListViewItem * ) ) );
	connect( currentDocument()->myObjectList, SIGNAL( returnPressed( QListViewItem *) ), this, SLOT( openObject( QListViewItem * ) ) );
	connect( currentDocument()->myObjectList, SIGNAL( doubleClicked( QListViewItem *) ), this, SLOT( openObjDef( QListViewItem * ) ) );
	connect( currentDocument()->myObjectList, SIGNAL( returnPressed( QListViewItem *) ), this, SLOT( openObjDef( QListViewItem * ) ) );
	connect( currentDocument()->myObjectList, SIGNAL( itemRenamed( QString, QString, Type ) ), this, SLOT( renameObject( QString, QString, Type ) ) );
	connect( currentDocument()->myScriptMainWindow->myScriptWorkspace, SIGNAL( saveScript( char *, char *, int, bool ) ), this, SLOT( saveObjectScript( char *, char *, int, bool ) ) );
	connect( currentDocument()->myScriptMainWindow->myScriptWorkspace, SIGNAL( saveEnemy( ObjectInfo_t *, int ) ), this, SLOT( saveEnemy( ObjectInfo_t *, int ) ) );
	return FALSE;
}


void SceneOverview::openObjDef( QListViewItem * item )
{
	if( item == 0 )
		item = currentDocument()->myObjectList->currentItem();
	int group = currentDocument()->myObjectList->getItemGroup( item );
	if( group == -1 )
		return;
	Type datablock = currentDocument()->myObjectList->getItemDatablock( item );
	
	if( datablock == ObjDef )
	{
		switch( group )
		{
		case 2:
			break;
		case 5:
			break;
		case 6:
			break;
		case 12:
			break;
		case 18:
			break;
		case 27:
			break;
		case 35:
			break;
		default:
			return;
		}
		if( group == 5 )
		{
			currentDocument()->myScriptMainWindow->myScriptWorkspace->addScriptWidget( item->text( 0 ),	group,
						sceneWrapper->ReadObjectScript( item->text( 0 ), false ), false );
		}
		else
		{
			QString script = QString::null;
			if( group == 27 )
				script = sceneWrapper->ReadObjectScript( item->text( 0 ), false );
			currentDocument()->myScriptMainWindow->myScriptWorkspace->addScriptWidget( item->text( 0 ), group, script, false,
						sceneWrapper->ReadObject( item->text( 0 ), false, SPECIAL_MAIN ) );
		}
	}
	else if( datablock == Init )
	{
		currentDocument()->myScriptMainWindow->myScriptWorkspace->addScriptWidget( item->text( 0 ), group,
					sceneWrapper->ReadObjectScript( item->text( 0 ), true ), true );
	}
}

void SceneOverview::openObject( QListViewItem * item )
{
	if( item == 0 )
		item = currentDocument()->myObjectList->currentItem();
	Type datablock = currentDocument()->myObjectList->getItemDatablock( item );
	int group = currentDocument()->myObjectList->getItemGroup( item );
	if( group == -1 )
		return;

	if( datablock == Object )
	{
		ObjectInfo_t * currentObject = sceneWrapper->ReadObject( item->text( 0 ) );
		currentDocument()->myObjectWidget->setInputFields( currentObject, item );
	}
}

void SceneOverview::quickSearch( const QString & text )
{
	currentDocument()->myObjectList->quickSearch( text );
}

void SceneOverview::renameObject( QString newName, QString oldName, Type type )
{
	sceneWrapper->EditObjectName( oldName, newName, eType2sType( type ) );
	status_bar->message( tr( "Object renamed." ), 5000 );
}

void SceneOverview::saveAllDocuments()
{
	for( uint i = 0; i < documentList.count(); i++ )
	{
		documentList.at( i )->setFocus();
		saveDocument();
		qApp->processEvents();
	}
}

void SceneOverview::saveDocument()
{
	currentDocument()->save();
	sceneWrapper->SaveScene2Bin();
}

void SceneOverview::setListDockVisible()
{
	if( documentList.at( documentTabBar->currentTab() )->scriptDock->isHidden() == false )
		documentList.at( documentTabBar->currentTab() )->scriptDock->hide();
	else
		documentList.at( documentTabBar->currentTab() )->scriptDock->show();
}

//In this function I call a preview of the current item.
//If the current item is an object, I call ReadObject and
// give the function the name of the object as parameter.
// item->text( 0 ) returns the text of the first column
// as a QString (where item is the selected item).
// QString::latin1() converts the QString into a const
// char *, and the (char *) cast in front of it is there
// because M$ shit file handle only takes a char * as
// parameter (even if const char * would do it's job, too!)
//Otherwise, if the current item is an init script, I read
// the text of the current item via ReadObjectScript( char *
// objectName, bool isInitScript = true ).
//And if it isn't an init script, I do nearly the same
// (bool isInitScript is of course set to false). The only
// thing I do before is check wether item is a valid script.
// I do that via checking wether the text of the second
// column (type column) is 5 or 27.
void SceneOverview::setPreview( QListViewItem * item )
{
	Type datablock = currentDocument()->myObjectList->getItemDatablock( item );
	int group = currentDocument()->myObjectList->getItemGroup( item );
	if( group == -1 )
		return;

	if( datablock == ObjDef )
	{
		if( group == 5 || group == 27 )
		{
			currentDocument()->myScriptMainWindow->previewScriptTextEdit->setText( sceneWrapper->ReadObjectScript( item->text( 0 ) ) );
			if( !currentDocument()->myScriptMainWindow->previewScriptTextEdit->isVisible() )
				setScriptPreviewVisible();
		}
		else if( currentDocument()->myScriptMainWindow->previewScriptTextEdit->isVisible() )
			setScriptPreviewVisible();		
	}
	else if( datablock == Init )
	{
		currentDocument()->myScriptMainWindow->previewScriptTextEdit->setText( sceneWrapper->ReadObjectScript( item->text( 0 ), true ) );
		if( !currentDocument()->myScriptMainWindow->previewScriptTextEdit->isVisible() )
				setScriptPreviewVisible();
	}
}

void SceneOverview::setScriptPreviewVisible()
{
	if( currentDocument()->myScriptMainWindow->scriptPreviewDock->isHidden() == false )
		currentDocument()->myScriptMainWindow->scriptPreviewDock->hide();
	else
		currentDocument()->myScriptMainWindow->scriptPreviewDock->show();
}

void SceneOverview::showSceneProperties()
{
	currentDocument()->myScenePropertiesDialog->show();
}
