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
				hp           = 50;
				maxHp        = 50;
				strength     = 5;
				dexterity    = 5;
				constitution = 1;
				symbol       = 'D';
				aiState      = engine::actor::AISTATE_PATROL;

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

			void update(){
				LOG_DEBUG("Dummy AI tick");
				MoveActor(vec2(randomRange(-1,1), randomRange(-1,1)));
			}

			void onAttack( engine::actor::ActorBase * target ) {
				LOG_DEBUG("Dummy attacks!");
			}
	};
}
}
}

#endif
