//Main Widget CPP File

#include "aboutdialog.h"
#include "addobjectdialog.h"
#include "documentoverview.h"
#include "mainwidget.h"
#include "preferencesdialog.h"
#include "qlistview.h"
#include "globaldefs.h"

#include "img/open.xpm"
#include "img/reopen.xpm"
#include "img/close.xpm"
#include "img/donedit.xpm"
#include "img/identity.xpm"
#include "img/delete.xpm"
#include "img/addobject.xpm"
#include "img/init.xpm"
#include "img/script.xpm"
#include "img/object.xpm"
#include "img/save.xpm"
#include "img/saveall.xpm"
#include "img/whatsthis.xpm"
#include "img/tilever.xpm"
#include "img/cascade.xpm"

#include <qpushbutton.h>
#include <qmenubar.h>
#include <qfiledialog.h>
#include <qlabel.h>
#include <qdockwindow.h>
#include <qapplication.h>
#include <qmessagebox.h>
#include <qtextstream.h>
#include <qfile.h>
#include <qpainter.h>
#include <qtooltip.h>
#include <qtextcodec.h>
#include <qlayout.h>
#include <qwhatsthis.h>
#include <qtoolbar.h>
#include <qpopupmenu.h>
#include <qaction.h>
#include <qfileinfo.h>
#include <qcombobox.h>

