#ifndef GAME_ITEM_ARROWITEM_H
#define GAME_ITEM_ARROWITEM_H

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