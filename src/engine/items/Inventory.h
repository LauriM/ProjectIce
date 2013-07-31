#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include "precompiled.h"
#include <map>

#include "engine/items/BaseItem.h"
#include "engine/actor/ActorBase.h"

namespace engine {
namespace items {

	class Inventory {
	private:

		std::map<String,BaseItem*> _inventoryMap;
		actor::ActorBase * _owner;

	public:

		void init(actor::ActorBase * owner);

		bool destroyItem(String name);
		BaseItem * dropItem(String name);
		bool useItem(String name);
		bool insertItem(BaseItem * b);
		bool inspectItem(String name);

	};

}
}

#endif
