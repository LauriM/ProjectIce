
#ifndef __QUIVER_ITEM_H__
#define __QUIVER_ITEM_H__

#include "game/items/ArrowItem.h"
#include "engine/actor/ActorBase.h"
#include "engine/items/BaseItem.h"
#include "engine/items/containers/BaseContainerItem.h"

namespace game {
namespace items {
namespace containers {
	
	class QuiverItem : public engine::items::containers::BaseContainerItem {
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