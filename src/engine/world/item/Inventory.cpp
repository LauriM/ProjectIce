
#include "engine/world/item/Inventory.h"

namespace engine {
namespace world {
namespace item {

	// initialize an inventory with a pointer that tells us
	// who the inventory belongs too so we can perform
	// actions on the player
	void Inventory::init( player::Player * owner )
	{
		_playerOwner = owner;
	}

	// Deletes the item from existance completely, not accessible
	// anywhere, because of the delete
	bool Inventory::destroyItem(String name) {
		BaseItem * item = _inventoryMap[name];
		bool destroyed = false;
		if ( item )
		{
			item->onDestroy(_playerOwner);
			_inventoryMap.erase(name);
			delete item;
			destroyed = true;
		}
		return destroyed;
	}

	// Removes the item from the player map and returns
	// and instance of the object
	BaseItem * Inventory::dropItem(String name) {
		BaseItem * item = _inventoryMap[name];
		if ( item )
		{
			item->onDrop(_playerOwner);
			_inventoryMap.erase(name);
		}
		return item;
	}

	// You can use items! Define the effect in the individual items.
	bool Inventory::useItem(String name) {
		BaseItem * item = _inventoryMap[name];
		bool used = false;
		if ( item && item->getQuantity() > 0 )
		{
			item->onUse(_playerOwner);
			used = true;
		}
		return used;
	}

	// TODO Add some weight checking, or max inventory count or something later.
	bool Inventory::insertItem(BaseItem * item) {
		bool inserted = false;
		if ( item ) {
			BaseItem * myItem = _inventoryMap[item->getName()]; // Checking if an entry exists
			if ( myItem ) {
				myItem->setQuantity( myItem->getQuantity() + item->getQuantity() );
			}
			else {
				_inventoryMap[item->getName()] = item;
			}
			item->onPickup(_playerOwner);
			inserted = true;
		}
		return inserted;

	}

	// I imagine this one will be used in a window or something, lets discuss how to handle this
	bool Inventory::inspectItem(String name) {
		BaseItem * item = _inventoryMap[name];
		bool inspected = false;
		if ( item )
		{
			item->onInspect(_playerOwner);
			inspected = true;
		}
		return inspected;
	}

}
}
}
