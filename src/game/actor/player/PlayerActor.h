#ifndef ENGINE_ACTOR_PLAYER_PLAYERACTOR_H
#define ENGINE_ACTOR_PLAYER_PLAYERACTOR_H

#include "precompiled.h"

#include "engine/actor/ActorBase.h"
#include "engine/actor/PlayableActorBase.h"
#include "engine/input/InputMapping.h"

#include <typeinfo>

namespace game {
namespace actor {
namespace player {

	class PlayerActor : public engine::actor::PlayableActorBase {
		private:

			engine::input::InputMapping * _inputMapping; // so you don't hae to retreive it each update

		public:
			PlayerActor(){
				name          = "Player";
				_inputMapping = engine::input::InputMapping::getInstance();

				hp            = 100;
				maxHp         = 100;

				strength      = 10;
				dexterity     = 10;
				constitution  = 10;

				symbol        = '@';
			}

			void update(){
				int key = getch();
				LOG_DEBUG_F("key %i",key);

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
