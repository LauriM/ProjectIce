#ifndef ENGINE_SCENE_SCENESYSTEM_H
#define ENGINE_SCENE_SCENESYSTEM_H

#include "precompiled.h"

#include "engine/EngineSystem.h"
#include "engine/world/WorldSystem.h"
#include "engine/inventory/ActorInventory.h"

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

			// the rest of the world
			std::vector<actor::ActorBase*> actorList;

			// player objects
			actor::ActorBase * playerActor;
			inventory::ActorInventory * playerInventory;
		public:

			SceneSystem( world::WorldSystem * world, actor::ActorBase * player ) {
				worldSystem = world;
				playerActor = player;
				playerInventory = new inventory::ActorInventory();
				playerInventory->setOwner(playerActor);
			}

			bool init( ){
				return true;
			}

			void uninit(){
				worldSystem->uninit();
			}

			void update(){
				worldSystem->update();
				playerActor->update();
			}

			/*getters & setters */

			actor::ActorBase * getPlayerActor(){
				return playerActor;
			}

			world::WorldSystem* getWorld(){
				return worldSystem;
			}

			std::vector<actor::ActorBase*> getActorList() {
				return actorList;
			}

			void addActor(actor::ActorBase * actor) {
				actorList.push_back(actor);
			}

	};

}
}

#endif
