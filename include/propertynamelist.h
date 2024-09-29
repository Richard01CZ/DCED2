/****************************************************************************
** Form interface generated from reading ui file 'trafficcarlist.ui'
**
** Created: Mo 15. Mrz 17:16:25 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.2.1   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef TRAFFICCARLIST_H
#define TRAFFICCARLIST_H

#include <qvariant.h>
#include <qwidget.h>
#include <qlistview.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QPushButton;

class TrafficItem : public QListViewItem
{
public:
	TrafficItem( QListView * listview, const QString text );

	long color;
	float density;
	bool flag2;
	bool flag4;
	bool gangster;
	bool police;

	bool nameChanged;
	bool colorChanged;
	bool densityChanged;
	bool flag2Changed;
	bool flag4Changed;
	bool gangsterChanged;
	bool policeChanged;
};

//---------------------------------------------------------------//

class PedestrianItem : public QListViewItem
{
public:
	PedestrianItem( QListView * listview, const QString text );

	long density;

	bool nameChanged;
	bool densityChanged;
};

/************************************************************************/
/*                               Lists                                  */
/************************************************************************/

class PropertyNameList: public QWidget
{
	Q_OBJECT
public:
	PropertyNameList( QWidget* parent, const char * name = "PropertyNameList" );
	~PropertyNameList();

	QPushButton* deleteItemButton;
	QPushButton* newItemButton;
	QListView* itemListView;

	virtual QListViewItem * insertItem( QString name ) const;
	void insertItem( QListViewItem * item );

public slots:
	virtual void renameItem( const QVariant& v );

protected:
    QGridLayout* layout;

protected slots:
	virtual void addItem();
	virtual void deleteItem();
    virtual void languageChange();
};

//---------------------------------------------------------------//

class TrafficNameList : public PropertyNameList
{
    Q_OBJECT

public:
    TrafficNameList( QWidget* parent );

	QListViewItem * insertItem( QString name ) const;

protected slots:
	virtual void addItem();
    virtual void languageChange();
};

//---------------------------------------------------------------//

class PedestrianModelList: public PropertyNameList
{
	Q_OBJECT
public:
	PedestrianModelList( QWidget* parent );

	QListViewItem * insertItem( QString name ) const;

protected slots:
	virtual void addItem();
    virtual void languageChange();
};

#endif // TRAFFICCARLIST_H
