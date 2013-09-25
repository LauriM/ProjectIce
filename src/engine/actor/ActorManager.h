#ifndef ENGINE_ACTOR_ACTORMANAGER_H
#define ENGINE_ACTOR_ACTORMANAGER_H

#include "engine/actor/ActorSystem.h"
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
		actor::ActorSystem *actorSystem;
		world::WorldSystem *worldSystem;

	public:
		ActorManager(actor::ActorSystem *actorSystem, world::WorldSystem *worldSystem)
			: actorSystem(actorSystem)
			, worldSystem(worldSystem)
		{}

		void moveActor(actor::ActorBase * actor,const vec2 pos);
		void moveActorRel(actor::ActorBase * actor,const vec2 pos);

		/* getters & setters */

		actor::ActorSystem * getActorSystem() {
			return actorSystem;
		}

		world::WorldSystem * getWorldSystem() {
			return worldSystem;
		}
	};

}
}

#endif