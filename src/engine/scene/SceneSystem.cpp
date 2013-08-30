#include "engine/scene/SceneSystem.h"

namespace engine {
namespace scene {

    SceneSystem::SceneSystem( world::WorldSystem * world, actor::ActorManager * actorMan, actor::ActorBase * player ) {
        worldSystem = world;
        actorManager = actorMan;
        playerActor = player; //TODO: WTF is player charachter handled this way !?!? FIX IT
        playerInventory = new actor::Inventory();

        roomInventory = new inventory::RoomInventory( worldSystem->getRoom(0,0,0) );

        actorManager->insertActorToRoom(playerActor);
    }

    bool SceneSystem::init( ){
        return true;
    }

    void SceneSystem::uninit(){
        worldSystem->uninit();
    }

    void SceneSystem::update(){
        worldSystem->update();

        /*
        std::vector<actor::ActorBase*> actorList = actorManager->getActorsInRoom(vec3(0,0,0));

        std::vector<actor::ActorBase*>::iterator it;
        for( it = actorList.begin(); it != actorList.end(); ++it ) {
            (*it)->update();
        }
        */
    }

    inventory::RoomInventory* SceneSystem::getRoomInventoryByPos(vec3 pos){
        //TODO: ONLY RETURNS THE TEST ROOM.
        return roomInventory;
    }

    actor::ActorManager* SceneSystem::getActorManager(){
        return actorManager;
    }

    actor::ActorBase* SceneSystem::getPlayerActor(){
        return playerActor;
    }

    world::WorldSystem* SceneSystem::getWorld(){
        return worldSystem;
    }

    void SceneSystem::addItem(item::ItemBase * item) {
        roomInventory->addItemToPosition( vec2(0,0), item );
    }

}
}