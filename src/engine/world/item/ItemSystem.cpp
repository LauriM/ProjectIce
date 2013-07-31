
#include "engine/world/item/ItemSystem.h"

namespace engine {
namespace world {
namespace item {

	void ItemSystem::init() {
		/* Just add crap for now */
		BaseItem * b = new BaseItem();
		b->setName("sword");
		b->setValue(20);
		_itemMap[b->getName()] = b;

		b = new BaseItem();
		b->setName("shield");
		b->setValue(30);
		_itemMap[b->getName()] = b;

		b = new BaseItem();
		b->setName("a void of space");
		b->setValue(40);
		_itemMap[b->getName()] = b;
	}

	BaseItem * ItemSystem::getItem(String name)
	{
		return _itemMap[name];
	}

}
}
}	