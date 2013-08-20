
#ifndef __ITEM_MANAGER_H__
#define __ITEM_MANAGER_H__

#include "engine/item/ItemBase.h"

#include <vector>

namespace engine {
namespace item {
	
	/**
	 *	The master, slaver owner, head hancho, the Item Manager
     *
	 *	This object is responsible for overseeing that item instances
	 *	are assigned to a unique identifier so that there isn't confusing
	 *	between an item definition and an item instance
     *
	 *	Items should be created via the ItemManager if they need to be
	 *	tracked by the engine
	 */
	class ItemManager {
	private:

		int lastUsedID;

		std::vector<int> deletedIDs;

		int activeItems;

		static ItemManager * instance;		

		/** registers an item modifying the object internal values
		 * @param b the item instance to register
		*/
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

		/** unregisters an item modifying the object internal values
		 * @param b the item instance to unregister
		*/
		void unregItem( ItemBase * b ) {
			if ( b->getId() <= lastUsedID ) {
				deletedIDs.push_back( b->getId() );
				b->id = -1; // not tracked
				activeItems--;
			}
		}

		/** Constructor sets the ItemManager to it's initial empty state
		*/
		ItemManager() {
			lastUsedID = -1;
			activeItems = 0;
		}

	public:

		/** Returns a singleton instance of the ItemManager so it can be used engine/game wide
		 *	@returns the static instance of ItemManager
		*/
		static ItemManager * getInstance() {
			if ( !instance ) {
				instance = new ItemManager();
			}
			return instance;
		}

		/** Registers an item (by identification number) to be tracked by the engine
		 *	@param b the item instance
		 *	@returns true if the item was able to be tracked, false if not able to track
		*/
		bool trackItem(ItemBase * b) {
			bool assigned = false;
			if ( b->getId() == -1 ) { // -1, no unique ID assigned
				regItem(b);
				assigned = true;
			}
			return assigned;
		}

		/** Removes an item identification number from being tracked by the engine
		 *	@param b the item instance
		 *	@returns true if the item is no longer tracked, false if not able to untrack item
		*/
		bool untrackItem(ItemBase * b) {
			if ( b->id == -1 || b->id > lastUsedID || b->getInInventory() ) {
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

		/** Checks to see if the identification number is being tracked by the engine
		 *	@param id the item identification number
		 *	@returns Whether or not the identification number is tracked by the engine
		*/
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

		/** Tells us how many items this manager is tracking
		 *	@returns engine active item count
		*/
		int getActiveItemCount() {
			return activeItems;
		}

	};

engine::item::ItemManager * engine::item::ItemManager::instance = NULL;

}
}

#endif