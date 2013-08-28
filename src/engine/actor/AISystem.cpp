#include "precompiled.h"

#include "engine/actor/AISystem.h"
#include "engine/math/random.h"
#include "engine/actor/AIState.h"
#include "engine/input/InputMapping.h"
#include "engine/combat/Combat.h"
#include <vector>

namespace engine {
namespace actor {

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

		for(unsigned int i = 0; i < actors.size();++i){
			handleActor(actors.at(i));
		}
	}

	void AISystem::handleActor(actor::ActorBase * actor){
		//TODO: This whole function looks like shit, fix it

		//check if the actor is dead
		if(actor->getHp() < 0){
			LOG_INFO("KILL!");
			actorManager->removeActor(actor);
			return;
		}

		vec2 newPos;

		switch( actor->getAIState() ){
			case AISTATE_SLEEP:
				return;
			case AISTATE_PATROL:
				//Patrolling enemies goes to random direction
				newPos.x = actor->getPos()->x + randomRange(-1,1);
				newPos.y = actor->getPos()->y + randomRange(-1,1);

				moveActor(actor,newPos);

				return;
			case AISTATE_PLAYER:
				//engine::input::InputMapping* _inputMapping = engine::input::InputMapping::getInstance();
				newPos.x = actor->getPos()->x;
				newPos.y = actor->getPos()->y;

				//TODO: This looks UGLY
				/*
				if ( key == _inputMapping->getMoveNorth() ) {
					newPos.y += 1;
				} else if ( key == _inputMapping->getMoveSouth() ) {
					newPos.y += -1;
				} else if ( key == _inputMapping->getMoveEast() ) {
					newPos.x += -1;
				} else if ( key == _inputMapping->getMoveWest() ) {
					newPos.x += 1;
				}
				*/

				moveActor(actor,newPos);

				return;
		}
	}


	//TODO: consider moving this to separated source file, this is not AI, this is movement !

	/**
	 * Moves actor to certain position. Checks if there is wall/other actors on the way.
	 *
	 * @param pos Position is absolute to the position where the actor should be moved.
	 */
	void AISystem::moveActor(actor::ActorBase * actor,vec2 pos){
		if(worldSystem->getRoom( actor->getLocation() )->getTile(pos.x,pos.y)->blocks){
			return; //hits a wall
		}

		std::vector<actor::ActorBase *> actors = actorManager->getActorsInRoom( actor->getLocation() );
		for(unsigned int i = 0; i < actors.size();++i){
			if(actors.at(i)->getPosition() == pos){
				actor::ActorBase * target = actors.at(i);
				if(engine::combat::attackActor(actor, target)){
					//Attack was issued! Lets spawn some blood!
					worldSystem->getRoom( actor->getLocation() )->getTile( target->getPosition() )->setBgColor(render::C_RED);
				}

				return; //hits other actor
			}
		}

		//nothing on the way, move the actor
		actor->setPosition(pos);
	}

}
}
