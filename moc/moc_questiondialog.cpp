/****************************************************************************
** QuestionDialog meta object code from reading C++ file 'questiondialog.h'
**
** Created: Sa 10. Jul 19:40:08 2004
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../include/questiondialog.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QuestionDialog::className() const
{
    return "QuestionDialog";
}

QMetaObject *QuestionDialog::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QuestionDialog( "QuestionDialog", &QuestionDialog::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QuestionDialog::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QuestionDialog", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QuestionDialog::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QuestionDialog", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QuestionDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"languageChange", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ "ask", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"setAskAgain", 1, param_slot_1 };
    static const QUMethod slot_2 = {"cancel", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "languageChange()", &slot_0, QMetaData::Protected },
	{ "setAskAgain(bool)", &slot_1, QMetaData::Protected },
	{ "cancel()", &slot_2, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"QuestionDialog", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QuestionDialog.setMetaObject( metaObj );
    return metaObj;
}

void* QuestionDialog::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QuestionDialog" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool QuestionDialog::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: languageChange(); break;
    case 1: setAskAgain((bool)static_QUType_bool.get(_o+1)); break;
    case 2: cancel(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QuestionDialog::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QuestionDialog::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool QuestionDialog::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
