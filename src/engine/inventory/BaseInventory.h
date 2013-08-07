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
		std::vector<items::BaseItem*> _itemList;
		inventory::UInventoryType _owner;
	public:
		void addItem(items::BaseItem * item) {
			if ( item )
				_itemList.push_back(item);
		}

		items::BaseItem * getItem(String name) {
			std::vector<items::BaseItem*>::iterator i;
			for ( i = _itemList.begin(); i != _itemList.end(); ++i ) {
				if ( (*i)->getName() == name )
					return (*i);
			}
			return NULL;
		}
	};

}
}

#endif
