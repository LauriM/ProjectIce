#include "engine/scene/SceneSystem.h"

namespace engine {
namespace scene {

    SceneSystem::SceneSystem( world::WorldSystem * world, actor::ActorManager * actorMan, actor::ActorBase * player ) {
        worldSystem = world;
        actorManager = actorMan;
        playerActor = player; //TODO: WTF is player charachter handled this way !?!? FIX IT

		actorManager->getActorSystem()->insertActorToRoom(playerActor);
    }

    bool SceneSystem::init( ){
        return true;
    }

    void SceneSystem::uninit(){
        worldSystem->uninit();
    }

    void SceneSystem::update(){
        worldSystem->update();
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

}
}
