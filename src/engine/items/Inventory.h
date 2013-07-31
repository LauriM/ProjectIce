#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include "precompiled.h"
#include <map>

#include "engine/items/BaseItem.h"
#include "engine/player/Player.h"

namespace engine {
namespace world {
namespace item {

	class Inventory {
	private:

		std::map<String,BaseItem*> _inventoryMap;
		player::Player * _playerOwner;

	public:

		void init(player::Player * owner);

		bool destroyItem(String name);
		BaseItem * dropItem(String name);
		bool useItem(String name);
		bool insertItem(BaseItem * b);
		bool inspectItem(String name);

	};

}
}
}

#endif
