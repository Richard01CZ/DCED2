#include "Datablock.h"
#include "documentwidget.h"
#include "objectlist.h"
#include "questiondialog.h"
#include "globaldefs.h"
#include "objecttypes.h"

#include <qheader.h>
#include <qinputdialog.h>
#include <qmessagebox.h>
#include <qpopupmenu.h>
#include <qtextstream.h>
#include <qwhatsthis.h>

ObjectTypeTree::ObjectTypeTree( QListView * parent, QString name )
			   : QListViewItem( parent, name )
{
	type = All;
}

ObjectsTree::ObjectsTree( QListView * parent, QString name )
			: ObjectTypeTree( parent, name )
{
	type = Object;
}

QString ObjectsTree::key( int column, bool ascending ) const
{
	return QString( "1" );
}

//-------------------------------------------------------//

ObjectDefinitionsTree::ObjectDefinitionsTree( QListView * parent, QString name )
			: ObjectTypeTree( parent, name )
{
	type = ObjDef;
}

QString ObjectDefinitionsTree::key( int column, bool ascending ) const
{
	return QString( "2" );
}

//-------------------------------------------------------//

InitTree::InitTree( QListView * parent, QString name )
			: ObjectTypeTree( parent, name )
{
	type = Init;
}

QString InitTree::key( int column, bool ascending ) const
{
	return QString( "3" );
}

/************************************************************************/
/*                             ObjectList                               */
/************************************************************************/

ObjectList::ObjectList( QWidget * parent, const char * name )
		: QListView( parent, name )
{

	addColumn( tr( "Name" ), 180 );
	setRootIsDecorated( true );
	setColumnWidthMode( 0, QListView::Maximum );

	objectsTree = new ObjectsTree( this, tr( "Objects" ) );
	objectDefinitionsTree = new ObjectDefinitionsTree( this, tr( "Object Definitions" ) );
	initTree = new InitTree( this, tr( "Init Scripts" ) );
	currentTree = 0;
	editMenu = 0;

	objectGroupList.setAutoDelete( TRUE );
	objdefGroupList.setAutoDelete( TRUE );

	QWhatsThis::add( this,
		"This is the object list where you can view all items inside this mission.<br>"
		"<br>"
		"A Mafia mission file (scene2.bin) consists of three main parts (datablocks):"
		"<ol>"
		"<li>Objects</li>"
		"<li>Object Defininitions</li>"
		"<li>INIT Scripts</li>"
		"</ol>"
		"Usually an object does not contain much information except for a model. Most informations are "
		"inside the same named object definition.<br>"
		"The third datablock consists of scripts which are executed before all other scripts." );

	connect( this, SIGNAL( itemRenamed( QListViewItem *, int ) ), this, SLOT( renameItem( QListViewItem *, int ) ) );
}

QListViewItem * ObjectList::addListItem( QString name, int type, short datablock )
{
	QListViewItem * parentList = 0;
	QListViewItem * groupItem = 0;
	QListViewItem * item;
	QString typeAsText = ObjectTypes::intToText( type, sType2eType( datablock ) );

	//------------------------------------------------------------------//
	if( datablock == NORMAL_MAIN )
	{
		parentList = objectsTree;
		QPtrListIterator<QListViewItem> it( objectGroupList );
		while( it.current() )
		{
			if( it.current()->parent() == parentList
			 && it.current()->text( 0 ) == typeAsText )
			{
				groupItem = it.current();
				break;
			}
			++it;
		}
		if( groupItem == 0)
		{
			groupItem = new QListViewItem( parentList, typeAsText );
			objectGroupList.append( groupItem );
		}
	}
	//------------------------------------------------------------------//
	else if( datablock == SPECIAL_MAIN )
	{
		parentList = objectDefinitionsTree;
		QPtrListIterator<QListViewItem> it( objdefGroupList );
		while( it.current() )
		{
			if( it.current()->parent() == parentList
			 && it.current()->text( 0 ) == typeAsText )
			{
				groupItem = it.current();
				break;
			}
			++it;
		}
		if( groupItem == 0)
		{
			groupItem = new QListViewItem( parentList, typeAsText );
			objdefGroupList.append( groupItem );
		}
	}
	//------------------------------------------------------------------//
	else if( datablock == ADDITIONAL_MAIN )
		groupItem = initTree;
	//------------------------------------------------------------------//
	else
		return 0;

	item = new QListViewItem( groupItem, name, name );
	item->setRenameEnabled( 0, true );
	return item;
}

