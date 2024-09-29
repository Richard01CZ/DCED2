/****************************************************************************
** Form implementation generated from reading ui file 'test.ui'
**
** Created: Mi 7. Jul 20:52:19 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.2.3   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "test.h"

#include <qvariant.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qaction.h>
#include <qmenubar.h>
#include <qpopupmenu.h>
#include <qtoolbar.h>

/*
 *  Constructs a Form2 as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 */
Form2::Form2( QWidget* parent, const char* name, WFlags fl )
    : QMainWindow( parent, name, fl )
{
    (void)statusBar();
    if ( !name )
	setName( "Form2" );

    // actions
    menuHelloAction = new QAction( this, "menuHelloAction" );
    menuHelloFuck_itAction = new QAction( this, "menuHelloFuck_itAction" );


    // toolbars


    // menubar
    MenuBarEditor = new QMenuBar( this, "MenuBarEditor" );

    MenuBarEditor->setGeometry( QRect( 0, 0, 600, 29 ) );

    PopupMenuEditor = new QPopupMenu( this );
    QPopupMenu *ActionItem = new QPopupMenu( this );
    PopupMenuEditor->setAccel( tr( "" ), 
        PopupMenuEditor->insertItem( menuHelloAction->iconSet(),tr( "Hello" ), ActionItem ) );
    menuHelloFuck_itAction->addTo( ActionItem );
    MenuBarEditor->insertItem( QString(""), PopupMenuEditor, 2 );

    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Form2::~Form2()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Form2::languageChange()
{
    setCaption( tr( "Form2" ) );
    menuHelloAction->setText( tr( "Hello" ) );
    menuHelloFuck_itAction->setText( tr( "Fuck it" ) );
    MenuBarEditor->findItem( 2 )->setText( tr( "Menu" ) );
}

