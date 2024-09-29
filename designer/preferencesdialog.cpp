/****************************************************************************
** Form implementation generated from reading ui file 'preferencesdialog.ui'
**
** Created: Sa 20. Mrz 19:14:39 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.2.1   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "preferencesdialog.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qcheckbox.h>
#include <qcombobox.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

static const char* const image0_data[] = { 
"16 16 87 2",
"Qt c None",
"#p c #222222",
".U c #272727",
".b c #282828",
"#h c #29292d",
".9 c #2e2e2e",
".2 c #2f2f2f",
"#c c #303030",
".d c #313131",
".c c #323232",
".# c #333333",
".I c #343434",
"#o c #363636",
".J c #424242",
"#u c #454545",
"#i c #484848",
"#j c #48484f",
"#g c #4f4f5c",
"#t c #545454",
"#l c #5b5b5b",
".a c #616161",
"#s c #646464",
".g c #656565",
".e c #676767",
"#b c #67677c",
".x c #6c6c6c",
".m c #727272",
"#r c #797979",
".f c #7a7a7a",
"## c #7c7c97",
".H c #7e7e94",
".8 c #7e7e97",
".6 c #808097",
".4 c #828297",
".1 c #838396",
"#f c #858598",
".T c #868697",
".l c #878787",
"#n c #888888",
".i c #8c8c8c",
".j c #8d8d8d",
".w c #8f8f8f",
"#q c #939393",
".E c #9a9ac0",
".D c #9b9bb5",
".y c #9c9c9c",
".C c #9c9ca9",
".z c #9e9e9e",
"#k c #9f9f9f",
"#m c #a0a0a0",
".F c #a4a4c5",
".A c #a5a5a5",
".B c #acacb9",
".G c #acacd9",
".K c #b2b2d9",
".k c #b7b7b7",
"#a c #b9b9e6",
"#e c #babad3",
".h c #bbbbbb",
"#d c #bcbcd9",
".L c #bdbddf",
".v c #c4c4c4",
".M c #c8c8e6",
"#. c #d0d0ff",
".n c #d2d2d2",
".N c #d2d2ec",
".7 c #d4d4ff",
".5 c #d7d7ff",
".u c #d9d9d9",
".O c #dbdbf2",
".3 c #dbdbff",
".t c #dddddd",
".0 c #dedeff",
".s c #dfdfdf",
".S c #e2e2ff",
".R c #e6e6ff",
".P c #e7e7fc",
".o c #e9e9e9",
".Q c #eaeaff",
".p c #ebebeb",
".r c #ececec",
".q c #ededed",
".Z c #ededff",
".Y c #f1f1ff",
".X c #f5f5ff",
".W c #f8f8ff",
".V c #fbfbff",
"QtQtQtQtQtQt.#.a.bQtQtQtQtQtQtQt",
"Qt.#.c.d.e.f.g.h.i.j.i.k.h.lQtQt",
"Qt.m.n.o.p.q.r.r.r.s.t.u.v.wQtQt",
"Qt.x.y.z.A.B.C.D.D.E.F.G.HQtQtQt",
"Qt.I.J.K.L.M.N.O.P.Q.R.S.TQtQtQt",
"QtQt.U.V.W.X.Y.Z.Q.R.S.0.1QtQtQt",
"QtQt.2.W.X.Y.Z.Q.R.S.0.3.4QtQtQt",
"QtQt.d.X.Y.Z.Q.R.S.0.3.5.6QtQtQt",
"QtQt.d.Y.Z.Q.R.S.0.3.5.7.8QtQtQt",
"QtQt.9.Z.Q.R.S.0.3.5.7#.##QtQtQt",
"QtQt.2.Q.R.S.0.3.5.7#.#a#bQtQtQt",
"QtQt#c.R.S.0#d#e#f#g#hQtQtQtQtQt",
"QtQt.9#i#j#i#i#k#lQtQtQtQtQtQtQt",
"QtQtQtQtQtQt#m.z.j#n#oQtQtQtQtQt",
"QtQtQtQt#p#q#rQtQt#s#tQtQtQtQtQt",
"QtQtQtQt.c#uQtQtQtQtQtQtQtQtQtQt"};


/*
 *  Constructs a PreferencesDialog as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
PreferencesDialog::PreferencesDialog( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl ),
      image0( (const char **) image0_data )
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

    cancelButton = new QPushButton( this, "cancelButton" );
    layout1->addWidget( cancelButton );

    okButton = new QPushButton( this, "okButton" );
    okButton->setDefault( TRUE );
    layout1->addWidget( okButton );

    PreferencesDialogLayout->addMultiCellLayout( layout1, 3, 3, 0, 1 );

    syntaxBox = new QGroupBox( this, "syntaxBox" );
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

    integersLabel = new QLabel( syntaxBox, "integersLabel" );
    integersLabel->setBackgroundOrigin( QLabel::ParentOrigin );

    syntaxBoxLayout->addWidget( integersLabel, 6, 0 );

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

    integersColorButton = new QPushButton( syntaxBox, "integersColorButton" );
    integersColorButton->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, integersColorButton->sizePolicy().hasHeightForWidth() ) );
    integersColorButton->setMaximumSize( QSize( 20, 20 ) );

    syntaxBoxLayout->addWidget( integersColorButton, 6, 2 );

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

    integersColorLabel = new QLabel( syntaxBox, "integersColorLabel" );
    integersColorLabel->setMinimumSize( QSize( 30, 20 ) );
    integersColorLabel->setMaximumSize( QSize( 30, 20 ) );
    integersColorLabel->setPaletteBackgroundColor( QColor( 0, 0, 0 ) );
    integersColorLabel->setFrameShape( QLabel::LineEditPanel );

    syntaxBoxLayout->addWidget( integersColorLabel, 6, 1 );
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

    editPreviewBoxLayout->addWidget( editPreviewTextEdit, 0, 0 );

    PreferencesDialogLayout->addWidget( editPreviewBox, 2, 1 );
    languageChange();
    resize( QSize(500, 550).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( okButton, SIGNAL( clicked() ), this, SLOT( accept() ) );
    connect( cancelButton, SIGNAL( clicked() ), this, SLOT( reject() ) );
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
    syntaxBox->setTitle( tr( "Colours" ) );
    dimsLabel->setText( tr( "Dims" ) );
    QToolTip::add( dimsLabel, tr( "\"dim_act\", \"dim_flt\", \"dim_frm\"" ) );
    dimsColorButton->setText( tr( "..." ) );
    integersLabel->setText( tr( "Digits" ) );
    quotationsColorButton->setText( tr( "..." ) );
    quotationsLabel->setText( tr( "Quotations" ) );
    QToolTip::add( quotationsLabel, tr( "\"This is a text between two quotations\"" ) );
    standardColorLabel->setText( QString::null );
    commentsColorButton->setText( tr( "..." ) );
    quotationsColorLabel->setText( QString::null );
    statementsColorButton->setText( tr( "..." ) );
    integersColorButton->setText( tr( "..." ) );
    statementsLabel->setText( tr( "Statements" ) );
    QToolTip::add( statementsLabel, tr( "Statements, like \"if\", \"goto\", \"wait\", \"end\" etc." ) );
    commentsLabel->setText( tr( "Comments" ) );
    QToolTip::add( commentsLabel, tr( "//This is a comment" ) );
    commandsLabel->setText( tr( "Commands" ) );
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
    integersColorLabel->setText( QString::null );
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
}