void ObjectList::contextMenuEvent( QContextMenuEvent * event )
{
	if( itemAt( event->pos() ) == 0 )
	{
		event->accept();
		return;
	}

	if( editMenu != 0 )
		delete editMenu;

	editMenu = new QPopupMenu( this, "editMenu" );
	
	if( currentItem()->parent() ) //Falls das Item ein übergeordnetes Objekt hat
	{
		editMenu->insertItem( tr( "&Rename" ), this, SLOT( startRename() ), QKeySequence( tr( "Ctrl+R", "Rename" ) ), 1 );
		editMenu->insertItem( tr( "&Delete" ), this, SLOT( deleteItem() ), QKeySequence( Key_Delete ), 2 );
		editMenu->insertItem( tr( "D&uplicate"), this, SLOT( duplicateItem() ), QKeySequence( tr( "Ctrl+D", "Duplicate") ), 3);
		if( getItemDatablock() == Object )
		{
			editMenu->insertSeparator();
			editMenu->insertItem( tr( "Switch to Object Definition" ), this, SLOT( switchToFriendItem() ), QKeySequence( tr( "Ctrl+S", "Switch to Friend Object" ) ), 4 );
		}
		else if( getItemDatablock() == ObjDef )
		{
			editMenu->insertSeparator();
			editMenu->insertItem( tr( "Switch to Object" ), this, SLOT( switchToFriendItem() ), QKeySequence( tr( "Ctrl+S", "Switch to Friend Object" ) ), 5 );
		}
		editMenu->insertSeparator();
	}
	editMenu->insertItem( tr( "Objects" ), this, SLOT( switchToObjects() ), QKeySequence( tr( "Ctrl+O", "Switch to Objects" ) ), 6 );
	editMenu->insertItem( tr( "Object Definitions" ), this, SLOT( switchToObjectDefinitions() ), QKeySequence( tr( "Ctrl+D", "Switch to Object Definitions" ) ), 7 );
	editMenu->insertItem( tr( "Init Scripts" ), this, SLOT( switchToInitScripts() ), QKeySequence( tr( "Ctrl+I", "Switch to Init Scripts" ) ), 8 );
	editMenu->move( event->globalPos() );
	editMenu->show();
	event->accept();
}

void ObjectList::deleteItem()
{
	QListViewItem * item = currentItem();
	QListViewItem * parentItem = item->parent();

	if( !isObjectItem( item ) )
		return;
	
	bool askAgain = settings->readBoolEntry( "ask_again/delete", TRUE );
	if( askAgain == FALSE || QuestionDialog::question( this, "Delete this object?",
						"Are you sure that you want to delete this object?", askAgain ) == QDialog::Accepted )
	{
		settings->writeEntry( "ask_again/delete", askAgain );

		sceneWrapper->DeleteObject( item->text( 0 ), eType2sType( getItemDatablock() ) );
		delete item;
		status_bar->message( tr( "Object deleted." ), 5000 );
	};

	if( parentItem->childCount() == 0 )
	{
		switch( getItemDatablock( parentItem ) )
		{
		case Object:
			objectGroupList.remove( parentItem );
			break;
		case ObjDef:
			objdefGroupList.remove( parentItem );
		}
	};
}

void ObjectList::duplicateItem()
{
	QListViewItem * item = currentItem();
	bool ok;
	bool e = true;
	QString objectName;
	while( e )
	{
		objectName = QInputDialog::getText( tr( "Duplicate Object" ),
						tr( "Please enter the name of the new object:" ),
						QLineEdit::Normal, item->text( 0 ), &ok, this );
		if( !ok )
			return;
		e = exists( item->parent(), objectName );
	}

	sceneWrapper->DuplicateObject( item->text( 0 ), objectName, eType2sType( getItemDatablock( item ) ) );

	item = new QListViewItem( item->parent(), objectName, objectName );
	item->setRenameEnabled( 0, true );
}

bool ObjectList::exists( QListViewItem * parentItem, QString col0 )
{
	QListViewItemIterator it( this );
	while( it.current() )
	{
		if( it.current()->text( 0 ).lower() == col0.lower()
		 && it.current()->parent() == parentItem )
			return true;
		++it;
	}
	return false;
}

bool ObjectList::exists( short datablock, QString name )
{
	QListViewItemIterator it( this );
	Type type = sType2eType( datablock );
	while( it.current() )
	{
		if( it.current()->text( 0 ).lower() == name.lower() && getItemDatablock( it.current() ) == type )
			return true;
		++it;
	}
	return false;
}

bool ObjectList::existsTwice( QListViewItem * item )
{
	QListViewItemIterator it( this );
	while( it.current() )
	{
		if( it.current() != item
		 && it.current()->text( 0 ).lower() == item->text( 0 ).lower()
		 //&& it.current()->text( 1 ) == item->text( 1 )
		 && it.current()->parent() == item->parent() )
			return true;
		++it;
	}
	return false;
}

