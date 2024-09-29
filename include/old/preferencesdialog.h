/****************************************************************************
** Form interface generated from reading ui file 'preferencesdialog.ui'
**
** Created: Mo 16. Feb 18:19:29 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.2.1   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qdialog.h>
#include <qsettings.h>

class MafiaSyntax;
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QPushButton;
class QGroupBox;
class QTextEdit;
class QLabel;

class PreferencesDialog : public QDialog
{
    Q_OBJECT

public:
    PreferencesDialog( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~PreferencesDialog();

    QPushButton* cancelButton;
    QPushButton* okButton;
    QGroupBox* previewBox;
    QTextEdit* previewTextEdit;
    QGroupBox* syntaxBox;
    QLabel* dimsLabel;
    QPushButton* dimsColorButton;
    QLabel* digitsLabel;
    QPushButton* quotationsColorButton;
    QLabel* quotationsLabel;
    QLabel* standardColorLabel;
    QPushButton* commentsColorButton;
    QLabel* quotationsColorLabel;
    QPushButton* statementsColorButton;
    QPushButton* digitsColorButton;
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
    QLabel* digitsColorLabel;
    QLabel* digitsFontLabel;
    QLabel* standardFontLabel;
    QPushButton* standardFontButton;
    QLabel* commentsFontLabel;
    QLabel* statementsFontLabel;
    QPushButton* digitsFontButton;
    QLabel* commandsFontLabel;
    QPushButton* commentsFontButton;
    QLabel* dimsFontLabel;
    QLabel* quotationsFontLabel;
    QLabel* labelsFontLabel;
    QPushButton* quotationsFontButton;
    QPushButton* commandsFontButton;
    QPushButton* dimsFontButton;
    QPushButton* statementsFontButton;
    QPushButton* labelsFontButton;
	MafiaSyntax* previewSyntax;

signals:
	void settingsSaved();

protected:
    QGridLayout* PreferencesDialogLayout;
    QHBoxLayout* layout1;
    QGridLayout* previewBoxLayout;
    QGridLayout* syntaxBoxLayout;
    QGridLayout* layout8;
    QGridLayout* layout9;

protected slots:
    virtual void languageChange();
	void reset();
	void save();
	void setStandardColor();
	void setStandardFont();
	void setLabelsColor();
	void setLabelsFont();
	void setStatementsColor();
	void setStatementsFont();
	void setCommandsColor();
	void setCommandsFont();
	void setDimsColor();
	void setDimsFont();
	void setCommentsColor();
	void setCommentsFont();
	void setDigitsColor();
	void setDigitsFont();
	void setQuotationsColor();
	void setQuotationsFont();

private:
    QPixmap image0;
	QSettings settings;

	friend class MafiaSyntax;
};

#endif // PREFERENCESDIALOG_H
