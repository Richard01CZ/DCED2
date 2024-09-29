 //About Dialog header file
#ifndef MYABOUTDIALOG_H
#define MYABOUTDIALOG_H

#include <qdialog.h>
#include <qpushbutton.h>

class AboutDialog : public QDialog
{
	Q_OBJECT
public:
	AboutDialog( QWidget * parent = 0, const char * name = 0, WFlags f = WStyle_Customize | WStyle_DialogBorder | WStyle_Title | WStyle_Tool | WStyle_SysMenu );
};

#endif
