
#ifndef __ITEM_MANAGER_H__
#define __ITEM_MANAGER_H__

#include "engine/item/ItemBase.h"

#include <vector>

namespace engine {
namespace item {
	
	/*
		The master, slaver owner, head hancho, the Item Manager

		This object is responsible for overseeing that item instances
		are assigned to a unique identifier so that there isn't confusing
		between an item definition and an item instance

		Items should be created via the ItemManager if they need to be
		tracked by the engine
	*/
	class ItemManager {
	private:

		// The ID number that was last given out
		// used only internally, this isn't a reliable indicator
		// of the size anyway because items can be unregistered
		// So this is pretty much the last used NON-RECYCLED number tracked
		int lastUsedID;

		// I'm going to keep track of ID's of the items that have
		// since been unregistered so I can recycle them
		std::vector<int> deletedIDs;

		// The count of active items in use by the engine
		int activeItems;

		// This object is a singleton so we'll have a static instance
		// which is valid program wide
		static ItemManager * instance;		

		// The item is registered as an in use id, lastUsedID is used if
		// deletedIDs is empty, otherwise get the first index out of 
		// there
		void regItem( ItemBase * b ) {
			// situation 1, left over ID's get recycled if they exist 
			if ( deletedIDs.size() > 0 ) {
				b->id = deletedIDs.at(0);
				deletedIDs.erase( deletedIDs.begin() );
				activeItems++;
			} else {
				lastUsedID++;
				b->id = lastUsedID;
				activeItems++;
			}
		}

		// The ID that belongs to this item is added to the deletedID's
		void unregItem( ItemBase * b ) {
			if ( b->getId() <= lastUsedID ) {
				deletedIDs.push_back( b->getId() );
				b->id = -1; // not tracked
				activeItems--;
			}
		}

		// I don't want anybody else recreating the instance of an Item Manager
		ItemManager() {
			lastUsedID = -1;
			activeItems = 0;
		}

	public:

		// This object is a singleton, if the object doesn't exist make it
		// if it does exist, return it
		static ItemManager * getInstance() {
			if ( !instance ) {
				instance = new ItemManager();
			}
			return instance;
		}

		// If the item already has an ID than return false otherwise
		// give it an ID and return that it went ok
		bool trackItem(ItemBase * b) {
			bool assigned = false;
			if ( b->getId() == -1 ) { // -1, no unique ID assigned
				regItem(b);
				assigned = true;
			}
			return assigned;
		}

		// make sure the id is being tracked and if so unassign it
		// and rest the item id back to -1
		bool untrackItem(ItemBase * b) {
			if ( b->id == -1 || b->id > lastUsedID ) {
				return false;
			}

			std::vector<int>::iterator iter;
			for ( iter = deletedIDs.begin(); iter != deletedIDs.end(); ++iter ) {
				if ( (*iter) == b->id ) {
					return false;
				}
			}

			unregItem(b);
			return true;
		}

		// Conditions checked to ensure no false-positive:
		//  1. Is the ID less than or equal too the last used ID so that it can be in range
		//     -> Yes, goto step 2
		//     -> No, not tracked, return false
		//  2. If the id found in the deleted id list?
		//     -> Yes, return false, it's not tracked
		//     -> No, not tracked, return false
		//  3. If the id is within range and not in the unused list
		//     -> It's tracked
		bool isIDTracked(int id) {
			if( id == -1 )
				return false;
			
			bool tracked = false;
			if( id <= lastUsedID ) {
				std::vector<int>::iterator iter;
				for( iter = deletedIDs.begin(); iter != deletedIDs.end(); ++iter ) {
					if ( (*iter) == id ) {
						return tracked;
					}
				}
				tracked = true;
			}
			return tracked;
		}

		// Returns the number of items that are actively being managed
		// engine wide, not just including your room
		int getActiveItemCount() {
			return activeItems;
		}

	};

engine::item::ItemManager * engine::item::ItemManager::instance = NULL;

}
}

#endif