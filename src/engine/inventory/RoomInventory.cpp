#include "precompiled.h"
#include "engine/inventory/RoomInventory.h"

#include <string>

namespace engine {
namespace inventory {
	
	vec2 RoomInventory::pairToVec2( pairVec2 pair ) {
		vec2 newVec;
		newVec.x = pair.first;
		newVec.y = pair.second;
		return newVec;
	}
	
	pairVec2 RoomInventory::vec2ToPair( vec2 vec ) {
		pairVec2 newPair;
		newPair.first = vec.x;
		newPair.second = vec.y;
		return newPair;
	}

	typeItemList * RoomInventory::initEmptyList( pairVec2 key ) {
		typeItemList * newList = new typeItemList();
		itemMap[key] = newList;
		return newList;
	}

	// --- PUBLIC --- //

	RoomInventory::RoomInventory( world::Room * owner ) {
		this->owner = owner;
	}

	typeItemMap RoomInventory::getItemMap() {
		return itemMap;
	}

	typeItemList * RoomInventory::getItemMapAsList() {
		typeMapIterator mapIter;
		typeItemList * list = new typeItemList();
		for( mapIter = itemMap.begin(); mapIter != itemMap.end(); ++mapIter ) {
			typeItemList * itemList = (*mapIter).second;
			typeItemIterator itemIter;
			for( itemIter = itemList->begin(); itemIter != itemList->end(); ++itemIter ) {
				list->push_back( (*itemIter) );
			}
		}
		return list;
	}	

	typeItemList * RoomInventory::getItemListByPosition( vec2 position ) {
		typeMapIterator it = itemMap.find( vec2ToPair(position) );
		if ( it != itemMap.end() ) {
			return (*it).second;
		}
		return NULL;
	}

	item::ItemBase * RoomInventory::getItemByID(int id) {
		typeMapIterator mapIter;
		for( mapIter = itemMap.begin(); mapIter != itemMap.end(); ++mapIter ) {
			typeItemList * itemList = (*mapIter).second;
			typeItemIterator itemIter;
			for( itemIter = itemList->begin(); itemIter != itemList->end(); ++itemIter ) {
				if ( (*itemIter)->getId() == id ) {
					return (*itemIter);
				}
			}
		}
		return NULL;
	}

	typeItemList * RoomInventory::getItemListByName( String name ) {
		typeMapIterator mapIter;
		typeItemList * foundList = new typeItemList();
		for( mapIter = itemMap.begin(); mapIter != itemMap.end(); ++mapIter ) {
			typeItemList * itemList = (*mapIter).second;
			typeItemIterator itemIter;
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
		typeMapIterator mapIter;
		for( mapIter = itemMap.begin(); mapIter != itemMap.end(); ++mapIter ) {
			typeItemList * itemList = (*mapIter).second;
			itemCount += itemList->size();
		}
		return itemCount;
	}

	int RoomInventory::getItemCountAtPosition( vec2 position ) {	
		typeItemList * itemList = getItemListByPosition(position);
		typeMapIterator it = itemMap.find( vec2ToPair(position) );
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

		pairVec2 pv = vec2ToPair(position);
		typeMapIterator it = itemMap.find(pv);
		typeItemList * itemList = NULL;
		if ( it == itemMap.end() ) {
			itemList = new typeItemList();
			itemMap[pv] = itemList;
		}
		else {
			itemList = (*it).second;
		}
		itemList->push_back( item );
		item->setInInventory(true);
		return true;
		//if ( itemIter->second ) {
		//typeItemList * itemList = ( itemMap.find(pv) ? itemMap.find(pv)->second, NULL );
		//if ( itemIter->second ) {
		//	itemIter->second->push_back(item);
		//}
		//else {
		//	typeItemList * itemList = initEmptyList(pv);
		//	itemList->push_back(item);
		//}
		//return true;
	}

	bool RoomInventory::deleteItemByPosition( vec2 position, int id ) {
		if ( id < 0 ) {
			return false;
		}
		bool deleted = false;
		pairVec2 pv = vec2ToPair(position);
		typeItemList * itemList = itemMap.find(pv)->second;
		if ( itemList ) {
			typeItemIterator itemIter = itemList->begin();
			for( itemIter = itemList->begin(); itemIter != itemList->end(); ++itemIter ) {
				if ( (*itemIter)->getId() == id ) {
					itemList->erase( itemIter );
					if ( itemList->size() == 0 ) {
						itemMap.erase(pv);
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