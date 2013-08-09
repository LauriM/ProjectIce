
#ifndef __POTION_ITEM_H__
#define __POTION_ITEM_H__

#include "engine/actor/ActorBase.h"
#include "engine/item/UseableItemBase.h"
#include "engine/actor/PlayableActorBase.h"

namespace game {
namespace item {

	class PotionItem : public engine::item::UseableItemBase {
	public:
		PotionItem() {
			name = "Potion";
			description = "Heal me! Please!";
			value = 1.0;
		}

		void onUse( engine::actor::ActorBase * user, engine::actor::ActorBase * target = 0 ) {
			engine::actor::PlayableActorBase * playableUser = dynamic_cast<engine::actor::PlayableActorBase*>(user);
			// If the cast didn't work to the object that can use the item, than they obviously can't use it.
			if ( playableUser )
				playableUser->setHp( playableUser->getHp() + 10 );
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