#include "precompiled.h"

#include "engine/inventory/ActorInventory.h"

namespace engine {
namespace inventory {

	void ActorInventory::setOwner(actor::ActorBase * actor) {
			owner = actor;
		}

	actor::ActorBase * ActorInventory::getOwner() {
			return owner;
		}

	const tyItemVector ActorInventory::getItemList() {
			return itemList;
		}

	tyItemVector ActorInventory::getItemsByName(const String name) {
		tyItemIterator iter;
		tyItemVector foundItems;
		for( iter = itemList.begin(); iter != itemList.end(); ++iter ) {
			if ( (*iter)->getName().compare(name) == 0 ) {
				foundItems.push_back( (*iter) );
			}
		}
		return foundItems;
	}

	item::ItemBase * ActorInventory::getItemByID(const int id) {
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

	bool ActorInventory::addItem(item::ItemBase * item) {
		// untracked items cannot be added
		if ( item->getId() == -1 ) {
			return false;
		}

		itemList.push_back( item );
		item->setInInventory(true);
		return true;
	}

	tyItemVector ActorInventory::removeItemsByName(const String name) {
		return tyItemVector();
	}

	bool ActorInventory::removeItemByID(const int id) {
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

}
}