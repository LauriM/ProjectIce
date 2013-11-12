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

				symbol        = '@';
				aiState       = engine::actor::AISTATE_PLAYER;

				//Build the body

				/*
				// Super powerfull arm for testing!
				engine::actor::body::Arm *arm = new engine::actor::body::Arm();
				arm->strength = 100;
				addBodyPart(arm);
				*/

				engine::actor::body::BodyPart *torso    = new engine::actor::body::Torso();
				engine::actor::body::BodyPart *head     = new engine::actor::body::Head();
				engine::actor::body::BodyPart *rightArm = new engine::actor::body::Arm();
				engine::actor::body::BodyPart *leftArm  = new engine::actor::body::Arm();
				engine::actor::body::BodyPart *rightLeg = new engine::actor::body::Leg();
				engine::actor::body::BodyPart *leftLeg  = new engine::actor::body::Leg();

				addBodyPart(torso);
				addBodyPart(head);
				addBodyPart(rightArm);
				addBodyPart(leftArm);
				addBodyPart(rightLeg);
				addBodyPart(leftLeg);
			}

			void update() {}

			void playerInput(int key){
			}

			void onAttack( engine::actor::ActorBase * target ) {
				//TODO: implement actor related attack stuff here.
				//TODO: This method is never called!
			}
	};

}
}
}

#endif
