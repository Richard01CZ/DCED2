//------------QT Header------------//
#include <qapplication.h>
#include <qsplashscreen.h>
#include <qtextcodec.h>
#include <qstatusbar.h>

//------eigene Header Dateien------//
#include "globaldefs.h"
#include "mainwidget.h"
//#include "img/splash.xpm"

int main( int argc, char **argv = 0 )
{
	//Anfang QT Teil
	QApplication EditorApp( argc, argv );

	//Splashscreen
//	QSplashScreen * splash = new QSplashScreen( QPixmap( (const char **)(splash_xpm) ) );
//	splash->show();
	
	// translation file for Qt
	QTranslator qt( 0 );
	qt.load( QString( "qt_" ) + QTextCodec::locale(), "." );
	EditorApp.installTranslator( &qt );
	init_settings();

	main_widget = new MainWidget();
	status_bar = main_widget->statusBar();
	main_widget->setGeometry( 100, 100, 200, 120 );

	EditorApp.setMainWidget( main_widget );
	main_widget->showMaximized();

	main_widget->OpenFile( EditorApp.argv()[1] );

//	splash->finish( main_widget );
//	delete splash;

	return EditorApp.exec();
}