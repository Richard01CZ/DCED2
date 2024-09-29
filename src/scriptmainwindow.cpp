#include "documentwidget.h"
#include "mafiasyntax.h"
#include "scriptmainwindow.h"
#include "scriptworkspace.h"

#include <qpopmenu.h>
#include <qmenubar.h>

ScriptMainWindow::ScriptMainWindow( DocumentWidget* parentWidget, const char* name, WFlags fl )
				: QMainWindow( parentWidget, name, fl )
{
	//Initialization
	parent = parentWidget;
	QPopupMenu * windowMenu = new QPopupMenu();
	myScriptWorkspace = new ScriptWorkspace( this, "ScriptWorkspace" );
	topLevelWidget()->removeEventFilter( myScriptWorkspace );
	
	//Setting options
	windowMenu->insertItem( tr( "Cascade" ),  myScriptWorkspace, SLOT( cascade() ), ALT+Key_C, 1 );
	windowMenu->insertItem( tr( "Tile" ),  myScriptWorkspace, SLOT( tile() ), ALT+Key_T, 2 );
	windowMenu->insertSeparator();
	windowMenu->insertItem( tr( "Close All" ),  myScriptWorkspace, SLOT( closeAllWindows() ), ALT+Key_Q, 3 );

	scriptPreviewDock = new QDockWindow( this );
	scriptPreviewDock->setVerticallyStretchable( true );
	scriptPreviewDock->setCaption( tr( "Script Preview" ) );
	scriptPreviewDock->setCloseMode( QDockWindow::Always );
	scriptPreviewDock->setResizeEnabled( true );
	scriptPreviewDock->setMinimumWidth( 140 );

	previewScriptTextEdit = new QTextEdit( scriptPreviewDock, "Script Preview TextEdit" );
	previewScriptTextEdit->setReadOnly( true );

	scriptSyntax = new MafiaSyntax( previewScriptTextEdit, MafiaSyntax::Preview );

	scriptPreviewDock->setWidget( previewScriptTextEdit );
	addDockWindow( scriptPreviewDock, Qt::DockRight );

	menuBar()->insertItem( tr( "Windows" ), windowMenu );

	setCentralWidget( myScriptWorkspace );
}
