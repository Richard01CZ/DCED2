/****************************************************************************
** Form interface generated from reading ui file 'filterlistdialog.ui'
**
** Created: Do 18. Dez 21:07:33 2003
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.2.1   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FILTERLISTDIALOG_H
#define FILTERLISTDIALOG_H

#include <qvariant.h>
#include <qdialog.h>
#include <qvaluelist.h>

class DocumentWidget;
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QButtonGroup;
class QCheckBox;
class QSpinBox;
class QGroupBox;
class QLabel;
class QPushButton;
class QRadioButton;
class QLineEdit;
class QListBox;
class QListBoxItem;

class FilterListDialog : public QDialog
{
    Q_OBJECT

public:
    FilterListDialog( DocumentWidget* parentWidget = 0, const char* name = 0, bool modal = TRUE, WFlags fl = 0 );
    ~FilterListDialog();

	QButtonGroup* buttonGroupID;
	QCheckBox* checkBoxIDMax;
	QCheckBox* checkBoxIDMin;
	QSpinBox* spinBoxIDMin;
	QSpinBox* spinBoxIDMax;
	QGroupBox* groupBoxHint;
	QLabel* labelHint;
	QPushButton* buttonOK;
	QPushButton* buttonCancel;
	QButtonGroup* buttonGroupName;
	QRadioButton* radioNameEndsWith;
	QRadioButton* radioNameStartsWith;
	QLineEdit* lineEditName;
	QRadioButton* radioNameContains;
	QButtonGroup* buttonGroupType;
//	QPushButton* buttonTypeSelectAll;
//	QPushButton* buttonTypeClear;
	QListBox* listBoxType;

    QGridLayout* FilterListDialogLayout;
    QHBoxLayout* bottomLayout;
    QGridLayout* buttonGroupTypeLayout;

	DocumentWidget const * parent;

protected slots:
    virtual void languageChange();
	void emitFilter();

signals:
	void filterCurrentList( QString, int, QValueList<int> );
};

#endif // FILTERLISTDIALOG_H
