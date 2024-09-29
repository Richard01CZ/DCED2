/****************************************************************************
** Form implementation generated from reading ui file 'preferencesdialog.ui'
**
** Created: Mo 16. Feb 18:19:30 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.2.1   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "preferencesdialog.h"
#include "img\identity.xpm"
#include "mysyntax.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qgroupbox.h>
#include <qtextedit.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>
#include <qcolordialog.h>
#include <qfontdialog.h>
#include <qsettings.h>

/*
 *  Constructs a PreferencesDialog as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
PreferencesDialog::PreferencesDialog( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl ),
      image0( (const char **) identity_xpm )
{
    if ( !name )
	setName( "PreferencesDialog" );
    setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, sizePolicy().hasHeightForWidth() ) );
    setMinimumSize( QSize( 500, 420 ) );
    setMaximumSize( QSize( 500, 420 ) );
    setIcon( image0 );
    PreferencesDialogLayout = new QGridLayout( this, 1, 1, 8, 5, "PreferencesDialogLayout"); 

    layout1 = new QHBoxLayout( 0, 0, 5, "layout1"); 
    QSpacerItem* spacer = new QSpacerItem( 392, 25, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout1->addItem( spacer );

    cancelButton = new QPushButton( this, "cancelButton" );
    layout1->addWidget( cancelButton );

    okButton = new QPushButton( this, "okButton" );
    okButton->setDefault( TRUE );
    layout1->addWidget( okButton );

    PreferencesDialogLayout->addLayout( layout1, 2, 0 );

    previewBox = new QGroupBox( this, "previewBox" );
    previewBox->setMargin( 0 );
    previewBox->setColumnLayout(0, Qt::Vertical );
    previewBox->layout()->setSpacing( 5 );
    previewBox->layout()->setMargin( 5 );
    previewBoxLayout = new QGridLayout( previewBox->layout() );
    previewBoxLayout->setAlignment( Qt::AlignTop );

    previewTextEdit = new QTextEdit( previewBox, "previewTextEdit" );
    previewTextEdit->setMargin( 0 );
    previewTextEdit->setTextFormat( QTextEdit::PlainText );
    previewTextEdit->setWordWrap( QTextEdit::NoWrap );
    previewTextEdit->setUndoRedoEnabled( FALSE );

	previewSyntax = new MafiaSyntax( previewTextEdit );

    previewBoxLayout->addWidget( previewTextEdit, 0, 0 );

    PreferencesDialogLayout->addWidget( previewBox, 1, 0 );

    syntaxBox = new QGroupBox( this, "syntaxBox" );
    QFont syntaxBox_font(  syntaxBox->font() );
    syntaxBox->setFont( syntaxBox_font ); 
    syntaxBox->setColumnLayout(0, Qt::Vertical );
    syntaxBox->layout()->setSpacing( 5 );
    syntaxBox->layout()->setMargin( 8 );
    syntaxBoxLayout = new QGridLayout( syntaxBox->layout() );
    syntaxBoxLayout->setAlignment( Qt::AlignTop );

    layout8 = new QGridLayout( 0, 1, 1, 0, 5, "layout8"); 

    dimsLabel = new QLabel( syntaxBox, "dimsLabel" );
    dimsLabel->setBackgroundOrigin( QLabel::ParentOrigin );

    layout8->addWidget( dimsLabel, 4, 0 );

    dimsColorButton = new QPushButton( syntaxBox, "dimsColorButton" );
    dimsColorButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, dimsColorButton->sizePolicy().hasHeightForWidth() ) );
    dimsColorButton->setMaximumSize( QSize( 20, 20 ) );

    layout8->addWidget( dimsColorButton, 4, 2 );

    digitsLabel = new QLabel( syntaxBox, "digitsLabel" );
    digitsLabel->setBackgroundOrigin( QLabel::ParentOrigin );

    layout8->addWidget( digitsLabel, 6, 0 );

    quotationsColorButton = new QPushButton( syntaxBox, "quotationsColorButton" );
    quotationsColorButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, quotationsColorButton->sizePolicy().hasHeightForWidth() ) );
    quotationsColorButton->setMaximumSize( QSize( 20, 20 ) );

    layout8->addWidget( quotationsColorButton, 7, 2 );

    quotationsLabel = new QLabel( syntaxBox, "quotationsLabel" );
    quotationsLabel->setBackgroundOrigin( QLabel::ParentOrigin );

    layout8->addWidget( quotationsLabel, 7, 0 );

    standardColorLabel = new QLabel( syntaxBox, "standardColorLabel" );
    standardColorLabel->setMinimumSize( QSize( 30, 20 ) );
    standardColorLabel->setMaximumSize( QSize( 30, 20 ) );
    standardColorLabel->setFrameShape( QLabel::LineEditPanel );

    layout8->addWidget( standardColorLabel, 0, 1 );

    commentsColorButton = new QPushButton( syntaxBox, "commentsColorButton" );
    commentsColorButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, commentsColorButton->sizePolicy().hasHeightForWidth() ) );
    commentsColorButton->setMaximumSize( QSize( 20, 20 ) );

    layout8->addWidget( commentsColorButton, 5, 2 );

    quotationsColorLabel = new QLabel( syntaxBox, "quotationsColorLabel" );
    quotationsColorLabel->setMinimumSize( QSize( 30, 20 ) );
    quotationsColorLabel->setMaximumSize( QSize( 30, 20 ) );
    quotationsColorLabel->setFrameShape( QLabel::LineEditPanel );

    layout8->addWidget( quotationsColorLabel, 7, 1 );

    statementsColorButton = new QPushButton( syntaxBox, "statementsColorButton" );
    statementsColorButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, statementsColorButton->sizePolicy().hasHeightForWidth() ) );
    statementsColorButton->setMaximumSize( QSize( 20, 20 ) );

    layout8->addWidget( statementsColorButton, 2, 2 );

    digitsColorButton = new QPushButton( syntaxBox, "digitsColorButton" );
    digitsColorButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, digitsColorButton->sizePolicy().hasHeightForWidth() ) );
    digitsColorButton->setMaximumSize( QSize( 20, 20 ) );

    layout8->addWidget( digitsColorButton, 6, 2 );

    statementsLabel = new QLabel( syntaxBox, "statementsLabel" );
    statementsLabel->setMinimumSize( QSize( 62, 0 ) );
    statementsLabel->setBackgroundOrigin( QLabel::ParentOrigin );

    layout8->addWidget( statementsLabel, 2, 0 );

    commentsLabel = new QLabel( syntaxBox, "commentsLabel" );
    commentsLabel->setBackgroundOrigin( QLabel::ParentOrigin );

    layout8->addWidget( commentsLabel, 5, 0 );

    commandsLabel = new QLabel( syntaxBox, "commandsLabel" );
    commandsLabel->setBackgroundOrigin( QLabel::ParentOrigin );

    layout8->addWidget( commandsLabel, 3, 0 );

    commandsColorLabel = new QLabel( syntaxBox, "commandsColorLabel" );
    commandsColorLabel->setMinimumSize( QSize( 30, 20 ) );
    commandsColorLabel->setMaximumSize( QSize( 30, 20 ) );
    commandsColorLabel->setFrameShape( QLabel::LineEditPanel );

    layout8->addWidget( commandsColorLabel, 3, 1 );

    standardLabel = new QLabel( syntaxBox, "standardLabel" );
    standardLabel->setBackgroundOrigin( QLabel::ParentOrigin );

    layout8->addWidget( standardLabel, 0, 0 );

    commentsColorLabel = new QLabel( syntaxBox, "commentsColorLabel" );
    commentsColorLabel->setMinimumSize( QSize( 30, 20 ) );
    commentsColorLabel->setMaximumSize( QSize( 30, 20 ) );
    commentsColorLabel->setFrameShape( QLabel::LineEditPanel );

    layout8->addWidget( commentsColorLabel, 5, 1 );

    standardColorButton = new QPushButton( syntaxBox, "standardColorButton" );
    standardColorButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, standardColorButton->sizePolicy().hasHeightForWidth() ) );
    standardColorButton->setMaximumSize( QSize( 20, 20 ) );

    layout8->addWidget( standardColorButton, 0, 2 );

    commandsColorButton = new QPushButton( syntaxBox, "commandsColorButton" );
    commandsColorButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, commandsColorButton->sizePolicy().hasHeightForWidth() ) );
    commandsColorButton->setMaximumSize( QSize( 20, 20 ) );

    layout8->addWidget( commandsColorButton, 3, 2 );

    labelsColorButton = new QPushButton( syntaxBox, "labelsColorButton" );
    labelsColorButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, labelsColorButton->sizePolicy().hasHeightForWidth() ) );
    labelsColorButton->setMaximumSize( QSize( 20, 20 ) );

    layout8->addWidget( labelsColorButton, 1, 2 );

    dimsColorLabel = new QLabel( syntaxBox, "dimsColorLabel" );
    dimsColorLabel->setMinimumSize( QSize( 30, 20 ) );
    dimsColorLabel->setMaximumSize( QSize( 30, 20 ) );
    dimsColorLabel->setFrameShape( QLabel::LineEditPanel );

    layout8->addWidget( dimsColorLabel, 4, 1 );

    statementsColorLabel = new QLabel( syntaxBox, "statementsColorLabel" );
    statementsColorLabel->setMinimumSize( QSize( 30, 20 ) );
    statementsColorLabel->setMaximumSize( QSize( 30, 20 ) );
    statementsColorLabel->setFrameShape( QLabel::LineEditPanel );

    layout8->addWidget( statementsColorLabel, 2, 1 );

    labelsColorLabel = new QLabel( syntaxBox, "labelsColorLabel" );
    labelsColorLabel->setMinimumSize( QSize( 30, 20 ) );
    labelsColorLabel->setMaximumSize( QSize( 30, 20 ) );
    labelsColorLabel->setFrameShape( QLabel::LineEditPanel );

    layout8->addWidget( labelsColorLabel, 1, 1 );

    labelsLabel = new QLabel( syntaxBox, "labelsLabel" );
    labelsLabel->setBackgroundOrigin( QLabel::ParentOrigin );

    layout8->addWidget( labelsLabel, 1, 0 );

    digitsColorLabel = new QLabel( syntaxBox, "digitsColorLabel" );
    digitsColorLabel->setMinimumSize( QSize( 30, 20 ) );
    digitsColorLabel->setMaximumSize( QSize( 30, 20 ) );
    digitsColorLabel->setFrameShape( QLabel::LineEditPanel );

    layout8->addWidget( digitsColorLabel, 6, 1 );

    syntaxBoxLayout->addLayout( layout8, 0, 0 );

    layout9 = new QGridLayout( 0, 1, 1, 0, 5, "layout9"); 

    digitsFontLabel = new QLabel( syntaxBox, "digitsFontLabel" );
    digitsFontLabel->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, digitsFontLabel->sizePolicy().hasHeightForWidth() ) );
    digitsFontLabel->setBackgroundOrigin( QLabel::ParentOrigin );

    layout9->addWidget( digitsFontLabel, 6, 0 );

    standardFontLabel = new QLabel( syntaxBox, "standardFontLabel" );
    standardFontLabel->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, standardFontLabel->sizePolicy().hasHeightForWidth() ) );
    standardFontLabel->setBackgroundOrigin( QLabel::ParentOrigin );

    layout9->addWidget( standardFontLabel, 0, 0 );

    standardFontButton = new QPushButton( syntaxBox, "standardFontButton" );
    standardFontButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, standardFontButton->sizePolicy().hasHeightForWidth() ) );
    standardFontButton->setMaximumSize( QSize( 20, 20 ) );

    layout9->addWidget( standardFontButton, 0, 1 );

    commentsFontLabel = new QLabel( syntaxBox, "commentsFontLabel" );
    commentsFontLabel->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, commentsFontLabel->sizePolicy().hasHeightForWidth() ) );
    commentsFontLabel->setBackgroundOrigin( QLabel::ParentOrigin );

    layout9->addWidget( commentsFontLabel, 5, 0 );

    statementsFontLabel = new QLabel( syntaxBox, "statementsFontLabel" );
    statementsFontLabel->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, statementsFontLabel->sizePolicy().hasHeightForWidth() ) );
    statementsFontLabel->setBackgroundOrigin( QLabel::ParentOrigin );

    layout9->addWidget( statementsFontLabel, 2, 0 );

    digitsFontButton = new QPushButton( syntaxBox, "digitsFontButton" );
    digitsFontButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, digitsFontButton->sizePolicy().hasHeightForWidth() ) );
    digitsFontButton->setMaximumSize( QSize( 20, 20 ) );

    layout9->addWidget( digitsFontButton, 6, 1 );

    commandsFontLabel = new QLabel( syntaxBox, "commandsFontLabel" );
    commandsFontLabel->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, commandsFontLabel->sizePolicy().hasHeightForWidth() ) );
    commandsFontLabel->setBackgroundOrigin( QLabel::ParentOrigin );

    layout9->addWidget( commandsFontLabel, 3, 0 );

    commentsFontButton = new QPushButton( syntaxBox, "commentsFontButton" );
    commentsFontButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, commentsFontButton->sizePolicy().hasHeightForWidth() ) );
    commentsFontButton->setMaximumSize( QSize( 20, 20 ) );

    layout9->addWidget( commentsFontButton, 5, 1 );

    dimsFontLabel = new QLabel( syntaxBox, "dimsFontLabel" );
    dimsFontLabel->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, dimsFontLabel->sizePolicy().hasHeightForWidth() ) );
    dimsFontLabel->setBackgroundOrigin( QLabel::ParentOrigin );

    layout9->addWidget( dimsFontLabel, 4, 0 );

    quotationsFontLabel = new QLabel( syntaxBox, "quotationsFontLabel" );
    quotationsFontLabel->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, quotationsFontLabel->sizePolicy().hasHeightForWidth() ) );
    quotationsFontLabel->setBackgroundOrigin( QLabel::ParentOrigin );

    layout9->addWidget( quotationsFontLabel, 7, 0 );

    labelsFontLabel = new QLabel( syntaxBox, "labelsFontLabel" );
    labelsFontLabel->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, labelsFontLabel->sizePolicy().hasHeightForWidth() ) );
    labelsFontLabel->setBackgroundOrigin( QLabel::ParentOrigin );

    layout9->addWidget( labelsFontLabel, 1, 0 );

    quotationsFontButton = new QPushButton( syntaxBox, "quotationsFontButton" );
    quotationsFontButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, quotationsFontButton->sizePolicy().hasHeightForWidth() ) );
    quotationsFontButton->setMaximumSize( QSize( 20, 20 ) );

    layout9->addWidget( quotationsFontButton, 7, 1 );

    commandsFontButton = new QPushButton( syntaxBox, "commandsFontButton" );
    commandsFontButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, commandsFontButton->sizePolicy().hasHeightForWidth() ) );
    commandsFontButton->setMaximumSize( QSize( 20, 20 ) );

    layout9->addWidget( commandsFontButton, 3, 1 );

    dimsFontButton = new QPushButton( syntaxBox, "dimsFontButton" );
    dimsFontButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, dimsFontButton->sizePolicy().hasHeightForWidth() ) );
    dimsFontButton->setMaximumSize( QSize( 20, 20 ) );

    layout9->addWidget( dimsFontButton, 4, 1 );

    statementsFontButton = new QPushButton( syntaxBox, "statementsFontButton" );
    statementsFontButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, statementsFontButton->sizePolicy().hasHeightForWidth() ) );
    statementsFontButton->setMaximumSize( QSize( 20, 20 ) );

    layout9->addWidget( statementsFontButton, 2, 1 );

    labelsFontButton = new QPushButton( syntaxBox, "labelsFontButton" );
    labelsFontButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, labelsFontButton->sizePolicy().hasHeightForWidth() ) );
    labelsFontButton->setMaximumSize( QSize( 20, 20 ) );

    layout9->addWidget( labelsFontButton, 1, 1 );

    syntaxBoxLayout->addLayout( layout9, 0, 1 );

    PreferencesDialogLayout->addWidget( syntaxBox, 0, 0 );
    languageChange();
    resize( QSize(500, 420).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

	settings.setPath( "DONCity", "DCED2", QSettings::User );

    // signals and slots connections
    connect( okButton, SIGNAL( clicked() ), this, SLOT( save() ) );
	connect( okButton, SIGNAL( clicked() ), this, SLOT( accept() ) );
    connect( cancelButton, SIGNAL( clicked() ), this, SLOT( reset() ) );
	connect( cancelButton, SIGNAL( clicked() ), this, SLOT( reject() ) );
	//Color buttons
	connect( standardColorButton, SIGNAL( clicked() ), this, SLOT( setStandardColor() ) );
	connect( labelsColorButton, SIGNAL( clicked() ), this, SLOT( setLabelsColor() ) );
	connect( statementsColorButton, SIGNAL( clicked() ), this, SLOT( setStatementsColor() ) );
	connect( commandsColorButton, SIGNAL( clicked() ), this, SLOT( setCommandsColor() ) );
	connect( dimsColorButton, SIGNAL( clicked() ), this, SLOT( setDimsColor() ) );
	connect( commentsColorButton, SIGNAL( clicked() ), this, SLOT( setCommentsColor() ) );
	connect( digitsColorButton, SIGNAL( clicked() ), this, SLOT( setDigitsColor() ) );
	connect( quotationsColorButton, SIGNAL( clicked() ), this, SLOT( setQuotationsColor() ) );
	//Font buttons
	connect( standardFontButton, SIGNAL( clicked() ), this, SLOT( setStandardFont() ) );
	connect( labelsFontButton, SIGNAL( clicked() ), this, SLOT( setLabelsFont() ) );
	connect( statementsFontButton, SIGNAL( clicked() ), this, SLOT( setStatementsFont() ) );
	connect( commandsFontButton, SIGNAL( clicked() ), this, SLOT( setCommandsFont() ) );
	connect( dimsFontButton, SIGNAL( clicked() ), this, SLOT( setDimsFont() ) );
	connect( commentsFontButton, SIGNAL( clicked() ), this, SLOT( setCommentsFont() ) );
	connect( digitsFontButton, SIGNAL( clicked() ), this, SLOT( setDigitsFont() ) );
	connect( quotationsFontButton, SIGNAL( clicked() ), this, SLOT( setQuotationsFont() ) );
}

/*
 *  Destroys the object and frees any allocated resources
 */
