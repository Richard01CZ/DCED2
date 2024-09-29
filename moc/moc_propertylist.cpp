/****************************************************************************
** PropertyTextItem meta object code from reading C++ file 'propertylist.h'
**
** Created: Sa 10. Jul 19:40:09 2004
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../include/propertylist.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *PropertyTextItem::className() const
{
    return "PropertyTextItem";
}

QMetaObject *PropertyTextItem::metaObj = 0;
static QMetaObjectCleanUp cleanUp_PropertyTextItem( "PropertyTextItem", &PropertyTextItem::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString PropertyTextItem::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PropertyTextItem", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString PropertyTextItem::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PropertyTextItem", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* PropertyTextItem::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"resetProperty", 0, 0 };
    static const QUMethod slot_1 = {"setValue", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "resetProperty()", &slot_0, QMetaData::Public },
	{ "setValue()", &slot_1, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out },
	{ 0, &static_QUType_QVariant, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"valueChanged", 2, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out },
	{ 0, &static_QUType_QVariant, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"valueReset", 2, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "valueChanged(const QVariant&)", &signal_0, QMetaData::Public },
	{ "valueReset(const QVariant&)", &signal_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"PropertyTextItem", parentObject,
	slot_tbl, 2,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_PropertyTextItem.setMetaObject( metaObj );
    return metaObj;
}

void* PropertyTextItem::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "PropertyTextItem" ) )
	return this;
    if ( !qstrcmp( clname, "PropertyItem" ) )
	return (PropertyItem*)this;
    return QObject::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL valueChanged
int PropertyTextItem::valueChanged( const QVariant& t0 )
{
    int something;
    if ( signalsBlocked() )
	return something;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return something;
    QUObject o[2];
    static_QUType_int.set(o,something);
    static_QUType_QVariant.set(o+1,t0);
    activate_signal( clist, o );
    return static_QUType_int.get(o);
}

// SIGNAL valueReset
int PropertyTextItem::valueReset( const QVariant& t0 )
{
    int something;
    if ( signalsBlocked() )
	return something;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return something;
    QUObject o[2];
    static_QUType_int.set(o,something);
    static_QUType_QVariant.set(o+1,t0);
    activate_signal( clist, o );
    return static_QUType_int.get(o);
}

bool PropertyTextItem::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: resetProperty(); break;
    case 1: setValue(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool PropertyTextItem::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: static_QUType_int.set(_o,valueChanged((const QVariant&)static_QUType_QVariant.get(_o+1))); break;
    case 1: static_QUType_int.set(_o,valueReset((const QVariant&)static_QUType_QVariant.get(_o+1))); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool PropertyTextItem::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool PropertyTextItem::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *PropertyDoubleItem::className() const
{
    return "PropertyDoubleItem";
}

QMetaObject *PropertyDoubleItem::metaObj = 0;
static QMetaObjectCleanUp cleanUp_PropertyDoubleItem( "PropertyDoubleItem", &PropertyDoubleItem::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString PropertyDoubleItem::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PropertyDoubleItem", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString PropertyDoubleItem::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PropertyDoubleItem", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* PropertyDoubleItem::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"resetProperty", 0, 0 };
    static const QUMethod slot_1 = {"setValue", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "resetProperty()", &slot_0, QMetaData::Public },
	{ "setValue()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"PropertyDoubleItem", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_PropertyDoubleItem.setMetaObject( metaObj );
    return metaObj;
}

void* PropertyDoubleItem::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "PropertyDoubleItem" ) )
	return this;
    if ( !qstrcmp( clname, "PropertyItem" ) )
	return (PropertyItem*)this;
    return QObject::qt_cast( clname );
}

bool PropertyDoubleItem::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: resetProperty(); break;
    case 1: setValue(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool PropertyDoubleItem::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool PropertyDoubleItem::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool PropertyDoubleItem::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *PropertyIntItem::className() const
{
    return "PropertyIntItem";
}

QMetaObject *PropertyIntItem::metaObj = 0;
static QMetaObjectCleanUp cleanUp_PropertyIntItem( "PropertyIntItem", &PropertyIntItem::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString PropertyIntItem::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PropertyIntItem", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString PropertyIntItem::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PropertyIntItem", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* PropertyIntItem::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"resetProperty", 0, 0 };
    static const QUMethod slot_1 = {"setValue", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "resetProperty()", &slot_0, QMetaData::Public },
	{ "setValue()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"PropertyIntItem", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_PropertyIntItem.setMetaObject( metaObj );
    return metaObj;
}

void* PropertyIntItem::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "PropertyIntItem" ) )
	return this;
    if ( !qstrcmp( clname, "PropertyItem" ) )
	return (PropertyItem*)this;
    return QObject::qt_cast( clname );
}

bool PropertyIntItem::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: resetProperty(); break;
    case 1: setValue(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool PropertyIntItem::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool PropertyIntItem::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool PropertyIntItem::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *PropertyBoolItem::className() const
{
    return "PropertyBoolItem";
}

QMetaObject *PropertyBoolItem::metaObj = 0;
static QMetaObjectCleanUp cleanUp_PropertyBoolItem( "PropertyBoolItem", &PropertyBoolItem::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString PropertyBoolItem::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PropertyBoolItem", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString PropertyBoolItem::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PropertyBoolItem", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* PropertyBoolItem::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"resetProperty", 0, 0 };
    static const QUMethod slot_1 = {"setValue", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "resetProperty()", &slot_0, QMetaData::Public },
	{ "setValue()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"PropertyBoolItem", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_PropertyBoolItem.setMetaObject( metaObj );
    return metaObj;
}

void* PropertyBoolItem::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "PropertyBoolItem" ) )
	return this;
    if ( !qstrcmp( clname, "PropertyItem" ) )
	return (PropertyItem*)this;
    return QObject::qt_cast( clname );
}

bool PropertyBoolItem::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: resetProperty(); break;
    case 1: setValue(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool PropertyBoolItem::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool PropertyBoolItem::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool PropertyBoolItem::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *PropertyColorItem::className() const
{
    return "PropertyColorItem";
}

QMetaObject *PropertyColorItem::metaObj = 0;
static QMetaObjectCleanUp cleanUp_PropertyColorItem( "PropertyColorItem", &PropertyColorItem::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString PropertyColorItem::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PropertyColorItem", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString PropertyColorItem::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PropertyColorItem", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* PropertyColorItem::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"resetProperty", 0, 0 };
    static const QUMethod slot_1 = {"getColor", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "resetProperty()", &slot_0, QMetaData::Public },
	{ "getColor()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"PropertyColorItem", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_PropertyColorItem.setMetaObject( metaObj );
    return metaObj;
}

void* PropertyColorItem::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "PropertyColorItem" ) )
	return this;
    if ( !qstrcmp( clname, "PropertyItem" ) )
	return (PropertyItem*)this;
    return QObject::qt_cast( clname );
}

bool PropertyColorItem::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: resetProperty(); break;
    case 1: getColor(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool PropertyColorItem::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool PropertyColorItem::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool PropertyColorItem::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *PropertyList::className() const
{
    return "PropertyList";
}

QMetaObject *PropertyList::metaObj = 0;
static QMetaObjectCleanUp cleanUp_PropertyList( "PropertyList", &PropertyList::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString PropertyList::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PropertyList", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString PropertyList::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PropertyList", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* PropertyList::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QListView::staticMetaObject();
    static const QUMethod slot_0 = {"updateEditorSize", 0, 0 };
    static const QUMethod slot_1 = {"resetProperty", 0, 0 };
    static const QUMethod slot_2 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "updateEditorSize()", &slot_0, QMetaData::Public },
	{ "resetProperty()", &slot_1, QMetaData::Public },
	{ "languageChange()", &slot_2, QMetaData::Protected }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_QVariant, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"valueChanged", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_QVariant, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"valueReset", 1, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "valueChanged(const QVariant&)", &signal_0, QMetaData::Protected },
	{ "valueReset(const QVariant&)", &signal_1, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"PropertyList", parentObject,
	slot_tbl, 3,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_PropertyList.setMetaObject( metaObj );
    return metaObj;
}

void* PropertyList::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "PropertyList" ) )
	return this;
    return QListView::qt_cast( clname );
}

// SIGNAL valueChanged
void PropertyList::valueChanged( const QVariant& t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_QVariant.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL valueReset
void PropertyList::valueReset( const QVariant& t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_QVariant.set(o+1,t0);
    activate_signal( clist, o );
}

bool PropertyList::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: updateEditorSize(); break;
    case 1: resetProperty(); break;
    case 2: languageChange(); break;
    default:
	return QListView::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool PropertyList::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: valueChanged((const QVariant&)static_QUType_QVariant.get(_o+1)); break;
    case 1: valueReset((const QVariant&)static_QUType_QVariant.get(_o+1)); break;
    default:
	return QListView::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool PropertyList::qt_property( int id, int f, QVariant* v)
{
    return QListView::qt_property( id, f, v);
}

bool PropertyList::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *EnemyEditor::className() const
{
    return "EnemyEditor";
}

QMetaObject *EnemyEditor::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EnemyEditor( "EnemyEditor", &EnemyEditor::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EnemyEditor::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EnemyEditor", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EnemyEditor::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EnemyEditor", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EnemyEditor::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = PropertyList::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"EnemyEditor", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EnemyEditor.setMetaObject( metaObj );
    return metaObj;
}

void* EnemyEditor::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EnemyEditor" ) )
	return this;
    return PropertyList::qt_cast( clname );
}

bool EnemyEditor::qt_invoke( int _id, QUObject* _o )
{
    return PropertyList::qt_invoke(_id,_o);
}

bool EnemyEditor::qt_emit( int _id, QUObject* _o )
{
    return PropertyList::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool EnemyEditor::qt_property( int id, int f, QVariant* v)
{
    return PropertyList::qt_property( id, f, v);
}

bool EnemyEditor::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *MovingBoxEditor::className() const
{
    return "MovingBoxEditor";
}

QMetaObject *MovingBoxEditor::metaObj = 0;
static QMetaObjectCleanUp cleanUp_MovingBoxEditor( "MovingBoxEditor", &MovingBoxEditor::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString MovingBoxEditor::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MovingBoxEditor", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString MovingBoxEditor::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MovingBoxEditor", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* MovingBoxEditor::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = PropertyList::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"MovingBoxEditor", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_MovingBoxEditor.setMetaObject( metaObj );
    return metaObj;
}

void* MovingBoxEditor::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "MovingBoxEditor" ) )
	return this;
    return PropertyList::qt_cast( clname );
}

bool MovingBoxEditor::qt_invoke( int _id, QUObject* _o )
{
    return PropertyList::qt_invoke(_id,_o);
}

bool MovingBoxEditor::qt_emit( int _id, QUObject* _o )
{
    return PropertyList::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool MovingBoxEditor::qt_property( int id, int f, QVariant* v)
{
    return PropertyList::qt_property( id, f, v);
}

bool MovingBoxEditor::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *TrafficEditor::className() const
{
    return "TrafficEditor";
}

QMetaObject *TrafficEditor::metaObj = 0;
static QMetaObjectCleanUp cleanUp_TrafficEditor( "TrafficEditor", &TrafficEditor::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString TrafficEditor::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TrafficEditor", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString TrafficEditor::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TrafficEditor", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* TrafficEditor::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = PropertyList::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"TrafficEditor", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_TrafficEditor.setMetaObject( metaObj );
    return metaObj;
}

void* TrafficEditor::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "TrafficEditor" ) )
	return this;
    return PropertyList::qt_cast( clname );
}

bool TrafficEditor::qt_invoke( int _id, QUObject* _o )
{
    return PropertyList::qt_invoke(_id,_o);
}

bool TrafficEditor::qt_emit( int _id, QUObject* _o )
{
    return PropertyList::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool TrafficEditor::qt_property( int id, int f, QVariant* v)
{
    return PropertyList::qt_property( id, f, v);
}

bool TrafficEditor::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *PedestrianEditor::className() const
{
    return "PedestrianEditor";
}

QMetaObject *PedestrianEditor::metaObj = 0;
static QMetaObjectCleanUp cleanUp_PedestrianEditor( "PedestrianEditor", &PedestrianEditor::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString PedestrianEditor::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PedestrianEditor", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString PedestrianEditor::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PedestrianEditor", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* PedestrianEditor::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = PropertyList::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"PedestrianEditor", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_PedestrianEditor.setMetaObject( metaObj );
    return metaObj;
}

void* PedestrianEditor::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "PedestrianEditor" ) )
	return this;
    return PropertyList::qt_cast( clname );
}

bool PedestrianEditor::qt_invoke( int _id, QUObject* _o )
{
    return PropertyList::qt_invoke(_id,_o);
}

bool PedestrianEditor::qt_emit( int _id, QUObject* _o )
{
    return PropertyList::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool PedestrianEditor::qt_property( int id, int f, QVariant* v)
{
    return PropertyList::qt_property( id, f, v);
}

bool PedestrianEditor::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *DoorEditor::className() const
{
    return "DoorEditor";
}

QMetaObject *DoorEditor::metaObj = 0;
static QMetaObjectCleanUp cleanUp_DoorEditor( "DoorEditor", &DoorEditor::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString DoorEditor::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "DoorEditor", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString DoorEditor::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "DoorEditor", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* DoorEditor::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = PropertyList::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"DoorEditor", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_DoorEditor.setMetaObject( metaObj );
    return metaObj;
}

void* DoorEditor::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "DoorEditor" ) )
	return this;
    return PropertyList::qt_cast( clname );
}

bool DoorEditor::qt_invoke( int _id, QUObject* _o )
{
    return PropertyList::qt_invoke(_id,_o);
}

bool DoorEditor::qt_emit( int _id, QUObject* _o )
{
    return PropertyList::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool DoorEditor::qt_property( int id, int f, QVariant* v)
{
    return PropertyList::qt_property( id, f, v);
}

bool DoorEditor::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
