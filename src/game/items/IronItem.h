
#ifndef __IRON_ITEM_H__
#define __IRON_ITEM_H__

#include "engine/actor/ActorBase.h"
#include "engine/items/BaseItem.h"

namespace game {
namespace items {
	
	class IronItem : public engine::items::BaseItem {
	private:
	public:
		IronItem();
		~IronItem();

		void onDestroy( engine::actor::ActorBase * aOwner );
		void onPickup( engine::actor::ActorBase * aOwner );
		void onDrop( engine::actor::ActorBase * aOwner );
		void onInspect( engine::actor::ActorBase * aOwner );
		void onUse( engine::actor::ActorBase * aOwner );

	};


}
}

#endif