PreferencesDialog::~PreferencesDialog()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void PreferencesDialog::languageChange()
{
    setCaption( tr( "Preferences" ) );
    cancelButton->setText( tr( "Cancel" ) );
    okButton->setText( tr( "OK" ) );
    previewBox->setTitle( tr( "Preview" ) );
    previewTextEdit->setText( tr( "//nahodny dite2\n"
"\n"
"dim_flt 1\n"
"dim_frm 1\n"
"FindFrame 0\n"
"\n"
"label 10\n"
"  rnd 0, 10                \n"
"  let flt[0] = flt[0] * 1000\n"
"  let flt[0] = flt[0] + 7000\n"
"  wait flt[0]\n"
"  frm_seton 0, 1\n"
"goto 10\n"
"end" ) );
    syntaxBox->setTitle( tr( "Syntax Highlighting" ) );
    dimsLabel->setText( tr( "Dims" ) );
    QToolTip::add( dimsLabel, tr( "\"dim_act\", \"dim_flt\", \"dim_frm\"" ) );
    dimsColorButton->setText( tr( "..." ) );
    digitsLabel->setText( tr( "Digits" ) );
    quotationsColorButton->setText( tr( "..." ) );
    quotationsLabel->setText( tr( "Quotations" ) );
    QToolTip::add( quotationsLabel, tr( "\"This is a text between two quotations\"" ) );
    standardColorLabel->setText( QString::null );
    commentsColorButton->setText( tr( "..." ) );
    quotationsColorLabel->setText( QString::null );
    statementsColorButton->setText( tr( "..." ) );
    digitsColorButton->setText( tr( "..." ) );
    statementsLabel->setText( tr( "Statements" ) );
    QToolTip::add( statementsLabel, tr( "Statements, like \"if\", \"goto\", \"wait\", \"end\" etc." ) );
    commentsLabel->setText( tr( "Comments" ) );
    QToolTip::add( commentsLabel, tr( "//This is a comment" ) );
    commandsLabel->setText( tr( "Commands" ) );
    QToolTip::add( commandsLabel, tr( "e.g. \"enemy_movetocar\", \"detector_waitforuse\", \"frm_getpos\" etc." ) );
    commandsColorLabel->setText( QString::null );
    standardLabel->setText( tr( "standard:" ) );
    QToolTip::add( standardLabel, tr( "The standard text" ) );
    commentsColorLabel->setText( QString::null );
    standardColorButton->setText( tr( "..." ) );
    commandsColorButton->setText( tr( "..." ) );
    labelsColorButton->setText( tr( "..." ) );
    dimsColorLabel->setText( QString::null );
    statementsColorLabel->setText( QString::null );
    labelsColorLabel->setText( QString::null );
    labelsLabel->setText( tr( "Labels:" ) );
    QToolTip::add( labelsLabel, tr( "Labels, e.g. \"label 101\"" ) );
    digitsColorLabel->setText( QString::null );
    standardFontButton->setText( tr( "..." ) );
    digitsFontButton->setText( tr( "..." ) );
    commentsFontButton->setText( tr( "..." ) );
    quotationsFontButton->setText( tr( "..." ) );
    commandsFontButton->setText( tr( "..." ) );
    dimsFontButton->setText( tr( "..." ) );
    statementsFontButton->setText( tr( "..." ) );
    labelsFontButton->setText( tr( "..." ) );

	reset();
}

