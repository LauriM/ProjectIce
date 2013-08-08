
#ifndef __IRON_ITEM_H__
#define __IRON_ITEM_H__

#include "engine/actor/ActorBase.h"
#include "engine/items/ItemBase.h"

namespace game {
namespace items {
	
	class IronItem : public engine::items::ItemBase {
	private:
	public:
		IronItem();
		~IronItem();

		void onPickup( engine::actor::ActorBase * aOwner );
		void onDrop( engine::actor::ActorBase * aOwner );
		void onInspect( engine::actor::ActorBase * aOwner );
	};

}
}

#endif