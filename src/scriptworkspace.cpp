#include "mafiasyntax.h"
#include "scriptmainwindow.h"
#include "scriptwidget.h"
#include "scriptworkspace.h"

#include <qmessagebox.h>

ScriptWorkspace::ScriptWorkspace( ScriptMainWindow* parentWidget, const char * name )
				: QWorkspace( parentWidget, name )
{
	parent = parentWidget;
	setScrollBarsEnabled( true );
	ScriptWidgetList.setAutoDelete( true );
	setChangeTopLevelCaption( FALSE );
}

void ScriptWorkspace::addScriptWidget( QString name, int type, QString script, bool init, ObjectInfo_t * objectInfo )
{
	int windowExists = -1;
	
	for( unsigned int i = 0; i < ScriptWidgetList.count(); i++ )
		if(	ScriptWidgetList.at( i )->name == name )
		{
			windowExists = i;
			break;
		}
	
	if( windowExists == -1 )
	{
		ScriptWidget * tempWidget = new ScriptWidget( this, name, type, script, init, objectInfo );
		ScriptWidgetList.append( tempWidget );
		connect( tempWidget, SIGNAL( closeSignal( ScriptWidget * ) ), this, SLOT( deleteScriptWidget( ScriptWidget * ) ) );
		ScriptWidgetList.at(ScriptWidgetList.count()-1)->show();
	}
	else
	{
		if( ScriptWidgetList.at(windowExists)->isChanged() == true )
			if( QMessageBox::question( 0, ScriptWidget::tr( "Are you sure?" ), ScriptWidget::tr( "Do you really want to abolish your script?" ), QMessageBox::Yes, QMessageBox::No | QMessageBox::Default | QMessageBox::Escape ) == QMessageBox::Yes )
				ScriptWidgetList.at(windowExists)->setInputFields( name, type, script, objectInfo );
		ScriptWidgetList.at(windowExists)->setFocus();
	}
}

void ScriptWorkspace::applySettings()
{
	for( uint i = 0; i < ScriptWidgetList.count(); i++ )
	{
		ScriptWidgetList.at( i )->scriptSyntax->reloadSettings();
		ScriptWidgetList.at( i )->scriptSyntax->reinitialise();
	}
}

void ScriptWorkspace::deleteScriptWidget( ScriptWidget * w )
{
	ScriptWidgetList.remove( w );
}

ScriptWidget * ScriptWorkspace::getActiveScriptWidget()
{
	QWidgetList windows = windowList( QWorkspace::CreationOrder );
	int activeWindowNr = -1;
	
	for( unsigned int i = 0; i < windows.count(); i++ )
		if(	windows.at( i ) == activeWindow() )
		{
			activeWindowNr = i;
			break;
		}

	return ScriptWidgetList.at( activeWindowNr );
}

void ScriptWorkspace::focusScriptWidget( QString name )
{
	QWidgetList windows = windowList( QWorkspace::CreationOrder );
	for( uint i = 0; i < windows.count(); i++ )
		if( windows.at( i )->name() == name )
			windows.at( i )->setFocus();
}

void ScriptWorkspace::saveAllWindows()
{
	for( uint i = 0; i < ScriptWidgetList.count(); i++ )
		ScriptWidgetList.at( i )->save();
}
