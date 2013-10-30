#ifndef ENGINE_ACTOR_ACTORSYSTEM_H
#define ENGINE_ACTOR_ACTORSYSTEM_H

#include <vector>

#include "engine/math/vec2.h"
#include "engine/math/vec3.h"
#include "engine/actor/ActorBase.h"

namespace engine {
namespace actor {

	/**
	 * ActorManager contains all the actors in game. (Stores the actors, doesn't actually do anything with them)
	 *
	 * The actors are organized so that they can be easily queried by the room.
	 *
	 * Actor position/location is stored inside the actorbase, here its splitted also just for faster queries.
	 *
	 * The system is not yet optimized, its just in the place to get the functions work. Internal stuff should be improved.
	 */
	class ActorSystem {
		private:
			//TODO: Only one vector with all the actors! Should be higly optimized!
			std::vector<ActorBase *> actors;
			std::vector<ActorBase *> removeQueue;

			void moveActor(actor::ActorBase * actor,vec2 dir);

			void removeActor(ActorBase* actor){
				for(unsigned int i = 0;i < actors.size();++i){
					if(actors.at(i) == actor){
						actors.erase( actors.begin() + i);
						LOG_INFO("actor removed!");
					}
				}
			}

		public:

			//TODO: implement moving from container to another

			/**
			 * Insert actor to the manager.
			 * @param actor actor to be inserted
			 */
			void insertActorToRoom(ActorBase* actor){
				actors.push_back(actor);
			}

			/**
			 * Adds actor to the remove queue.
			 *
			 * @param actor pointer to the actor to be removed.
			 */
			void deleteActor(ActorBase* actor) {
				removeQueue.push_back(actor);
			}

			/**
			 * Remove actors queue for remove
			 */
			void handleRemoveQueue() {
				for(unsigned int i = 0;i < removeQueue.size();++i){
					removeActor(removeQueue.at(i));
				}
			}

			std::vector<ActorBase *> getActorsInRoom(vec3 location){
				std::vector<ActorBase *> output;

				for(unsigned int i = 0;i < actors.size();++i){
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
