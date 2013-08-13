#ifndef ENGINE_AI_AISYSTEM
#define ENGINE_AI_AISYSTEM

#include "engine/world/WorldSystem.h"
#include "engine/actor/ActorManager.h"

namespace engine {
namespace AI {

	/**
	 * AISystem handles are AI stuff that the NPC's have
	 *
	 * Aisystem requires scene. Scene contains all the data AISystem needs to do the decisions.
	 *
	 * AISystem will loop trough the relevant actors in the scene, and will process the movement accordingly.
	 *
	 * AIState is handled inside the ActorBase. (Current AI state, memory)
	 */
	class AISystem : public EngineSystem {
		private:
			engine::actor::ActorManager *actorManager;
			engine::world::WorldSystem *worldSystem;

			void handleActor(actor::ActorBase * actor);

		public:
			AISystem(actor::ActorManager *actorManager, world::WorldSystem *worldSystem);
			~AISystem() {};

			virtual bool init();
			virtual void uninit();
			virtual void update();
	};

}
}

#endif
