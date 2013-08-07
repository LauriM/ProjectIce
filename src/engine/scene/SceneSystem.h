#ifndef ENGINE_SCENE_SCENESYSTEM_H
#define ENGINE_SCENE_SCENESYSTEM_H

#include "precompiled.h"

#include "engine/EngineSystem.h"
#include "engine/world/WorldSystem.h"
#include "game/actor/player/PlayerActor.h"
#include "engine/inventory/InvOwnerUnion.h"
#include "engine/inventory/BaseInventory.h"

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

			//TODO: add arrays of inventories and actors here

			//Always keep the pointer to playeractor close

			actor::ActorBase * playerActor;
			//game::actor::player::PlayerActor *playerActor;

		public:

			// I would think that worldSystem and player should be created outside of the SceneSystem instead
			// of being initialized here. #1 splitting the creation up if something goes wrong it's easier
			// to pull it apart and also you'll extend the engine via the game namespace which isn't
			// very nice to do.
			bool init( ){
				worldSystem = new world::WorldSystem();
				if(!worldSystem->init()){
					return false;//world could not be initialized
				}

				worldSystem->generate();

				//create player
				playerActor = new game::actor::player::PlayerActor();

				playerActor->setName("Player");
				playerActor->getPos()->x = 10;
				playerActor->getPos()->y = 10;
				playerActor->setWorld(worldSystem);

				// Test Bryan
				inventory::UInventoryType ut;
				ut.ownerType = inventory::ACTOR;
				ut.actorOwner = playerActor;
				inventory::BaseInventory * playerInv = new inventory::BaseInventory();
				playerInv->setOwner( ut );
				// Bryan


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
	};

}
}

#endif
