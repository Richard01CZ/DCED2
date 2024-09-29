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
	
	ObjectTypeList typeList() const; // Gibt die Liste zur�ck

	static QString intToText( int id, Type type );  // gibt den Typ als Text zur�ck
	static int textToInt( QString text, Type type ); // gibt den Typ als Zahl zur�ck
	static ObjectTypeList objectTypeList( Type type, bool supportedOnly = FALSE ); // gibt eine Liste aller Typen zur�ck (n�heres bei struct ObjectTypeItem)
	static QStringList objectStringList( Type type, bool supportedOnly = FALSE ); // gibt eine Textliste aller Typen zur�ck
	static QString getDescription( QString text, Type type ); // gibt die zugeh�rige Beschreibung des Typs zur�ck
	static QString getDescription( int id, Type type );

private:
	ObjectTypeList list; // Liste mit den Objekten
};

#endif // OBJECTTYPES