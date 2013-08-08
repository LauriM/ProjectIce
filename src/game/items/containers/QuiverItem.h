
#ifndef __QUIVER_ITEM_H__
#define __QUIVER_ITEM_H__

#include "game/items/ArrowItem.h"
#include "engine/actor/ActorBase.h"
#include "engine/items/ItemBase.h"
#include "engine/items/containers/ItemContainerBase.h"

namespace game {
namespace items {
namespace containers {
	
	class QuiverItem : public engine::items::containers::ItemContainerBase {
	private:
	public:
		QuiverItem();
		~QuiverItem();

		void onPickup( engine::actor::ActorBase * aOwner );
		void onInspect( engine::actor::ActorBase * aOwner );
		void onDrop( engine::actor::ActorBase * aOwner );
	};

}
}
}

#endif