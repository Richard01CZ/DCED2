/****************************************************************************
** ColorPicker meta object code from reading C++ file 'colorwidget.h'
**
** Created: Sa 10. Jul 19:40:09 2004
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../include/colorwidget.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *ColorPicker::className() const
{
    return "ColorPicker";
}

QMetaObject *ColorPicker::metaObj = 0;
static QMetaObjectCleanUp cleanUp_ColorPicker( "ColorPicker", &ColorPicker::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString ColorPicker::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ColorPicker", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString ColorPicker::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ColorPicker", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* ColorPicker::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QFrame::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "h", &static_QUType_int, 0, QUParameter::In },
	{ "s", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setCol", 2, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "setCol(int,int)", &slot_0, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ "h", &static_QUType_int, 0, QUParameter::In },
	{ "s", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"newCol", 2, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "newCol(int,int)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"ColorPicker", parentObject,
	slot_tbl, 1,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_ColorPicker.setMetaObject( metaObj );
    return metaObj;
}

void* ColorPicker::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "ColorPicker" ) )
	return this;
    return QFrame::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL newCol
void ColorPicker::newCol( int t0, int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_int.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    activate_signal( clist, o );
}

bool ColorPicker::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setCol((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    default:
	return QFrame::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool ColorPicker::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: newCol((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    default:
	return QFrame::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool ColorPicker::qt_property( int id, int f, QVariant* v)
{
    return QFrame::qt_property( id, f, v);
}

bool ColorPicker::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *ColorLuminancePicker::className() const
{
    return "ColorLuminancePicker";
}

QMetaObject *ColorLuminancePicker::metaObj = 0;
static QMetaObjectCleanUp cleanUp_ColorLuminancePicker( "ColorLuminancePicker", &ColorLuminancePicker::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString ColorLuminancePicker::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ColorLuminancePicker", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString ColorLuminancePicker::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ColorLuminancePicker", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* ColorLuminancePicker::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "h", &static_QUType_int, 0, QUParameter::In },
	{ "s", &static_QUType_int, 0, QUParameter::In },
	{ "v", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setCol", 3, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "h", &static_QUType_int, 0, QUParameter::In },
	{ "s", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"setCol", 2, param_slot_1 };
    static const QMetaData slot_tbl[] = {
	{ "setCol(int,int,int)", &slot_0, QMetaData::Public },
	{ "setCol(int,int)", &slot_1, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ "h", &static_QUType_int, 0, QUParameter::In },
	{ "s", &static_QUType_int, 0, QUParameter::In },
	{ "v", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"newHsv", 3, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "newHsv(int,int,int)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"ColorLuminancePicker", parentObject,
	slot_tbl, 2,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_ColorLuminancePicker.setMetaObject( metaObj );
    return metaObj;
}

void* ColorLuminancePicker::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "ColorLuminancePicker" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL newHsv
void ColorLuminancePicker::newHsv( int t0, int t1, int t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_int.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    static_QUType_int.set(o+3,t2);
    activate_signal( clist, o );
}

bool ColorLuminancePicker::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setCol((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3)); break;
    case 1: setCol((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool ColorLuminancePicker::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: newHsv((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool ColorLuminancePicker::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool ColorLuminancePicker::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *ColorShower::className() const
{
    return "ColorShower";
}

QMetaObject *ColorShower::metaObj = 0;
static QMetaObjectCleanUp cleanUp_ColorShower( "ColorShower", &ColorShower::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString ColorShower::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ColorShower", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString ColorShower::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ColorShower", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* ColorShower::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "rgb", &static_QUType_ptr, "QRgb", QUParameter::In }
    };
    static const QUMethod slot_0 = {"setRgb", 1, param_slot_0 };
    static const QUMethod slot_1 = {"rgbEd", 0, 0 };
    static const QUMethod slot_2 = {"hsvEd", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "setRgb(QRgb)", &slot_0, QMetaData::Public },
	{ "rgbEd()", &slot_1, QMetaData::Private },
	{ "hsvEd()", &slot_2, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ "rgb", &static_QUType_ptr, "QRgb", QUParameter::In }
    };
    static const QUMethod signal_0 = {"newCol", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "newCol(QRgb)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"ColorShower", parentObject,
	slot_tbl, 3,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_ColorShower.setMetaObject( metaObj );
    return metaObj;
}

void* ColorShower::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "ColorShower" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL newCol
void ColorShower::newCol( QRgb t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

bool ColorShower::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setRgb((QRgb)(*((QRgb*)static_QUType_ptr.get(_o+1)))); break;
    case 1: rgbEd(); break;
    case 2: hsvEd(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool ColorShower::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: newCol((QRgb)(*((QRgb*)static_QUType_ptr.get(_o+1)))); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool ColorShower::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool ColorShower::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *ColorShowLabel::className() const
{
    return "ColorShowLabel";
}

QMetaObject *ColorShowLabel::metaObj = 0;
static QMetaObjectCleanUp cleanUp_ColorShowLabel( "ColorShowLabel", &ColorShowLabel::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString ColorShowLabel::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ColorShowLabel", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString ColorShowLabel::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ColorShowLabel", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* ColorShowLabel::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QFrame::staticMetaObject();
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QRgb", QUParameter::In }
    };
    static const QUMethod signal_0 = {"colorDropped", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "colorDropped(QRgb)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"ColorShowLabel", parentObject,
	0, 0,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_ColorShowLabel.setMetaObject( metaObj );
    return metaObj;
}

void* ColorShowLabel::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "ColorShowLabel" ) )
	return this;
    return QFrame::qt_cast( clname );
}

// SIGNAL colorDropped
void ColorShowLabel::colorDropped( QRgb t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

bool ColorShowLabel::qt_invoke( int _id, QUObject* _o )
{
    return QFrame::qt_invoke(_id,_o);
}

bool ColorShowLabel::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: colorDropped((QRgb)(*((QRgb*)static_QUType_ptr.get(_o+1)))); break;
    default:
	return QFrame::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool ColorShowLabel::qt_property( int id, int f, QVariant* v)
{
    return QFrame::qt_property( id, f, v);
}

bool ColorShowLabel::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *ColorWidget::className() const
{
    return "ColorWidget";
}

QMetaObject *ColorWidget::metaObj = 0;
static QMetaObjectCleanUp cleanUp_ColorWidget( "ColorWidget", &ColorWidget::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString ColorWidget::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ColorWidget", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString ColorWidget::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ColorWidget", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* ColorWidget::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "h", &static_QUType_int, 0, QUParameter::In },
	{ "s", &static_QUType_int, 0, QUParameter::In },
	{ "v", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"newHsv", 3, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "rgb", &static_QUType_ptr, "QRgb", QUParameter::In }
    };
    static const QUMethod slot_1 = {"newColorTypedIn", 1, param_slot_1 };
    static const QMetaData slot_tbl[] = {
	{ "newHsv(int,int,int)", &slot_0, QMetaData::Public },
	{ "newColorTypedIn(QRgb)", &slot_1, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ "color", &static_QUType_varptr, "\x0a", QUParameter::In }
    };
    static const QUMethod signal_0 = {"colorChanged", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "colorChanged(QColor)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"ColorWidget", parentObject,
	slot_tbl, 2,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_ColorWidget.setMetaObject( metaObj );
    return metaObj;
}

void* ColorWidget::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "ColorWidget" ) )
	return this;
    return QObject::qt_cast( clname );
}

// SIGNAL colorChanged
void ColorWidget::colorChanged( QColor t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_varptr.set(o+1,&t0);
    activate_signal( clist, o );
}

bool ColorWidget::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: newHsv((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3)); break;
    case 1: newColorTypedIn((QRgb)(*((QRgb*)static_QUType_ptr.get(_o+1)))); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool ColorWidget::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: colorChanged((QColor)(*((QColor*)static_QUType_ptr.get(_o+1)))); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool ColorWidget::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool ColorWidget::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
