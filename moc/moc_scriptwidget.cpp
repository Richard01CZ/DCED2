/****************************************************************************
** ScriptWidget meta object code from reading C++ file 'scriptwidget.h'
**
** Created: Sa 10. Jul 19:40:08 2004
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../include/scriptwidget.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *ScriptWidget::className() const
{
    return "ScriptWidget";
}

QMetaObject *ScriptWidget::metaObj = 0;
static QMetaObjectCleanUp cleanUp_ScriptWidget( "ScriptWidget", &ScriptWidget::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString ScriptWidget::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ScriptWidget", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString ScriptWidget::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ScriptWidget", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* ScriptWidget::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"save", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ "nName", &static_QUType_charstar, 0, QUParameter::In },
	{ "nType", &static_QUType_int, 0, QUParameter::In },
	{ "nScript", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"setInputFields", 3, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "nName", &static_QUType_charstar, 0, QUParameter::In },
	{ "nType", &static_QUType_int, 0, QUParameter::In },
	{ "nScript", &static_QUType_QString, 0, QUParameter::In },
	{ "nObjectInfo", &static_QUType_ptr, "ObjectInfo_t", QUParameter::In }
    };
    static const QUMethod slot_2 = {"setInputFields", 4, param_slot_2 };
    static const QUMethod slot_3 = {"setLineNumbers", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ "i", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"setLineNumbers", 1, param_slot_4 };
    static const QUMethod slot_5 = {"updateProperties", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "save()", &slot_0, QMetaData::Public },
	{ "setInputFields(const char*,int,QString)", &slot_1, QMetaData::Public },
	{ "setInputFields(const char*,int,QString,ObjectInfo_t*)", &slot_2, QMetaData::Public },
	{ "setLineNumbers()", &slot_3, QMetaData::Protected },
	{ "setLineNumbers(int)", &slot_4, QMetaData::Protected },
	{ "updateProperties()", &slot_5, QMetaData::Protected }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "ScriptWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"closeSignal", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "closeSignal(ScriptWidget*)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"ScriptWidget", parentObject,
	slot_tbl, 6,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_ScriptWidget.setMetaObject( metaObj );
    return metaObj;
}

void* ScriptWidget::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "ScriptWidget" ) )
	return this;
    return QWidget::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL closeSignal
void ScriptWidget::closeSignal( ScriptWidget* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

bool ScriptWidget::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: save(); break;
    case 1: setInputFields((const char*)static_QUType_charstar.get(_o+1),(int)static_QUType_int.get(_o+2),(QString)static_QUType_QString.get(_o+3)); break;
    case 2: setInputFields((const char*)static_QUType_charstar.get(_o+1),(int)static_QUType_int.get(_o+2),(QString)static_QUType_QString.get(_o+3),(ObjectInfo_t*)static_QUType_ptr.get(_o+4)); break;
    case 3: setLineNumbers(); break;
    case 4: setLineNumbers((int)static_QUType_int.get(_o+1)); break;
    case 5: updateProperties(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool ScriptWidget::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: closeSignal((ScriptWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool ScriptWidget::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool ScriptWidget::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
