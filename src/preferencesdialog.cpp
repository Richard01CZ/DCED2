#include "preferencesdialog.h"
#include "img\identity.xpm"
#include "mafiasyntax.h"
#include "globaldefs.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qcheckbox.h>
#include <qcombobox.h>
#include <qbuttongroup.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>
#include <qfontdatabase.h>
#include <qcolordialog.h>

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
    setMinimumSize( QSize( 500, 550 ) );
    setMaximumSize( QSize( 500, 550 ) );
    setIcon( image0 );
    PreferencesDialogLayout = new QGridLayout( this, 1, 1, 8, 5, "PreferencesDialogLayout"); 

    layout1 = new QHBoxLayout( 0, 0, 5, "layout1"); 
    QSpacerItem* spacer = new QSpacerItem( 392, 25, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout1->addItem( spacer );

    okButton = new QPushButton( this, "okButton" );
    okButton->setDefault( TRUE );
    layout1->addWidget( okButton );

    cancelButton = new QPushButton( this, "cancelButton" );
    layout1->addWidget( cancelButton );

    PreferencesDialogLayout->addMultiCellLayout( layout1, 3, 3, 0, 1 );

    syntaxBox = new QButtonGroup( this, "syntaxBox" );
    QFont syntaxBox_font(  syntaxBox->font() );
    syntaxBox->setFont( syntaxBox_font ); 
    syntaxBox->setColumnLayout(0, Qt::Vertical );
    syntaxBox->layout()->setSpacing( 5 );
    syntaxBox->layout()->setMargin( 8 );
    syntaxBoxLayout = new QGridLayout( syntaxBox->layout() );
    syntaxBoxLayout->setAlignment( Qt::AlignTop );

    dimsLabel = new QLabel( syntaxBox, "dimsLabel" );
    dimsLabel->setBackgroundOrigin( QLabel::ParentOrigin );

    syntaxBoxLayout->addWidget( dimsLabel, 4, 0 );

    dimsColorButton = new QPushButton( syntaxBox, "dimsColorButton" );
    dimsColorButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, dimsColorButton->sizePolicy().hasHeightForWidth() ) );
    dimsColorButton->setMaximumSize( QSize( 20, 20 ) );

    syntaxBoxLayout->addWidget( dimsColorButton, 4, 2 );

    digitsLabel = new QLabel( syntaxBox, "digitsLabel" );
    digitsLabel->setBackgroundOrigin( QLabel::ParentOrigin );

    syntaxBoxLayout->addWidget( digitsLabel, 6, 0 );

    quotationsColorButton = new QPushButton( syntaxBox, "quotationsColorButton" );
    quotationsColorButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, quotationsColorButton->sizePolicy().hasHeightForWidth() ) );
    quotationsColorButton->setMaximumSize( QSize( 20, 20 ) );

    syntaxBoxLayout->addWidget( quotationsColorButton, 7, 2 );

    quotationsLabel = new QLabel( syntaxBox, "quotationsLabel" );
    quotationsLabel->setBackgroundOrigin( QLabel::ParentOrigin );

    syntaxBoxLayout->addWidget( quotationsLabel, 7, 0 );

    standardColorLabel = new QLabel( syntaxBox, "standardColorLabel" );
    standardColorLabel->setMinimumSize( QSize( 30, 20 ) );
    standardColorLabel->setMaximumSize( QSize( 30, 20 ) );
    standardColorLabel->setPaletteBackgroundColor( QColor( 0, 0, 0 ) );
    standardColorLabel->setFrameShape( QLabel::LineEditPanel );

    syntaxBoxLayout->addWidget( standardColorLabel, 0, 1 );

    commentsColorButton = new QPushButton( syntaxBox, "commentsColorButton" );
    commentsColorButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, commentsColorButton->sizePolicy().hasHeightForWidth() ) );
    commentsColorButton->setMaximumSize( QSize( 20, 20 ) );

    syntaxBoxLayout->addWidget( commentsColorButton, 5, 2 );

    quotationsColorLabel = new QLabel( syntaxBox, "quotationsColorLabel" );
    quotationsColorLabel->setMinimumSize( QSize( 30, 20 ) );
    quotationsColorLabel->setMaximumSize( QSize( 30, 20 ) );
    quotationsColorLabel->setPaletteBackgroundColor( QColor( 230, 0, 180 ) );
    quotationsColorLabel->setFrameShape( QLabel::LineEditPanel );

    syntaxBoxLayout->addWidget( quotationsColorLabel, 7, 1 );

    statementsColorButton = new QPushButton( syntaxBox, "statementsColorButton" );
    statementsColorButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, statementsColorButton->sizePolicy().hasHeightForWidth() ) );
    statementsColorButton->setMaximumSize( QSize( 20, 20 ) );

    syntaxBoxLayout->addWidget( statementsColorButton, 2, 2 );

    digitsColorButton = new QPushButton( syntaxBox, "digitsColorButton" );
    digitsColorButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, digitsColorButton->sizePolicy().hasHeightForWidth() ) );
    digitsColorButton->setMaximumSize( QSize( 20, 20 ) );

    syntaxBoxLayout->addWidget( digitsColorButton, 6, 2 );

    statementsLabel = new QLabel( syntaxBox, "statementsLabel" );
    statementsLabel->setMinimumSize( QSize( 62, 0 ) );
    statementsLabel->setBackgroundOrigin( QLabel::ParentOrigin );

    syntaxBoxLayout->addWidget( statementsLabel, 2, 0 );

    commentsLabel = new QLabel( syntaxBox, "commentsLabel" );
    commentsLabel->setBackgroundOrigin( QLabel::ParentOrigin );

    syntaxBoxLayout->addWidget( commentsLabel, 5, 0 );

    commandsLabel = new QLabel( syntaxBox, "commandsLabel" );
    commandsLabel->setBackgroundOrigin( QLabel::ParentOrigin );

    syntaxBoxLayout->addWidget( commandsLabel, 3, 0 );

    commandsColorLabel = new QLabel( syntaxBox, "commandsColorLabel" );
    commandsColorLabel->setMinimumSize( QSize( 30, 20 ) );
    commandsColorLabel->setMaximumSize( QSize( 30, 20 ) );
    commandsColorLabel->setPaletteBackgroundColor( QColor( 0, 0, 180 ) );
    commandsColorLabel->setFrameShape( QLabel::LineEditPanel );

    syntaxBoxLayout->addWidget( commandsColorLabel, 3, 1 );

    standardLabel = new QLabel( syntaxBox, "standardLabel" );
    standardLabel->setBackgroundOrigin( QLabel::ParentOrigin );

    syntaxBoxLayout->addWidget( standardLabel, 0, 0 );

    commentsColorLabel = new QLabel( syntaxBox, "commentsColorLabel" );
    commentsColorLabel->setMinimumSize( QSize( 30, 20 ) );
    commentsColorLabel->setMaximumSize( QSize( 30, 20 ) );
    commentsColorLabel->setPaletteBackgroundColor( QColor( 0, 125, 0 ) );
    commentsColorLabel->setFrameShape( QLabel::LineEditPanel );

    syntaxBoxLayout->addWidget( commentsColorLabel, 5, 1 );

    standardColorButton = new QPushButton( syntaxBox, "standardColorButton" );
    standardColorButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, standardColorButton->sizePolicy().hasHeightForWidth() ) );
    standardColorButton->setMaximumSize( QSize( 20, 20 ) );

    syntaxBoxLayout->addWidget( standardColorButton, 0, 2 );

    commandsColorButton = new QPushButton( syntaxBox, "commandsColorButton" );
    commandsColorButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, commandsColorButton->sizePolicy().hasHeightForWidth() ) );
    commandsColorButton->setMaximumSize( QSize( 20, 20 ) );

    syntaxBoxLayout->addWidget( commandsColorButton, 3, 2 );

    labelsColorButton = new QPushButton( syntaxBox, "labelsColorButton" );
    labelsColorButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, labelsColorButton->sizePolicy().hasHeightForWidth() ) );
    labelsColorButton->setMaximumSize( QSize( 20, 20 ) );

    syntaxBoxLayout->addWidget( labelsColorButton, 1, 2 );

    dimsColorLabel = new QLabel( syntaxBox, "dimsColorLabel" );
    dimsColorLabel->setMinimumSize( QSize( 30, 20 ) );
    dimsColorLabel->setMaximumSize( QSize( 30, 20 ) );
    dimsColorLabel->setPaletteBackgroundColor( QColor( 255, 0, 0 ) );
    dimsColorLabel->setFrameShape( QLabel::LineEditPanel );

    syntaxBoxLayout->addWidget( dimsColorLabel, 4, 1 );

    statementsColorLabel = new QLabel( syntaxBox, "statementsColorLabel" );
    statementsColorLabel->setMinimumSize( QSize( 30, 20 ) );
    statementsColorLabel->setMaximumSize( QSize( 30, 20 ) );
    statementsColorLabel->setPaletteBackgroundColor( QColor( 0, 0, 180 ) );
    statementsColorLabel->setFrameShape( QLabel::LineEditPanel );

    syntaxBoxLayout->addWidget( statementsColorLabel, 2, 1 );

    labelsColorLabel = new QLabel( syntaxBox, "labelsColorLabel" );
    labelsColorLabel->setMinimumSize( QSize( 30, 20 ) );
    labelsColorLabel->setMaximumSize( QSize( 30, 20 ) );
    labelsColorLabel->setPaletteBackgroundColor( QColor( 0, 0, 180 ) );
    labelsColorLabel->setFrameShape( QLabel::LineEditPanel );

    syntaxBoxLayout->addWidget( labelsColorLabel, 1, 1 );

    labelsLabel = new QLabel( syntaxBox, "labelsLabel" );
    labelsLabel->setBackgroundOrigin( QLabel::ParentOrigin );

    syntaxBoxLayout->addWidget( labelsLabel, 1, 0 );

    digitsColorLabel = new QLabel( syntaxBox, "digitsColorLabel" );
    digitsColorLabel->setMinimumSize( QSize( 30, 20 ) );
    digitsColorLabel->setMaximumSize( QSize( 30, 20 ) );
    digitsColorLabel->setPaletteBackgroundColor( QColor( 0, 0, 0 ) );
    digitsColorLabel->setFrameShape( QLabel::LineEditPanel );

    syntaxBoxLayout->addWidget( digitsColorLabel, 6, 1 );
    QSpacerItem* spacer_2 = new QSpacerItem( 30, 21, QSizePolicy::Maximum, QSizePolicy::Minimum );
    syntaxBoxLayout->addItem( spacer_2, 0, 3 );

    standardBoldCheckBox = new QCheckBox( syntaxBox, "standardBoldCheckBox" );
    QFont standardBoldCheckBox_font(  standardBoldCheckBox->font() );
    standardBoldCheckBox_font.setBold( TRUE );
    standardBoldCheckBox->setFont( standardBoldCheckBox_font ); 

    syntaxBoxLayout->addWidget( standardBoldCheckBox, 0, 4 );

    standardItalicCheckBox = new QCheckBox( syntaxBox, "standardItalicCheckBox" );
    QFont standardItalicCheckBox_font(  standardItalicCheckBox->font() );
    standardItalicCheckBox_font.setItalic( TRUE );
    standardItalicCheckBox->setFont( standardItalicCheckBox_font ); 

    syntaxBoxLayout->addWidget( standardItalicCheckBox, 0, 5 );

    standardUnderlineCheckBox = new QCheckBox( syntaxBox, "standardUnderlineCheckBox" );
    QFont standardUnderlineCheckBox_font(  standardUnderlineCheckBox->font() );
    standardUnderlineCheckBox_font.setUnderline( TRUE );
    standardUnderlineCheckBox->setFont( standardUnderlineCheckBox_font ); 

    syntaxBoxLayout->addWidget( standardUnderlineCheckBox, 0, 6 );
    QSpacerItem* spacer_3 = new QSpacerItem( 30, 21, QSizePolicy::Maximum, QSizePolicy::Minimum );
    syntaxBoxLayout->addItem( spacer_3, 1, 3 );

    labelsBoldCheckBox = new QCheckBox( syntaxBox, "labelsBoldCheckBox" );
    QFont labelsBoldCheckBox_font(  labelsBoldCheckBox->font() );
    labelsBoldCheckBox_font.setBold( TRUE );
    labelsBoldCheckBox->setFont( labelsBoldCheckBox_font ); 

    syntaxBoxLayout->addWidget( labelsBoldCheckBox, 1, 4 );

    labelsItalicCheckBox = new QCheckBox( syntaxBox, "labelsItalicCheckBox" );
    QFont labelsItalicCheckBox_font(  labelsItalicCheckBox->font() );
    labelsItalicCheckBox_font.setItalic( TRUE );
    labelsItalicCheckBox->setFont( labelsItalicCheckBox_font ); 

    syntaxBoxLayout->addWidget( labelsItalicCheckBox, 1, 5 );

    labelsUnderlineCheckBox = new QCheckBox( syntaxBox, "labelsUnderlineCheckBox" );
    QFont labelsUnderlineCheckBox_font(  labelsUnderlineCheckBox->font() );
    labelsUnderlineCheckBox_font.setUnderline( TRUE );
    labelsUnderlineCheckBox->setFont( labelsUnderlineCheckBox_font ); 

    syntaxBoxLayout->addWidget( labelsUnderlineCheckBox, 1, 6 );
    QSpacerItem* spacer_4 = new QSpacerItem( 30, 21, QSizePolicy::Maximum, QSizePolicy::Minimum );
    syntaxBoxLayout->addItem( spacer_4, 2, 3 );

    statementsBoldCheckBox = new QCheckBox( syntaxBox, "statementsBoldCheckBox" );
    QFont statementsBoldCheckBox_font(  statementsBoldCheckBox->font() );
    statementsBoldCheckBox_font.setBold( TRUE );
    statementsBoldCheckBox->setFont( statementsBoldCheckBox_font ); 

    syntaxBoxLayout->addWidget( statementsBoldCheckBox, 2, 4 );

    statementsItalicCheckBox = new QCheckBox( syntaxBox, "statementsItalicCheckBox" );
    QFont statementsItalicCheckBox_font(  statementsItalicCheckBox->font() );
    statementsItalicCheckBox_font.setItalic( TRUE );
    statementsItalicCheckBox->setFont( statementsItalicCheckBox_font ); 

    syntaxBoxLayout->addWidget( statementsItalicCheckBox, 2, 5 );

    statementsUnderlineCheckBox = new QCheckBox( syntaxBox, "statementsUnderlineCheckBox" );
    QFont statementsUnderlineCheckBox_font(  statementsUnderlineCheckBox->font() );
    statementsUnderlineCheckBox_font.setUnderline( TRUE );
    statementsUnderlineCheckBox->setFont( statementsUnderlineCheckBox_font ); 

    syntaxBoxLayout->addWidget( statementsUnderlineCheckBox, 2, 6 );

    commandsBoldCheckBox = new QCheckBox( syntaxBox, "commandsBoldCheckBox" );
    QFont commandsBoldCheckBox_font(  commandsBoldCheckBox->font() );
    commandsBoldCheckBox_font.setBold( TRUE );
    commandsBoldCheckBox->setFont( commandsBoldCheckBox_font ); 

    syntaxBoxLayout->addWidget( commandsBoldCheckBox, 3, 4 );
    QSpacerItem* spacer_5 = new QSpacerItem( 30, 21, QSizePolicy::Maximum, QSizePolicy::Minimum );
    syntaxBoxLayout->addItem( spacer_5, 3, 3 );

    commandsItalicCheckBox = new QCheckBox( syntaxBox, "commandsItalicCheckBox" );
    QFont commandsItalicCheckBox_font(  commandsItalicCheckBox->font() );
    commandsItalicCheckBox_font.setItalic( TRUE );
    commandsItalicCheckBox->setFont( commandsItalicCheckBox_font ); 

    syntaxBoxLayout->addWidget( commandsItalicCheckBox, 3, 5 );

    commandsUnderlineCheckBox = new QCheckBox( syntaxBox, "commandsUnderlineCheckBox" );
    QFont commandsUnderlineCheckBox_font(  commandsUnderlineCheckBox->font() );
    commandsUnderlineCheckBox_font.setUnderline( TRUE );
    commandsUnderlineCheckBox->setFont( commandsUnderlineCheckBox_font ); 

    syntaxBoxLayout->addWidget( commandsUnderlineCheckBox, 3, 6 );
    QSpacerItem* spacer_6 = new QSpacerItem( 30, 21, QSizePolicy::Maximum, QSizePolicy::Minimum );
    syntaxBoxLayout->addItem( spacer_6, 4, 3 );

    dimsBoldCheckBox = new QCheckBox( syntaxBox, "dimsBoldCheckBox" );
    QFont dimsBoldCheckBox_font(  dimsBoldCheckBox->font() );
    dimsBoldCheckBox_font.setBold( TRUE );
    dimsBoldCheckBox->setFont( dimsBoldCheckBox_font ); 

    syntaxBoxLayout->addWidget( dimsBoldCheckBox, 4, 4 );

    dimsItalicCheckBox = new QCheckBox( syntaxBox, "dimsItalicCheckBox" );
    QFont dimsItalicCheckBox_font(  dimsItalicCheckBox->font() );
    dimsItalicCheckBox_font.setItalic( TRUE );
    dimsItalicCheckBox->setFont( dimsItalicCheckBox_font ); 

    syntaxBoxLayout->addWidget( dimsItalicCheckBox, 4, 5 );

    dimsUnderlineCheckBox = new QCheckBox( syntaxBox, "dimsUnderlineCheckBox" );
    QFont dimsUnderlineCheckBox_font(  dimsUnderlineCheckBox->font() );
    dimsUnderlineCheckBox_font.setUnderline( TRUE );
    dimsUnderlineCheckBox->setFont( dimsUnderlineCheckBox_font ); 

    syntaxBoxLayout->addWidget( dimsUnderlineCheckBox, 4, 6 );
    QSpacerItem* spacer_7 = new QSpacerItem( 30, 21, QSizePolicy::Maximum, QSizePolicy::Minimum );
    syntaxBoxLayout->addItem( spacer_7, 5, 3 );

    commentsBoldCheckBox = new QCheckBox( syntaxBox, "commentsBoldCheckBox" );
    QFont commentsBoldCheckBox_font(  commentsBoldCheckBox->font() );
    commentsBoldCheckBox_font.setBold( TRUE );
    commentsBoldCheckBox->setFont( commentsBoldCheckBox_font ); 

    syntaxBoxLayout->addWidget( commentsBoldCheckBox, 5, 4 );

    commentsItalicCheckBox = new QCheckBox( syntaxBox, "commentsItalicCheckBox" );
    QFont commentsItalicCheckBox_font(  commentsItalicCheckBox->font() );
    commentsItalicCheckBox_font.setItalic( TRUE );
    commentsItalicCheckBox->setFont( commentsItalicCheckBox_font ); 

    syntaxBoxLayout->addWidget( commentsItalicCheckBox, 5, 5 );

    commentsUnderlineCheckBox = new QCheckBox( syntaxBox, "commentsUnderlineCheckBox" );
    QFont commentsUnderlineCheckBox_font(  commentsUnderlineCheckBox->font() );
    commentsUnderlineCheckBox_font.setUnderline( TRUE );
    commentsUnderlineCheckBox->setFont( commentsUnderlineCheckBox_font ); 

    syntaxBoxLayout->addWidget( commentsUnderlineCheckBox, 5, 6 );
    QSpacerItem* spacer_8 = new QSpacerItem( 30, 21, QSizePolicy::Maximum, QSizePolicy::Minimum );
    syntaxBoxLayout->addItem( spacer_8, 6, 3 );

    digitsBoldCheckBox = new QCheckBox( syntaxBox, "digitsBoldCheckBox" );
    QFont digitsBoldCheckBox_font(  digitsBoldCheckBox->font() );
    digitsBoldCheckBox_font.setBold( TRUE );
    digitsBoldCheckBox->setFont( digitsBoldCheckBox_font ); 

    syntaxBoxLayout->addWidget( digitsBoldCheckBox, 6, 4 );

    digitsItalicCheckBox = new QCheckBox( syntaxBox, "digitsItalicCheckBox" );
    QFont digitsItalicCheckBox_font(  digitsItalicCheckBox->font() );
    digitsItalicCheckBox_font.setItalic( TRUE );
    digitsItalicCheckBox->setFont( digitsItalicCheckBox_font ); 

    syntaxBoxLayout->addWidget( digitsItalicCheckBox, 6, 5 );

    digitsUnderlineCheckBox = new QCheckBox( syntaxBox, "digitsUnderlineCheckBox" );
    QFont digitsUnderlineCheckBox_font(  digitsUnderlineCheckBox->font() );
    digitsUnderlineCheckBox_font.setUnderline( TRUE );
    digitsUnderlineCheckBox->setFont( digitsUnderlineCheckBox_font ); 

    syntaxBoxLayout->addWidget( digitsUnderlineCheckBox, 6, 6 );
    QSpacerItem* spacer_9 = new QSpacerItem( 30, 21, QSizePolicy::Maximum, QSizePolicy::Minimum );
    syntaxBoxLayout->addItem( spacer_9, 7, 3 );

    quotationsBoldCheckBox = new QCheckBox( syntaxBox, "quotationsBoldCheckBox" );
    QFont quotationsBoldCheckBox_font(  quotationsBoldCheckBox->font() );
    quotationsBoldCheckBox_font.setBold( TRUE );
    quotationsBoldCheckBox->setFont( quotationsBoldCheckBox_font ); 

    syntaxBoxLayout->addWidget( quotationsBoldCheckBox, 7, 4 );

    quotationsItalicCheckBox = new QCheckBox( syntaxBox, "quotationsItalicCheckBox" );
    QFont quotationsItalicCheckBox_font(  quotationsItalicCheckBox->font() );
    quotationsItalicCheckBox_font.setItalic( TRUE );
    quotationsItalicCheckBox->setFont( quotationsItalicCheckBox_font ); 

    syntaxBoxLayout->addWidget( quotationsItalicCheckBox, 7, 5 );

    quotationsUnderlineCheckBox = new QCheckBox( syntaxBox, "quotationsUnderlineCheckBox" );
    QFont quotationsUnderlineCheckBox_font(  quotationsUnderlineCheckBox->font() );
    quotationsUnderlineCheckBox_font.setUnderline( TRUE );
    quotationsUnderlineCheckBox->setFont( quotationsUnderlineCheckBox_font ); 

    syntaxBoxLayout->addWidget( quotationsUnderlineCheckBox, 7, 6 );

    PreferencesDialogLayout->addMultiCellWidget( syntaxBox, 1, 1, 0, 1 );

    fontBox = new QGroupBox( this, "fontBox" );
    fontBox->setColumnLayout(0, Qt::Vertical );
    fontBox->layout()->setSpacing( 5 );
    fontBox->layout()->setMargin( 8 );
    fontBoxLayout = new QGridLayout( fontBox->layout() );
    fontBoxLayout->setAlignment( Qt::AlignTop );

    previewFontLabel = new QLabel( fontBox, "previewFontLabel" );
    previewFontLabel->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)4, 0, 0, previewFontLabel->sizePolicy().hasHeightForWidth() ) );

    fontBoxLayout->addWidget( previewFontLabel, 0, 0 );

    editFontLabel = new QLabel( fontBox, "editFontLabel" );
    editFontLabel->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)4, (QSizePolicy::SizeType)5, 0, 0, editFontLabel->sizePolicy().hasHeightForWidth() ) );

    fontBoxLayout->addWidget( editFontLabel, 1, 0 );

    editFontComboBox = new QComboBox( FALSE, fontBox, "editFontComboBox" );

    fontBoxLayout->addWidget( editFontComboBox, 1, 1 );

    previewFontComboBox = new QComboBox( FALSE, fontBox, "previewFontComboBox" );

    fontBoxLayout->addWidget( previewFontComboBox, 0, 1 );

    PreferencesDialogLayout->addMultiCellWidget( fontBox, 0, 0, 0, 1 );

    previewPreviewBox = new QGroupBox( this, "previewPreviewBox" );
    previewPreviewBox->setMargin( 0 );
    previewPreviewBox->setColumnLayout(0, Qt::Vertical );
    previewPreviewBox->layout()->setSpacing( 5 );
    previewPreviewBox->layout()->setMargin( 5 );
    previewPreviewBoxLayout = new QGridLayout( previewPreviewBox->layout() );
    previewPreviewBoxLayout->setAlignment( Qt::AlignTop );

    previewPreviewTextEdit = new QTextEdit( previewPreviewBox, "previewPreviewTextEdit" );
    previewPreviewTextEdit->setTextFormat( QTextEdit::PlainText );
    previewPreviewTextEdit->setWordWrap( QTextEdit::NoWrap );
    previewPreviewTextEdit->setUndoRedoEnabled( FALSE );

	previewSyntax = new MafiaSyntax( previewPreviewTextEdit, MafiaSyntax::Preview );

	previewPreviewTextEdit->setFamily( previewSyntax->fontFamily );

    previewPreviewBoxLayout->addWidget( previewPreviewTextEdit, 0, 0 );

    PreferencesDialogLayout->addWidget( previewPreviewBox, 2, 0 );

    editPreviewBox = new QGroupBox( this, "editPreviewBox" );
    editPreviewBox->setColumnLayout(0, Qt::Vertical );
    editPreviewBox->layout()->setSpacing( 5 );
    editPreviewBox->layout()->setMargin( 8 );
    editPreviewBoxLayout = new QGridLayout( editPreviewBox->layout() );
    editPreviewBoxLayout->setAlignment( Qt::AlignTop );

    editPreviewTextEdit = new QTextEdit( editPreviewBox, "editPreviewTextEdit" );
    editPreviewTextEdit->setTextFormat( QTextEdit::PlainText );
    editPreviewTextEdit->setWordWrap( QTextEdit::NoWrap );
    editPreviewTextEdit->setUndoRedoEnabled( FALSE );

	editSyntax = new MafiaSyntax( editPreviewTextEdit, MafiaSyntax::Edit );

	editPreviewTextEdit->setFamily( editSyntax->fontFamily );

    editPreviewBoxLayout->addWidget( editPreviewTextEdit, 0, 0 );

    PreferencesDialogLayout->addWidget( editPreviewBox, 2, 1 );
    languageChange();
    resize( QSize(500, 550).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
	connect( okButton, SIGNAL( clicked() ), this, SLOT( save() ) );
    connect( cancelButton, SIGNAL( clicked() ), this, SLOT( reject() ) );
	connect( standardColorButton, SIGNAL( clicked() ), this, SLOT( setStandardColor() ) );
	connect( labelsColorButton, SIGNAL( clicked() ), this, SLOT( setLabelsColor() ) );
	connect( statementsColorButton, SIGNAL( clicked() ), this, SLOT( setStatementsColor() ) );
	connect( commandsColorButton, SIGNAL( clicked() ), this, SLOT( setCommandsColor() ) );
	connect( dimsColorButton, SIGNAL( clicked() ), this, SLOT( setDimsColor() ) );
	connect( commentsColorButton, SIGNAL( clicked() ), this, SLOT( setCommentsColor() ) );
	connect( digitsColorButton, SIGNAL( clicked() ), this, SLOT( setDigitsColor() ) );
	connect( quotationsColorButton, SIGNAL( clicked() ), this, SLOT( setQuotationsColor() ) );
	connect( syntaxBox, SIGNAL( clicked( int ) ), this, SLOT( updatePreview() ) );
	connect( editFontComboBox, SIGNAL( activated( int ) ), this, SLOT( updatePreview() ) );
	connect( previewFontComboBox, SIGNAL( activated( int ) ), this, SLOT( updatePreview() ) );
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

	QFontDatabase fdb;
	previewFontComboBox->insertStringList( fdb.families() );
	editFontComboBox->insertStringList( fdb.families( ) );

    syntaxBox->setTitle( tr( "Colours" ) );
    dimsLabel->setText( tr( "Dims:" ) );
    QToolTip::add( dimsLabel, tr( "\"dim_act\", \"dim_flt\", \"dim_frm\"" ) );
    dimsColorButton->setText( tr( "..." ) );
    digitsLabel->setText( tr( "Digits:" ) );
    quotationsColorButton->setText( tr( "..." ) );
    quotationsLabel->setText( tr( "Quotations:" ) );
    QToolTip::add( quotationsLabel, tr( "\"This is a text between two quotations\"" ) );
    standardColorLabel->setText( QString::null );
    commentsColorButton->setText( tr( "..." ) );
    quotationsColorLabel->setText( QString::null );
    statementsColorButton->setText( tr( "..." ) );
    digitsColorButton->setText( tr( "..." ) );
    statementsLabel->setText( tr( "Statements:" ) );
    QToolTip::add( statementsLabel, tr( "Statements, like \"if\", \"goto\", \"wait\", \"end\" etc." ) );
    commentsLabel->setText( tr( "Comments:" ) );
    QToolTip::add( commentsLabel, tr( "//This is a comment" ) );
    commandsLabel->setText( tr( "Commands:" ) );
    QToolTip::add( commandsLabel, tr( "e.g. \"enemy_movetocar\", \"detector_waitforuse\", \"frm_getpos\" etc." ) );
    commandsColorLabel->setText( QString::null );
    standardLabel->setText( tr( "Standard:" ) );
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
    standardBoldCheckBox->setText( tr( "Bold" ) );
    standardItalicCheckBox->setText( tr( "Italic" ) );
    standardUnderlineCheckBox->setText( tr( "Underline" ) );
    labelsBoldCheckBox->setText( tr( "Bold" ) );
    labelsItalicCheckBox->setText( tr( "Italic" ) );
    labelsUnderlineCheckBox->setText( tr( "Underline" ) );
    statementsBoldCheckBox->setText( tr( "Bold" ) );
    statementsItalicCheckBox->setText( tr( "Italic" ) );
    statementsUnderlineCheckBox->setText( tr( "Underline" ) );
    commandsBoldCheckBox->setText( tr( "Bold" ) );
    commandsItalicCheckBox->setText( tr( "Italic" ) );
    commandsUnderlineCheckBox->setText( tr( "Underline" ) );
    dimsBoldCheckBox->setText( tr( "Bold" ) );
    dimsItalicCheckBox->setText( tr( "Italic" ) );
    dimsUnderlineCheckBox->setText( tr( "Underline" ) );
    commentsBoldCheckBox->setText( tr( "Bold" ) );
    commentsItalicCheckBox->setText( tr( "Italic" ) );
    commentsUnderlineCheckBox->setText( tr( "Underline" ) );
    digitsBoldCheckBox->setText( tr( "Bold" ) );
    digitsItalicCheckBox->setText( tr( "Italic" ) );
    digitsUnderlineCheckBox->setText( tr( "Underline" ) );
    quotationsBoldCheckBox->setText( tr( "Bold" ) );
    quotationsItalicCheckBox->setText( tr( "Italic" ) );
    quotationsUnderlineCheckBox->setText( tr( "Underline" ) );
    fontBox->setTitle( tr( "Fonts" ) );
    previewFontLabel->setText( tr( "Preview Box:   " ) );
    editFontLabel->setText( tr( "Edit Window:   " ) );
    previewPreviewBox->setTitle( tr( "Preview Box" ) );
    previewPreviewTextEdit->setText( tr( "//nahodny dite2\n"
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
    editPreviewBox->setTitle( tr( "Edit Window" ) );
	editPreviewTextEdit->setText( tr( "//nahodny dite2\n"
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

	editFontComboBox->setCurrentText( editSyntax->standardFont.family() );
	previewFontComboBox->setCurrentText( previewSyntax->standardFont.family() );
}

/*
 *	Color functions
 */

void PreferencesDialog::setStandardColor()
{
	previewSyntax->standardColor = QColorDialog::getColor( previewSyntax->standardColor, this );
	editSyntax->standardColor = previewSyntax->standardColor;
	standardColorLabel->setPaletteBackgroundColor( previewSyntax->standardColor );
	previewSyntax->reinitialise();
	editSyntax->reinitialise();
}

void PreferencesDialog::setLabelsColor()
{
	previewSyntax->labelColor = QColorDialog::getColor( previewSyntax->labelColor, this );
	editSyntax->labelColor = previewSyntax->labelColor;
	labelsColorLabel->setPaletteBackgroundColor( previewSyntax->labelColor );
	previewSyntax->reinitialise();
	editSyntax->reinitialise();
}

void PreferencesDialog::setStatementsColor()
{
	previewSyntax->statementColor = QColorDialog::getColor( previewSyntax->statementColor, this );
	editSyntax->statementColor = previewSyntax->statementColor;
	statementsColorLabel->setPaletteBackgroundColor( previewSyntax->statementColor );
	previewSyntax->reinitialise();
	editSyntax->reinitialise();
}

void PreferencesDialog::setCommandsColor()
{
	previewSyntax->commandColor = QColorDialog::getColor( previewSyntax->commandColor, this );
	editSyntax->commandColor = previewSyntax->commandColor;
	commandsColorLabel->setPaletteBackgroundColor( previewSyntax->commandColor );
	previewSyntax->reinitialise();
	editSyntax->reinitialise();
}

void PreferencesDialog::setDimsColor()
{
	previewSyntax->dimColor = QColorDialog::getColor( previewSyntax->dimColor, this );
	editSyntax->dimColor = previewSyntax->dimColor;
	dimsColorLabel->setPaletteBackgroundColor( previewSyntax->dimColor );
	previewSyntax->reinitialise();
	editSyntax->reinitialise();
}

void PreferencesDialog::setCommentsColor()
{
	previewSyntax->commentColor = QColorDialog::getColor( previewSyntax->commentColor, this );
	editSyntax->commentColor = previewSyntax->commentColor;
	commentsColorLabel->setPaletteBackgroundColor( previewSyntax->commentColor );
	previewSyntax->reinitialise();
	editSyntax->reinitialise();
}

void PreferencesDialog::setDigitsColor()
{
	previewSyntax->digitColor = QColorDialog::getColor( previewSyntax->digitColor, this );
	editSyntax->digitColor = previewSyntax->digitColor;
	digitsColorLabel->setPaletteBackgroundColor( previewSyntax->digitColor );
	previewSyntax->reinitialise();
	editSyntax->reinitialise();
}

void PreferencesDialog::setQuotationsColor()
{
	previewSyntax->quotationColor = QColorDialog::getColor( previewSyntax->quotationColor, this );
	editSyntax->quotationColor = previewSyntax->quotationColor;
	quotationsColorLabel->setPaletteBackgroundColor( previewSyntax->quotationColor );
	previewSyntax->reinitialise();
	editSyntax->reinitialise();
}

void PreferencesDialog::updatePreview()
{
	// Edit
	editSyntax->standardFont.setBold( standardBoldCheckBox->isChecked() );
	editSyntax->standardFont.setItalic( standardItalicCheckBox->isChecked() );
	editSyntax->standardFont.setUnderline( standardUnderlineCheckBox->isChecked() );
	editSyntax->standardFont.setFamily( editFontComboBox->currentText() );
	editSyntax->labelFont.setBold( labelsBoldCheckBox->isChecked() );
	editSyntax->labelFont.setItalic( labelsItalicCheckBox->isChecked() );
	editSyntax->labelFont.setUnderline( labelsUnderlineCheckBox->isChecked() );
	editSyntax->labelFont.setFamily( editFontComboBox->currentText() );
	editSyntax->statementFont.setBold( statementsBoldCheckBox->isChecked() );
	editSyntax->statementFont.setItalic( statementsItalicCheckBox->isChecked() );
	editSyntax->statementFont.setUnderline( statementsUnderlineCheckBox->isChecked() );
	editSyntax->statementFont.setFamily( editFontComboBox->currentText() );
	editSyntax->commandFont.setBold( commandsBoldCheckBox->isChecked() );
	editSyntax->commandFont.setItalic( commandsItalicCheckBox->isChecked() );
	editSyntax->commandFont.setUnderline( commandsUnderlineCheckBox->isChecked() );
	editSyntax->commandFont.setFamily( editFontComboBox->currentText() );
	editSyntax->dimFont.setBold( dimsBoldCheckBox->isChecked() );
	editSyntax->dimFont.setItalic( dimsItalicCheckBox->isChecked() );
	editSyntax->dimFont.setUnderline( dimsUnderlineCheckBox->isChecked() );
	editSyntax->dimFont.setFamily( editFontComboBox->currentText() );
	editSyntax->commentFont.setBold( commentsBoldCheckBox->isChecked() );
	editSyntax->commentFont.setItalic( commentsItalicCheckBox->isChecked() );
	editSyntax->commentFont.setUnderline( commentsUnderlineCheckBox->isChecked() );
	editSyntax->commentFont.setFamily( editFontComboBox->currentText() );
	editSyntax->digitFont.setBold( digitsBoldCheckBox->isChecked() );
	editSyntax->digitFont.setItalic( digitsItalicCheckBox->isChecked() );
	editSyntax->digitFont.setUnderline( digitsUnderlineCheckBox->isChecked() );
	editSyntax->digitFont.setFamily( editFontComboBox->currentText() );
	editSyntax->quotationFont.setBold( quotationsBoldCheckBox->isChecked() );
	editSyntax->quotationFont.setItalic( quotationsItalicCheckBox->isChecked() );
	editSyntax->quotationFont.setUnderline( quotationsUnderlineCheckBox->isChecked() );
	editSyntax->quotationFont.setFamily( editFontComboBox->currentText() );

	// Preview
	previewSyntax->standardFont.setBold( standardBoldCheckBox->isChecked() );
	previewSyntax->standardFont.setItalic( standardItalicCheckBox->isChecked() );
	previewSyntax->standardFont.setUnderline( standardUnderlineCheckBox->isChecked() );
	previewSyntax->standardFont.setFamily( previewFontComboBox->currentText() );
	previewSyntax->labelFont.setBold( labelsBoldCheckBox->isChecked() );
	previewSyntax->labelFont.setItalic( labelsItalicCheckBox->isChecked() );
	previewSyntax->labelFont.setUnderline( labelsUnderlineCheckBox->isChecked() );
	previewSyntax->labelFont.setFamily( previewFontComboBox->currentText() );
	previewSyntax->statementFont.setBold( statementsBoldCheckBox->isChecked() );
	previewSyntax->statementFont.setItalic( statementsItalicCheckBox->isChecked() );
	previewSyntax->statementFont.setUnderline( statementsUnderlineCheckBox->isChecked() );
	previewSyntax->statementFont.setFamily( previewFontComboBox->currentText() );
	previewSyntax->commandFont.setBold( commandsBoldCheckBox->isChecked() );
	previewSyntax->commandFont.setItalic( commandsItalicCheckBox->isChecked() );
	previewSyntax->commandFont.setUnderline( commandsUnderlineCheckBox->isChecked() );
	previewSyntax->commandFont.setFamily( previewFontComboBox->currentText() );
	previewSyntax->dimFont.setBold( dimsBoldCheckBox->isChecked() );
	previewSyntax->dimFont.setItalic( dimsItalicCheckBox->isChecked() );
	previewSyntax->dimFont.setUnderline( dimsUnderlineCheckBox->isChecked() );
	previewSyntax->dimFont.setFamily( previewFontComboBox->currentText() );
	previewSyntax->commentFont.setBold( commentsBoldCheckBox->isChecked() );
	previewSyntax->commentFont.setItalic( commentsItalicCheckBox->isChecked() );
	previewSyntax->commentFont.setUnderline( commentsUnderlineCheckBox->isChecked() );
	previewSyntax->commentFont.setFamily( previewFontComboBox->currentText() );
	previewSyntax->digitFont.setBold( digitsBoldCheckBox->isChecked() );
	previewSyntax->digitFont.setItalic( digitsItalicCheckBox->isChecked() );
	previewSyntax->digitFont.setUnderline( digitsUnderlineCheckBox->isChecked() );
	previewSyntax->digitFont.setFamily( previewFontComboBox->currentText() );
	previewSyntax->quotationFont.setBold( quotationsBoldCheckBox->isChecked() );
	previewSyntax->quotationFont.setItalic( quotationsItalicCheckBox );
	previewSyntax->quotationFont.setUnderline( quotationsUnderlineCheckBox->isChecked() );
	previewSyntax->quotationFont.setFamily( previewFontComboBox->currentText() );

	// reinitialise
	previewSyntax->reinitialise();
	editSyntax->reinitialise();
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
	editFontComboBox->setCurrentText( editSyntax->fontFamily );
	previewFontComboBox->setCurrentText( previewSyntax->fontFamily );
}

void PreferencesDialog::save()
{
	// Edit
	settings->writeEntry( "syntax/edit/colors/standard", editSyntax->standardColor.name() );
	settings->writeEntry( "syntax/edit/colors/label", editSyntax->labelColor.name() );
	settings->writeEntry( "syntax/edit/colors/statement", editSyntax->statementColor.name() );
	settings->writeEntry( "syntax/edit/colors/command", editSyntax->commandColor.name() );
	settings->writeEntry( "syntax/edit/colors/dim", editSyntax->dimColor.name() );
	settings->writeEntry( "syntax/edit/colors/digit", editSyntax->digitColor.name() );
	settings->writeEntry( "syntax/edit/colors/quotation", editSyntax->quotationColor.name() );
	settings->writeEntry( "syntax/edit/colors/comment", editSyntax->commentColor.name() );
	
	settings->writeEntry( "syntax/edit/fonts/standard", editSyntax->standardFont.toString() );
	settings->writeEntry( "syntax/edit/fonts/label", editSyntax->labelFont.toString() );
	settings->writeEntry( "syntax/edit/fonts/statement", editSyntax->statementFont.toString() );
	settings->writeEntry( "syntax/edit/fonts/command", editSyntax->commandFont.toString() );
	settings->writeEntry( "syntax/edit/fonts/dim", editSyntax->dimFont.toString() );
	settings->writeEntry( "syntax/edit/fonts/digit", editSyntax->digitFont.toString() );
	settings->writeEntry( "syntax/edit/fonts/quotation", editSyntax->quotationFont.toString() );
	settings->writeEntry( "syntax/edit/fonts/comment", editSyntax->commentFont.toString() );


	// Preview
	settings->writeEntry( "syntax/preview/colors/standard", previewSyntax->standardColor.name() );
	settings->writeEntry( "syntax/preview/colors/label", previewSyntax->labelColor.name() );
	settings->writeEntry( "syntax/preview/colors/statement", previewSyntax->statementColor.name() );
	settings->writeEntry( "syntax/preview/colors/command", previewSyntax->commandColor.name() );
	settings->writeEntry( "syntax/preview/colors/dim", previewSyntax->dimColor.name() );
	settings->writeEntry( "syntax/preview/colors/digit", previewSyntax->digitColor.name() );
	settings->writeEntry( "syntax/preview/colors/quotation", previewSyntax->quotationColor.name() );
	settings->writeEntry( "syntax/preview/colors/comment", previewSyntax->commentColor.name() );
	
	settings->writeEntry( "syntax/preview/fonts/standard", previewSyntax->standardFont.toString() );
	settings->writeEntry( "syntax/preview/fonts/label", previewSyntax->labelFont.toString() );
	settings->writeEntry( "syntax/preview/fonts/statement", previewSyntax->statementFont.toString() );
	settings->writeEntry( "syntax/preview/fonts/command", previewSyntax->commandFont.toString() );
	settings->writeEntry( "syntax/preview/fonts/dim", previewSyntax->dimFont.toString() );
	settings->writeEntry( "syntax/preview/fonts/digit", previewSyntax->digitFont.toString() );
	settings->writeEntry( "syntax/preview/fonts/quotation", previewSyntax->quotationFont.toString() );
	settings->writeEntry( "syntax/preview/fonts/comment", previewSyntax->commentFont.toString() );

	emit settingsSaved();
	accept();
}
