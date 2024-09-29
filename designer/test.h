/****************************************************************************
** Form interface generated from reading ui file 'test.ui'
**
** Created: Mi 7. Jul 20:52:12 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.2.3   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FORM2_H
#define FORM2_H

#include <qvariant.h>
#include <qmainwindow.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QAction;
class QActionGroup;
class QToolBar;
class QPopupMenu;

class Form2 : public QMainWindow
{
    Q_OBJECT

public:
    Form2( QWidget* parent = 0, const char* name = 0, WFlags fl = WType_TopLevel );
    ~Form2();

    QMenuBar *MenuBarEditor;
    QPopupMenu *PopupMenuEditor;
    QAction* menuHelloAction;
    QAction* menuHelloFuck_itAction;

protected:

protected slots:
    virtual void languageChange();

};

#endif // FORM2_H
