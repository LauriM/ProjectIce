#ifndef ENGINE_ACTOR_ACTORMANAGER_H
#define ENGINE_ACTOR_ACTORMANAGER_H

#include <vector>

#include "engine/math/vec2.h"
#include "engine/math/vec3.h"
#include "engine/actor/ActorBase.h"

namespace engine {
namespace actor {

	/**
	 * ActorManager contains all the actors in game.
	 *
	 * The actors are organized so that they can be easily queried by the room.
	 *
	 * Actor position/location is stored inside the actorbase, here its splitted also just for faster queries.
	 *
	 * The system is not yet optimized, its just in the place to get the functions work. Internal stuff should be improved.
	 */
	class ActorManager {
		private:
			//TODO: Only one vector with all the actors! Should be higly optimized!
			std::vector<ActorBase *> actors;

		public:

			//TODO: implement moving from container to another

			void insertActorToRoom(ActorBase* actor){
				actors.push_back(actor);
			}

			std::vector<ActorBase *> getActorsInRoom(vec3 location){
				std::vector<ActorBase *> output;

				for(int i = 0;i < actors.size();++i){
					if(actors.at(i)->getLocation() == location){
						output.push_back(actors.at(i));
					}
				}

				return output;
			}
	};

}
}

#endif
