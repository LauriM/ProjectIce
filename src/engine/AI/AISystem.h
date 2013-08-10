#ifndef ENGINE_AI_AISYSTEM
#define ENGINE_AI_AISYSTEM

#include "engine/scene/SceneSystem.h"

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
			scene::SceneSystem *sceneSystem;
		public:
			AISystem(scene::SceneSystem *sceneSystem);
			~AISystem() {};

			virtual bool init();
			virtual void uninit();
			virtual void update();
	};

}
}

#endif