MainWidget::MainWidget( QMainWindow *parent, const char *name, WFlags f )
	: QMainWindow( parent, name, f )
{
	//Version number
	currentVersion = "1.00";
	titleText = "DC||ED";
	
	//Icons
	doneditIcon = QPixmap( (const char **)(donedit_xpm) );
	openIcon = QIconSet( QPixmap( (const char **)(open_xpm) ) );
	reopenIcon = QIconSet( QPixmap( (const char **)(reopen_xpm) ) );
	saveIcon = QIconSet( QPixmap( (const char **)(save_xpm) ) );
	saveAllIcon = QIconSet( QPixmap( (const char **)(saveall_xpm) ) );
	closeIcon = QIconSet( QPixmap( (const char **)(close_xpm) ) );
	addObjectIcon = QIconSet( QPixmap( (const char **)(addobject_xpm) ) );
	deleteObjectIcon = QIconSet( QPixmap( (const char **)(delete_xpm) ) );
	listInitIcon = QIconSet( QPixmap( (const char **)(init_xpm) ) );
	listObjDefIcon = QIconSet( QPixmap( (const char **)(script_xpm) ) );
	listObjectIcon = QIconSet( QPixmap( (const char **)(object_xpm) ) );
	whatsThisIcon = QIconSet( QPixmap( (const char **)(whatsthis_xpm) ) );
	tileIcon = QIconSet( QPixmap( (const char **)(tilever_xpm) ) );
	cascadeIcon = QIconSet( QPixmap( (const char **)(cascade_xpm) ) );

	//Setting MainWindow properties
	setMinimumSize( 640, 460 );
	setCaption( tr( titleText + " :: " + currentVersion ) );
	setIcon( doneditIcon );

	//Reading out the language from the registry
	 //If the language is not available, I write the standart language, "English", to the registry.
	QString language = settings->readEntry( "language", "DONCITYEDITOR_ERROR:NOFILEAVAILABLE" );

	if( language == "DONCITYEDITOR_ERROR:NOFILEAVAILABLE" )
		settings->writeEntry( "language", "English" );

	if( language == "German" && QFileInfo( "language/dced_de.qm" ).exists() == TRUE )
	{
		translator.load( QString( "language/dced_de.qm" ) + QTextCodec::locale(), "." );
		qApp->installTranslator( &translator );
	}
	else if( language == "French" && QFileInfo( "language/dced_fr.qm" ).exists() == TRUE )
	{
		translator.load( QString( "language/dced_fr.qm" ) + QTextCodec::locale(), "." );
		qApp->installTranslator( &translator );
	}
	else if( language == "Spanish" && QFileInfo( "language/dced_es.qm" ).exists() == TRUE )
	{
		translator.load( QString( "language/dced_es.qm" ) + QTextCodec::locale(), "." );
		qApp->installTranslator( &translator );
	}
	else if( language == "Czech" && QFileInfo( "language/dced_cz.qm" ).exists() == TRUE )
	{
		translator.load( QString( "language/dced_cz.qm" ) + QTextCodec::locale(), "." );
		qApp->installTranslator( &translator );
	}

	//----------------------------------------------------------------------//

	myAboutDialog = new AboutDialog( this );
	myAboutDialog->hide();

	myPreferencesDialog = new PreferencesDialog( this );
	myPreferencesDialog->hide();

	mySceneOverview = new SceneOverview( this );

	//----------------------------------------------------------------------//

	// Creating the Menus at the top

	fileMenu = new QPopupMenu();
	menuBar()->insertItem( tr( "&File" ), fileMenu );
	fileToolbar = new QToolBar( this, "fileToolbar" );
	fileToolbar->setFixedExtentHeight( 23 );
	fileRecentMenu = new QPopupMenu( fileMenu );

	editMenu = new QPopupMenu();
	menuBar()->insertItem( tr( "&Edit" ), editMenu );
	editToolbar = new QToolBar( this, "editToolbar" );
	editToolbar->setFixedExtentHeight( 23 );

	viewMenu = new QPopupMenu();
	menuBar()->insertItem( tr( "&View" ), viewMenu );
	viewToolbar = new QToolBar( this, "viewToolbar" );
	viewToolbar->setFixedExtentHeight( 23 );

	langMenu = new QPopupMenu();
	menuBar()->insertItem( tr( "&Language" ), langMenu );

	windowMenu = new QPopupMenu();
	menuBar()->insertItem( tr( "&Window" ), windowMenu );

	quickSearchToolbar = new QToolBar( this, "quickSearchToolbar" );
	quickSearchToolbar->setFixedExtentHeight( 23 );

	helpMenu = new QPopupMenu();
	menuBar()->insertItem( tr( "&Help" ), helpMenu );
	helpToolbar = new QToolBar( this, "helpToolbar" );
	helpToolbar->setFixedExtentHeight( 23 );

	/************************************************************************/
	/* Creating the Actions. Actions are items that can be used as          */
	/* QToolButtons and QFileMenu entries at the same time.                 */
	/************************************************************************/

	fileOpenAction = new QAction( openIcon, tr( "&Open" ),
			QKeySequence( tr( "Ctrl+O", "File|Open" ) ), this, "fileOpenAction" );
	fileReopenAction = new QAction( reopenIcon, tr( "Open &Recent" ),
			QKeySequence( tr( "Ctrl+R", "File|Open Recent" ) ), this, "fileReopenAction" );
	fileSaveAction = new QAction( saveIcon, tr( "&Save" ),
			QKeySequence( tr( "Ctrl+S", "File|Save" ) ), this, "fileSaveAction" );
	fileSaveAllAction = new QAction( saveAllIcon, tr( "Save All" ),
			QKeySequence( tr( "Ctrl+Shift+S", "File|Save All" ) ), this, "fileSaveAction" );
	fileCloseAction = new QAction( closeIcon, tr( "Close" ),
			QKeySequence( tr( "Ctrl+W", "File|Close" ) ), this, "fileCloseAction" );
	filePropertiesAction = new QAction( tr( "General Properties" ),
			QKeySequence( tr( "Ctrl+G", "General Properties" ) ), this, "filePropertiesAction" );
	filePreferencesAction = new QAction( tr( "&Preferences" ),
			QKeySequence( tr( "Ctrl+P", "File|Preferences" ) ), this, "filePreferencesAction" );
	fileQuitAction = new QAction( tr( "Quit" ),
			QKeySequence( tr( "Ctrl+Q", "File|Quit" ) ), this, "fileQuitAction" );

	//----------------------------------------------------------------------//

	editAddAction = new QAction( addObjectIcon, tr( "&Add Object" ),
			QKeySequence( tr( "Ctrl+N", "Edit|Add Object" ) ), this, "editAddAction" );
	editDeleteAction = new QAction( deleteObjectIcon, tr( "&Delete Object" ),
			QKeySequence(), this, "editDeleteAction" );
	editExportAction = new QAction( tr( "&Export" ),
			QKeySequence( tr( "Ctrl+E", "Edit|Export Object" ) ), this, "editExportAction" );
	editImportAction = new QAction( tr( "&Import" ),
			QKeySequence( tr( "Ctrl+I", "Edit|Import Object" ) ), this, "editImportAction" );
	editTemplateAction = new QAction ( tr( "&Create Template" ),
			QKeySequence(), this, "editTemplateAction " );

	//----------------------------------------------------------------------//

	viewInitAction = new QAction( listInitIcon, tr( "Show Init Scripts" ),
			QKeySequence(), this, "viewInitAction" );
	viewObjDefAction = new QAction( listObjDefIcon, tr( "Show Object Definitions" ),
			QKeySequence(), this, "viewObjDefAction" );
	viewObjectAction = new QAction( listObjectIcon, tr( "Show Objects" ),
			QKeySequence(), this, "viewObjectAction" );

	viewInitAction->setToggleAction( TRUE );
	viewInitAction->setOn( TRUE );
	viewObjDefAction->setToggleAction( TRUE );
	viewObjDefAction->setOn( TRUE );
	viewObjectAction->setToggleAction( TRUE );
	viewObjectAction->setOn( TRUE );

	//----------------------------------------------------------------------//

	langEnglishAction = new QAction( tr( "English"), QKeySequence(), this, "langEnglishAction" );
	langGermanAction = new QAction( tr( "Deutsch"), QKeySequence(), this, "langGermanAction" );
	langCzechAction = new QAction( tr( "Çesky"), QKeySequence(), this, "langCzechAction" );
	langFrenchAction = new QAction( tr( "Français"), QKeySequence(), this, "langFrenchAction" );
	langSpanishAction = new QAction( tr( "Español"), QKeySequence(), this, "langSpanishAction" );

	//----------------------------------------------------------------------//

	windowCascadeAction = new QAction( cascadeIcon, tr( "Cascade" ), QKeySequence(), this, "windowCascadeAction" );
	windowTileAction = new QAction( tileIcon, tr( "Tile" ), QKeySequence(), this, "windowTileAction" );
	
	//----------------------------------------------------------------------//

	quickSearchInput = new QComboBox( quickSearchToolbar );
	quickSearchInput->setInsertionPolicy( QComboBox::AtTop );
	quickSearchInput->setEditable( TRUE );
	quickSearchInput->setMinimumWidth( 100 );

	//----------------------------------------------------------------------//
	
	helpAboutAction = new QAction( tr( "About" ), QKeySequence(), this, "helpAboutAction" );
	helpWhatsThisAction = new QAction( whatsThisIcon, tr( "What's This" ), QKeySequence(), this, "helpWhatsThisAction" );

	/************************************************************************/
	/* Inserting the actions into the toolbars and menus                    */
	/************************************************************************/

	fileOpenAction->addTo( fileMenu );
	fileOpenAction->addTo( fileToolbar );
	fileReopenAction->addTo( fileMenu );
	fileReopenAction->addTo( fileToolbar );
	fileSaveAction->addTo( fileMenu );
	fileSaveAction->addTo( fileToolbar );
	fileSaveAllAction->addTo( fileMenu );
	fileCloseAction->addTo( fileMenu );
	fileCloseAction->addTo( fileToolbar );
	fileMenu->insertSeparator();
	fileMenu->insertItem( tr( "Recent Files" ), fileRecentMenu, 77 );
	fileMenu->insertSeparator();
	filePropertiesAction->addTo( fileMenu );
	filePreferencesAction->addTo( fileMenu );
	fileMenu->insertSeparator();
	fileQuitAction->addTo( fileMenu );

	editAddAction->addTo( editMenu );
	editAddAction->addTo( editToolbar );
	editDeleteAction->addTo( editMenu );
	editDeleteAction->addTo( editToolbar );
	editMenu->insertSeparator();
	editExportAction->addTo( editMenu );
	editImportAction->addTo( editMenu );
	editMenu->insertSeparator();
	editTemplateAction->addTo( editMenu );

	viewMenu->insertSeparator();
	viewObjectAction->addTo( viewMenu );
	viewObjectAction->addTo( viewToolbar );
	viewObjDefAction->addTo( viewMenu );
	viewObjDefAction->addTo( viewToolbar );
	viewInitAction->addTo( viewMenu );
	viewInitAction->addTo( viewToolbar );

	langEnglishAction->addTo( langMenu );
	langGermanAction->addTo( langMenu );
	langCzechAction->addTo( langMenu );
	langFrenchAction->addTo( langMenu );
	langSpanishAction->addTo( langMenu );

	windowCascadeAction->addTo( windowMenu );
	windowTileAction->addTo( windowMenu );

	helpAboutAction->addTo( helpMenu );
	helpWhatsThisAction->addTo( helpMenu );
	helpWhatsThisAction->addTo( helpToolbar );

	/************************************************************************/
	/* Here I check wether a language file is available                     */
	/************************************************************************/

	if( !QFileInfo( "language/dced_de.qm" ).exists() )
		langGermanAction->setVisible( FALSE );
	if( !QFileInfo( "language/dced_fr.qm" ).exists() )
		langFrenchAction->setVisible( FALSE );
	if( !QFileInfo( "language/dced_es.qm" ).exists() )
		langSpanishAction->setVisible( FALSE );
	if( !QFileInfo( "language/dced_cz.qm" ).exists() )
		langCzechAction->setVisible( FALSE );

	/************************************************************************/
	/* Checking for the "recentfile" key inside the registry which has the  */
	/* path to the last file as value                                       */
	/************************************************************************/

	recentFiles = settings->readListEntry( "recentfiles" );
	
	if( recentFiles.isEmpty() )
	{
		fileReopenAction->setVisible( FALSE );
		fileRecentMenu->setEnabled( FALSE );
	}
	else
	{
		uint max = QMIN( 4, recentFiles.count() );
		for (uint m = 0; m < max; ++m)
		{
			fileRecentMenu->insertItem(recentFiles[m]);
		}
	}

	connect( myPreferencesDialog, SIGNAL( settingsSaved() ), mySceneOverview, SLOT( applySettings() ) );

	//----------------------------//
	// Setting up the connections //
	//----------------------------//

	connect( fileOpenAction, SIGNAL( activated() ), this, SLOT( OpenFile() ) );
	connect( fileReopenAction, SIGNAL( activated() ), this, SLOT( ReopenFile() ) );
	connect( fileSaveAction, SIGNAL( activated() ), this , SLOT( SaveFile() ) );
	connect( fileSaveAllAction, SIGNAL( activated() ), this, SLOT( SaveAllFiles() ) );
	connect( fileCloseAction, SIGNAL( activated() ), this, SLOT( CloseFile() ) );
	connect( fileRecentMenu, SIGNAL( activated( int ) ), this, SLOT( ReopenFile( int ) ) );
	connect( filePropertiesAction, SIGNAL( activated() ), mySceneOverview, SLOT( showSceneProperties() ) );
	connect( filePreferencesAction, SIGNAL( activated() ), this->myPreferencesDialog, SLOT( show() ) );
	connect( fileQuitAction, SIGNAL( activated() ), this, SLOT( close() ) );

	connect( editAddAction, SIGNAL( activated() ), mySceneOverview->addObjectDialog, SLOT( show() ) );
	connect( editDeleteAction, SIGNAL( activated() ), mySceneOverview, SLOT( deleteObject() ) );
	connect( editExportAction, SIGNAL( activated() ), mySceneOverview, SLOT( exportObject() ) );
	connect( editImportAction, SIGNAL( activated() ), mySceneOverview, SLOT( importObject() ) );
	connect( editTemplateAction, SIGNAL( activated() ), mySceneOverview, SLOT( createTemplate() ) );

	connect( viewInitAction, SIGNAL( toggled( bool ) ), mySceneOverview, SLOT( listInits( bool ) ) );
	connect( viewObjDefAction, SIGNAL( toggled( bool ) ), mySceneOverview, SLOT( listObjDefs( bool ) ) );
	connect( viewObjectAction, SIGNAL( toggled( bool ) ), mySceneOverview, SLOT( listObjects( bool ) ) );

	connect( langEnglishAction, SIGNAL( activated() ), this, SLOT( setLanguageEnglish() ) );
	connect( langGermanAction, SIGNAL( activated() ), this, SLOT( setLanguageGerman() ) );
	connect( langCzechAction, SIGNAL( activated() ), this, SLOT( setLanguageCzech() ) );
	connect( langFrenchAction, SIGNAL( activated() ), this, SLOT( setLanguageFrench() ) );
	connect( langSpanishAction, SIGNAL( activated() ), this, SLOT( setLanguageSpanish() ) );

	connect( windowCascadeAction, SIGNAL( activated() ), mySceneOverview->documentWorkspace, SLOT( cascade() ) );
	connect( windowTileAction, SIGNAL( activated() ), mySceneOverview->documentWorkspace, SLOT( tile() ) );

	connect( helpAboutAction, SIGNAL( activated() ), myAboutDialog, SLOT( show() ) );
	connect( helpWhatsThisAction, SIGNAL( activated() ), this, SLOT( whatsThis() ) );

	connect( viewInitAction, SIGNAL( toggled( bool ) ), mySceneOverview, SLOT( listInits( bool ) ) );
	connect( viewObjDefAction, SIGNAL( toggled( bool ) ), mySceneOverview, SLOT( listObjDefs( bool ) ) );
	connect( viewObjectAction, SIGNAL( toggled( bool ) ), mySceneOverview, SLOT( listObjects( bool ) ) );

	connect( quickSearchInput, SIGNAL( textChanged( const QString & ) ), mySceneOverview, SLOT( quickSearch( const QString & ) ) );

	/************************************************************************/
	/* Finished. Calling some other functions now...                        */
	/************************************************************************/

	setCentralWidget( mySceneOverview );
	checkActionState();
	statusBar()->message( tr( "Program started." ), 2000);
}

