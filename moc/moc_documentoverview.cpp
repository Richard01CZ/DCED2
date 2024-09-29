/****************************************************************************
** DocumentOverview meta object code from reading C++ file 'documentoverview.h'
**
** Created: So 25. Jul 16:57:54 2004
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../include/documentoverview.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *DocumentOverview::className() const
{
    return "DocumentOverview";
}

QMetaObject *DocumentOverview::metaObj = 0;
static QMetaObjectCleanUp cleanUp_DocumentOverview( "DocumentOverview", &DocumentOverview::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString DocumentOverview::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "DocumentOverview", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString DocumentOverview::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "DocumentOverview", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* DocumentOverview::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QVBox::staticMetaObject();
    static const QUMethod slot_0 = {"closeAll", 0, 0 };
    static const QUMethod slot_1 = {"closeDocument", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ "number", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"changeDocument", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "widget", &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod slot_3 = {"changeDocument", 1, param_slot_3 };
    static const QMetaData slot_tbl[] = {
	{ "closeAll()", &slot_0, QMetaData::Public },
	{ "closeDocument()", &slot_1, QMetaData::Public },
	{ "changeDocument(int)", &slot_2, QMetaData::Protected },
	{ "changeDocument(QWidget*)", &slot_3, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"DocumentOverview", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_DocumentOverview.setMetaObject( metaObj );
    return metaObj;
}

void* DocumentOverview::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "DocumentOverview" ) )
	return this;
    return QVBox::qt_cast( clname );
}

bool DocumentOverview::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: closeAll(); break;
    case 1: closeDocument(); break;
    case 2: changeDocument((int)static_QUType_int.get(_o+1)); break;
    case 3: changeDocument((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QVBox::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool DocumentOverview::qt_emit( int _id, QUObject* _o )
{
    return QVBox::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool DocumentOverview::qt_property( int id, int f, QVariant* v)
{
    return QVBox::qt_property( id, f, v);
}

bool DocumentOverview::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *SceneOverview::className() const
{
    return "SceneOverview";
}

QMetaObject *SceneOverview::metaObj = 0;
static QMetaObjectCleanUp cleanUp_SceneOverview( "SceneOverview", &SceneOverview::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString SceneOverview::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "SceneOverview", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString SceneOverview::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "SceneOverview", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* SceneOverview::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = DocumentOverview::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "short", QUParameter::In }
    };
    static const QUMethod slot_0 = {"addListItem", 3, param_slot_0 };
    static const QUMethod slot_1 = {"applySettings", 0, 0 };
    static const QUMethod slot_2 = {"closeDocument", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "short", QUParameter::In }
    };
    static const QUMethod slot_3 = {"createListItem", 3, param_slot_3 };
    static const QUMethod slot_4 = {"createTemplate", 0, 0 };
    static const QUMethod slot_5 = {"deleteObject", 0, 0 };
    static const QUMethod slot_6 = {"exportObject", 0, 0 };
    static const QUMethod slot_7 = {"importObject", 0, 0 };
    static const QUParameter param_slot_8[] = {
	{ "on", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"listInits", 1, param_slot_8 };
    static const QUParameter param_slot_9[] = {
	{ "on", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_9 = {"listObjDefs", 1, param_slot_9 };
    static const QUParameter param_slot_10[] = {
	{ "on", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_10 = {"listObjects", 1, param_slot_10 };
    static const QUParameter param_slot_11[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_11 = {"openObjDef", 1, param_slot_11 };
    static const QUParameter param_slot_12[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_12 = {"openObject", 1, param_slot_12 };
    static const QUParameter param_slot_13[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_13 = {"quickSearch", 1, param_slot_13 };
    static const QUParameter param_slot_14[] = {
	{ "newName", &static_QUType_QString, 0, QUParameter::In },
	{ "oldName", &static_QUType_QString, 0, QUParameter::In },
	{ "type", &static_QUType_ptr, "Type", QUParameter::In }
    };
    static const QUMethod slot_14 = {"renameObject", 3, param_slot_14 };
    static const QUMethod slot_15 = {"saveAllDocuments", 0, 0 };
    static const QUMethod slot_16 = {"saveDocument", 0, 0 };
    static const QUMethod slot_17 = {"setListDockVisible", 0, 0 };
    static const QUParameter param_slot_18[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_18 = {"setPreview", 1, param_slot_18 };
    static const QUMethod slot_19 = {"setScriptPreviewVisible", 0, 0 };
    static const QUMethod slot_20 = {"showSceneProperties", 0, 0 };
    static const QUParameter param_slot_21[] = {
	{ "widget", &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod slot_21 = {"changeDocument", 1, param_slot_21 };
    static const QMetaData slot_tbl[] = {
	{ "addListItem(char*,int,short)", &slot_0, QMetaData::Public },
	{ "applySettings()", &slot_1, QMetaData::Public },
	{ "closeDocument()", &slot_2, QMetaData::Public },
	{ "createListItem(char*,int,short)", &slot_3, QMetaData::Public },
	{ "createTemplate()", &slot_4, QMetaData::Public },
	{ "deleteObject()", &slot_5, QMetaData::Public },
	{ "exportObject()", &slot_6, QMetaData::Public },
	{ "importObject()", &slot_7, QMetaData::Public },
	{ "listInits(bool)", &slot_8, QMetaData::Public },
	{ "listObjDefs(bool)", &slot_9, QMetaData::Public },
	{ "listObjects(bool)", &slot_10, QMetaData::Public },
	{ "openObjDef(QListViewItem*)", &slot_11, QMetaData::Public },
	{ "openObject(QListViewItem*)", &slot_12, QMetaData::Public },
	{ "quickSearch(const QString&)", &slot_13, QMetaData::Public },
	{ "renameObject(QString,QString,Type)", &slot_14, QMetaData::Public },
	{ "saveAllDocuments()", &slot_15, QMetaData::Public },
	{ "saveDocument()", &slot_16, QMetaData::Public },
	{ "setListDockVisible()", &slot_17, QMetaData::Public },
	{ "setPreview(QListViewItem*)", &slot_18, QMetaData::Public },
	{ "setScriptPreviewVisible()", &slot_19, QMetaData::Public },
	{ "showSceneProperties()", &slot_20, QMetaData::Public },
	{ "changeDocument(QWidget*)", &slot_21, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"SceneOverview", parentObject,
	slot_tbl, 22,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_SceneOverview.setMetaObject( metaObj );
    return metaObj;
}

void* SceneOverview::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "SceneOverview" ) )
	return this;
    return DocumentOverview::qt_cast( clname );
}

bool SceneOverview::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: addListItem((char*)static_QUType_charstar.get(_o+1),(int)static_QUType_int.get(_o+2),(short)(*((short*)static_QUType_ptr.get(_o+3)))); break;
    case 1: applySettings(); break;
    case 2: closeDocument(); break;
    case 3: createListItem((char*)static_QUType_charstar.get(_o+1),(int)static_QUType_int.get(_o+2),(short)(*((short*)static_QUType_ptr.get(_o+3)))); break;
    case 4: createTemplate(); break;
    case 5: deleteObject(); break;
    case 6: exportObject(); break;
    case 7: importObject(); break;
    case 8: listInits((bool)static_QUType_bool.get(_o+1)); break;
    case 9: listObjDefs((bool)static_QUType_bool.get(_o+1)); break;
    case 10: listObjects((bool)static_QUType_bool.get(_o+1)); break;
    case 11: openObjDef((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 12: openObject((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 13: quickSearch((const QString&)static_QUType_QString.get(_o+1)); break;
    case 14: renameObject((QString)static_QUType_QString.get(_o+1),(QString)static_QUType_QString.get(_o+2),(Type)(*((Type*)static_QUType_ptr.get(_o+3)))); break;
    case 15: saveAllDocuments(); break;
    case 16: saveDocument(); break;
    case 17: setListDockVisible(); break;
    case 18: setPreview((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 19: setScriptPreviewVisible(); break;
    case 20: showSceneProperties(); break;
    case 21: changeDocument((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return DocumentOverview::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool SceneOverview::qt_emit( int _id, QUObject* _o )
{
    return DocumentOverview::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool SceneOverview::qt_property( int id, int f, QVariant* v)
{
    return DocumentOverview::qt_property( id, f, v);
}

bool SceneOverview::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
