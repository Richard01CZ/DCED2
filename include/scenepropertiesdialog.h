/****************************************************************************
** Form interface generated from reading ui file 'scenepropertiesdialog.ui'
**
** Created: Mi 24. Mrz 16:30:00 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.2.1   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef SCENEPROPERTIESDIALOG_H
#define SCENEPROPERTIESDIALOG_H

#include "MLWrapper.h"

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QLabel;
class QLineEdit;
class QGroupBox;
class QTextEdit;
class QPushButton;

class ScenePropertiesDialog : public QDialog
{
    Q_OBJECT

public:
    ScenePropertiesDialog( QWidget* parent, bool modal = FALSE, WFlags fl = WStyle_Customize | WStyle_DialogBorder | WStyle_Title | WStyle_SysMenu  );
    ~ScenePropertiesDialog();

	virtual void show();

    QLabel* worldDimension1Title;
    QLabel* worldDimension2Title;
    QLabel* viewDistanceTitle;
    QLabel* cameraDistanceTitle;
    QLineEdit* worldDimension1Input;
    QLineEdit* worldDimension2Input;
    QLineEdit* cameraDistanceInput;
    QLineEdit* viewDistanceInput;
	QPushButton* okButton;
    QPushButton* abortButton;

protected:
    QGridLayout* ScenePropertiesDialogLayout;
    QGridLayout* helpBoxLayout;
	QGridLayout* buttonLayout;
	ObjectInfo_t * objectInfo;

protected slots:
    virtual void languageChange();
	virtual void accept();

};

#endif // SCENEPROPERTIESDIALOG_H
