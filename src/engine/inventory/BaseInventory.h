#ifndef __BASE_INVENTORY_H__
#define __BASE_INVENTORY_H__

#include "precompiled.h"
#include <vector>

#include "engine/math/vec2.h"
#include "engine/items/BaseItem.h"
#include "engine/inventory/InvOwnerUnion.h"
#include "engine/actor/ActorBase.h"

namespace engine {
namespace inventory {

	/* I dunno, is this an ok idea? */
	class BaseInventory {
	private:
		std::vector<items::BaseItem*> itemList;
		inventory::UInventoryType owner;
	public:

		void setOwner( UInventoryType owner ) {
			this->owner = owner;
		}

		UInventoryType getOwner() {
			return owner;
		}

		void addItem(items::BaseItem * item) {
			if ( item )
				itemList.push_back(item);
		}

		items::BaseItem * getItem(String name) {
			std::vector<items::BaseItem*>::iterator i;
			for ( i = itemList.begin(); i != itemList.end(); ++i ) {
				if ( (*i)->getName() == name )
					return (*i);
			}
			return NULL;
		}
	};

}
}

#endif