ObjectTypeTree * ObjectList::getDatablockItem( Type datablock )
{
	if( datablock == Object )
		return objectsTree;
	else if( datablock == ObjDef )
		return objectDefinitionsTree;
	else if( datablock == Init )
		return initTree;
	else return 0;
}

Type ObjectList::getItemDatablock( QListViewItem * item /* = 0 */ )
{
	if( item == 0 )
		item = currentItem();

	QListViewItem * parentItem = item;
	while( parentItem )
	{
		if( parentItem->parent() )
			parentItem = parentItem->parent();
		else
			break;
	}
	return ((ObjectTypeTree *)parentItem)->type;
}

int ObjectList::getItemGroup( QListViewItem * item /* = 0  */)
{
	if( item == 0 )	item = currentItem();
	if( !item->parent() ) return -1;
	if( getItemDatablock( item ) == Init ) return 155;

	int itemGroup = ObjectTypes::textToInt( item->parent()->text( 0 ), getItemDatablock( item ) );
	return itemGroup;
}

void ObjectList::insertListItem( QString name, int type, short datablock )
{
	QListViewItem * item;
	bool ex = true; //exists
	bool ok;
	while( ex )
	{
		ex = exists( datablock, name );
		if( !ex )
		{
			item = addListItem( name, type, datablock );
			ensureItemVisible( item );
			setCurrentItem( item );
			emit clicked( item );
		}
		else
		{
			name = QInputDialog::getText( tr( "Object Name" ), tr( "Please enter a name for the object that isn't used yet" ),
								   QLineEdit::Normal, name, &ok, this );
			if( !ok )
				return;
		}
	}
}

bool ObjectList::isObjectItem( QListViewItem * item /* = 0 */ )
{
	if( item == 0 )
		item = currentItem();

	if( item->parent() )
		if( item->parent()->parent() )
			return true;
		else if( getItemDatablock( item ) == Init )
			return true;
		else
			return false;
	else
		return false;
}

void ObjectList::keyPressEvent(	QKeyEvent *e )
{
	if( e->key() == Key_Delete )
		deleteItem();
	else
		QListView::keyPressEvent( e );
}

void ObjectList::quickSearch( const QString & text )
{
	QListViewItemIterator it( this );
	while( it.current() )
	{
		if( it.current()->text( 0 ).lower().startsWith( text.lower() ) )
		{
			this->setSelected( it.current(), TRUE );
			ensureItemVisible( it.current() );
			return;
		}
		++it;
	}
}

void ObjectList::renameItem( QListViewItem * item, int col )
{
	if( existsTwice( item ) )
	{
		startRename();
		return;
	}
	else
	{
		emit itemRenamed( item->text( 0 ), item->text( 1 ), getItemDatablock( item ) );
		item->setText( 1, item->text( 0 ) );
	}
}

void ObjectList::reset()
{
	objectGroupList.clear();
	objdefGroupList.clear();
	QListView::clear();
	objectsTree = new ObjectsTree( this, tr( "Objects" ) );
	objectDefinitionsTree = new ObjectDefinitionsTree( this, tr( "Object Definitions" ) );
	initTree = new InitTree( this, tr( "Init Scripts" ) );
	currentTree = 0;
	editMenu = 0;
}

void ObjectList::startRename()
{
	currentItem()->startRename( 0 );
}

void ObjectList::switchToFriendItem()
{
	if( getItemGroup() == -1 );

	QListViewItem * itemParent;
	if( getItemDatablock() == Object )
		itemParent = objectDefinitionsTree;
	else
		itemParent = objectsTree;

	for( QListViewItemIterator it( itemParent ); it.current(); it++ )
		if( it.current()->text( 0 ) == currentItem()->text( 0 ) )
		{
			setCurrentItem( it.current() );
			emit clicked( it.current() );
			ensureItemVisible( it.current() );
			return;
		}
}

void ObjectList::switchToInitScripts()
{
	setCurrentItem( initTree->firstChild() );
	ensureItemVisible( initTree );
	ensureItemVisible( initTree->firstChild() );
}
void ObjectList::switchToObjectDefinitions()
{
	setCurrentItem( objectDefinitionsTree->firstChild() );
	ensureItemVisible( objectDefinitionsTree );
	ensureItemVisible( objectDefinitionsTree->firstChild() );
}
void ObjectList::switchToObjects()
{
	setCurrentItem( objectsTree->firstChild() );
	ensureItemVisible( objectsTree );
	ensureItemVisible( objectsTree->firstChild() );
}
