/****************************************************************************
** PreferencesDialog meta object code from reading C++ file 'preferencesdialog.h'
**
** Created: So 11. Jul 17:53:47 2004
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../include/preferencesdialog.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *PreferencesDialog::className() const
{
    return "PreferencesDialog";
}

QMetaObject *PreferencesDialog::metaObj = 0;
static QMetaObjectCleanUp cleanUp_PreferencesDialog( "PreferencesDialog", &PreferencesDialog::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString PreferencesDialog::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PreferencesDialog", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString PreferencesDialog::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PreferencesDialog", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* PreferencesDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"languageChange", 0, 0 };
    static const QUMethod slot_1 = {"reset", 0, 0 };
    static const QUMethod slot_2 = {"save", 0, 0 };
    static const QUMethod slot_3 = {"setStandardColor", 0, 0 };
    static const QUMethod slot_4 = {"setLabelsColor", 0, 0 };
    static const QUMethod slot_5 = {"setStatementsColor", 0, 0 };
    static const QUMethod slot_6 = {"setCommandsColor", 0, 0 };
    static const QUMethod slot_7 = {"setDimsColor", 0, 0 };
    static const QUMethod slot_8 = {"setCommentsColor", 0, 0 };
    static const QUMethod slot_9 = {"setDigitsColor", 0, 0 };
    static const QUMethod slot_10 = {"setQuotationsColor", 0, 0 };
    static const QUMethod slot_11 = {"updatePreview", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "languageChange()", &slot_0, QMetaData::Protected },
	{ "reset()", &slot_1, QMetaData::Protected },
	{ "save()", &slot_2, QMetaData::Protected },
	{ "setStandardColor()", &slot_3, QMetaData::Protected },
	{ "setLabelsColor()", &slot_4, QMetaData::Protected },
	{ "setStatementsColor()", &slot_5, QMetaData::Protected },
	{ "setCommandsColor()", &slot_6, QMetaData::Protected },
	{ "setDimsColor()", &slot_7, QMetaData::Protected },
	{ "setCommentsColor()", &slot_8, QMetaData::Protected },
	{ "setDigitsColor()", &slot_9, QMetaData::Protected },
	{ "setQuotationsColor()", &slot_10, QMetaData::Protected },
	{ "updatePreview()", &slot_11, QMetaData::Protected }
    };
    static const QUMethod signal_0 = {"settingsSaved", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "settingsSaved()", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"PreferencesDialog", parentObject,
	slot_tbl, 12,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_PreferencesDialog.setMetaObject( metaObj );
    return metaObj;
}

void* PreferencesDialog::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "PreferencesDialog" ) )
	return this;
    return QDialog::qt_cast( clname );
}

// SIGNAL settingsSaved
void PreferencesDialog::settingsSaved()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

bool PreferencesDialog::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: languageChange(); break;
    case 1: reset(); break;
    case 2: save(); break;
    case 3: setStandardColor(); break;
    case 4: setLabelsColor(); break;
    case 5: setStatementsColor(); break;
    case 6: setCommandsColor(); break;
    case 7: setDimsColor(); break;
    case 8: setCommentsColor(); break;
    case 9: setDigitsColor(); break;
    case 10: setQuotationsColor(); break;
    case 11: updatePreview(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool PreferencesDialog::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: settingsSaved(); break;
    default:
	return QDialog::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool PreferencesDialog::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool PreferencesDialog::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
