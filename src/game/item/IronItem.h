#ifndef GAME_ITEM_IRONITEM_H
#define GAME_ITEM_IRONITEM_H

#include "engine/actor/ActorBase.h"
#include "engine/item/ItemBase.h"

namespace game {
namespace item {
	
	class IronItem : public engine::item::ItemBase {
	private:
	public:
		IronItem();
		~IronItem();

		void onPickup( engine::actor::ActorBase * actor  );
		void onDrop( engine::actor::ActorBase * actor  );
		void onInspect( engine::actor::ActorBase * actor  );
	};

}
}

#endif