/****************************************************************************
** Form interface generated from reading ui file 'filterobjectdefinitionspage.ui'
**
** Created: So 2. Mai 11:49:41 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.2.1   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FILTEROBJECTDEFINITIONSPAGE_H
#define FILTEROBJECTDEFINITIONSPAGE_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QButtonGroup;
class QRadioButton;
class QLineEdit;
class QPushButton;
class QListBox;
class QListBoxItem;
class QTextEdit;

class FilterObjectDefinitionsPage : public QWidget
{
    Q_OBJECT

public:
    FilterObjectDefinitionsPage( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~FilterObjectDefinitionsPage();

    QButtonGroup* buttonGroupName;
    QRadioButton* radioNameEndsWith;
    QRadioButton* radioNameStartsWith;
    QRadioButton* radioNameContains;
    QLineEdit* lineEditName;
    QButtonGroup* buttonGroupType;
    QPushButton* buttonTypeClear;
    QPushButton* buttonTypeSelectAll;
    QListBox* listBoxType;
    QTextEdit* helpBox;

protected:
    QGridLayout* FilterObjectDefinitionsPageLayout;
    QGridLayout* buttonGroupNameLayout;
    QGridLayout* buttonGroupTypeLayout;

protected slots:
    virtual void languageChange();

};

#endif // FILTEROBJECTDEFINITIONSPAGE_H
