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
	 *
	 * ActorManager also knows the pointer to the playerActor.
	 */
	class ActorManager {
	private:
		actor::ActorStorage *actorStorage;
		world::WorldSystem *worldSystem;

		actor::ActorBase * playerActor;
	public:
		ActorManager(actor::ActorStorage *actorStorage, world::WorldSystem *worldSystem, actor::ActorBase * playerActor)
			: actorStorage(actorStorage)
			, worldSystem(worldSystem)
			, playerActor(playerActor)
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

		const actor::ActorBase * getPlayerActor() {
			return playerActor;
		}
	};

}
}

#endif
