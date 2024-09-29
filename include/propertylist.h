/***********************************************************
** Copyright (C) 2004 DON|City. All rights reserved.
**
** This file is part of DC||ED. 
***********************************************************/

#ifndef MY_PROPERTYLIST_H
#define MY_PROPERTYLIST_H

#include <qlistview.h>
#include <qguardedptr.h>
#include <qpainter.h>
#include <qstringlist.h>
#include <qvariant.h>

class PropertyWhatsThis;
class PropertyList;
class QComboBox;
class QHBox;
class QLabel;
class QPushButton;

class PropertyItem : public QListViewItem
{
public:
    PropertyItem( PropertyList *l, PropertyItem *after, PropertyItem *prop, const QString &propName, QString wT = QString::null );
    ~PropertyItem();

    void paintCell( QPainter *p, const QColorGroup &cg, int column, int width, int align );
    void paintBranches( QPainter * p, const QColorGroup & cg,
			int w, int y, int h );
    void paintFocus( QPainter *p, const QColorGroup &cg, const QRect &r );

    virtual bool hasSubItems() const;
    virtual void createChildren();
    virtual void initChildren();

    bool isOpen() const;
    void setOpen( bool b );

    virtual void showEditor();
    virtual void hideEditor();

    virtual void setValue( const QVariant &v, bool setOrig = FALSE );
    QVariant value() const;
    QString name() const;
    virtual void notifyValueChange();

    virtual void setChanged( bool b );
    bool isChanged() const;

    virtual void placeEditor( QWidget *w );

    virtual PropertyItem *propertyParent() const;
    virtual void childValueChanged( PropertyItem *child );

    void addChild( PropertyItem *i );
    int childCount() const;
    PropertyItem *child( int i ) const;

    virtual bool hasCustomContents() const;
    virtual void drawCustomContents( QPainter *p, const QRect &r );

    void updateBackColor();

    void setup() { QListViewItem::setup(); setHeight( QListViewItem::height() + 2 ); }

    virtual QString currentItem() const;
    virtual int currentIntItem() const;
    virtual void setCurrentItem( const QString &s );
    virtual void setCurrentItem( int i );
    virtual int currentIntItemFromObject() const;
    virtual QString currentItemFromObject() const;

    void setFocus( QWidget *w );

    virtual void toggle();
    void setText( int col, const QString &txt );

	virtual void resetProperty();

	void setWhatsThisText( const QString &s );
	const QString whatsThisText();
	
    QPushButton *resetButton;

protected:
    PropertyList *listview;
    QVariant val, originalValue;

private:
    QColor backgroundColor();
    void createResetButton();
    void updateResetButtonState();

private:
    bool open, changed;
    PropertyItem *property;
    QString propertyName;
    QPtrList<PropertyItem> children;
    QColor backColor;
	QString whatsThis;

};

//---------------------------------------------------------//

class PropertyTextItem : public QObject,
			 public PropertyItem
{
    Q_OBJECT

public:
    PropertyTextItem( PropertyList *l, PropertyItem *after, PropertyItem *prop,
					  const QString &propName, QString &val = QString::null, QString wT = QString::null );
    ~PropertyTextItem();

    virtual void createChildren( QString name );
    virtual void initChildren();

    virtual void showEditor();
    virtual void hideEditor();

    virtual void setValue( const QVariant &v, bool setOrig = FALSE );
    virtual bool hasSubItems() const;
    virtual void childValueChanged( PropertyItem *child );

    virtual void setChanged( bool b );
	virtual void setMaxLength( int l );
	
    const QString getText();

public slots:
	void resetProperty();

signals:
	valueChanged( const QVariant& );
	valueReset( const QVariant& );

private slots:
    void setValue();

private:
    QLineEdit *lined();
    QGuardedPtr<QLineEdit> lin;
};

//---------------------------------------------------------//

class PropertyDoubleItem : public QObject,
			public PropertyItem
{
    Q_OBJECT

public:
    PropertyDoubleItem( PropertyList *l, PropertyItem *after, PropertyItem *prop,
		     const QString &propName, double val, QString wT = QString::null );
    ~PropertyDoubleItem();

    virtual void showEditor();
    virtual void hideEditor();

    virtual void setValue( const QVariant &v, bool setOrig = FALSE );

public slots:
	void resetProperty();

private slots:
    void setValue();

private:
    QLineEdit *lined();
    QGuardedPtr<QLineEdit> lin;
};

//---------------------------------------------------------//

class PropertyIntItem : public QObject,
			public PropertyItem
{
    Q_OBJECT

public:
    PropertyIntItem( PropertyList *l, PropertyItem *after, PropertyItem *prop,
		     const QString &propName, int val, QString wT = QString::null );
    ~PropertyIntItem();

    virtual void showEditor();
    virtual void hideEditor();

    virtual void setValue( const QVariant &v, bool setOrig = FALSE );

public slots:
	void resetProperty();

private slots:
    void setValue();

private:
    QLineEdit *lined();
    QGuardedPtr<QLineEdit> lin;
};

//---------------------------------------------------------//

class PropertyBoolItem : public QObject,
			 public PropertyItem
{
    Q_OBJECT

public:
    PropertyBoolItem( PropertyList *l, PropertyItem *after, PropertyItem *prop, const QString &propName,
			bool checked = 0, QString wT = QString::null );
    ~PropertyBoolItem();

    virtual void showEditor();
    virtual void hideEditor();

    virtual void setValue( const QVariant &v, bool setOrig = FALSE );
    virtual void toggle();

public slots:
	void resetProperty();

private slots:
    void setValue();

private:
    QComboBox *combo();
    QGuardedPtr<QComboBox> comb;

};

