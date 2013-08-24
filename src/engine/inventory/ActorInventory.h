
#ifndef __ACTOR_INVENTORY_H__
#define __ACTOR_INVENTORY_H__

#include "precompiled.h"

#include "engine/actor/ActorBase.h"
#include "engine/item/ItemBase.h"

#include <vector>

namespace engine {
namespace inventory {

	/**
	* typedef'd the vector so I don't have to look at ::<><>:::><><>
	*/
	typedef std::vector<item::ItemBase*>           tyItemVector;
	typedef std::vector<item::ItemBase*>::iterator tyItemIterator;
	
	class ActorInventory {
	private:
		std::vector<item::ItemBase*> itemList;	
		engine::actor::ActorBase * owner;
	public:

		/** Sets the owner of this inventory
		 * @param actor the actor who owns this inventory
		 */
		void setOwner(actor::ActorBase * actor) {
			owner = actor;
		}

		/** Returns the actor who owns this inventory
		 * @returns the actor who owns this inventory
		 */
		actor::ActorBase * getOwner() {
			return owner;
		}

		/** Returns an unchangable list of the items contained with this inventory object
		 * @returns a list of items of std::vector<item::ItemBase*>
		 */
		const tyItemVector getItemList() {
			return itemList;
		}

		/** Find all of the instances of a object by the supplied name and return a vector of those items
		 * @param name the name of the item to look for
		 * @returns a vector of ItemBase* to the instances of the found object
		 */
		tyItemVector getItemsByName(String name) {
			tyItemIterator iter;
			tyItemVector foundItems;
			for( iter = itemList.begin(); iter != itemList.end(); ++iter ) {
				if ( (*iter)->getName().compare(name) == 0) {
					foundItems.push_back( (*iter) );
				}
			}
			return foundItems;
		}

		/** Find all of the instances of a object by the supplied name and return a vector of those items
		 * @param name the name of the item to look for
		 * @returns a vector of ItemBase* to the instances of the found object
		 */
		item::ItemBase * getItemByID( int id ) {
			item::ItemBase * returnItem = NULL;
			tyItemIterator iter;
			for( iter = itemList.begin(); iter != itemList.end(); ++iter ) {
				if ( (*iter)->getId() == id ) {
					returnItem = (*iter);
					break;
				}
			}
			return returnItem;
		}

		/** Adds a tracked item to the inventory
         * @param item the ItemBase in which to add
         * @returns boolean indication whether the item was added or not
		 */
		bool addItem(item::ItemBase * item) {
			// untracked items cannot be added
			if ( item->getId() == -1 ) {
				return false;
			}

			itemList.push_back( item );
			item->setInInventory(true);
			return true;
		}

		/** Removes all of the items in this inventory that match a certain name
		 * @param name the name of the item to look for
		 * @returns a vector of ItemBase* which was removed from this inventory
		 */
		tyItemVector removeItemsByName(String name) {
			return tyItemVector();
		}

		/** Removes a specific instance of an item based on it's ID number
		 * @param name the name of the item to look for
		 * @returns a boolean indication whether it was removed or not
		 */
		bool removeItemByID(int id) {
			if ( id < 0 ) { // ids less than 0 (-1) indicate untracked item, it can't be here anyway
				return false;
			}

			tyItemIterator iter;
			for( iter = itemList.begin(); iter != itemList.end(); ++iter ) {
				if ( (*iter)->getId() == id ) {
					iter = itemList.erase(iter);
					(*iter)->setInInventory(false);
					return true;
				}
			}
			return false;
		}

	};

}
}

#endif