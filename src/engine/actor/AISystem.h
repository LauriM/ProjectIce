#ifndef ENGINE_ACTOR_AISYSTEM
#define ENGINE_ACTOR_AISYSTEM

#include "engine/actor/ActorManager.h"

namespace engine {
namespace actor {

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
			//TODO: consider just getting the pointers for the actorsystem and worldsystem... used lot in the code.
			engine::actor::ActorManager *actorManager;

			void handleActor(actor::ActorBase * actor);

		public:
			AISystem(actor::ActorManager *actorManager);
			~AISystem() {};

			virtual bool init();
			virtual void uninit();
			virtual void update();
	};

}
}

#endif
