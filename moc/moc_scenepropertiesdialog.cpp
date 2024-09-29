/****************************************************************************
** ScenePropertiesDialog meta object code from reading C++ file 'scenepropertiesdialog.h'
**
** Created: Do 22. Jul 17:10:19 2004
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../include/scenepropertiesdialog.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *ScenePropertiesDialog::className() const
{
    return "ScenePropertiesDialog";
}

QMetaObject *ScenePropertiesDialog::metaObj = 0;
static QMetaObjectCleanUp cleanUp_ScenePropertiesDialog( "ScenePropertiesDialog", &ScenePropertiesDialog::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString ScenePropertiesDialog::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ScenePropertiesDialog", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString ScenePropertiesDialog::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ScenePropertiesDialog", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* ScenePropertiesDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"languageChange", 0, 0 };
    static const QUMethod slot_1 = {"accept", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "languageChange()", &slot_0, QMetaData::Protected },
	{ "accept()", &slot_1, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"ScenePropertiesDialog", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_ScenePropertiesDialog.setMetaObject( metaObj );
    return metaObj;
}

void* ScenePropertiesDialog::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "ScenePropertiesDialog" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool ScenePropertiesDialog::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: languageChange(); break;
    case 1: accept(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool ScenePropertiesDialog::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool ScenePropertiesDialog::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool ScenePropertiesDialog::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
