#include "precompiled.h"

#include "engine/AI/AISystem.h"
#include <vector>

namespace engine {
namespace AI {

	AISystem::AISystem(scene::SceneSystem *sceneSystem)
		: sceneSystem(sceneSystem)
	{}

	bool AISystem::init(){
		LOG_INFO("AISystem init");

		return true;
	}

	void AISystem::uninit(){
		LOG_INFO("AISystem uninit");
	}

	void AISystem::update(){
		//This is going to be deprecrated most likely, AI system under heavy development.
		sceneSystem->getActorManager();
	}

}
}
