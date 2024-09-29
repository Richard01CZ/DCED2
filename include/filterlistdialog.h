/****************************************************************************
** Form interface generated from reading ui file 'filterlistdialog.ui'
**
** Created: Fr 6. Feb 19:22:24 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.2.1   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FILTERLISTDIALOG_H
#define FILTERLISTDIALOG_H

#include <qvariant.h>
#include <qdialog.h>
#include <qvaluelist.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QTextEdit;
class QButtonGroup;
class QRadioButton;
class QLineEdit;
class QPushButton;
class QListView;

class FilterListDialog : public QDialog
{
    Q_OBJECT

public:
    FilterListDialog( QWidget* parent = 0, const char* name = "FilterListDialog", bool modal = TRUE, WFlags fl = WStyle_Customize | WStyle_DialogBorder | WStyle_Title | WStyle_SysMenu );
    ~FilterListDialog();

	enum Datablock { Object, ObjDef, Init };

    QTextEdit* helpBox;
    QButtonGroup* buttonGroupName;
    QRadioButton* radioNameEndsWith;
    QRadioButton* radioNameStartsWith;
    QRadioButton* radioNameContains;
    QLineEdit* lineEditName;
    QPushButton* buttonOK;
    QPushButton* buttonCancel;
    QButtonGroup* buttonGroupType;
    QPushButton* buttonTypeSelectAll;
    QPushButton* buttonTypeClear;
    QListView* listViewType;

	virtual void setDatablock( Datablock );

public slots:
    virtual void selectAllTypes();

protected:
    QGridLayout* FilterListDialogLayout;
    QHBoxLayout* bottomLayout;
    QGridLayout* buttonGroupTypeLayout;
	Datablock datablock;

protected slots:
    virtual void languageChange();
	void emitFilter();

signals:
	void filterCurrentList( QString, int, QValueList<int> );
};

#endif // FILTERLISTDIALOG_H
