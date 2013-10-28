#include "precompiled.h"

#include "engine/actor/AISystem.h"
#include "engine/math/random.h"
#include "engine/actor/AIState.h"
#include <vector>

namespace engine {
namespace actor {

	AISystem::AISystem(actor::ActorManager *actorManager)
		: actorManager(actorManager)
	{}

	bool AISystem::init(){
		LOG_INFO("AISystem init");

		return true;
	}

	void AISystem::uninit(){
		LOG_INFO("AISystem uninit");
	}

	void AISystem::update(){
		std::vector<actor::ActorBase *> actors = actorManager->getActorSystem()->getActorsInRoom(vec3(0,0,0));

		for(unsigned int i = 0; i < actors.size();++i){
			handleActor(actors.at(i));
		}
	}

	void AISystem::handleActor(actor::ActorBase * actor){
		//TODO: This whole function looks like shit, fix it

		//TODO: IMPLEMENT A DAMN DEATH/ALIVE CHECK HERE!

		vec2 newPos;

		switch( actor->getAIState() ){
			case AISTATE_SLEEP:
				return;
			case AISTATE_PATROL:
				//Patrolling enemies goes to random direction
				newPos.x = actor->getPos()->x + randomRange(-1,1);
				newPos.y = actor->getPos()->y + randomRange(-1,1);

				actorManager->moveActor(actor,newPos);

				return;
			case AISTATE_PLAYER:
				//Do nothing, its the player!

				//If some wierd hallusionation mode is on, then we could actually use some random movement here...

				return;
		}
	}


}
}
