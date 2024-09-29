#include "globaldefs.h"
#include <qmessagebox.h>

#ifndef NO_STATIC_COLORS

static void init_colors()
{
    if ( backColor1 )
	return;

#if 0 // a calculated alternative for backColor1
    QColorGroup myCg = qApp->palette().active();
    int h1, s1, v1;
    int h2, s2, v2;
    myCg.color( QColorGroup::Base ).hsv( &h1, &s1, &v1 );
    myCg.color( QColorGroup::Background ).hsv( &h2, &s2, &v2 );
    QColor c( h1, s1, ( v1 + v2 ) / 2, QColor::Hsv );
#endif // 0

    backColor1 = new QColor(  250, 248, 235 );
    backColor2 = new QColor( 255, 255, 255 );
    selectedBack = new QColor( 230, 230, 230 );
}

#endif //NO_STATIC_COLORS

CMLWrapper *sceneWrapper = new CMLWrapper();
QSettings *settings = new QSettings( QSettings::Native );
MainWidget * main_widget;
QStatusBar * status_bar;

extern void init_settings()
{
	settings->setPath( "DON|City", "DCED2", QSettings::User );
};

extern void dcDebug( QString title, QString message )
{
	QMessageBox::information( 0, title, message );
}

extern short eType2sType( Type type )
{
	short nDatablockType = 0;
	if( type == Object )
		nDatablockType = NORMAL_MAIN;
	else if( type == ObjDef )
		nDatablockType = SPECIAL_MAIN;
	else if( type == Init )
		nDatablockType = ADDITIONAL_MAIN;
	return nDatablockType;
}

extern Type sType2eType( short nDatablockType )
{
	Type type;
	if( nDatablockType == NORMAL_MAIN )
		type = Object;
	else if( nDatablockType == SPECIAL_MAIN )
		type = ObjDef;
	else if( nDatablockType == ADDITIONAL_MAIN )
		type = Init;
	return type;
}