void PreferencesDialog::reset()
{
	/*
	 *	Color boxes
	 */
	standardColorLabel->setPaletteBackgroundColor( previewSyntax->standardColor );
    digitsColorLabel->setPaletteBackgroundColor( previewSyntax->digitColor );
    labelsColorLabel->setPaletteBackgroundColor( previewSyntax->labelColor );
    statementsColorLabel->setPaletteBackgroundColor( previewSyntax->statementColor );
    dimsColorLabel->setPaletteBackgroundColor( previewSyntax->dimColor );
    commentsColorLabel->setPaletteBackgroundColor( previewSyntax->commentColor );
    commandsColorLabel->setPaletteBackgroundColor( previewSyntax->commandColor );
    quotationsColorLabel->setPaletteBackgroundColor( previewSyntax->quotationColor );

	/*
	 *	Font boxes
	 */
	standardFontLabel->setText( previewSyntax->standardFont.toString() );
	labelsFontLabel->setText( previewSyntax->labelFont.toString() );
	commandsFontLabel->setText( previewSyntax->commandFont.toString() );
	dimsFontLabel->setText( previewSyntax->dimFont.toString() );
	commentsFontLabel->setText( previewSyntax->commentFont.toString() );
	digitsFontLabel->setText( previewSyntax->digitFont.toString() );
	quotationsFontLabel->setText( previewSyntax->quotationFont.toString() );
}

