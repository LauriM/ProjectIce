#ifndef GAME_ACTOR_NPC_DUMMYACTOR_H
#define GAME_ACTOR_NPC_DUMMYACTOR_H

#include "precompiled.h"

#include "engine/actor/ActorBase.h"
#include "engine/actor/PlayableActorBase.h"

namespace game {
namespace actor {
namespace npc {

	class DummyActor : public engine::actor::PlayableActorBase {
		private:
		public:
			DummyActor(){
				name         = "Dummy";
				hp           = 50;
				maxHp        = 50;
				strength     = 5;
				dexterity    = 5;
				constitution = 1;
				symbol       = 'D';
			}

			void update(){
				LOG_DEBUG("Dummy AI tick");
			}

			void onAttack( engine::actor::ActorBase * target ) {
				LOG_DEBUG("Dummy attacks!");
			}
	};
}
}
}

#endif
