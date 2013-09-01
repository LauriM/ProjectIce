#include "precompiled.h"
#include "engine/inventory/RoomInventory.h"

#include <string>

namespace engine {
namespace inventory {

	ItemList * RoomInventory::initEmptyList( vec2 key ) {
		ItemList * newList = new ItemList();
		itemMap[key] = newList;
		return newList;
	}

	// --- PUBLIC --- //

	RoomInventory::RoomInventory( world::Room * owner ) {
		this->owner = owner;
	}

	ItemMap RoomInventory::getItemMap() {
		return itemMap;
	}

	ItemList * RoomInventory::getItemMapAsList() {
		MapIterator mapIter;
		ItemList * list = new ItemList();
		for( mapIter = itemMap.begin(); mapIter != itemMap.end(); ++mapIter ) {
			ItemList * itemList = (*mapIter).second;
			ItemIterator itemIter;
			for( itemIter = itemList->begin(); itemIter != itemList->end(); ++itemIter ) {
				list->push_back( (*itemIter) );
			}
		}
		return list;
	}

	ItemList * RoomInventory::getItemListByPosition( vec2 position ) {
		MapIterator it = itemMap.find( position );
		if ( it != itemMap.end() ) {
			return (*it).second;
		}
		return NULL;
	}

	item::ItemBase * RoomInventory::getItemByID(int id) {
		MapIterator mapIter;
		for( mapIter = itemMap.begin(); mapIter != itemMap.end(); ++mapIter ) {
			ItemList * itemList = (*mapIter).second;
			ItemIterator itemIter;
			for( itemIter = itemList->begin(); itemIter != itemList->end(); ++itemIter ) {
				if ( (*itemIter)->getId() == id ) {
					return (*itemIter);
				}
			}
		}
		return NULL;
	}

	ItemList * RoomInventory::getItemListByName( String name ) {
		MapIterator mapIter;
		ItemList * foundList = new ItemList();
		for( mapIter = itemMap.begin(); mapIter != itemMap.end(); ++mapIter ) {
			ItemList * itemList = (*mapIter).second;
			ItemIterator itemIter;
			for( itemIter = itemList->begin(); itemIter != itemList->end(); ++itemIter ) {
				if ( (*itemIter)->getName() == name ) {
					foundList->push_back( (*itemIter) );
				}
			}
		}
		return foundList;
	}

	int RoomInventory::getItemCount() {
		int itemCount = 0;
		MapIterator mapIter;
		for( mapIter = itemMap.begin(); mapIter != itemMap.end(); ++mapIter ) {
			ItemList * itemList = (*mapIter).second;
			itemCount += itemList->size();
		}
		return itemCount;
	}

	int RoomInventory::getItemCountAtPosition( vec2 position ) {
		ItemList * itemList = getItemListByPosition(position);
		MapIterator it = itemMap.find( position );
		if ( it != itemMap.end() ) {
			return itemList->size();
		}
		else {
			return 0;
		}
	}

	bool RoomInventory::addItemToPosition( vec2 position, item::ItemBase * item ) {
		// check first to make sure item is bound and it's tracked by the engine
		if ( !item || item->getId() < 0 ) {
			return false;
		}

		// check also to make sure this item instance isn't avaliable in the room already
		if ( getItemByID( item->getId() ) ) {
			return false;
		}

		MapIterator it = itemMap.find( position );
		ItemList * itemList = NULL;
		if ( it == itemMap.end() ) {
			itemList = new ItemList();
			itemMap[position] = itemList;
		}
		else {
			itemList = (*it).second;
		}
		itemList->push_back( item );
		item->setInInventory(true);
		return true;
	}

	bool RoomInventory::deleteItemByPosition( vec2 position, int id ) {
		if ( id < 0 ) {
			return false;
		}
		bool deleted = false;
		ItemList * itemList = itemMap.find( position )->second;
		if ( itemList ) {
			ItemIterator itemIter = itemList->begin();
			for( itemIter = itemList->begin(); itemIter != itemList->end(); ++itemIter ) {
				if ( (*itemIter)->getId() == id ) {
					itemList->erase( itemIter );
					if ( itemList->size() == 0 ) {
						itemMap.erase( position );
					}
					(*itemIter)->setInInventory(false);
					deleted = true;
				}
			}
		}
		return deleted;
	}
}
}