void PreferencesDialog::save()
{
	settings.writeEntry( "syntax/colors/standard", previewSyntax->standardColor.name() );
	settings.writeEntry( "syntax/colors/label", previewSyntax->labelColor.name() );
	settings.writeEntry( "syntax/colors/statement", previewSyntax->statementColor.name() );
	settings.writeEntry( "syntax/colors/command", previewSyntax->commandColor.name() );
	settings.writeEntry( "syntax/colors/dim", previewSyntax->dimColor.name() );
	settings.writeEntry( "syntax/colors/digit", previewSyntax->digitColor.name() );
	settings.writeEntry( "syntax/colors/quotation", previewSyntax->quotationColor.name() );
	settings.writeEntry( "syntax/colors/comment", previewSyntax->commentColor.name() );
	
	settings.writeEntry( "syntax/fonts/standard", previewSyntax->standardFont.toString() );
	settings.writeEntry( "syntax/fonts/label", previewSyntax->labelFont.toString() );
	settings.writeEntry( "syntax/fonts/statement", previewSyntax->statementFont.toString() );
	settings.writeEntry( "syntax/fonts/command", previewSyntax->commandFont.toString() );
	settings.writeEntry( "syntax/fonts/dim", previewSyntax->dimFont.toString() );
	settings.writeEntry( "syntax/fonts/digit", previewSyntax->digitFont.toString() );
	settings.writeEntry( "syntax/fonts/quotation", previewSyntax->quotationFont.toString() );
	settings.writeEntry( "syntax/fonts/comment", previewSyntax->commentFont.toString() );

	emit settingsSaved();
}

