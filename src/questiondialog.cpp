/****************************************************************************
** Form implementation generated from reading ui file 'deletedialog.ui'
**
** Created: Mi 24. Mrz 21:28:14 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.2.1   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "questiondialog.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qcheckbox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>
#include <qmessagebox.h>

static const char* const image_question[] = { 
"39 38 5 1",
". c None",
"b c #000000",
"c c #0000ff",
"# c #999999",
"a c #ffffff",
".......................................",
".......................................",
".......................................",
".......................................",
"...............########................",
"............###aaaaaaaa###.............",
"..........##aaaaaaaaaaaaaa##...........",
".........#aaaaaaaaaaaaaaaaaa#..........",
"........#aaaaaaaaaaaaaaaaaaaab.........",
".......#aaaaaaaaccccccaaaaaaaab........",
"......#aaaaaaaacaaaccccaaaaaaaab.......",
".....#aaaaaaaaccaaaaccccaaaaaaaab......",
".....#aaaaaaaaccccaaccccaaaaaaaab#.....",
"....#aaaaaaaaaccccaaccccaaaaaaaaab#....",
".....aaaaaaaaaaccaaccccaaaaaaaaaab#....",
"....#aaaaaaaaaaaaaccccaaaaaaaaaaab##...",
"....#aaaaaaaaaaaaacccaaaaaaaaaaaab##...",
"....#aaaaaaaaaaaaaccaaaaaaaaaaaaab##...",
"....#aaaaaaaaaaaaaccaaaaaaaaaaaaab##...",
"....#aaaaaaaaaaaaaaaaaaaaaaaaaaaab##...",
".....#aaaaaaaaaaaaccaaaaaaaaaaaab###...",
".....#aaaaaaaaaaaccccaaaaaaaaaaab###...",
"......#aaaaaaaaaaccccaaaaaaaaaab###....",
".......baaaaaaaaaaccaaaaaaaaaab####....",
"........baaaaaaaaaaaaaaaaaaaab####.....",
".........baaaaaaaaaaaaaaaaaab####......",
"..........bbaaaaaaaaaaaaaabb####.......",
"...........#bbbaaaaaaaabbb#####........",
"............###bbbaaaab#######.........",
"..............####baaab#####...........",
".................#baaab##..............",
"...................baab##..............",
"....................bab##..............",
".....................bb##..............",
"......................###..............",
".......................##..............",
".......................................",
"......................................."};


/*
 *  Constructs a deleteDialog as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
QuestionDialog::QuestionDialog( QWidget* parent, QString caption, QString message,
							    bool & askAgain, bool hasCancelButton, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl ),
      image0( (const char **) image_question ),
	  ask( askAgain ),
	  c( hasCancelButton )
{
    if ( !name )
		setName( "QuestionDialog" );

    setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)4, (QSizePolicy::SizeType)4, 0, 0, sizePolicy().hasHeightForWidth() ) );
    setModal( TRUE );
    deleteDialogLayout = new QGridLayout( this, 1, 1, 7, 5, "deleteDialogLayout"); 
    deleteDialogLayout->setResizeMode( QLayout::Fixed );

    layout1 = new QHBoxLayout( 0, 0, 6, "layout1"); 

	pixmapLabel2 = new QLabel( this, "pixmapLabel2" );
	pixmapLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)4, (QSizePolicy::SizeType)4, 0, 0, pixmapLabel2->sizePolicy().hasHeightForWidth() ) );
    pixmapLabel2->setPixmap( image0 );
    pixmapLabel2->setScaledContents( TRUE );
    layout1->addWidget( pixmapLabel2 );

    label = new QLabel( this, "label" );
    label->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)3, 0, 0, label->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( label );

    deleteDialogLayout->addMultiCellLayout( layout1, 0, 0, 0, 3 );
    QSpacerItem* spacer = new QSpacerItem( 10, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum );
    deleteDialogLayout->addItem( spacer, 1, 0 );
    QSpacerItem* spacer_2 = new QSpacerItem( 10, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum );
    deleteDialogLayout->addItem( spacer_2, 1, 3 );

    yesButton = new QPushButton( this, "yesButton" );
    yesButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)4, (QSizePolicy::SizeType)0, 0, 0, yesButton->sizePolicy().hasHeightForWidth() ) );

    deleteDialogLayout->addWidget( yesButton, 1, 1 );

    noButton = new QPushButton( this, "noButton" );
    noButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)4, (QSizePolicy::SizeType)0, 0, 0, noButton->sizePolicy().hasHeightForWidth() ) );

    deleteDialogLayout->addWidget( noButton, 1, 2 );

	if( c )
	{
		cancelButton = new QPushButton( this, "cancelButton" );
		cancelButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)4, (QSizePolicy::SizeType)0, 0, 0, noButton->sizePolicy().hasHeightForWidth() ) );

		deleteDialogLayout->addWidget( cancelButton, 1, 3 );
	}

    askAgainBox = new QCheckBox( this, "askAgainBox" );

    deleteDialogLayout->addMultiCellWidget( askAgainBox, 2, 2, 0, 3 );
    languageChange();
    resize( QSize(249, 108).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( yesButton, SIGNAL( clicked() ), this, SLOT( accept() ) );
    connect( noButton, SIGNAL( clicked() ), this, SLOT( reject() ) );
	if( c ) connect( cancelButton, SIGNAL( clicked() ), this, SLOT( cancel() ) );
	connect( askAgainBox, SIGNAL( toggled( bool ) ), this, SLOT( setAskAgain( bool ) ) );

    // tab order
    setTabOrder( noButton, yesButton );
    setTabOrder( yesButton, askAgainBox );

	//settings texts
    setCaption( caption );
    label->setText( message );
}

void QuestionDialog::setAskAgain( bool askAgain )
{
	ask = !askAgain;
}

void QuestionDialog::cancel()
{
	done( -1 );
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void QuestionDialog::languageChange()
{
    yesButton->setText( tr( "&Yes" ) );
    yesButton->setAccel( QKeySequence( tr( "Alt+Y" ) ) );
    noButton->setText( tr( "&No" ) );
    noButton->setAccel( QKeySequence( tr( "Alt+N" ) ) );
	if( c )
	{
		cancelButton->setText( tr( "&Cancel" ) );
		cancelButton->setAccel( QKeySequence( tr( "Alt+C" ) ) );
	}
    askAgainBox->setText( tr( "Don't ask me again" ) );
}

int QuestionDialog::question( QWidget* parent, QString caption, QString message, bool & askAgain, bool hasCancelButton )
{
	QuestionDialog * d = new QuestionDialog( parent, caption, message, askAgain, hasCancelButton, caption.latin1(), TRUE );
	return d->exec();
}
