
#ifndef __POTION_ITEM_H__
#define __POTION_ITEM_H__

#include "engine/actor/ActorBase.h"
#include "engine/item/UseableItemBase.h"

namespace game {
namespace item {

	class PotionItem : public engine::item::UseableItemBase {
	public:
		PotionItem() {
			name        = "Potion";
			description = "Heal me! Please!";
			value       = 1.0;
			symbol      = '!';
		}

		void onUse( engine::actor::ActorBase * user, engine::actor::ActorBase * target = 0 ) {
			//TODO: This whole item needs a huge refactor!
			// HP is removed from the game, so this should affect bodyparts attributes or something.
			//user->setHp( user->getHp() + 10 );
		}

		void onPickup( engine::actor::ActorBase * actor ) {

		}

		void onInspect( engine::actor::ActorBase * actor ) {

		}

		void onDrop( engine::actor::ActorBase * actor ) {

		}

	};

}
}

#endif
