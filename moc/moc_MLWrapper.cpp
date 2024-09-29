/****************************************************************************
** CMLWrapper meta object code from reading C++ file 'MLWrapper.h'
**
** Created: Mi 28. Jul 19:10:07 2004
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../include/MLWrapper.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CMLWrapper::className() const
{
    return "CMLWrapper";
}

QMetaObject *CMLWrapper::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CMLWrapper( "CMLWrapper", &CMLWrapper::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CMLWrapper::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CMLWrapper", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CMLWrapper::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CMLWrapper", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CMLWrapper::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out },
	{ "szObjectName", &static_QUType_QString, 0, QUParameter::In },
	{ "Buffer", &static_QUType_QString, 0, QUParameter::In },
	{ "init", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"SaveObjectScript", 4, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out },
	{ "Scene2ObjectInfo_t", &static_QUType_ptr, "ObjectInfo_t", QUParameter::In },
	{ "oldName", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"SaveObject", 3, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out },
	{ "Scene2ObjectInfo_t", &static_QUType_ptr, "ObjectInfo_t", QUParameter::In },
	{ "oldName", &static_QUType_QString, 0, QUParameter::In },
	{ "b", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"SaveObject", 4, param_slot_2 };
    static const QMetaData slot_tbl[] = {
	{ "SaveObjectScript(QString,QString,bool)", &slot_0, QMetaData::Public },
	{ "SaveObject(ObjectInfo_t*,QString)", &slot_1, QMetaData::Public },
	{ "SaveObject(ObjectInfo_t*,QString,bool)", &slot_2, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "short", QUParameter::In }
    };
    static const QUMethod signal_0 = {"addObjectToList", 3, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "short", QUParameter::In }
    };
    static const QUMethod signal_1 = {"objectCreated", 3, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "addObjectToList(char*,int,short)", &signal_0, QMetaData::Public },
	{ "objectCreated(char*,int,short)", &signal_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"CMLWrapper", parentObject,
	slot_tbl, 3,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CMLWrapper.setMetaObject( metaObj );
    return metaObj;
}

void* CMLWrapper::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CMLWrapper" ) )
	return this;
    return QObject::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL addObjectToList
void CMLWrapper::addObjectToList( char* t0, int t1, short t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_charstar.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    static_QUType_ptr.set(o+3,&t2);
    activate_signal( clist, o );
}

// SIGNAL objectCreated
void CMLWrapper::objectCreated( char* t0, int t1, short t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_charstar.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    static_QUType_ptr.set(o+3,&t2);
    activate_signal( clist, o );
}

bool CMLWrapper::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: static_QUType_int.set(_o,SaveObjectScript((QString)static_QUType_QString.get(_o+1),(QString)static_QUType_QString.get(_o+2),(bool)static_QUType_bool.get(_o+3))); break;
    case 1: static_QUType_int.set(_o,SaveObject((ObjectInfo_t*)static_QUType_ptr.get(_o+1),(QString)static_QUType_QString.get(_o+2))); break;
    case 2: static_QUType_int.set(_o,SaveObject((ObjectInfo_t*)static_QUType_ptr.get(_o+1),(QString)static_QUType_QString.get(_o+2),(bool)static_QUType_bool.get(_o+3))); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CMLWrapper::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: addObjectToList((char*)static_QUType_charstar.get(_o+1),(int)static_QUType_int.get(_o+2),(short)(*((short*)static_QUType_ptr.get(_o+3)))); break;
    case 1: objectCreated((char*)static_QUType_charstar.get(_o+1),(int)static_QUType_int.get(_o+2),(short)(*((short*)static_QUType_ptr.get(_o+3)))); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool CMLWrapper::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool CMLWrapper::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
