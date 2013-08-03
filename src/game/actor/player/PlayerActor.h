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

				//handle players input
				int key = getch();
				//This switch provides "world overview specating"
				switch(key){
					//hjkl
					case 106:
						MoveActor(vec2(0,1));
						break;
					case 107:
						MoveActor(vec2(0,-1));
						break;
					case 104:
						MoveActor(vec2(-1,0));
						break;
					case 108:
						MoveActor(vec2(1,0));
						break;
					case 27:
						//quitStatus = true;
						LOG_INFO("quit triggered!");
						break;
				}

			}
	};

}
}
}

#endif
