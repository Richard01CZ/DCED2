/****************************************************************************
** Form interface generated from reading ui file 'carlistdialog.ui'
**
** Created: Mo 15. Mrz 16:28:50 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.2.1   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CARLISTDIALOG_H
#define CARLISTDIALOG_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QPushButton;
class QListBox;
class QListBoxItem;
class QGroupBox;
class QLineEdit;
class QLabel;

class CarListDialog : public QDialog
{
    Q_OBJECT

public:
    CarListDialog( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CarListDialog();

    QPushButton* newCarButton;
    QPushButton* deleteCarButton;
    QListBox* carListBox;
    QPushButton* okButton;
    QPushButton* cancelButton;
    QGroupBox* carPropertiesBox;
    QLineEdit* carNameInput;
    QLabel* carNameLabel;

protected:
    QGridLayout* CarListDialogLayout;
    QHBoxLayout* bottomLayout;
    QGridLayout* carPropertiesBoxLayout;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;

};

#endif // CARLISTDIALOG_H
