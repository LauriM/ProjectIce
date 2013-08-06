#ifndef ENGINE_ACTOR_PLAYER_PLAYERACTOR_H
#define ENGINE_ACTOR_PLAYER_PLAYERACTOR_H

#include "engine/actor/ActorBase.h"
#include "engine/input/InputMapping.h"


namespace game {
namespace actor {
namespace player {

	class PlayerActor : public engine::actor::ActorBase {
	private:

		engine::input::InputMapping * _inputMapping; // so you don't hae to retreive it each update

		public:
			PlayerActor(){
				hp    = 10;
				maxHp = 10;
				name  = "Player";
				_inputMapping = engine::input::InputMapping::getInstance();
			}

			void update(){
				int key = getch();

				//TODO: This looks UGLY
				if ( key == _inputMapping->getMoveNorth() ) {
					MoveActor(vec2(0,1));
				} else if ( key == _inputMapping->getMoveSouth() ) {
					MoveActor(vec2(0,-1));
				} else if ( key == _inputMapping->getMoveEast() ) {
					MoveActor(vec2(-1,0));
				} else if ( key == _inputMapping->getMoveWest() ) {
					MoveActor(vec2(1,0));
				} else if ( key == _inputMapping->getSuicide() ) {
					LOG_INFO("This actor quit life.");
				}
			}
	};

}
}
}

#endif
