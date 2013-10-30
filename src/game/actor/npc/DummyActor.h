#ifndef GAME_ACTOR_NPC_DUMMYACTOR_H
#define GAME_ACTOR_NPC_DUMMYACTOR_H

#include "precompiled.h"

#include "engine/actor/ActorBase.h"
#include "engine/math/random.h"

namespace game {
namespace actor {
namespace npc {

	class DummyActor : public engine::actor::ActorBase {
		private:
		public:
			DummyActor(){
				name         = "Dummy";

				symbol       = 'D';
				aiState      = engine::actor::AISTATE_PATROL;

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
