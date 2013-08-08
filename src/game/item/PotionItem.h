
#ifndef __POTION_ITEM_H__
#define __POTION_ITEM_H__

#include "engine/actor/ActorBase.h"
#include "engine/item/UseableItemBase.h"

namespace game {
namespace item {

	class PotionItem : public engine::item::UseableItemBase {
	public:
		void onUse( engine::actor::ActorBase * user, engine::ctor::ActorBase * target = 0 ) {
			user->setHp( user->getHp() + 10 );
		}

		void onPickup( actor::ActorBase * actor ) {

		}

		void onInspect( actor::ActorBase * actor ) {

		}

		void onDrop( actor::ActorBase * actor ) {

		}
	};

}
}

#endif