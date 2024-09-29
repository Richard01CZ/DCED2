/****************************************************************************
** ScriptWorkspace meta object code from reading C++ file 'scriptworkspace.h'
**
** Created: Sa 10. Jul 19:40:08 2004
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../include/scriptworkspace.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *ScriptWorkspace::className() const
{
    return "ScriptWorkspace";
}

QMetaObject *ScriptWorkspace::metaObj = 0;
static QMetaObjectCleanUp cleanUp_ScriptWorkspace( "ScriptWorkspace", &ScriptWorkspace::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString ScriptWorkspace::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ScriptWorkspace", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString ScriptWorkspace::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ScriptWorkspace", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* ScriptWorkspace::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWorkspace::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "name", &static_QUType_QString, 0, QUParameter::In },
	{ "type", &static_QUType_int, 0, QUParameter::In },
	{ "script", &static_QUType_QString, 0, QUParameter::In },
	{ "init", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"addScriptWidget", 4, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "name", &static_QUType_QString, 0, QUParameter::In },
	{ "type", &static_QUType_int, 0, QUParameter::In },
	{ "script", &static_QUType_QString, 0, QUParameter::In },
	{ "init", &static_QUType_bool, 0, QUParameter::In },
	{ "objectInfo", &static_QUType_ptr, "ObjectInfo_t", QUParameter::In }
    };
    static const QUMethod slot_1 = {"addScriptWidget", 5, param_slot_1 };
    static const QUMethod slot_2 = {"applySettings", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_ptr, "ScriptWidget", QUParameter::In }
    };
    static const QUMethod slot_3 = {"deleteScriptWidget", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"focusScriptWidget", 1, param_slot_4 };
    static const QUMethod slot_5 = {"saveAllWindows", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "addScriptWidget(QString,int,QString,bool)", &slot_0, QMetaData::Public },
	{ "addScriptWidget(QString,int,QString,bool,ObjectInfo_t*)", &slot_1, QMetaData::Public },
	{ "applySettings()", &slot_2, QMetaData::Public },
	{ "deleteScriptWidget(ScriptWidget*)", &slot_3, QMetaData::Public },
	{ "focusScriptWidget(QString)", &slot_4, QMetaData::Public },
	{ "saveAllWindows()", &slot_5, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"ScriptWorkspace", parentObject,
	slot_tbl, 6,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_ScriptWorkspace.setMetaObject( metaObj );
    return metaObj;
}

void* ScriptWorkspace::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "ScriptWorkspace" ) )
	return this;
    return QWorkspace::qt_cast( clname );
}

bool ScriptWorkspace::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: addScriptWidget((QString)static_QUType_QString.get(_o+1),(int)static_QUType_int.get(_o+2),(QString)static_QUType_QString.get(_o+3),(bool)static_QUType_bool.get(_o+4)); break;
    case 1: addScriptWidget((QString)static_QUType_QString.get(_o+1),(int)static_QUType_int.get(_o+2),(QString)static_QUType_QString.get(_o+3),(bool)static_QUType_bool.get(_o+4),(ObjectInfo_t*)static_QUType_ptr.get(_o+5)); break;
    case 2: applySettings(); break;
    case 3: deleteScriptWidget((ScriptWidget*)static_QUType_ptr.get(_o+1)); break;
    case 4: focusScriptWidget((QString)static_QUType_QString.get(_o+1)); break;
    case 5: saveAllWindows(); break;
    default:
	return QWorkspace::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool ScriptWorkspace::qt_emit( int _id, QUObject* _o )
{
    return QWorkspace::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool ScriptWorkspace::qt_property( int id, int f, QVariant* v)
{
    return QWorkspace::qt_property( id, f, v);
}

bool ScriptWorkspace::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
