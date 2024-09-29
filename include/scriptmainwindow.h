#ifndef MY_SCRIPTMAINWINDOW_H
#define MY_SCRIPTMAINWINDOW_H

#include "Scene2.h"

#include <qmainwindow.h>
#include <qtextedit.h>

class DocumentWidget;
class ScriptWorkspace;
class MafiaSyntax;

class ScriptMainWindow : public QMainWindow
{
	Q_OBJECT
public:
	ScriptMainWindow( DocumentWidget * parentWidget, const char * name = 0, WFlags fl = 0 );

	void setEnemyPreview( ObjectInfo_t * );

	ScriptWorkspace * myScriptWorkspace;
	QTextEdit * previewScriptTextEdit;
	QDockWindow * scriptPreviewDock;
	DocumentWidget const * parent;
	MafiaSyntax * scriptSyntax;
};

#endif