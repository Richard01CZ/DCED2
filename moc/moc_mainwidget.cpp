/****************************************************************************
** MainWidget meta object code from reading C++ file 'mainwidget.h'
**
** Created: Do 22. Jul 21:13:58 2004
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../include/mainwidget.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *MainWidget::className() const
{
    return "MainWidget";
}

QMetaObject *MainWidget::metaObj = 0;
static QMetaObjectCleanUp cleanUp_MainWidget( "MainWidget", &MainWidget::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString MainWidget::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MainWidget", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString MainWidget::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MainWidget", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* MainWidget::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMainWindow::staticMetaObject();
    static const QUMethod slot_0 = {"OpenFile", 0, 0 };
    static const QUMethod slot_1 = {"ReopenFile", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"ReopenFile", 1, param_slot_2 };
    static const QUMethod slot_3 = {"SaveFile", 0, 0 };
    static const QUMethod slot_4 = {"SaveAllFiles", 0, 0 };
    static const QUMethod slot_5 = {"CloseFile", 0, 0 };
    static const QUMethod slot_6 = {"setLanguageEnglish", 0, 0 };
    static const QUMethod slot_7 = {"setLanguageGerman", 0, 0 };
    static const QUMethod slot_8 = {"setLanguageFrench", 0, 0 };
    static const QUMethod slot_9 = {"setLanguageSpanish", 0, 0 };
    static const QUMethod slot_10 = {"setLanguageCzech", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "OpenFile()", &slot_0, QMetaData::Public },
	{ "ReopenFile()", &slot_1, QMetaData::Public },
	{ "ReopenFile(int)", &slot_2, QMetaData::Public },
	{ "SaveFile()", &slot_3, QMetaData::Public },
	{ "SaveAllFiles()", &slot_4, QMetaData::Public },
	{ "CloseFile()", &slot_5, QMetaData::Public },
	{ "setLanguageEnglish()", &slot_6, QMetaData::Public },
	{ "setLanguageGerman()", &slot_7, QMetaData::Public },
	{ "setLanguageFrench()", &slot_8, QMetaData::Public },
	{ "setLanguageSpanish()", &slot_9, QMetaData::Public },
	{ "setLanguageCzech()", &slot_10, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"MainWidget", parentObject,
	slot_tbl, 11,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_MainWidget.setMetaObject( metaObj );
    return metaObj;
}

void* MainWidget::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "MainWidget" ) )
	return this;
    return QMainWindow::qt_cast( clname );
}

bool MainWidget::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: OpenFile(); break;
    case 1: ReopenFile(); break;
    case 2: ReopenFile((int)static_QUType_int.get(_o+1)); break;
    case 3: SaveFile(); break;
    case 4: SaveAllFiles(); break;
    case 5: CloseFile(); break;
    case 6: setLanguageEnglish(); break;
    case 7: setLanguageGerman(); break;
    case 8: setLanguageFrench(); break;
    case 9: setLanguageSpanish(); break;
    case 10: setLanguageCzech(); break;
    default:
	return QMainWindow::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool MainWidget::qt_emit( int _id, QUObject* _o )
{
    return QMainWindow::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool MainWidget::qt_property( int id, int f, QVariant* v)
{
    return QMainWindow::qt_property( id, f, v);
}

bool MainWidget::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
