
#ifndef __ACTOR_INVENTORY_H__
#define __ACTOR_INVENTORY_H__

#include "precompiled.h"

#include "engine/actor/ActorBase.h"
#include "engine/item/ItemBase.h"

#include <vector>

namespace engine {
namespace inventory {
	
	class ActorInventory {
	private:
		std::vector<item::ItemBase*> itemList;	
		engine::actor::ActorBase * owner;
	public:

		/*
			Kinda explains itself
		*/
		void setOwner(actor::ActorBase * actor) {
			owner = actor;
		}

		/*
			To see which actor this instance belongs too
		*/
		engine::actor::ActorBase * getOwner() {
			return owner;
		}

		/* 
			Well if you must you can look but you can't touch.
		*/
		const std::vector<item::ItemBase*> getItemList() {
			return itemList;
		}

		/*
			It'll loop across the inventory and count how many of the item
			by whatever name you have. That will be in the by reference parameeter
			quantity. The method itself will give you a pointer to the object itself.
		*/
		item::ItemBase * getItem(String name, int & quantity) {
			quantity = 0;
			std::vector<item::ItemBase*>::iterator it;
			item::ItemBase * returnItem = NULL;
			for( it = itemList.begin(); it != itemList.end(); ++it ) {
				if ( (*it)->getName() == name ) {
					quantity += 1;
					returnItem = (*it);
				}
			}
			return returnItem;
		}

		/*
			Removes a single instance
		*/
		bool removeItem(String name) {
			return false;
		}

	};

}
}

#endif