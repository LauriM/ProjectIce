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
					/*
					case 106:
						render->cameraPos.y -= 1;
						break;
					case 107:
						render->cameraPos.y += 1;
						break;
					case 104:
						render->cameraPos.x -= 1;
						break;
					case 108:
						render->cameraPos.x += 1;
						break;
					case 62:
						render->cameraPos.z -= 1;
						break;
						*/
					case 60:
						LOG_INFO("player movement!");
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
