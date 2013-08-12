#ifndef ENGINE_SCENE_SCENESYSTEM_H
#define ENGINE_SCENE_SCENESYSTEM_H

#include "precompiled.h"

#include "engine/EngineSystem.h"
#include "engine/world/WorldSystem.h"
#include "engine/inventory/ActorInventory.h"
#include "engine/inventory/RoomInventory.h"
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

			//TODO: Create RoomIventoryManager
			inventory::RoomInventory * roomInventory;

			// the rest of the world
			std::vector<actor::ActorBase*> actorList;

			// player objects
			actor::ActorBase * playerActor;
			inventory::ActorInventory * playerInventory;
		public:

			SceneSystem( world::WorldSystem * world, actor::ActorManager * actorMan, actor::ActorBase * player ) {
				worldSystem = world;
				actorManager = actorMan;
				playerActor = player; //TODO: WTF is player charachter handled this way !?!? FIX IT
				playerInventory = new inventory::ActorInventory();
				playerInventory->setOwner(playerActor);

				roomInventory = new inventory::RoomInventory();
				roomInventory->setRoomOwner( worldSystem->getRoom(0,0,0) );

				actorManager->insertActorToRoom(playerActor);
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

				/*
					Process the actors on current room here


				std::vector<actor::ActorBase*>::iterator it;
				for( it = actorList.begin(); it != actorList.end(); ++it ) {
					(*it)->update();
				}
				*/
			}

			/*getters & setters */

			inventory::RoomInventory * getRoomInventoryByPos(vec3 pos){
				//TODO: ONLY RETURNS THE TEST ROOM.
				return roomInventory;
			}

			actor::ActorManager * getActorManager(){
				return actorManager;
			}

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

			void addItem(item::ItemBase * item) {
				roomInventory->addItem( vec2(0,0), item );
			}

	};

}
}

#endif
