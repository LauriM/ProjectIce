#ifndef GAME_UI_CONTAINERS_STATSCONTAINER_H
#define GAME_UI_CONTAINERS_STATSCONTAINER_H

#include <stdio.h>

#include "engine/UI/ContainerBase.h"
#include "engine/math/AABB.h"

#include "game/actor/player/PlayerActor.h"

namespace game {
namespace UI {
namespace containers {

	/**
	 * Displays player stats.
	 */
	class StatsContainer : public engine::UI::ContainerBase {
		private:
			actor::player::PlayerActor *playerActor;
		public:
			void init(){
				playerActor = NULL;
			}

			void uninit() {}

			void render(AABB bounds){
				if(playerActor == NULL){
//					engine::render::drawStringTobounds(bounds,vec2(0,0),"ERROR");
					LOG_WARNING("StatsContainer can't find PlayerActor!");
					return;
				}

				//TODO: change the color depending on the HP %
			//	char buffer[25];
				//snprintf(buffer,25,"HP: %i/%i",playerActor->getHp(),playerActor->getMaxHp() );
//				engine::render::drawStringTobounds(bounds,vec2(0,0),buffer);
			}

			void setPlayerActor(actor::player::PlayerActor *actor){
				playerActor = actor;
			}

			void handleInput(int key) { }
	};

}
}
}

#endif
