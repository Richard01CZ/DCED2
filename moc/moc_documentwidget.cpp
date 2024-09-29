/****************************************************************************
** DocumentWidget meta object code from reading C++ file 'documentwidget.h'
**
** Created: Mo 26. Jul 19:59:05 2004
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../include/documentwidget.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *DocumentWidget::className() const
{
    return "DocumentWidget";
}

QMetaObject *DocumentWidget::metaObj = 0;
static QMetaObjectCleanUp cleanUp_DocumentWidget( "DocumentWidget", &DocumentWidget::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString DocumentWidget::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "DocumentWidget", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString DocumentWidget::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "DocumentWidget", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* DocumentWidget::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMainWindow::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_0 = {"setCentralWindow", 1, param_slot_0 };
    static const QUMethod slot_1 = {"save", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "setCentralWindow(QListViewItem*)", &slot_0, QMetaData::Public },
	{ "save()", &slot_1, QMetaData::Public }
    };
    static const QUMethod signal_0 = {"closeSignal", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "closeSignal()", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"DocumentWidget", parentObject,
	slot_tbl, 2,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_DocumentWidget.setMetaObject( metaObj );
    return metaObj;
}

void* DocumentWidget::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "DocumentWidget" ) )
	return this;
    return QMainWindow::qt_cast( clname );
}

// SIGNAL closeSignal
void DocumentWidget::closeSignal()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

bool DocumentWidget::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setCentralWindow((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 1: save(); break;
    default:
	return QMainWindow::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool DocumentWidget::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: closeSignal(); break;
    default:
	return QMainWindow::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool DocumentWidget::qt_property( int id, int f, QVariant* v)
{
    return QMainWindow::qt_property( id, f, v);
}

bool DocumentWidget::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
