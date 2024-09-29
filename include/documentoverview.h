#ifndef MY_DOCUMENTOVERVIEW_H
#define MY_DOCUMENTOVERVIEW_H

#include <qfileinfo.h>
#include <qmainwindow.h>
#include <qptrlist.h>
#include <qsettings.h>
#include <qtabbar.h>
#include <qvbox.h>
#include <qworkspace.h>

#include "globaldefs.h"
#include "MLWrapper.h"

class AddObjectDialog;
class DocumentWidget;
class FilterListDialog;
class MainWidget;
class ObjectList;
class ObjectWidget;
class QListViewItem;
class ScriptMainWindow;
class ScriptWorkspace;

class DocumentOverview : public QVBox
{
	Q_OBJECT
public:
	DocumentOverview( QWidget * parent, const char * name = 0 );
	~DocumentOverview();
	int count();
	DocumentWidget * currentDocument();
	DocumentWidget * findDocument( QString name );
	virtual bool openDocument( QFileInfo file );

	int tabOverview;
	QPtrList<DocumentWidget> documentList;
	QPtrList<QTab> tabList;
	QTabBar * documentTabBar;
	QWorkspace * documentWorkspace;

public slots:
	virtual void closeAll();
	virtual void closeDocument();

protected slots:
	virtual void changeDocument( int number );
	virtual void changeDocument( QWidget * widget );
};

/************************************************************************/
/*                            SceneOverview                             */
/************************************************************************/

class SceneOverview : public DocumentOverview
{
	Q_OBJECT
public:
	SceneOverview( QWidget * parent );
	~SceneOverview();
	
	AddObjectDialog * addObjectDialog;
	virtual bool openDocument( QFileInfo file );

public slots:
	void addListItem( char *, int, short );
	void applySettings();
	virtual void closeDocument();
	void createListItem( char *, int, short );
	void createTemplate();
	void deleteObject();
	void exportObject();
	void importObject();
	void listInits( bool on );
	void listObjDefs( bool on );
	void listObjects( bool on );
	void openObjDef( QListViewItem * );
	void openObject( QListViewItem * );
	void quickSearch( const QString & text );
	void renameObject( QString newName, QString oldName, Type type );
	void saveAllDocuments();
	void saveDocument();
	void setListDockVisible();
	void setPreview( QListViewItem * );
	void setScriptPreviewVisible();
	void showSceneProperties();

protected slots:
	virtual void changeDocument( QWidget * widget );
};

#endif