void MainWidget::closeEvent( QCloseEvent * event )
{
	if( mySceneOverview->count() > 0 )
		mySceneOverview->closeAll();
	if( mySceneOverview->count() == 0 )
		event->accept();
}

void MainWidget::OpenFile( QString filename )
{
	QFileInfo fileinfo( filename );
	if( !fileinfo.exists() )
		return;

	// Checking wether this document is already open
	bool exists = mySceneOverview->openDocument( fileinfo );
	// if it is already open
	if( exists )
	{
		statusBar()->message( fileinfo.absFilePath().replace( "/", "\\" ) + tr( " is already opened." ), 5000 );
		return;
	}
	// otherwise
	checkActionState();
	statusBar()->message( fileinfo.absFilePath().replace( "/", "\\" ) + tr( " was loaded successfully." ), 5000 );
	updateRecentFiles( filename );
}

void MainWidget::OpenFile()
{
	QString filename;
	if( recentFiles.count() > 0 )
		filename = QFileDialog::getOpenFileName( QFileInfo( recentFiles.first() ).dirPath( TRUE ), "scene2.bin ( *.bin )", 0 );
	else
		filename = QFileDialog::getOpenFileName( "./", "scene2.bin ( *.bin );;All files ( *.* )", 0 );

	OpenFile( filename );
}