/*
 *	Color functions
 */

void PreferencesDialog::setStandardColor()
{
	previewSyntax->standardColor = QColorDialog::getColor( previewSyntax->standardColor, this );
	standardColorLabel->setPaletteBackgroundColor( previewSyntax->standardColor );
	previewSyntax->reinitialise();
}

void PreferencesDialog::setLabelsColor()
{
	previewSyntax->labelColor = QColorDialog::getColor( previewSyntax->labelColor, this );
	labelsColorLabel->setPaletteBackgroundColor( previewSyntax->labelColor );
	previewSyntax->reinitialise();
}

void PreferencesDialog::setStatementsColor()
{
	previewSyntax->statementColor = QColorDialog::getColor( previewSyntax->statementColor, this );
	statementsColorLabel->setPaletteBackgroundColor( previewSyntax->statementColor );
	previewSyntax->reinitialise();
}

void PreferencesDialog::setCommandsColor()
{
	previewSyntax->commandColor = QColorDialog::getColor( previewSyntax->commandColor, this );
	commandsColorLabel->setPaletteBackgroundColor( previewSyntax->commandColor );
	previewSyntax->reinitialise();
}

void PreferencesDialog::setDimsColor()
{
	previewSyntax->dimColor = QColorDialog::getColor( previewSyntax->dimColor, this );
	dimsColorLabel->setPaletteBackgroundColor( previewSyntax->dimColor );
	previewSyntax->reinitialise();
}

