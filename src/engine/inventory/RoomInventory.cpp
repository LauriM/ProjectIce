
#include "engine/inventory/RoomInventory.h"

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
		pairVec2 pv = vec2ToPair(position);
		typeItemList * list = itemMap[pv];
		return list;
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
		int itemCount;
		typeMapIterator mapIter;
		for( mapIter = itemMap.begin(); mapIter != itemMap.end(); ++mapIter ) {
			typeItemList * itemList = (*mapIter).second;
			itemCount += itemList->size();
		}
		return itemCount;
	}

	int RoomInventory::getItemCountAtPosition( vec2 position ) {
		pairVec2 pv = vec2ToPair(position);		
		typeItemList * itemList = itemMap[pv];
		if ( itemList ) {
			return itemList->size();
		}
		else {
			return 0;
		}
	}

	bool RoomInventory::addItemToPosition( vec2 position, item::ItemBase * item ) {
		if ( !item || item->getId() < 0 ) {
			return false;
		}

		pairVec2 pv = vec2ToPair(position);
		typeItemList * itemList = itemMap[pv];
		if ( itemList ) {
			itemList->push_back(item);
		}
		else {
			itemList = new typeItemList();
			itemList->push_back(item);
			itemMap.insert( typeItemMap::value_type(pv,itemList) );
		}
		return true;
	}

	bool RoomInventory::deleteItemByPosition( vec2 position, int id ) {
		if ( id < 0 ) {
			return false;
		}
		bool deleted = false;
		pairVec2 pv = vec2ToPair(position);
		typeItemList * itemList = itemMap[pv];
		if ( itemList ) {
			typeItemIterator itemIter = itemList->begin();
			for( itemIter = itemList->begin(); itemIter != itemList->end(); ++itemIter ) {
				if ( (*itemIter)->getId() == id ) {
					itemList->erase( itemIter );
					if ( itemList->size() == 0 ) {
						itemMap.erase(pv);
					}
					deleted = true;
				}
			}
		}
		return deleted;
	}
}
}