/****************************************************************************
** Form interface generated from reading ui file 'deletedialog.ui'
**
** Created: Mi 24. Mrz 21:28:03 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.2.1   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef QUESTIONDIALOG_H
#define QUESTIONDIALOG_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qdialog.h>
#include <qsettings.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QLabel;
class QPushButton;
class QCheckBox;

class QuestionDialog : public QDialog
{
    Q_OBJECT

public:
    QuestionDialog( QWidget* parent, QString caption, QString message, bool & askAgain, bool hasCancelButton = FALSE,
					const char* name = 0, bool modal = TRUE, WFlags fl = WDestructiveClose | WType_Dialog );

    QLabel* pixmapLabel2;
    QLabel* label;
    QPushButton* yesButton;
    QPushButton* noButton;
	QPushButton* cancelButton;
    QCheckBox* askAgainBox;

	static int question( QWidget* parent, QString caption, QString message, bool & askAgain, bool hasCancelButton = FALSE );

protected:
    QGridLayout* deleteDialogLayout;
    QHBoxLayout* layout1;
	QSettings settings;

protected slots:
    virtual void languageChange();
	void setAskAgain( bool ask );
	virtual void cancel();

private:
    QPixmap image0;
	bool & ask;
	bool c;
};

#endif // QUESTIONDIALOG_H