void PreferencesDialog::setCommentsColor()
{
	previewSyntax->commentColor = QColorDialog::getColor( previewSyntax->commentColor, this );
	commentsColorLabel->setPaletteBackgroundColor( previewSyntax->commentColor );
	previewSyntax->reinitialise();
}

void PreferencesDialog::setDigitsColor()
{
	previewSyntax->digitColor = QColorDialog::getColor( previewSyntax->digitColor, this );
	digitsColorLabel->setPaletteBackgroundColor( previewSyntax->digitColor );
	previewSyntax->reinitialise();
}

void PreferencesDialog::setQuotationsColor()
{
	previewSyntax->quotationColor = QColorDialog::getColor( previewSyntax->quotationColor, this );
	quotationsColorLabel->setPaletteBackgroundColor( previewSyntax->quotationColor );
	previewSyntax->reinitialise();
}

/*
 *	Font functions
 */

void PreferencesDialog::setStandardFont()
{
	previewSyntax->standardFont = QFontDialog::getFont( 0, previewSyntax->standardFont, this );
	standardFontLabel->setText( previewSyntax->standardFont.toString() );
	previewSyntax->reinitialise();
}

void PreferencesDialog::setLabelsFont()
{
	previewSyntax->labelFont = QFontDialog::getFont( 0, previewSyntax->labelFont, this );
	labelsFontLabel->setText( previewSyntax->labelFont.toString() );
	previewSyntax->reinitialise();
}