void MainWidget::ReopenFile()
{
	OpenFile( recentFiles.first() );
}

void MainWidget::ReopenFile( int id )
{
	OpenFile( fileRecentMenu->text( id ) );
}

void MainWidget::SaveFile()
{
	mySceneOverview->saveDocument();
	statusBar()->message( tr( "File saved." ), 5000 );
}

void MainWidget::SaveAllFiles()
{
	mySceneOverview->saveAllDocuments();
	statusBar()->message( tr( "All files saved." ), 10000 );
}

void MainWidget::CloseFile()
{
	//And in the following lines, I delete all the text that is still in any input line or text edit.
	mySceneOverview->closeDocument();

	checkActionState();
}

void MainWidget::checkActionState()
{
	if( mySceneOverview->count() > 0 )
	{
		fileSaveAction->setEnabled( TRUE );
		fileSaveAllAction->setEnabled( TRUE );
		fileCloseAction->setEnabled( TRUE );
		filePropertiesAction->setEnabled( TRUE );

		editMenu->setEnabled( TRUE );
		editAddAction->setEnabled( TRUE );
		editDeleteAction->setEnabled( TRUE );
		editExportAction->setEnabled( TRUE );
		editImportAction->setEnabled( TRUE );

		viewMenu->setEnabled( TRUE );
		viewInitAction->setEnabled( TRUE );
		viewObjDefAction->setEnabled( TRUE );
		viewObjectAction->setEnabled( TRUE );
		
		windowMenu->setEnabled( TRUE );
		windowCascadeAction->setEnabled( TRUE );
		windowTileAction->setEnabled( TRUE );

		quickSearchInput->setEnabled( TRUE );

		mySceneOverview->listInits( viewInitAction->isOn() );
		mySceneOverview->listObjDefs( viewObjDefAction->isOn() );
		mySceneOverview->listObjects( viewObjectAction->isOn() );
	}
	else
	{
		fileSaveAction->setEnabled( FALSE );
		fileSaveAllAction->setEnabled( FALSE );
		fileCloseAction->setEnabled( FALSE );
		filePropertiesAction->setEnabled( FALSE );

		editMenu->setEnabled( FALSE );
		editAddAction->setEnabled( FALSE );
		editDeleteAction->setEnabled( FALSE );
		editExportAction->setEnabled( FALSE );
		editImportAction->setEnabled( FALSE );

		viewMenu->setEnabled( FALSE );
		viewInitAction->setEnabled( FALSE );
		viewObjDefAction->setEnabled( FALSE );
		viewObjectAction->setEnabled( FALSE );

		quickSearchInput->setEnabled( FALSE );
		
		windowMenu->setEnabled( FALSE );
		windowCascadeAction->setEnabled( FALSE );
		windowTileAction->setEnabled( FALSE );
	}
}

