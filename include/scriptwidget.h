#ifndef MYSCRIPTWIDGET_H
#define MYSCRIPTWIDGET_H

#include "MLWrapper.h"

#include <qtextedit.h>
#include <qpushbutton.h>
#include <qsettings.h>

class MafiaSyntax;
class QGridLayout;
class QScrollView;
class QSplitter;
class QTable;
class ScriptWorkspace;


class PropertyList;
class DoorEditor;
class EnemyEditor;
class MovingBoxEditor;
class PedestrianEditor;
class TrafficEditor;

class PedestrianModelList;
class TrafficNameList;

class ScriptWidget : public QWidget
{
	Q_OBJECT
public:
	ScriptWidget( ScriptWorkspace * parentWidget, QString n, int t,
				  QString s, bool i, ObjectInfo_t * objInfo = 0, WFlags fl = 0 );

	void closeEvent( QCloseEvent * );
	bool isChanged();

	bool init;
	QString name;
	QString script;
	int type;
	QTextEdit * scriptInput;
	MafiaSyntax * scriptSyntax;
	ScriptWorkspace const* parent;
	ObjectInfo_t * objectInfo;

public slots:	
	void save();
	void setInputFields( const char * nName, int nType, QString nScript, ObjectInfo_t * nObjectInfo = 0 );

signals:
	void closeSignal( ScriptWidget * );

protected:
	QTextEdit * lineNumbers;
	QScrollView * scriptSV;
	QSettings settings;

	PropertyList * propertyEditor;
	DoorEditor * doorEditor;
	EnemyEditor * enemyEditor;
	MovingBoxEditor * movingBoxEditor;
	PedestrianEditor * pedestrianEditor;
	TrafficEditor * trafficEditor;

	QSplitter * splitter;

	TrafficNameList * trafficNameList;
	PedestrianModelList * pedestrianModelList;

protected slots:
	void setLineNumbers( int i = 0 );
	void updateProperties();

private:
	QGridLayout * grid;
};

#endif