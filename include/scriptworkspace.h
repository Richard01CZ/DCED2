#include <qworkspace.h>
#include <qptrlist.h>
#include <qlistview.h>
#include "Scene2.h"

class ScriptMainWindow;
class ScriptWidget;

class ScriptWorkspace : public QWorkspace
{
	Q_OBJECT
public:
	ScriptWorkspace( ScriptMainWindow* parentWidget, const char * name = 0 );
	ScriptWidget * getActiveScriptWidget();
	ScriptMainWindow const * parent;

public slots:
	void addScriptWidget( QString name, int type, QString script, bool init, ObjectInfo_t * objectInfo = 0 );
	void applySettings();
	void deleteScriptWidget( ScriptWidget * );
	void focusScriptWidget( QString );
	void saveAllWindows();

protected:
	QPtrList<ScriptWidget> ScriptWidgetList;
	ScriptWidget * currentScriptWidget;

	friend class QWorkspace;
};