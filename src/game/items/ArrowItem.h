
#ifndef __ARROW_ITEM_H__
#define __ARROW_ITEM_H__

#include "engine/actor/ActorBase.h"
#include "engine/items/BaseItem.h"

namespace game {
namespace items {
	
	class ArrowItem : public engine::items::BaseItem {
	private:
	public:
		ArrowItem();
		~ArrowItem();

		void onPickup( engine::actor::ActorBase * aOwner );
		void onDrop( engine::actor::ActorBase * aOwner );
		void onInspect( engine::actor::ActorBase * aOwner );
	};

}
}

#endif