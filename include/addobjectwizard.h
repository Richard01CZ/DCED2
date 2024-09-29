/****************************************************************************
** Form interface generated from reading ui file 'addobjectwizard.ui'
**
** Created: Fr 6. Feb 13:19:52 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.2.1   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ADDOBJECTWIZARD_H
#define ADDOBJECTWIZARD_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qwizard.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QWidget;
class QLabel;
class QTextEdit;
class QListView;
class QListViewItem;
class QGroupBox;
class QFrame;
class QCheckBox;
class QLineEdit;
class QComboBox;

class AddObjectWizard : public QWizard
{
    Q_OBJECT

public:
    AddObjectWizard( QWidget* parent = 0, const char* name = 0, bool modal = TRUE, WFlags fl = WStyle_Customize | WStyle_DialogBorder | WStyle_Title | WStyle_SysMenu );
    ~AddObjectWizard();

    QWidget* page1;
    QLabel* page1TitleLabel;
    QTextEdit* page1HelpBox;
    QListView* page1TypeList;
    QLabel* page1Logo;
    QWidget* page2;
    QGroupBox* additionalBox;
    QFrame* modelFrame;
    QLabel* modelTitleLabel;
    QCheckBox* modelCheckBox;
    QLineEdit* modelLineEdit;
    QFrame* sectorFrame;
    QLabel* sectorTitleLabel;
    QCheckBox* sectorCheckBox;
    QComboBox* sectorComboBox;
    QGroupBox* rotationGroupBox;
    QLabel* rotationXTitle;
    QLineEdit* rotationXInput;
    QLabel* rotationYTitle;
    QLineEdit* rotationYInput;
    QLabel* rotationZTitle;
    QLineEdit* rotationZInput;
    QGroupBox* positionGroupBox;
    QLabel* positionXTitle;
    QLineEdit* positionXInput;
    QLabel* positionYTitle;
    QLineEdit* positionYInput;
    QLabel* positionZTitle;
    QLineEdit* positionZInput;
    QLabel* objectNameTitle;
    QLineEdit* objectNameInput;
    QGroupBox* scalingGroupBox;
    QLabel* scalingXTitle;
    QLineEdit* scalingXInput;
    QLabel* scalingYTitle;
    QLineEdit* scalingYInput;
    QLabel* scalingZTitle;
    QLineEdit* scalingZInput;
    QTextEdit* page2HelpBox;
    QLabel* page2Logo;

public slots:
    virtual void setPage2BottomButtons( const QString& );
    virtual void setHelpBox( QListViewItem * item );
    virtual void setPage1BottomButtons( QListViewItem * );
	void open();
	
protected:
    QVBoxLayout* additionalBoxLayout;
    QVBoxLayout* modelFrameLayout;
    QHBoxLayout* modelInputLayout;
    QVBoxLayout* sectorFrameLayout;
    QHBoxLayout* sectorInputLayout;
    QVBoxLayout* rotationGroupBoxLayout;
    QHBoxLayout* rotationXLayout;
    QHBoxLayout* rotationYLayout;
    QHBoxLayout* rotationZLayout;
    QVBoxLayout* positionGroupBoxLayout;
    QHBoxLayout* positionXLayout;
    QHBoxLayout* positionYLayout;
    QHBoxLayout* positionZLayout;
    QHBoxLayout* objectTitleLayout;
    QVBoxLayout* scalingGroupBoxLayout;
    QHBoxLayout* scalingXLayout;
    QHBoxLayout* scalingYLayout;
    QHBoxLayout* scalingZLayout;
	QListViewItem * objectsItem;
	QListViewItem * objectDefinitionsItem;
	QListViewItem * initScriptsItem;

protected slots:
    virtual void languageChange();

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
    QPixmap image10;

};

#endif // ADDOBJECTWIZARD_H