//-----------------------------------------------------------------//
//-----------------------Language Functions------------------------//
//-----------------------------------------------------------------//

void MainWidget::setLanguageEnglish()
{
	settings->writeEntry( "language", "English" );
	int restart = QMessageBox::question( this, tr( "Restart DC||ED?" ), tr( "To change the language, you need to restart DC||ED.\nDo you want to close it now?" ), QMessageBox::Yes | QMessageBox::Default, QMessageBox::No | QMessageBox::Escape );
	if( restart == QMessageBox::Yes )
		qApp->quit();
}

void MainWidget::setLanguageGerman()
{
	settings->writeEntry( "language", "German" );
	int restart = QMessageBox::question( this, tr( "Restart DC||ED?" ), tr( "To change the language, you need to restart DC||ED.\nDo you want to close it now?" ), QMessageBox::Yes | QMessageBox::Default, QMessageBox::No | QMessageBox::Escape );
	if( restart == QMessageBox::Yes )
		qApp->quit();
}

void MainWidget::setLanguageFrench()
{
	settings->writeEntry( "language", "French" );
	int restart = QMessageBox::question( this, tr( "Restart DC||ED?" ), tr( "To change the language, you need to restart DC||ED.\nDo you want to close it now?" ), QMessageBox::Yes | QMessageBox::Default, QMessageBox::No | QMessageBox::Escape );
	if( restart == QMessageBox::Yes )
		qApp->quit();
}

