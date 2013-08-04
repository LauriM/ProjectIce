#ifndef __BASE_INVENTORY_H__
#define __BASE_INVENTORY_H__

#include "precompiled.h"
#include <vector>

#include "engine/math/vec2.h"
#include "engine/items/BaseItem.h"
#include "engine/actor/ActorBase.h"

namespace engine {
namespace items {

	/* I dunno, is this an ok idea? */
	template <typename K>
	class BaseInventory {
	private:
		std::vector<BaseItem*> _itemList;
	public:
		void addItem(BaseItem * item) {
			if ( item )
				_itemList.push_back(item);
		}

		BaseItem * getItem(String name) {
			std::vector<BaseItem*>::iterator i;
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
