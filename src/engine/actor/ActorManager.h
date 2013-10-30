#ifndef ENGINE_ACTOR_ACTORMANAGER_H
#define ENGINE_ACTOR_ACTORMANAGER_H

#include "engine/actor/ActorStorage.h"
#include "engine/world/WorldSystem.h"

namespace engine {
namespace actor {

	/**
	 * ActorManager provides movement/manipulation commands for the actors.
	 *
	 * These commands usually require access to both world and actor systems.
	 *
	 * ActorManager also provides the pointers to the systems it depends on.
	 */
	class ActorManager {
	private:
		actor::ActorStorage *actorStorage;
		world::WorldSystem *worldSystem;

	public:
		ActorManager(actor::ActorStorage *actorStorage, world::WorldSystem *worldSystem)
			: actorStorage(actorStorage)
			, worldSystem(worldSystem)
		{}

		void actorTick(actor::ActorBase * actor);

		void moveActor(actor::ActorBase * actor,const vec2 pos);
		void moveActorRel(actor::ActorBase * actor,const vec2 pos);

		/* getters & setters */

		actor::ActorStorage * getActorStorage() {
			return actorStorage;
		}

		world::WorldSystem * getWorldSystem() {
			return worldSystem;
		}
	};

}
}

#endif
