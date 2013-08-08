
#ifndef __IRON_ITEM_H__
#define __IRON_ITEM_H__

#include "engine/actor/ActorBase.h"
#include "engine/item/ItemBase.h"

namespace game {
namespace item {
	
	class IronItem : public engine::item::ItemBase {
	private:
	public:
		IronItem();
		~IronItem();

		void onPickup(  );
		void onDrop(  );
		void onInspect(  );
	};

}
}

#endif