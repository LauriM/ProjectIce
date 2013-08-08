
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

		void onPickup( engine::actor::ActorBase * aOwner );
		void onDrop( engine::actor::ActorBase * aOwner );
		void onInspect( engine::actor::ActorBase * aOwner );
	};

}
}

#endif