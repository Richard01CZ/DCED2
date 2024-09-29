/****************************************************************************
** PropertyNameList meta object code from reading C++ file 'propertynamelist.h'
**
** Created: Sa 10. Jul 19:40:09 2004
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../include/propertynamelist.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *PropertyNameList::className() const
{
    return "PropertyNameList";
}

QMetaObject *PropertyNameList::metaObj = 0;
static QMetaObjectCleanUp cleanUp_PropertyNameList( "PropertyNameList", &PropertyNameList::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString PropertyNameList::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PropertyNameList", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString PropertyNameList::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PropertyNameList", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* PropertyNameList::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "v", &static_QUType_QVariant, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"renameItem", 1, param_slot_0 };
    static const QUMethod slot_1 = {"addItem", 0, 0 };
    static const QUMethod slot_2 = {"deleteItem", 0, 0 };
    static const QUMethod slot_3 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "renameItem(const QVariant&)", &slot_0, QMetaData::Public },
	{ "addItem()", &slot_1, QMetaData::Protected },
	{ "deleteItem()", &slot_2, QMetaData::Protected },
	{ "languageChange()", &slot_3, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"PropertyNameList", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_PropertyNameList.setMetaObject( metaObj );
    return metaObj;
}

void* PropertyNameList::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "PropertyNameList" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool PropertyNameList::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: renameItem((const QVariant&)static_QUType_QVariant.get(_o+1)); break;
    case 1: addItem(); break;
    case 2: deleteItem(); break;
    case 3: languageChange(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool PropertyNameList::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool PropertyNameList::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool PropertyNameList::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *TrafficNameList::className() const
{
    return "TrafficNameList";
}

QMetaObject *TrafficNameList::metaObj = 0;
static QMetaObjectCleanUp cleanUp_TrafficNameList( "TrafficNameList", &TrafficNameList::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString TrafficNameList::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TrafficNameList", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString TrafficNameList::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TrafficNameList", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* TrafficNameList::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = PropertyNameList::staticMetaObject();
    static const QUMethod slot_0 = {"addItem", 0, 0 };
    static const QUMethod slot_1 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "addItem()", &slot_0, QMetaData::Protected },
	{ "languageChange()", &slot_1, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"TrafficNameList", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_TrafficNameList.setMetaObject( metaObj );
    return metaObj;
}

void* TrafficNameList::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "TrafficNameList" ) )
	return this;
    return PropertyNameList::qt_cast( clname );
}

bool TrafficNameList::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: addItem(); break;
    case 1: languageChange(); break;
    default:
	return PropertyNameList::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool TrafficNameList::qt_emit( int _id, QUObject* _o )
{
    return PropertyNameList::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool TrafficNameList::qt_property( int id, int f, QVariant* v)
{
    return PropertyNameList::qt_property( id, f, v);
}

bool TrafficNameList::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *PedestrianModelList::className() const
{
    return "PedestrianModelList";
}

QMetaObject *PedestrianModelList::metaObj = 0;
static QMetaObjectCleanUp cleanUp_PedestrianModelList( "PedestrianModelList", &PedestrianModelList::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString PedestrianModelList::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PedestrianModelList", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString PedestrianModelList::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PedestrianModelList", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* PedestrianModelList::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = PropertyNameList::staticMetaObject();
    static const QUMethod slot_0 = {"addItem", 0, 0 };
    static const QUMethod slot_1 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "addItem()", &slot_0, QMetaData::Protected },
	{ "languageChange()", &slot_1, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"PedestrianModelList", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_PedestrianModelList.setMetaObject( metaObj );
    return metaObj;
}

void* PedestrianModelList::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "PedestrianModelList" ) )
	return this;
    return PropertyNameList::qt_cast( clname );
}

bool PedestrianModelList::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: addItem(); break;
    case 1: languageChange(); break;
    default:
	return PropertyNameList::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool PedestrianModelList::qt_emit( int _id, QUObject* _o )
{
    return PropertyNameList::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool PedestrianModelList::qt_property( int id, int f, QVariant* v)
{
    return PropertyNameList::qt_property( id, f, v);
}

bool PedestrianModelList::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
