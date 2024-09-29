#ifndef MYLISTTAB_H
#define MYLISTTAB_H

#include <qtabwidget.h>
#include <qlistview.h>
#include <qvaluelist.h>

class ListTab : public QTabWidget
{
	Q_OBJECT
public:
	ListTab( QWidget * parent, const char * name = 0 );
	
	QListView * objectsTree;
	QListView * objectDefinitionsTree;
	QListView * lightmapTree;
	QListView * sectorTree;
	QListView * initScriptTree;
	QListView * currentTree;
	
public slots:
	//void addScriptListItem( int, char *, long, int, char * objectSector = 0, QString objectModel = 0 );
	void addListItem( char *, int, short );
	void filterCurrent( QString, int, int, int, QValueList<int> );
	
protected:
	void keyPressEvent( QKeyEvent * );
};

#endif