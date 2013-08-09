
#include "engine/inventory/RoomInventory.h"

namespace engine {
namespace inventory {

	/*
		Gets the room which owns this inventory
	*/
	world::Room * RoomInventory::getRoomOwner() {
		return roomOwner;
	}

	/* 
		Sets the room which owns this inventory
	*/
	void RoomInventory::setRoomOwner(world::Room * room) {
		roomOwner = room;
	}

	/*
		Adds a new item to a position inside the room
	*/
	void RoomInventory::addItem( vec2 position, item::ItemBase * item ) {
		tyV2Pair pair = convertVec2ToPair(position);
		tyItemVector * itemListAtPos = itemMap[pair];
		if ( !itemListAtPos )
			itemListAtPos = createEmptyVector(pair);
		itemListAtPos->push_back(item);
	}

	/*
		Removes a single item from the world at a given position, also check
		if it's empty we're going to remove the position from the map
	*/
	bool RoomInventory::removeItem( String name, vec2 position ) {
		bool itemFound = false;
		tyV2Pair pair = convertVec2ToPair(position);
		tyItemVector * itemList = itemMap[pair];
		if ( itemList ) {

			for( tyItemIterator ii = itemList->begin(); ii != itemList->end(); ++ii ) {
				item::ItemBase * item = (*ii);
				if ( item->getName() == name ) {
					int position = std::distance( itemList->begin(), ii );
					itemList->erase( itemList->begin() + position );
					itemFound = true;
					break; // exit the loop
				}
			}

			// and now check if the map row is empty and if it is delete it
			if( itemList->size() == 0 ) {
				itemMap.erase(pair); // this position will return NULL now
			}
		}
		return itemFound;
	}

	/*
		Returns the item at the given position
	*/
	tyItemVector * RoomInventory::getItemListByPostition( vec2 position ) {
		tyV2Pair pair = convertVec2ToPair(position);
		return itemMap[pair];
	}

	/*
		Searches if an item by the name exists in the rooms, returns
		the definition. The by reference position will return the key
		of where this item is located in the room
	*/
	item::ItemBase * RoomInventory::searchForItem( String name, vec2 & position ) {
		for( tyMapIterator mi = itemMap.begin(); mi != itemMap.end(); ++mi ) {
			tyItemVector * itemList = (*mi).second;
			for( tyItemIterator ii = itemList->begin(); ii != itemList->end(); ++ii ) {
				item::ItemBase * item = (*ii); // current item being checked
				if ( item->getName() == name ) {
					position = convertPairToVec2( (*mi).first );
					return item;
				}
			}
		}
		return NULL;
	}

	/*
		Creates an empty vector, places it in the map, and returns the pointer
	*/
	tyItemVector * RoomInventory::createEmptyVector(tyV2Pair key) {
		tyItemVector * newVector = new tyItemVector();
		itemMap[key] = newVector;
		return newVector;
	}

	/*
		Converts a vector to a pair to be used for the map since the complier
		doesn't seem to like the vec2 object as a key for the map
	*/
	tyV2Pair RoomInventory::convertVec2ToPair(vec2 value) {
		tyV2Pair newPair;
		newPair.first = value.x;
		newPair.second = value.y;
		return newPair;
	}

	/*
		Converts the pair back to a vector so it can be used elsewhere in the engine
	*/
	vec2 RoomInventory::convertPairToVec2(tyV2Pair pair) {
		vec2 newVec;
		newVec.x = pair.first;
		newVec.y = pair.second;
		return newVec;
	}

}
}