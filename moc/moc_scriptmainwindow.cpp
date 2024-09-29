/****************************************************************************
** ScriptMainWindow meta object code from reading C++ file 'scriptmainwindow.h'
**
** Created: Sa 10. Jul 19:40:08 2004
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../include/scriptmainwindow.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *ScriptMainWindow::className() const
{
    return "ScriptMainWindow";
}

QMetaObject *ScriptMainWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_ScriptMainWindow( "ScriptMainWindow", &ScriptMainWindow::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString ScriptMainWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ScriptMainWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString ScriptMainWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ScriptMainWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* ScriptMainWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMainWindow::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"ScriptMainWindow", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_ScriptMainWindow.setMetaObject( metaObj );
    return metaObj;
}

void* ScriptMainWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "ScriptMainWindow" ) )
	return this;
    return QMainWindow::qt_cast( clname );
}

bool ScriptMainWindow::qt_invoke( int _id, QUObject* _o )
{
    return QMainWindow::qt_invoke(_id,_o);
}

bool ScriptMainWindow::qt_emit( int _id, QUObject* _o )
{
    return QMainWindow::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool ScriptMainWindow::qt_property( int id, int f, QVariant* v)
{
    return QMainWindow::qt_property( id, f, v);
}

bool ScriptMainWindow::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
