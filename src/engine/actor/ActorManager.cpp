#include "precompiled.h"

#include "engine/actor/ActorBase.h"
#include "engine/actor/ActorManager.h"

namespace engine {
namespace actor {

	/**
	 * Handles tick that should happen for each actor each game tick.
	 *
	 * This doesn't handle the AI. This is just the bodypart status handling, etc.
	 *
	 * AISystem handles the ai ticks.
	 */
	void ActorManager::actorTick(actor::ActorBase * actor) {

		/*
		 * Following steps happeng to each actor:
		 *
		 * > Nutrition goes down each turn
		 * > Attributes are checked and handled
		 * > Check if the actor is "dead" and should be removed
		 */

		//Remove nutrition based on the str and weight.
		actor->addNutrition( -abs( (actor->getWeight() + actor->getStrength()) / 50 ) );

		printf("nutr: %i\n", actor->getNutrition());
	}

	/**
	 * Moves actor to certain position. Checks if there is wall/other actors on the way.
	 *
	 * @param pos Position is absolute to the position where the actor should be moved.
	 */
	void ActorManager::moveActor(actor::ActorBase * actor,const vec2 pos){
		if(worldSystem->getRoom( actor->getLocation() )->getTile(pos.x,pos.y)->blocks){
			return; //hits a wall
		}

		std::vector<actor::ActorBase *> actors = actorSystem->getActorsInRoom( actor->getLocation() );
		for(unsigned int i = 0; i < actors.size();++i){
			if(actors.at(i)->getPosition() == pos){
				actor::ActorBase * target = actors.at(i);
				if(actor == target){
					return;
				}
				if(actor->attack(target)){
					//Attack was issued! Lets spawn some blood!
					worldSystem->getRoom( actor->getLocation() )->getTile( target->getPosition() )->setBgColor(render::C_RED);
				}

				return; //hits other actor
			}
		}

		//nothing on the way, move the actor
		actor->setPosition(pos);
	}

	/**
	 * Calls the moveActor function, but uses relative positions instead of absolute.
	 */
	void ActorManager::moveActorRel(actor::ActorBase * actor,const vec2 pos){
		vec2 absPos = actor->getPosition();

		absPos += pos;

		moveActor(actor,absPos);
	}

}
}
