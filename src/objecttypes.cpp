#include "objecttypes.h"

ObjectTypes::ObjectTypes()
{
	ObjectTypeItem item;

	//Objects
	item.type = Object;

	item.text = QObject::tr( "Light" );
	item.description = QObject::tr( "Lights shouldn't need any explanation. They shine and are usually bright ;-)." );
	item.id = 2;
	item.supported = TRUE;
	list.append( item );

	item.text = QObject::tr( "Camera" );
	item.description = QObject::tr( "A camera can be called in a script as a frame and used with the camera commands." );
	item.id = 3;
	item.supported = TRUE;
	list.append( item );

	item.text = QObject::tr( "Sound" );
	item.description = QObject::tr( "Sound objects are invisible for the player and play a wav file in 3D sound. They are "
		"not full supported" );
	item.id = 4;
	item.supported = FALSE;
	list.append( item );

	item.text = QObject::tr( "Standard Object" );
	item.description = QObject::tr( "Standard objects have some special values whose function we didn't find out yet." );
	item.id = 6;
	item.supported = TRUE;
	list.append( item );

	item.text = QObject::tr( "Model Object" );
	item.description = QObject::tr( "Model objects have coordinates like each other object type, too, but also have a model.");
	item.id = 9;
	item.supported = TRUE;
	list.append( item );

	item.text = QObject::tr( "Occluder" );
	item.description = QObject::tr( "An occluder is an object used to optimize the rendering time of Direct3D. "
		"Occluders are not full supported in DC||ED." );
	item.id = 12;
	item.supported = FALSE;
	list.append( item );

	item.text = QObject::tr( "City Music" );
	item.description = QObject::tr( "A city music object defines an area where you can hear it." );
	item.id = 14;
	item.supported = FALSE;
	list.append( item );

	item.text = QObject::tr( "Sector" );
	item.description = QObject::tr( "A sector defines an area. If you move a sector, every object of this sector moves "
		"with the sector. That is very helpful if you want to move a full house with interior. The translation data of an "
		"object which belongs to a sector are <i>relative</i> to the sector." );
	item.id = 153;
	item.supported = TRUE;
	list.append( item );

	item.text = QObject::tr( "Lightmap" );
	item.description = QObject::tr( "" );
	item.id = 154;
	item.supported = FALSE;
	list.append( item );

	//---------------------------------------------//

	//Object Definitions
	item.type = ObjDef;

	item.text = QObject::tr( "Ghost object" );
	item.description = QObject::tr( "" );
	item.id = 1;
	item.supported = FALSE;
	list.append( item );

	item.text = QObject::tr( "Player" );
	item.description = QObject::tr( "The player is the guy you control, mostly Tommy. Note that if you create a second player, "
			"he will move just like the first one!" );
	item.id = 2;
	item.supported = TRUE;
	list.append( item );

	item.text = QObject::tr( "Car" );
	item.description = QObject::tr( "Cars shouldn't need any explanation. They have four wheels and you can drive with them ;-)." );
	item.id = 4;
	item.supported = TRUE;
	list.append( item );

	item.text = QObject::tr( "Script" );
	item.description = QObject::tr( "Scripts are very important. They make the world interactive." );
	item.id = 5;
	item.supported = TRUE;
	list.append( item );

	item.text = QObject::tr( "Door" );
	item.description = QObject::tr( "This makes an object become a door. You can set the sound it makes when it's opened, "
		"closed, or when it's locked, the open and close speed of it and much more." );
	item.id = 6;
	item.supported = TRUE;
	list.append( item );

	item.text = QObject::tr( "Trolley" );
	item.description = QObject::tr( "" );
	item.id = 8;
	item.supported = FALSE;
	list.append( item );

	item.text = QObject::tr( "A special object in the villa mission" );
	item.description = QObject::tr( "" );
	item.id = 9;
	item.supported = FALSE;
	list.append( item );

	item.text = QObject::tr( "Traffic Setup" );
	item.description = QObject::tr( "This list contains the names of cars that are shown in the traffic. Also, it defines "
		"how many cars appear, and how many cars of each typ relative to the other types." );
	item.id = 12;
	item.supported = TRUE;
	list.append( item );

	item.text = QObject::tr( "Pedestrian Setup" );
	item.description = QObject::tr( "This list contains the names of models of pedestrians that are shown in Lost Heaven. "
		"Also, it defines how many pedestrians appear, and how many pedestrians of each typ relative to the other types." );
	item.id = 18;
	item.supported = TRUE;
	list.append( item );

	item.text = QObject::tr( "Unknown" );
	item.description = QObject::tr( "" );
	item.id = 20;
	item.supported = FALSE;
	list.append( item );

	item.text = QObject::tr( "Dog" );
	item.description = QObject::tr( "" );
	item.id = 21;
	item.supported = FALSE;
	list.append( item );

	item.text = QObject::tr( "Plane" );
	item.description = QObject::tr( "" );
	item.id = 22;
	item.supported = FALSE;
	list.append( item );

	item.text = QObject::tr( "Rail route (\"lucky bastard\" mission only)" );
	item.description = QObject::tr( "" );
	item.id = 24;
	item.supported = FALSE;
	list.append( item );

	item.text = QObject::tr( "Pumpar" );
	item.description = QObject::tr( "The pumpar is the guy at the petrol station who fills your tank." );
	item.id = 25;
	item.supported = FALSE;
	list.append( item );

	item.text = QObject::tr( "Enemy" );
	item.description = QObject::tr( "An enemy is a scriptable person. It consists of "
		"two parts: the properties for the enemy like health or shooting skills, and the script where you can program it's AI." );
	item.id = 27;
	item.supported = TRUE;
	list.append( item );

	item.text = QObject::tr( "Race camera" );
	item.description = QObject::tr( "Race cameras are very less documentated, because they are only used in the race-mission." );
	item.id = 28;
	item.supported = TRUE;
	list.append( item );

	item.text = QObject::tr( "Wagons (\"lucky bastard\" mission only)" );
	item.description = QObject::tr( "" );
	item.id = 30;
	item.supported = FALSE;
	list.append( item );

	item.text = QObject::tr( "Clocks" );
	item.description = QObject::tr( "" );
	item.id = 34;
	item.supported = FALSE;
	list.append( item );

	item.text = QObject::tr( "Physical object" );
	item.description = QObject::tr( "Physical objects are objects you can move in the game. They are handled by the physics "
		"engine in Mafia and when they're shot, hit etc., they really fall around and not just stay on their place like "
		"normal objects." );
	item.id = 35;
	item.supported = TRUE;
	list.append( item );

	item.text = QObject::tr( "Truck" );
	item.description = QObject::tr( "" );
	item.id = 36;
	item.supported = FALSE; //SHURE??
	list.append( item );

	//---------------------------------------------//

	//Init Scripts
	item.type = Init;

	item.text = QObject::tr( "Init Script" );
	item.description = QObject::tr( "Init Scripts are scripts that are executed before ALL other scripts. This is useful "
		"if you want to deactivate something right from the beginning." );
	item.id = 155;
	item.supported = TRUE;
	list.append( item );

}

