#include "precompiled.h"

#include "engine/inventory/Inventory.h"
#include "engine/item/ItemBase.h"

namespace engine {
namespace inventory {

	const std::vector<item::ItemBase*> Inventory::getItemList() {
		return itemList;
	}

	Inventory::ItemVector Inventory::getItemsByName(const String name) {
		std::vector<item::ItemBase*> foundItems;

		for( auto iter = itemList.begin(); iter != itemList.end(); ++iter ) {
			if ( (*iter)->getName().compare(name) == 0 ) {
				foundItems.push_back( (*iter) );
			}
		}

		return foundItems;
	}

	item::ItemBase* Inventory::getItemByID(const int id) {
		item::ItemBase* returnItem = NULL;

		for( auto iter = itemList.begin(); iter != itemList.end(); ++iter ) {
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

	Inventory::ItemVector Inventory::removeItemsByName(const String name) {
		std::vector<item::ItemBase*> foundItems;

		for( auto iter = itemList.begin(); iter != itemList.end(); ++iter ) {
			if ( (*iter)->getName().compare(name) == 0 ) {
				item::ItemBase* item = (*iter);

				item->setInInventory(false);
				iter = itemList.erase(iter);

				foundItems.push_back( item );
			}
		}

		return foundItems;
	}

	item::ItemBase* Inventory::removeItemByID(const int id) {
		if ( id < 0 ) { // ids less than 0 (-1) indicate untracked item, it can't be here anyway
			return NULL;
		}

		for( auto iter = itemList.begin(); iter != itemList.end(); ++iter ) {
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
