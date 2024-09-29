/****************************************************************************
** AddObjectDialog meta object code from reading C++ file 'addobjectdialog.h'
**
** Created: Mo 12. Jul 21:09:25 2004
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../include/addobjectdialog.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *AddObjectDialog::className() const
{
    return "AddObjectDialog";
}

QMetaObject *AddObjectDialog::metaObj = 0;
static QMetaObjectCleanUp cleanUp_AddObjectDialog( "AddObjectDialog", &AddObjectDialog::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString AddObjectDialog::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "AddObjectDialog", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString AddObjectDialog::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "AddObjectDialog", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* AddObjectDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"accept", 0, 0 };
    static const QUMethod slot_1 = {"languageChange", 0, 0 };
    static const QUMethod slot_2 = {"setOkButtonState", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ "item", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_3 = {"setHelp", 1, param_slot_3 };
    static const QMetaData slot_tbl[] = {
	{ "accept()", &slot_0, QMetaData::Public },
	{ "languageChange()", &slot_1, QMetaData::Protected },
	{ "setOkButtonState()", &slot_2, QMetaData::Protected },
	{ "setHelp(QListViewItem*)", &slot_3, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"AddObjectDialog", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_AddObjectDialog.setMetaObject( metaObj );
    return metaObj;
}

void* AddObjectDialog::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "AddObjectDialog" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool AddObjectDialog::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: accept(); break;
    case 1: languageChange(); break;
    case 2: setOkButtonState(); break;
    case 3: setHelp((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool AddObjectDialog::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool AddObjectDialog::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool AddObjectDialog::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
