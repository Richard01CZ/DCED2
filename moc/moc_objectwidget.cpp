/****************************************************************************
** ObjectWidget meta object code from reading C++ file 'objectwidget.h'
**
** Created: Mo 26. Jul 19:57:05 2004
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../include/objectwidget.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *ObjectWidget::className() const
{
    return "ObjectWidget";
}

QMetaObject *ObjectWidget::metaObj = 0;
static QMetaObjectCleanUp cleanUp_ObjectWidget( "ObjectWidget", &ObjectWidget::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString ObjectWidget::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ObjectWidget", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString ObjectWidget::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ObjectWidget", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* ObjectWidget::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"saveObject", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "ObjectInfo_t", QUParameter::In }
    };
    static const QUMethod slot_1 = {"setInputFields", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_ptr, "ObjectInfo_t", QUParameter::In },
	{ "item", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_2 = {"setInputFields", 2, param_slot_2 };
    static const QUMethod slot_3 = {"languageChange", 0, 0 };
    static const QUMethod slot_4 = {"objectEdited", 0, 0 };
    static const QUMethod slot_5 = {"insertLightSector", 0, 0 };
    static const QUMethod slot_6 = {"removeLightSector", 0, 0 };
    static const QUParameter param_slot_7[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"changeLightSector", 1, param_slot_7 };
    static const QMetaData slot_tbl[] = {
	{ "saveObject()", &slot_0, QMetaData::Public },
	{ "setInputFields(ObjectInfo_t*)", &slot_1, QMetaData::Public },
	{ "setInputFields(ObjectInfo_t*,QListViewItem*)", &slot_2, QMetaData::Public },
	{ "languageChange()", &slot_3, QMetaData::Protected },
	{ "objectEdited()", &slot_4, QMetaData::Protected },
	{ "insertLightSector()", &slot_5, QMetaData::Protected },
	{ "removeLightSector()", &slot_6, QMetaData::Protected },
	{ "changeLightSector(const QString&)", &slot_7, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"ObjectWidget", parentObject,
	slot_tbl, 8,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_ObjectWidget.setMetaObject( metaObj );
    return metaObj;
}

void* ObjectWidget::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "ObjectWidget" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool ObjectWidget::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: saveObject(); break;
    case 1: setInputFields((ObjectInfo_t*)static_QUType_ptr.get(_o+1)); break;
    case 2: setInputFields((ObjectInfo_t*)static_QUType_ptr.get(_o+1),(QListViewItem*)static_QUType_ptr.get(_o+2)); break;
    case 3: languageChange(); break;
    case 4: objectEdited(); break;
    case 5: insertLightSector(); break;
    case 6: removeLightSector(); break;
    case 7: changeLightSector((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool ObjectWidget::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool ObjectWidget::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool ObjectWidget::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
