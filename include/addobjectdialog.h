/****************************************************************************
** Form interface generated from reading ui file 'addobjectdialog.ui'
**
** Created: So 28. Mrz 17:06:49 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.2.1   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ADDOBJECTDIALOG_H
#define ADDOBJECTDIALOG_H

#include "MLWrapper.h"
#include "objectlist.h"

#include <qvariant.h>
#include <qpixmap.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QLabel;
class QLineEdit;
class QListView;
class QListViewItem;
class QTextEdit;
class QPushButton;

class AddObjectDialog : public QDialog
{
    Q_OBJECT

public:
    AddObjectDialog( QWidget* parent );
    ~AddObjectDialog();

    QLabel* nameTitle;
    QLineEdit* nameInput;
    QLabel* titleLabel;
    QLabel* addLogo;
    QListView* typeList;
    QTextEdit* helpBox;
    QPushButton* okButton;
    QPushButton* cancelButton;

public slots:
	virtual void accept();

protected:
    QGridLayout* AddObjectDialogLayout;
    QHBoxLayout* objectTitleLayout;
    QHBoxLayout* layout3;
	ObjectsTree * objectsTree;
	ObjectDefinitionsTree * objectDefinitionsTree;
	InitTree * initTree;

	Type getCurrentDatablock();

protected slots:
    virtual void languageChange();
	virtual void setOkButtonState();
	virtual void setHelp( QListViewItem * item );

private:
    QPixmap image0;
    QPixmap image1;
};

#endif // ADDOBJECTDIALOG_H
