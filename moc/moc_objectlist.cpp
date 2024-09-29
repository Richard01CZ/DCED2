/****************************************************************************
** ObjectList meta object code from reading C++ file 'objectlist.h'
**
** Created: Di 27. Jul 18:10:52 2004
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../include/objectlist.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *ObjectList::className() const
{
    return "ObjectList";
}

QMetaObject *ObjectList::metaObj = 0;
static QMetaObjectCleanUp cleanUp_ObjectList( "ObjectList", &ObjectList::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString ObjectList::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ObjectList", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString ObjectList::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ObjectList", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* ObjectList::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QListView::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::Out },
	{ "name", &static_QUType_QString, 0, QUParameter::In },
	{ "type", &static_QUType_int, 0, QUParameter::In },
	{ "datablock", &static_QUType_ptr, "short", QUParameter::In }
    };
    static const QUMethod slot_0 = {"addListItem", 4, param_slot_0 };
    static const QUMethod slot_1 = {"deleteItem", 0, 0 };
    static const QUMethod slot_2 = {"duplicateItem", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"quickSearch", 1, param_slot_3 };
    static const QUMethod slot_4 = {"startRename", 0, 0 };
    static const QUMethod slot_5 = {"switchToFriendItem", 0, 0 };
    static const QUMethod slot_6 = {"switchToInitScripts", 0, 0 };
    static const QUMethod slot_7 = {"switchToObjectDefinitions", 0, 0 };
    static const QUMethod slot_8 = {"switchToObjects", 0, 0 };
    static const QUParameter param_slot_9[] = {
	{ "item", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ "col", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_9 = {"renameItem", 2, param_slot_9 };
    static const QMetaData slot_tbl[] = {
	{ "addListItem(QString,int,short)", &slot_0, QMetaData::Public },
	{ "deleteItem()", &slot_1, QMetaData::Public },
	{ "duplicateItem()", &slot_2, QMetaData::Public },
	{ "quickSearch(const QString&)", &slot_3, QMetaData::Public },
	{ "startRename()", &slot_4, QMetaData::Public },
	{ "switchToFriendItem()", &slot_5, QMetaData::Public },
	{ "switchToInitScripts()", &slot_6, QMetaData::Public },
	{ "switchToObjectDefinitions()", &slot_7, QMetaData::Public },
	{ "switchToObjects()", &slot_8, QMetaData::Public },
	{ "renameItem(QListViewItem*,int)", &slot_9, QMetaData::Protected }
    };
    static const QUMethod signal_0 = {"objectDeleted", 0, 0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "Type", QUParameter::In }
    };
    static const QUMethod signal_1 = {"itemRenamed", 3, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "objectDeleted()", &signal_0, QMetaData::Public },
	{ "itemRenamed(QString,QString,Type)", &signal_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"ObjectList", parentObject,
	slot_tbl, 10,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_ObjectList.setMetaObject( metaObj );
    return metaObj;
}

void* ObjectList::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "ObjectList" ) )
	return this;
    return QListView::qt_cast( clname );
}

// SIGNAL objectDeleted
void ObjectList::objectDeleted()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL itemRenamed
void ObjectList::itemRenamed( QString t0, QString t1, Type t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_QString.set(o+1,t0);
    static_QUType_QString.set(o+2,t1);
    static_QUType_ptr.set(o+3,&t2);
    activate_signal( clist, o );
}

bool ObjectList::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: static_QUType_ptr.set(_o,addListItem((QString)static_QUType_QString.get(_o+1),(int)static_QUType_int.get(_o+2),(short)(*((short*)static_QUType_ptr.get(_o+3))))); break;
    case 1: deleteItem(); break;
    case 2: duplicateItem(); break;
    case 3: quickSearch((const QString&)static_QUType_QString.get(_o+1)); break;
    case 4: startRename(); break;
    case 5: switchToFriendItem(); break;
    case 6: switchToInitScripts(); break;
    case 7: switchToObjectDefinitions(); break;
    case 8: switchToObjects(); break;
    case 9: renameItem((QListViewItem*)static_QUType_ptr.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    default:
	return QListView::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool ObjectList::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: objectDeleted(); break;
    case 1: itemRenamed((QString)static_QUType_QString.get(_o+1),(QString)static_QUType_QString.get(_o+2),(Type)(*((Type*)static_QUType_ptr.get(_o+3)))); break;
    default:
	return QListView::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool ObjectList::qt_property( int id, int f, QVariant* v)
{
    return QListView::qt_property( id, f, v);
}

bool ObjectList::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
