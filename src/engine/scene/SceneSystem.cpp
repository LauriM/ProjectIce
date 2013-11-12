#include "engine/scene/SceneSystem.h"

namespace engine {
namespace scene {

    SceneSystem::SceneSystem( world::WorldSystem * world, actor::ActorManager * actorMan, actor::ActorBase * player )
		: worldSystem(world)
		, actorManager(actorMan)
		, playerActor(player)
		{
			actorManager->getActorStorage()->insertActorToRoom(playerActor);
		}

    bool SceneSystem::init( ){
        return true;
    }

    void SceneSystem::uninit(){
        worldSystem->uninit();
    }

    void SceneSystem::update(){
		//Update the visible stuff for player
		worldSystem->updateVisualOnPosition(playerActor->getLocation(), playerActor->getPosition());

		//Handle actorTick for all actors in the same room with player
		std::vector<actor::ActorBase *> actors = actorManager->getActorStorage()->getActorsInRoom(playerActor->getLocation());

		for(unsigned int i = 0; i < actors.size();++i){
			actorManager->actorTick(actors.at(i));
		}

		//remove killed actors
		actorManager->getActorStorage()->handleRemoveQueue();

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
