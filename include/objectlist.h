#ifndef MYLISTTAB_H
#define MYLISTTAB_H

#include <qtabwidget.h>
#include <qlistview.h>
#include <qvaluelist.h>
#include "globaldefs.h"

class DocumentWidgetObjectDock;
class QPopupMenu;

class ObjectTypeTree : public QListViewItem
{
public:
	ObjectTypeTree( QListView * parent, QString name );

	Type type;
};

class ObjectDefinitionsTree : public ObjectTypeTree
{
public:
	ObjectDefinitionsTree( QListView * parent, QString name );

	virtual QString key( int column, bool ascending ) const;
};

//---------------------------------------------------------------//

class ObjectsTree : public ObjectTypeTree
{
public:
	ObjectsTree( QListView * parent, QString name );

	virtual QString key( int column, bool ascending ) const;
};

//---------------------------------------------------------------//

class InitTree : public ObjectTypeTree
{
public:
	InitTree( QListView * parent, QString name );

	virtual QString key( int column, bool ascending ) const;
};

//---------------------------------------------------------------//

class ObjectList : public QListView
{
	Q_OBJECT
public:
	ObjectList( QWidget * parent, const char * name = 0 );
	ObjectTypeTree * objectsTree;
	ObjectTypeTree * objectDefinitionsTree;
	ObjectTypeTree * initTree;
	QListViewItem * currentTree;

	virtual void reset();
	void insertListItem( QString name, int type, short datablock );
	ObjectTypeTree * getDatablockItem( Type datablock );
	Type getItemDatablock( QListViewItem * item = 0 );
	int getItemGroup( QListViewItem * item = 0 );
	
	bool existsTwice( QListViewItem * item );
	bool exists( QListViewItem * parent, QString col0 );
	bool exists( short datablock, QString name );
	bool isObjectItem( QListViewItem * item = 0 );
	
public slots:
	QListViewItem * addListItem( QString name, int type, short datablock );
	void deleteItem();
	void duplicateItem();
	void quickSearch( const QString & text );
	void startRename();
	void switchToFriendItem();
	void switchToInitScripts();
	void switchToObjectDefinitions();
	void switchToObjects();

signals:
	void objectDeleted();
	void itemRenamed( QString, QString, Type );

protected:
	virtual void contextMenuEvent( QContextMenuEvent * );
	virtual void keyPressEvent(	QKeyEvent *e );

	QPopupMenu * editMenu;
	QPtrList<QListViewItem> objectGroupList;
	QPtrList<QListViewItem> objdefGroupList;

protected slots:
	void renameItem( QListViewItem * item, int col );
};

#endif