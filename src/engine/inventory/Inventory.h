#ifndef ENGINE_INVENTORY_INVENTORY_H
#define ENGINE_INVENTORY_INVENTORY_H

#include "precompiled.h"

#include "engine/actor/ActorBase.h"
#include "engine/item/ItemBase.h"

#include <vector>

namespace engine {
namespace inventory {

	// Typedefs because long types :(
	typedef std::vector<item::ItemBase*>           itemVector;
	typedef std::vector<item::ItemBase*>::iterator itemIterator;
	
	/**
	 * Actor inventory class. Each inventory contains a list of items (and thus maybe also containers), together a reference to the owner of the inventory.
	 */
	class Inventory {
	private:
		std::vector<item::ItemBase*> itemList;	
		engine::actor::ActorBase* owner;
	public:

		/** Sets the owner of the inventory.
		 *
		 * @param actor The new actor who will own the inventory.
		 */
		void setOwner(actor::ActorBase* actor);

		/** Returns the actor who owns the inventory.
		 *
		 * @returns The actor who owns the inventory.
		 */
		actor::ActorBase* getOwner();

		/** Returns a list of items contained within the inventory.
		 *
		 * @returns A list of items of type std::vector<item::ItemBase*>.
		 */
		const itemVector getItemList();

		/** Find all of the instances of a object by the supplied name and return a vector of those items.
		 *
		 * @param name The name of the item to look for.
		 * @returns A list of items of type std::vector<item::ItemBase*> of the found objects.
		 */
		itemVector getItemsByName(const String name);

		/** Find an item in the inventory by its ID.
		 *
		 * @param id The ID of the item.
		 * @returns A pointer to the item if found, null otherwise.
		 */
		item::ItemBase* getItemByID(const int id);

		/** Adds an item to the inventory.
		 *
		 * @param item The item to add to the inventory.
		 * @returns Whether the item has been added to the invnetory or not.
		 */
		bool addItem(item::ItemBase* item);

		/** Removes all of the items in this inventory that matches a certain name.
		 *
		 * @param name The name of the items to remove.
		 * @returns A vector of ItemBase* which was removed from this inventory.
		 */
		itemVector removeItemsByName(const String name);

		/** Removes a specific instance of an item based on it's ID number.
		 *
		 * @param id The ID of the item to remove.
		 * @returns The item that has been removed, or null if none has been removed at all.
		 */
		item::ItemBase* removeItemByID(const int id);

	};

}
}

#endif