void MainWidget::setLanguageSpanish()
{
	settings->writeEntry( "language", "Spanish" );
	int restart = QMessageBox::question( this, tr( "Restart DC||ED?" ), tr( "To change the language, you need to restart DC||ED.\nDo you want to close it now?" ), QMessageBox::Yes | QMessageBox::Default, QMessageBox::No | QMessageBox::Escape );
	if( restart == QMessageBox::Yes )
		qApp->quit();
}

void MainWidget::setLanguageCzech()
{
	settings->writeEntry( "language", "Czech" );
	int restart = QMessageBox::question( this, tr( "Restart DC||ED?" ), tr( "To change the language, you need to restart DC||ED.\nDo you want to close it now?" ), QMessageBox::Yes | QMessageBox::Default, QMessageBox::No | QMessageBox::Escape );
	if( restart == QMessageBox::Yes )
		qApp->quit();
}

/*
 * This function sets the recent files entry inside the file menu correctly
 */

void MainWidget::updateRecentFiles( QString fn )
{
	fileRecentMenu->clear();

	if( recentFiles.findIndex(fn) == -1 )
		recentFiles.prepend(fn);
	else
	{
		recentFiles.remove(fn);
		recentFiles.prepend(fn);
	}

	uint max = QMIN( 4, recentFiles.count() );
	for (uint m = 0; m < max; ++m)
	{
		fileRecentMenu->insertItem( recentFiles[m], m );
	}

	fileReopenAction->setEnabled( TRUE );
	fileRecentMenu->setEnabled( TRUE );
	
	settings->writeEntry( "recentfiles", recentFiles );
}

void MainWidget::removeRecentFiles( QString fn )
{
	fileRecentMenu->clear();

	recentFiles.remove(fn);

	if( recentFiles.isEmpty() )
	{
		fileReopenAction->setEnabled( FALSE );
		fileRecentMenu->setEnabled( FALSE );
	}
	else
	{
		uint max = QMIN( 4, recentFiles.count() );
		for (uint m = 0; m < max; ++m)
		{
			fileRecentMenu->insertItem( recentFiles[m], m );
		}
		fileRecentMenu->show();
		fileReopenAction->setEnabled( TRUE );
	}
}
