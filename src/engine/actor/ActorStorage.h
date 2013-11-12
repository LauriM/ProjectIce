#ifndef ENGINE_ACTOR_ACTORSYSTEM_H
#define ENGINE_ACTOR_ACTORSYSTEM_H

#include <vector>

#include "engine/math/vec2.h"
#include "engine/math/vec3.h"
#include "engine/actor/ActorBase.h"

namespace engine {
namespace actor {

	/**
	 * ActorStorage contains all the actors in game. (Stores the actors, doesn't actually do anything with them)
	 *
	 * The actors are organized so that they can be easily queried by the room.
	 *
	 * Actor position/location is stored inside the actorbase, here its splitted also just for faster queries.
	 */
	class ActorStorage {
		private:
			std::vector<ActorBase *> actors;
			std::vector<ActorBase *> removeQueue;

			void moveActor(actor::ActorBase * actor,vec2 dir);

			void removeActor(ActorBase* actor);

		public:

			void insertActorToRoom(ActorBase* actor);
			void deleteActor(ActorBase* actor);
			void handleRemoveQueue();
			std::vector<ActorBase *> getActorsInRoom(const vec3 location);

	};

}
}

#endif
