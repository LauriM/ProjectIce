#ifndef ENGINE_SCENE_SCENESYSTEM_H
#define ENGINE_SCENE_SCENESYSTEM_H

#include "precompiled.h"

#include "engine/EngineSystem.h"
#include "engine/world/WorldSystem.h"
#include "game/actor/player/PlayerActor.h"

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
			game::actor::player::PlayerActor *playerActor;

		public:
			bool init(){
				worldSystem = new world::WorldSystem();
				if(!worldSystem->init()){
					return false;//world could not be initialized
				}

				worldSystem->generate();

				//create player
				playerActor = new game::actor::player::PlayerActor();

				playerActor->setName("Player");
				playerActor->getPos()->x = 20;
				playerActor->getPos()->y = 20;

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

			game::actor::player::PlayerActor* getPlayerActor(){
				return playerActor;
			}

			world::WorldSystem* getWorld(){
				return worldSystem;
			}
	};

}
}

#endif
