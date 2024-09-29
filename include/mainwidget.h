// Main Widget Header File

#ifndef MYMAINWIDGET_H
#define MYMAINWIDGET_H

#include <qmainwindow.h>
#include <qstringlist.h>
#include <qsettings.h>
#include <qtranslator.h>
#include <qstatusbar.h>
#include <qiconset.h>

class AboutDialog;
class SceneOverview;
class PreferencesDialog;
class QListViewItem;
class QToolBar;
class QAction;
class QPopupMenu;
class QComboBox;

class MainWidget : public QMainWindow
{
    Q_OBJECT
public:
    MainWidget( QMainWindow *parent=0, const char *name=0, WFlags f = WType_TopLevel );
	
	SceneOverview * mySceneOverview;

	virtual void OpenFile( QString filename );
	virtual void checkActionState();
    
public slots:
	void OpenFile();
	void ReopenFile();
	void ReopenFile( int id );
	void SaveFile();
	void SaveAllFiles();
	void CloseFile();

	//Language functions
	void setLanguageEnglish();
	void setLanguageGerman();
	void setLanguageFrench();
	void setLanguageSpanish();
	void setLanguageCzech();
	
protected:
	virtual void closeEvent( QCloseEvent * );
	void updateRecentFiles( QString fn );
	void removeRecentFiles( QString fn );
	
	QPopupMenu * fileMenu;
	QToolBar * fileToolbar;
	QAction * fileOpenAction;
	QAction * fileReopenAction;
	QAction * fileSaveAction;
	QAction * fileSaveAllAction;
	QAction * fileCloseAction;
		QPopupMenu * fileRecentMenu;
	QAction * filePropertiesAction;
	QAction * filePreferencesAction;
	QAction * fileQuitAction;

	QPopupMenu * editMenu;
	QToolBar * editToolbar;
	QAction * editAddAction;
	QAction * editDeleteAction;
	QAction * editExportAction;
	QAction * editImportAction;
	QAction * editTemplateAction;

	QPopupMenu * viewMenu;
	QToolBar * viewToolbar;
	QAction * viewInitAction;
	QAction * viewObjDefAction;
	QAction * viewObjectAction;

	QPopupMenu * langMenu;
	QAction * langEnglishAction;
	QAction * langGermanAction;
	QAction * langCzechAction;
	QAction * langFrenchAction;
	QAction * langSpanishAction;

	QPopupMenu * windowMenu;
	QAction * windowCascadeAction;
	QAction * windowTileAction;

	QPopupMenu * helpMenu;
	QToolBar * helpToolbar;
	QAction * helpAboutAction;
	QAction * helpWhatsThisAction;

	QToolBar * quickSearchToolbar;
	QComboBox * quickSearchInput;
	
	AboutDialog * myAboutDialog;
	PreferencesDialog * myPreferencesDialog;
	
	QStringList recentFiles;

	QTranslator translator;

private:
	QString currentVersion;
	QString titleText;
	QPixmap doneditIcon;
	QIconSet openIcon, reopenIcon, saveIcon, saveAllIcon, closeIcon,
			 addObjectIcon, deleteObjectIcon, listInitIcon,
			 listObjDefIcon, listObjectIcon, whatsThisIcon,
			 tileIcon, cascadeIcon, objectListIcon;
};

#endif