ObjectTypeList ObjectTypes::typeList() const
{
	return ObjectTypeList( list );
}

QString ObjectTypes::intToText( int id, Type type )
{
	if( type == All )
		return "Type 'All' is not allowed for ID to text conversions.";

	ObjectTypeList l = ObjectTypes().typeList();
	for( ObjectTypeListIterator it = l.begin(); it != l.end(); it++ )
		if( (*it).type == type && (*it).id == id )
			return (*it).text;

	return "ID " + QString::number( id ) + " doesn't exist.";
}

int ObjectTypes::textToInt( QString text, Type type )
{
	if( type == All )
		return -2;

	ObjectTypeList l = ObjectTypes().typeList();
	for( ObjectTypeListIterator it = l.begin(); it != l.end(); it++ )
		if( (*it).type == type && (*it).text == text )
			return (*it).id;

	return -1;
}

ObjectTypeList ObjectTypes::objectTypeList( Type type, bool supportedOnly /* = false */ )
{
	ObjectTypeList returnList;
	ObjectTypeList l = ObjectTypes().typeList();
	for( ObjectTypeListIterator it = l.begin(); it != l.end(); it++ )
		if( (*it).type == type )
			if( supportedOnly )
			{
				if( (*it).supported )
					returnList.append( (*it) );
				continue;
			}
			else
				returnList.append( (*it) );
	return returnList;
}

QStringList ObjectTypes::objectStringList( Type type, bool supportedOnly /* = false */ )
{
	QStringList returnList;
	ObjectTypeList l = ObjectTypes().typeList();
	for( ObjectTypeListIterator it = l.begin(); it != l.end(); it++ )
		if( (*it).type == type )
			if( supportedOnly )
			{
				if( (*it).supported )
					returnList.append( (*it).text );
				continue;
			}
			else
				returnList.append( (*it).text );
	return returnList;	
}

QString ObjectTypes::getDescription( QString text, Type type )
{
	if( type == All )
		return "Error: Cannot search in all datablocks!";

	ObjectTypeList l = ObjectTypes().typeList();
	for( ObjectTypeListIterator it = l.begin(); it != l.end(); it++ )
		if( (*it).type == type && (*it).text == text )
			return (*it).description;

	return "Error: Object " + text + " not found!";
}

QString ObjectTypes::getDescription( int id, Type type )
{
	if( type == All )
		return "Error: Cannot search in all datablocks!";

	ObjectTypeList l = ObjectTypes().typeList();
	for( ObjectTypeListIterator it = l.begin(); it != l.end(); it++ )
		if( (*it).type == type && (*it).id == id )
			return (*it).description;

	return "Error: Object type " + QString::number( id ) + " not found!";
}