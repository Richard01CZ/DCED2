#ifndef MY_DOCUMENTWIDGET
#define MY_DOCUMENTWIDGET

#include <qmainwindow.h>

class DocumentOverview;
class ObjectList;
class ObjectWidget;
class QListViewItem;
class ScenePropertiesDialog;
class ScriptMainWindow;
class ScriptWorkspace;
class QWorkspace;
class QScrollView;

class DocumentWidget : public QMainWindow
{
	Q_OBJECT
public:
	DocumentWidget( QWidget* parent, const char * name, int Id, WFlags fl = 0 );
	void closeEvent( QCloseEvent * );

	int tabId;
	ObjectList * myObjectList;						//This is the object list.
	QDockWindow * scriptDock;						//This is the dock which has the object list inside.
	QScrollView * myObjectWidgetScrollView;			//This widget provides scrollbars for the object widget.
	ObjectWidget * myObjectWidget;					//In this widget you can view and edit the properties of the current object
	ScriptMainWindow * myScriptMainWindow;			//This is the main window for the scripts. It supports the menu bar at the top of the script interface.
	ScenePropertiesDialog * myScenePropertiesDialog;	//This is the General Scene Properties Dialog
	
public slots:
	void setCentralWindow( QListViewItem * );
	void save();

signals:
	void closeSignal();
};

#endif //MY_DOCUMENTWIDGET