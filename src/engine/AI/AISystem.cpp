#include "precompiled.h"

#include "engine/AI/AISystem.h"
#include "engine/math/random.h"
#include <vector>

namespace engine {
namespace AI {

	AISystem::AISystem(actor::ActorManager *actorManager, world::WorldSystem *worldSystem)
		: actorManager(actorManager),
		  worldSystem(worldSystem)
	{}

	bool AISystem::init(){
		LOG_INFO("AISystem init");

		return true;
	}

	void AISystem::uninit(){
		LOG_INFO("AISystem uninit");
	}

	void AISystem::update(){
		std::vector<actor::ActorBase *> actors = actorManager->getActorsInRoom(vec3(0,0,0));

		for(int i = 0; i < actors.size();++i){
			handleActor(actors.at(i));
		}
	}

	void AISystem::handleActor(actor::ActorBase * actor){
		//just something random for testing
		vec2 newPos;
		newPos.x = actor->getPos()->x + randomRange(-1,1);
		newPos.y = actor->getPos()->y + randomRange(-1,1);

		if(!worldSystem->getRoom(actor->getLocation())->getTile(newPos.x,newPos.y)->blocks){
			actor->setPosition(newPos);
			return;
		}

		LOG_DEBUG("actor collides with tile");
	}

}
}
