#ifndef ENGINE_INVENTORY_INVENTORY_H
#define ENGINE_INVENTORY_INVENTORY_H

#include "precompiled.h"

#include "engine/actor/ActorBase.h"
#include "engine/item/ItemBase.h"

#include <vector>

namespace engine {
namespace inventory {

	/**
	* typedef'd the vector so I don't have to look at ::<><>:::><><>
	*/
	typedef std::vector<item::ItemBase*>           itemVector;
	typedef std::vector<item::ItemBase*>::iterator itemIterator;
	
	class ActorInventory {
	private:
		std::vector<item::ItemBase*> itemList;	
		engine::actor::ActorBase * owner;
	public:

		/** Sets the owner of this inventory
		 * @param actor the actor who owns this inventory
		 */
		void setOwner(actor::ActorBase * actor);

		/** Returns the actor who owns this inventory
		 * @returns the actor who owns this inventory
		 */
		actor::ActorBase * getOwner();

		/** Returns an unchangable list of the items contained with this inventory object
		 * @returns a list of items of std::vector<item::ItemBase*>
		 */
		const itemVector getItemList();

		/** Find all of the instances of a object by the supplied name and return a vector of those items
		 * @param name the name of the item to look for
		 * @returns a vector of ItemBase* to the instances of the found object
		 */
		itemVector getItemsByName(const String name);

		/** Find all of the instances of a object by the supplied name and return a vector of those items
		 * @param name the name of the item to look for
		 * @returns a vector of ItemBase* to the instances of the found object
		 */
		item::ItemBase * getItemByID(const int id);

		/** Adds a tracked item to the inventory
		 * @param item the ItemBase in which to add
		 * @returns boolean indication whether the item was added or not
		 */
		bool addItem(item::ItemBase * item);

		/** Removes all of the items in this inventory that match a certain name
		 * @param name the name of the item to look for
		 * @returns a vector of ItemBase* which was removed from this inventory
		 */
		itemVector removeItemsByName(const String name);

		/** Removes a specific instance of an item based on it's ID number
		 * @param name the name of the item to look for
		 * @returns a boolean indication whether it was removed or not
		 */
		bool removeItemByID(const int id);

	};

}
}

#endif
