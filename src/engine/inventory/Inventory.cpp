#include "precompiled.h"

#include "engine/inventory/Inventory.h"

namespace engine {
namespace inventory {

	void Inventory::setOwner(actor::ActorBase* actor) {
		owner = actor;
	}

	actor::ActorBase* Inventory::getOwner() {
		return owner;
	}

	const itemVector Inventory::getItemList() {
		return itemList;
	}

	itemVector Inventory::getItemsByName(const String name) {
		itemIterator iter;
		itemVector foundItems;

		for( iter = itemList.begin(); iter != itemList.end(); ++iter ) {
			if ( (*iter)->getName().compare(name) == 0 ) {
				foundItems.push_back( (*iter) );
			}
		}

		return foundItems;
	}

	item::ItemBase* Inventory::getItemByID(const int id) {
		item::ItemBase* returnItem = NULL;
		itemIterator iter;

		for( iter = itemList.begin(); iter != itemList.end(); ++iter ) {
			if ( (*iter)->getId() == id ) {
				returnItem = (*iter);
				break;
			}
		}

		return returnItem;
	}

	bool Inventory::addItem(item::ItemBase* item) {
		// untracked items cannot be added
		if ( item->getId() == -1 ) {
			return false;
		}

		itemList.push_back( item );
		item->setInInventory(true);
		return true;
	}

	itemVector Inventory::removeItemsByName(const String name) {
		return itemVector();
	}

	item::ItemBase* Inventory::removeItemByID(const int id) {
		if ( id < 0 ) { // ids less than 0 (-1) indicate untracked item, it can't be here anyway
			return NULL;
		}

		itemIterator iter;

		for( iter = itemList.begin(); iter != itemList.end(); ++iter ) {
			if ( (*iter)->getId() == id ) {
				item::ItemBase* item = (*iter);

				item->setInInventory(false);
				iter = itemList.erase(iter);

				return item;
			}
		}

		return NULL;
	}

}
}