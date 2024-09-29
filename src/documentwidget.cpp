#include "documentwidget.h"
#include "documentoverview.h"
#include "objectlist.h"
#include "objectwidget.h"
#include "scenepropertiesdialog.h"
#include "scriptmainwindow.h"
#include "scriptworkspace.h"

#include <qapplication.h>
#include <qlistview.h>
#include <qmessagebox.h>
#include <qworkspace.h>
#include "img\openterm.xpm"

DocumentWidget::DocumentWidget( QWidget* parent, const char* name, int Id, WFlags fl )
			  : QMainWindow( parent, name, fl )
{	tabId = Id;

	setCaption( QFileInfo( QString( name ) ).absFilePath().replace( "/", "\\" ) );
	setIcon( QPixmap( openterm_xpm ) );

	myScenePropertiesDialog = new ScenePropertiesDialog( this );
	myScenePropertiesDialog->hide();

	//Creating the script list dock window
	scriptDock = new QDockWindow( this, "Scriptlist" );
	scriptDock->setResizeEnabled( true );
	scriptDock->setBaseSize( 310, 400 );
	scriptDock->setBackgroundMode( Qt::PaletteDark );
	scriptDock->setVerticallyStretchable( TRUE );
	//scriptDock->setCaption( tr( "Object Tree" ) );
	//scriptDock->setCloseMode( QDockWindow::Always );
	//scriptDock->setMovingEnabled ( FALSE );

	//Creating the list view's parent widget, a QTabWidget
	myObjectList = new ObjectList( scriptDock, "ObjectList" );
	myObjectList->setAllColumnsShowFocus( true );
	myObjectList->setSorting( 1 );

	//Back to the script list dock window
	scriptDock->setWidget( myObjectList );
	addDockWindow( scriptDock, Qt::DockLeft );

	//Creating an object view class handle
	myObjectWidget = new ObjectWidget( this );
	myScriptMainWindow = new ScriptMainWindow ( this );

	myObjectWidget->hide();
	myScriptMainWindow->hide();

	setCentralWidget( 0 );
	resize( parent->width() / 4 * 3, parent->height() / 4 * 3 );
	showMaximized();
	//setCentralWindow( myObjectList->objectsTree );
	
	//connecting Objects
	connect( myObjectList, SIGNAL( currentChanged( QListViewItem *) ), this, SLOT( setCentralWindow( QListViewItem * ) ) );
}

void DocumentWidget::closeEvent( QCloseEvent * close )
{
	emit closeSignal();
}

void DocumentWidget::save()
{
	//if( centralWidget() == myObjectWidget )
		myObjectWidget->saveObject();
	//else if( centralWidget() == myScriptMainWindow )
		myScriptMainWindow->myScriptWorkspace->saveAllWindows();
}

void DocumentWidget::setCentralWindow( QListViewItem * item )
{
	if( myObjectList->getItemDatablock( item ) == Object )
	{
		myObjectWidget->show();
		myScriptMainWindow->hide();
		myObjectList->currentTree = myObjectList->objectsTree;
		setCentralWidget( myObjectWidget );
	}
	else if( myObjectList->getItemDatablock( item ) == ObjDef )
	{
		myObjectWidget->hide();
		myScriptMainWindow->show();
		myObjectList->currentTree = myObjectList->objectDefinitionsTree;
		setCentralWidget( myScriptMainWindow );
	}
	else if( myObjectList->getItemDatablock( item ) == Init )
	{
		myObjectWidget->hide();
		myScriptMainWindow->show();
		myObjectList->currentTree = myObjectList->initTree;
		setCentralWidget( myScriptMainWindow );
	}
}