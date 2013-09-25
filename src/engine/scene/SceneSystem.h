#ifndef ENGINE_SCENE_SCENESYSTEM_H
#define ENGINE_SCENE_SCENESYSTEM_H

#include "precompiled.h"

#include "engine/EngineSystem.h"
#include "engine/world/WorldSystem.h"
#include "engine/inventory/Inventory.h"
#include "engine/actor/ActorManager.h"

namespace engine {
namespace scene {

	/**
	 * Scene contains world,items and actors.
	 *
	 * It will also have saving/loading of the world
	 */
	class SceneSystem : public EngineSystem {
		private:
			world::WorldSystem *worldSystem;
			actor::ActorManager *actorManager;

			// player related objects
			actor::ActorBase * playerActor;
		public:

			SceneSystem( world::WorldSystem * world, actor::ActorManager * actorMan, actor::ActorBase * player );

			bool init( );
			void uninit();
			void update();

			/*getters & setters */
			actor::ActorManager* getActorManager();
			actor::ActorBase* getPlayerActor();
			world::WorldSystem* getWorld();
	};

}
}

#endif
