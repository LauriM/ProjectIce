#ifndef __ROOM_INVENTORY_H__
#define __ROOM_INVENTORY_H__

#include "precompiled.h"

#include "engine/item/ItemBase.h"
#include "engine/math/vec2.h"
#include "engine/world/Room.h"

#include <map>
#include <vector>
#include <iterator>

namespace engine {
namespace inventory {

	typedef std::pair<int,int> tyV2Pair;
	typedef std::vector<item::ItemBase*> tyItemVector;
	typedef std::vector<item::ItemBase*>::iterator tyItemIterator;
	typedef std::map< tyV2Pair, tyItemVector* > tyItemMap;
	typedef std::map< tyV2Pair, tyItemVector* >::iterator tyMapIterator;

	class RoomInventory {
	private:
		tyItemMap itemMap; // a map of vectors of ItemBase*
		world::Room * roomOwner;

		tyItemVector * findItemVector(vec2 key);
		tyItemVector * createEmptyVector(tyV2Pair key);
		tyV2Pair convertVec2ToPair(vec2 value);
		vec2 convertPairToVec2(tyV2Pair pair);

	public:

		/*
			Get the owner room of this inventory
		*/
		world::Room * getRoomOwner();

		/*
			Sets the room which owns this inventory
		*/
		void setRoomOwner(world::Room * room);

		/*
			Adds a new item to a position inside the room
		*/
		void addItem( vec2 position, item::ItemBase * item );

		/*
			Removes a single item from the world at a given position
		*/
		bool removeItem( String name, vec2 position );

		/*
			Counts the number of a type of item at a position
		*/
		int getItemCountAtPosition( vec2 position, String );

		/*
			Counts the total number of items at a position
		*/
		int getTotalItemCountAtPosition( vec2 position );

		/*
			Returns the item at the given position
		*/
		tyItemVector * getItemListByPosition( vec2 position );

		/*
			Returns an item at a given position
		*/
		item::ItemBase * getItemByPosition( vec2 position, String name );

		/*
			Searches if an item by the name exists in the rooms, returns
			the definition. The by reference position will return the key
			used in the map
		*/
		item::ItemBase * searchForItem( String name, vec2 * position = 0);

		/*
		    Just give the full list of items
		*/
		tyItemVector getAllItems();

	};

}
}

#endif
