#ifndef ENGINE_ACTOR_PLAYER_PLAYERACTOR_H
#define ENGINE_ACTOR_PLAYER_PLAYERACTOR_H

#include "engine/actor/ActorBase.h"

namespace game {
namespace actor {
namespace player {

	class PlayerActor : public engine::actor::ActorBase {
		public:
			PlayerActor(){
				hp    = 10;
				maxHp = 10;
				name  = "Player";
			}

			void update(){
				LOG_INFO("Player update")
			}
	};

}
}
}

#endif
