#include "precompiled.h"

#include "engine/AI/AISystem.h"
#include "engine/math/random.h"
#include "engine/AI/AIState.h"
#include "engine/input/InputMapping.h"
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
		//TODO: This whole function looks like shit, fix it

		vec2 newPos;

		switch( actor->getAIState() ){
			case AISTATE_SLEEP:
				return;
			case AISTATE_PATROL:
				//just something random for testing
				newPos.x = actor->getPos()->x + randomRange(-1,1);
				newPos.y = actor->getPos()->y + randomRange(-1,1);

				if(!worldSystem->getRoom(actor->getLocation())->getTile(newPos.x,newPos.y)->blocks){
					actor->setPosition(newPos);
					return;
				}

				LOG_DEBUG("actor collides with tile");
				return;
			case AISTATE_PLAYER:
				int key = getch();
				LOG_DEBUG_F("key %i",key);

				engine::input::InputMapping* _inputMapping = engine::input::InputMapping::getInstance();
				newPos.x = actor->getPos()->x;
				newPos.y = actor->getPos()->y;

				//TODO: This looks UGLY
				if ( key == _inputMapping->getMoveNorth() ) {
					newPos.y += 1;
				} else if ( key == _inputMapping->getMoveSouth() ) {
					newPos.y += -1;
				} else if ( key == _inputMapping->getMoveEast() ) {
					newPos.x += -1;
				} else if ( key == _inputMapping->getMoveWest() ) {
					newPos.x += 1;
				}

				if(!worldSystem->getRoom(actor->getLocation())->getTile(newPos.x,newPos.y)->blocks){
					actor->setPosition(newPos);
					return;
				}

				LOG_DEBUG("Player collides with tile");
				return;
		}
	}

}
}
