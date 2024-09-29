/****************************************************************************
** Form interface generated from reading ui file 'objectwidget.ui'
**
** Created: Mi 11. Feb 22:59:45 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.2.1   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef OBJECTWIDGET_H
#define OBJECTWIDGET_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qwidget.h>
#include "MLWrapper.h"

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QGroupBox;
class QLabel;
class QLineEdit;
class QTextEdit;
class QFrame;
class QCheckBox;
class QComboBox;
class QListBox;
class QListBoxItem;
class QPushButton;
class QListViewItem;

class ColorWidget;

class ObjectWidget : public QWidget
{
    Q_OBJECT

public:
    ObjectWidget( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ObjectWidget();

    QGroupBox* positionGroupBox;
    QLabel* positionXTitle;
    QLineEdit* positionXInput;
    QLabel* positionYTitle;
    QLineEdit* positionYInput;
    QLabel* positionZTitle;
    QLineEdit* positionZInput;
    QGroupBox* rotationGroupBox;
    QLabel* rotationXTitle;
    QLineEdit* rotationXInput;
    QLabel* rotationYTitle;
    QLineEdit* rotationYInput;
    QLabel* rotationZTitle;
    QLineEdit* rotationZInput;
    QGroupBox* scalingGroupBox;
    QLabel* scalingXTitle;
    QLineEdit* scalingXInput;
    QLabel* scalingYTitle;
    QLineEdit* scalingYInput;
    QLabel* scalingZTitle;
    QLineEdit* scalingZInput;
    QGroupBox* additionalBox;
    QLabel* additionalXTitle;
    QLineEdit* additionalXInput;
    QLabel* additionalYTitle;
    QLineEdit* additionalYInput;
    QLabel* additionalZTitle;
    QLineEdit* additionalZInput;
    QLabel* objectNameTitle;
    QLineEdit* objectNameInput;
    QGroupBox* sectorBox;
    QLabel* sector22Title;
    QLabel* sector25Title;
    QLabel* sector26Title;
    QLabel* sector23Title;
    QLineEdit* sector26Input;
    QLabel* sector24Title;
    QLineEdit* sector25Input;
    QLineEdit* sector22Input;
    QLineEdit* sector23Input;
    QLineEdit* sector24Input;
    QLabel* sector16Title;
    QLabel* sector15Title;
    QLabel* sector18Title;
    QLabel* sector17Title;
    QLabel* sector19Title;
    QLabel* sector21Title;
    QLabel* sector20Title;
    QLineEdit* sector18Input;
    QLineEdit* sector16Input;
    QLineEdit* sector17Input;
    QLineEdit* sector15Input;
    QLineEdit* sector20Input;
    QLineEdit* sector21Input;
    QLineEdit* sector19Input;
    QLabel* sector9Title;
    QLabel* sector13Title;
    QLabel* sector8Title;
    QLabel* sector10Title;
    QLabel* sector14Title;
    QLabel* sector11Title;
    QLabel* sector12Title;
    QLineEdit* sector12Input;
    QLineEdit* sector10Input;
    QLineEdit* sector9Input;
    QLineEdit* sector13Input;
    QLineEdit* sector14Input;
    QLineEdit* sector11Input;
    QLineEdit* sector8Input;
    QLabel* sector2Title;
    QLabel* sector4Title;
    QLabel* sector1Title;
    QLabel* sector7Title;
    QLabel* sector5Title;
    QLabel* sector6Title;
    QLineEdit* sector4Input;
    QLineEdit* sector1Input;
    QLineEdit* sector5Input;
    QLabel* sector3Title;
    QLineEdit* sector7Input;
    QLineEdit* sector2Input;
    QLineEdit* sector3Input;
    QLineEdit* sector6Input;
    QTextEdit* helpTextEdit;
    QGroupBox* extraBox;
    QFrame* modelFrame;
    QLabel* modelTitleLabel;
    QCheckBox* modelCheckBox;
    QLineEdit* modelLineEdit;
    QFrame* sectorFrame;
    QLabel* sectorTitleLabel;
    QCheckBox* sectorCheckBox;
    QComboBox* sectorComboBox;
    QFrame* lightFrame;
    QGroupBox* lightColorBox;
    QGroupBox* lightFlagBox;
    QCheckBox* flag4CheckBox;
    QCheckBox* flag3CheckBox;
    QCheckBox* flag2CheckBox;
    QCheckBox* flag1CheckBox;
    QCheckBox* flag8CheckBox;
    QCheckBox* flag6CheckBox;
    QCheckBox* flag5CheckBox;
    QCheckBox* flag7CheckBox;
    QGroupBox* lightRangeBox;
    QLabel* nearRangeTitle;
    QLabel* farRangeTitle;
    QLineEdit* nearRangeInput;
    QLineEdit* farRangeInput;
    QGroupBox* lightSectorBox;
    QComboBox* lightSectorComboBox;
    QListBox* lightSectorListBox;
    QPushButton* addSectorButton;
    QPushButton* removeSectorButton;
    QGroupBox* lightOtherBox;
    QComboBox* lightTypeComboBox;
    QLabel* lightTypeTitle;
    QLabel* lightPowerTitle;
    QLabel* lightCone1Title;
    QLineEdit* lightPowerInput;
    QLineEdit* lightCone1Input;
    QLineEdit* lightCone2Input;
    QLabel* lightCone2Title;
	ColorWidget* lightColorWidget;
    QGroupBox* longObjectBox;
    QLabel* longObject1Title;
    QLabel* longObject2Title;
    QLabel* longObject3Title;
    QLabel* longObject4Title;
    QLabel* longObject5Title;
    QLabel* longObject6Title;
    QLineEdit* longObject1Input;
    QLineEdit* longObject2Input;
    QLineEdit* longObject3Input;
    QLineEdit* longObject4Input;
    QLineEdit* longObject5Input;
    QLineEdit* longObject6Input;

protected:
    QGridLayout* ObjectWidgetLayout;
    QVBoxLayout* positionGroupBoxLayout;
    QHBoxLayout* positionXLayout;
    QHBoxLayout* positionYLayout;
    QHBoxLayout* positionZLayout;
    QVBoxLayout* rotationGroupBoxLayout;
    QHBoxLayout* rotationXLayout;
    QHBoxLayout* rotationYLayout;
    QHBoxLayout* rotationZLayout;
    QVBoxLayout* scalingGroupBoxLayout;
    QHBoxLayout* scalingXLayout;
    QHBoxLayout* scalingYLayout;
    QHBoxLayout* scalingZLayout;
    QVBoxLayout* additionalBoxLayout;
    QHBoxLayout* additionalXLayout;
    QHBoxLayout* additionalYLayout;
    QHBoxLayout* additionalZLayout;
    QHBoxLayout* objectTitleLayout;
    QGridLayout* sectorBoxLayout;
    QVBoxLayout* extraBoxLayout;
    QVBoxLayout* modelFrameLayout;
    QHBoxLayout* modelInputLayout;
    QVBoxLayout* sectorFrameLayout;
    QHBoxLayout* sectorInputLayout;
    QHBoxLayout* lightFrameLayout;
    QVBoxLayout* layout25;
    QGridLayout* lightFlagBoxLayout;
    QGridLayout* lightRangeBoxLayout;
    QVBoxLayout* layout26;
    QGridLayout* lightSectorBoxLayout;
    QGridLayout* lightOtherBoxLayout;
    QGridLayout* longObjectBoxLayout;
    QHBoxLayout* layout18;

	void focusOutEvent( QFocusEvent * );

public slots:
	void saveObject();
	void setInputFields( ObjectInfo_t *, QListViewItem * item = 0 );

protected slots:
    virtual void languageChange();
	void objectEdited();
	void insertLightSector();
	void removeLightSector();
	void changeLightSector( const QString & text /* = QString::null */ );

private:
    QPixmap image0;
    QPixmap image1;
    QPixmap image2;
    QPixmap image3;
    QPixmap image4;
    QPixmap image5;
    QPixmap image6;
    QPixmap image7;
    QPixmap image8;
    QPixmap image9;

	ObjectInfo_t * currentObject;
	QListViewItem * currentListItem;
	QString oldName;
	bool edited;
	QString normalHint;
	QString lightHint;
	QString sectorHint;
};

#endif // OBJECTWIDGET_H