//---------------------------------------------------------//

class PropertyColorItem : public QObject,
			  public PropertyItem
{
    Q_OBJECT

public:
    PropertyColorItem( PropertyList *l, PropertyItem *after, PropertyItem *prop,
		       const QString &propName, bool children, QColor color, QString wT = QString::null );
    ~PropertyColorItem();

    virtual void createChildren();
    virtual void initChildren();

    virtual void showEditor();
    virtual void hideEditor();

    virtual void setValue( const QVariant &v, bool setOrig = FALSE );
    virtual bool hasSubItems() const;
    virtual void childValueChanged( PropertyItem *child );

    virtual bool hasCustomContents() const;
    virtual void drawCustomContents( QPainter *p, const QRect &r );

public slots:
	void resetProperty();

private slots:
    void getColor();

private:
    QGuardedPtr<QHBox> box;
    QGuardedPtr<QFrame> colorPrev;
    QGuardedPtr<QPushButton> button;
    bool withChildren;

};

//---------------------------------------------------------//

class PropertyList : public QListView
{
	Q_OBJECT
public:
	PropertyList( QWidget * parent );
	
	virtual void setCurrentItem( QListViewItem *item );
	virtual void valueChanged( PropertyItem *item );
	virtual void valueReset( PropertyItem *item );
	virtual bool isChanged();
    
	QString whatsThisAt( const QPoint &p );
	void showCurrentWhatsThis();

public slots:
	void updateEditorSize();
	void resetProperty();

protected slots:
	virtual void languageChange();

signals:
	void valueChanged( const QVariant& );
	void valueReset( const QVariant& );

private:
	QString whatsThisText( QListViewItem *i );

	bool changed;
	PropertyWhatsThis * whatsThis;
};

//---------------------------------------------------------//

class EnemyEditor : public PropertyList
{
	Q_OBJECT
public:
	EnemyEditor(	QWidget * parent );
	~EnemyEditor();

	void clear();
	bool isChanged();
	void setup();

	PropertyItem * strengthItem;
	PropertyItem * energyItem;
		PropertyItem * energyLeftHandItem;
		PropertyItem * energyRightHandItem;
		PropertyItem * energyLeftLegItem;
		PropertyItem * energyRightLegItem;
	PropertyItem * reactionsItem;
	PropertyItem * speedItem;
	PropertyItem * aggressivityItem;
	PropertyItem * intelligenceItem;
	PropertyItem * shootingItem;
	PropertyItem * sightItem;
	PropertyItem * hearingItem;
	PropertyItem * drivingItem;
	PropertyItem * massItem;
	PropertyItem * behaviour2Item;	
	PropertyItem * behaviour1Item;
	PropertyItem * voiceItem;
};

//---------------------------------------------------------//

class MovingBoxEditor : public PropertyList
{
	Q_OBJECT
public:
	MovingBoxEditor( QWidget * parent );
	~MovingBoxEditor();

	void clear();
	bool isChanged();
	void setup();

	PropertyItem * soundItem;
	PropertyItem * value1Item;
	PropertyItem * value2Item;
	PropertyItem * frictionItem;
	PropertyItem * value4Item;
	PropertyItem * value5Item;
	PropertyItem * weightItem;
};

//---------------------------------------------------------//

class TrafficEditor : public PropertyList
{
	Q_OBJECT
public:
	TrafficEditor( QWidget * parent );
	~TrafficEditor();

	void clear();
	bool isChanged();
	void setup();

	PropertyItem * trafficVal1Item;
	PropertyItem * trafficVal2Item;
	PropertyItem * trafficVal3Item;
	PropertyItem * densityItem;
	PropertyTextItem * curNameItem;
	PropertyItem * curDensityItem;
	PropertyItem * curColorItem;
	PropertyItem * curPoliceItem;
	PropertyItem * curFlag2Item;
	PropertyItem * curGangsterItem;
	PropertyItem * curFlag4Item;
};

//---------------------------------------------------------//

class PedestrianEditor : public PropertyList
{
	Q_OBJECT
public:
	PedestrianEditor( QWidget * parent );
	~PedestrianEditor();

	void clear();
	bool isChanged();
	void setup();

	PropertyItem * val1Item;
	PropertyItem * val2Item;
	PropertyItem * val3Item;
	PropertyItem * val4Item;
	PropertyItem * val5Item;
	PropertyItem * densityItem;
	PropertyTextItem * curNameItem;
	PropertyItem * curDensityItem;
};

//---------------------------------------------------------//

class DoorEditor : public PropertyList
{
	Q_OBJECT
public:
	DoorEditor( QWidget * parent );
	~DoorEditor();

	void clear();
	bool isChanged();
	void setup();

	PropertyItem * openDirection1Item;
	PropertyItem * openDirection2Item;
	PropertyItem * moveAngleItem;
	PropertyItem * isOpenItem;
	PropertyItem * isLockedItem;
	PropertyItem * closeSpeedItem;
	PropertyItem * openSpeedItem;
	PropertyTextItem * openSoundItem;
	PropertyTextItem * closeSoundItem;
	PropertyTextItem * lockedSoundItem;
	PropertyItem * flagItem;
};

#endif; //MY_PROPERTYLIST_H