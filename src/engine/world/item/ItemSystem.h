
#ifndef __ITEM_SYSTEM_H__
#define __ITEM_SYSTEM_H__

#include <map>
#include "engine/world/item/BaseItem.h"

namespace engine {
namespace world {
namespace item {

	class ItemSystem {
	private:
		std::map< String, BaseItem* > _itemMap;
	public:
		void init();
		BaseItem * getItem(String name);
		
	};

}
}
}	

#endif