void PreferencesDialog::setStatementsFont()
{
	previewSyntax->statementFont = QFontDialog::getFont( 0, previewSyntax->statementFont, this );
	statementsFontLabel->setText( previewSyntax->statementFont.toString() );
	previewSyntax->reinitialise();
}

void PreferencesDialog::setCommandsFont()
{
	previewSyntax->commandFont = QFontDialog::getFont( 0, previewSyntax->commandFont, this );
	commandsFontLabel->setText( previewSyntax->commandFont.toString() );
	previewSyntax->reinitialise();
}

void PreferencesDialog::setDimsFont()
{
	previewSyntax->dimFont = QFontDialog::getFont( 0, previewSyntax->dimFont, this );
	dimsFontLabel->setText( previewSyntax->dimFont.toString() );
	previewSyntax->reinitialise();
}

void PreferencesDialog::setCommentsFont()
{	
	previewSyntax->commentFont = QFontDialog::getFont( 0, previewSyntax->commentFont, this );
	commentsFontLabel->setText( previewSyntax->commentFont.toString() );
	previewSyntax->reinitialise();
}

void PreferencesDialog::setDigitsFont()
{
	previewSyntax->digitFont = QFontDialog::getFont( 0, previewSyntax->digitFont, this );
	digitsFontLabel->setText( previewSyntax->digitFont.toString() );
	previewSyntax->reinitialise();
}

void PreferencesDialog::setQuotationsFont()
{
	previewSyntax->quotationFont = QFontDialog::getFont( 0, previewSyntax->quotationFont, this );
	quotationsFontLabel->setText( previewSyntax->quotationFont.toString() );
	previewSyntax->reinitialise();
}