
#ifndef __ARROW_ITEM_H__
#define __ARROW_ITEM_H__

#include "engine/actor/ActorBase.h"
#include "engine/item/ItemBase.h"

namespace game {
namespace item {
	
	class ArrowItem : public engine::item::ItemBase {
	private:
	public:
		ArrowItem();
		~ArrowItem();

		void onPickup( engine::actor::ActorBase * actor );
		void onDrop( engine::actor::ActorBase * actor );
		void onInspect( engine::actor::ActorBase * actor );
	};

}
}

#endif