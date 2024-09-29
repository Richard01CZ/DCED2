#ifndef OBJECTTYPES
#define OBJECTTYPES

#include <qstring.h>
#include <qvaluelist.h>
#include <qstringlist.h>
#include "globaldefs.h"

struct ObjectTypeItem {
	QString text;
	QString description;
	int id;
	bool supported;
	Type type;
};

typedef QValueList<ObjectTypeItem> ObjectTypeList;
typedef QValueListIterator<ObjectTypeItem> ObjectTypeListIterator;
typedef QValueList<int> IntList;
typedef QValueListIterator<int> IntListIterator;

class ObjectTypes
{
public:
	ObjectTypes();
	
	ObjectTypeList typeList() const; // Gibt die Liste zurück

	static QString intToText( int id, Type type );  // gibt den Typ als Text zurück
	static int textToInt( QString text, Type type ); // gibt den Typ als Zahl zurück
	static ObjectTypeList objectTypeList( Type type, bool supportedOnly = FALSE ); // gibt eine Liste aller Typen zurück (näheres bei struct ObjectTypeItem)
	static QStringList objectStringList( Type type, bool supportedOnly = FALSE ); // gibt eine Textliste aller Typen zurück
	static QString getDescription( QString text, Type type ); // gibt die zugehörige Beschreibung des Typs zurück
	static QString getDescription( int id, Type type );

private:
	ObjectTypeList list; // Liste mit den Objekten
};

#endif // OBJECTTYPES