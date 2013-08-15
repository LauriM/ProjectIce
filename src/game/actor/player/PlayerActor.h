#ifndef ENGINE_ACTOR_PLAYER_PLAYERACTOR_H
#define ENGINE_ACTOR_PLAYER_PLAYERACTOR_H

#include "precompiled.h"

#include "engine/actor/ActorBase.h"
#include "engine/actor/PlayableActorBase.h"

#include <typeinfo>

namespace game {
namespace actor {
namespace player {

	class PlayerActor : public engine::actor::PlayableActorBase {
		public:
			PlayerActor(){
				name          = "Player";

				hp            = 100;
				maxHp         = 100;

				strength      = 10;
				dexterity     = 10;
				constitution  = 10;

				symbol        = '@';
				aiState       = engine::AI::AISTATE_PLAYER;
			}

			void update() {}

			void playerInput(int key){
			}

			void onAttack( engine::actor::ActorBase * target ) {
				// ta = target actor
				engine::actor::PlayableActorBase * ta = dynamic_cast<PlayableActorBase*>(target);
				if ( ta ) {
					int targetHp = ta->getHp();
					targetHp -= strength;
					ta->setHp(targetHp);
				}
			}
	};

}
}
}

#endif
