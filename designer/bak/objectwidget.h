/****************************************************************************
** Form interface generated from reading ui file 'objectwidget.ui'
**
** Created: Fr 6. Feb 13:10:04 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.2.1   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef OBJECTWIDGET_H
#define OBJECTWIDGET_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QLabel;
class QLineEdit;
class QGroupBox;
class QFrame;
class QCheckBox;
class QComboBox;
class QTextEdit;
class QPushButton;

class ObjectWidget : public QWidget
{
    Q_OBJECT

public:
    ObjectWidget( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ObjectWidget();

    QLabel* objectNameTitle;
    QLineEdit* objectNameInput;
    QGroupBox* additionalBox;
    QFrame* modelFrame;
    QLabel* modelTitleLabel;
    QCheckBox* modelCheckBox;
    QLineEdit* modelLineEdit;
    QFrame* sectorFrame;
    QLabel* sectorTitleLabel;
    QCheckBox* sectorCheckBox;
    QComboBox* sectorComboBox;
    QTextEdit* helpTextEdit;
    QFrame* changeFrame;
    QPushButton* changeButton;
    QFrame* applyFrame;
    QPushButton* abortButton;
    QPushButton* applyButton;
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
    QGroupBox* scalingGroupBox;
    QLabel* scalingXTitle;
    QLineEdit* scalingXInput;
    QLabel* scalingYTitle;
    QLineEdit* scalingYInput;
    QLabel* scalingZTitle;
    QLineEdit* scalingZInput;

protected:
    QGridLayout* ObjectWidgetLayout;
    QHBoxLayout* objectTitleLayout;
    QVBoxLayout* additionalBoxLayout;
    QVBoxLayout* modelFrameLayout;
    QHBoxLayout* modelInputLayout;
    QVBoxLayout* sectorFrameLayout;
    QHBoxLayout* sectorInputLayout;
    QHBoxLayout* changeFrameLayout;
    QHBoxLayout* applyFrameLayout;
    QVBoxLayout* rotationGroupBoxLayout;
    QHBoxLayout* rotationXLayout;
    QHBoxLayout* rotationYLayout;
    QHBoxLayout* rotationZLayout;
    QVBoxLayout* positionGroupBoxLayout;
    QHBoxLayout* positionXLayout;
    QHBoxLayout* positionYLayout;
    QHBoxLayout* positionZLayout;
    QVBoxLayout* scalingGroupBoxLayout;
    QHBoxLayout* scalingXLayout;
    QHBoxLayout* scalingYLayout;
    QHBoxLayout* scalingZLayout;

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

};

#endif // OBJECTWIDGET_H
