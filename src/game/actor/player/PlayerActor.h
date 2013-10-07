#ifndef ENGINE_ACTOR_PLAYER_PLAYERACTOR_H
#define ENGINE_ACTOR_PLAYER_PLAYERACTOR_H

#include "precompiled.h"

#include "engine/actor/ActorBase.h"
#include "engine/actor/body/Torso.h"
#include "engine/actor/body/Head.h"
#include "engine/actor/body/Arm.h"
#include "engine/actor/body/Leg.h"

#include <typeinfo>

namespace game {
namespace actor {
namespace player {

	class PlayerActor : public engine::actor::ActorBase {
		public:
			PlayerActor(){
				name          = "Player";

				hp            = 100;
				maxHp         = 100;

				strength      = 10;
				dexterity     = 10;
				constitution  = 10;

				symbol        = '@';
				aiState       = engine::actor::AISTATE_PLAYER;

				//Build the body
				torso = new engine::actor::body::Torso();
				torso->parent = torso;

				engine::actor::body::BodyPart *head     = new engine::actor::body::Head();
				engine::actor::body::BodyPart *rightArm = new engine::actor::body::Arm();
				engine::actor::body::BodyPart *leftArm  = new engine::actor::body::Arm();
				engine::actor::body::BodyPart *rightLeg = new engine::actor::body::Leg();
				engine::actor::body::BodyPart *leftLeg  = new engine::actor::body::Leg();

				torso->addChild(head);
				torso->addChild(rightArm);
				torso->addChild(leftArm);
				torso->addChild(rightLeg);
				torso->addChild(leftLeg);
			}

			void update() {}

			void playerInput(int key){
			}

			void onAttack( engine::actor::ActorBase * target ) {
				//TODO: implement actor related attack stuff here.
			}
	};

}
}
}

#endif
