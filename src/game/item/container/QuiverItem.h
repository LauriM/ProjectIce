
#ifndef __QUIVER_ITEM_H__
#define __QUIVER_ITEM_H__

#include "game/item/ArrowItem.h"
#include "engine/actor/ActorBase.h"
#include "engine/item/ItemBase.h"
#include "engine/item/container/ItemContainerBase.h"

namespace game {
namespace item {
namespace container {
	
	class QuiverItem : public engine::item::container::ItemContainerBase {
	private:
	public:
		QuiverItem();
		~QuiverItem();

		void onPickup( engine::actor::ActorBase * actor );
		void onInspect( engine::actor::ActorBase * actor );
		void onDrop( engine::actor::ActorBase * actor );
	};

}
}
}

#endif