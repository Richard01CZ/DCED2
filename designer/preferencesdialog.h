/****************************************************************************
** Form interface generated from reading ui file 'preferencesdialog.ui'
**
** Created: Sa 20. Mrz 19:14:28 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.2.1   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QPushButton;
class QGroupBox;
class QLabel;
class QCheckBox;
class QComboBox;
class QTextEdit;

class PreferencesDialog : public QDialog
{
    Q_OBJECT

public:
    PreferencesDialog( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~PreferencesDialog();

    QPushButton* cancelButton;
    QPushButton* okButton;
    QGroupBox* syntaxBox;
    QLabel* dimsLabel;
    QPushButton* dimsColorButton;
    QLabel* integersLabel;
    QPushButton* quotationsColorButton;
    QLabel* quotationsLabel;
    QLabel* standardColorLabel;
    QPushButton* commentsColorButton;
    QLabel* quotationsColorLabel;
    QPushButton* statementsColorButton;
    QPushButton* integersColorButton;
    QLabel* statementsLabel;
    QLabel* commentsLabel;
    QLabel* commandsLabel;
    QLabel* commandsColorLabel;
    QLabel* standardLabel;
    QLabel* commentsColorLabel;
    QPushButton* standardColorButton;
    QPushButton* commandsColorButton;
    QPushButton* labelsColorButton;
    QLabel* dimsColorLabel;
    QLabel* statementsColorLabel;
    QLabel* labelsColorLabel;
    QLabel* labelsLabel;
    QLabel* integersColorLabel;
    QCheckBox* standardBoldCheckBox;
    QCheckBox* standardItalicCheckBox;
    QCheckBox* standardUnderlineCheckBox;
    QCheckBox* labelsBoldCheckBox;
    QCheckBox* labelsItalicCheckBox;
    QCheckBox* labelsUnderlineCheckBox;
    QCheckBox* statementsBoldCheckBox;
    QCheckBox* statementsItalicCheckBox;
    QCheckBox* statementsUnderlineCheckBox;
    QCheckBox* commandsBoldCheckBox;
    QCheckBox* commandsItalicCheckBox;
    QCheckBox* commandsUnderlineCheckBox;
    QCheckBox* dimsBoldCheckBox;
    QCheckBox* dimsItalicCheckBox;
    QCheckBox* dimsUnderlineCheckBox;
    QCheckBox* commentsBoldCheckBox;
    QCheckBox* commentsItalicCheckBox;
    QCheckBox* commentsUnderlineCheckBox;
    QCheckBox* digitsBoldCheckBox;
    QCheckBox* digitsItalicCheckBox;
    QCheckBox* digitsUnderlineCheckBox;
    QCheckBox* quotationsBoldCheckBox;
    QCheckBox* quotationsItalicCheckBox;
    QCheckBox* quotationsUnderlineCheckBox;
    QGroupBox* fontBox;
    QLabel* previewFontLabel;
    QLabel* editFontLabel;
    QComboBox* editFontComboBox;
    QComboBox* previewFontComboBox;
    QGroupBox* previewPreviewBox;
    QTextEdit* previewPreviewTextEdit;
    QGroupBox* editPreviewBox;
    QTextEdit* editPreviewTextEdit;

protected:
    QGridLayout* PreferencesDialogLayout;
    QHBoxLayout* layout1;
    QGridLayout* syntaxBoxLayout;
    QGridLayout* fontBoxLayout;
    QGridLayout* previewPreviewBoxLayout;
    QGridLayout* editPreviewBoxLayout;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;

};

#endif // PREFERENCESDIALOG_H
