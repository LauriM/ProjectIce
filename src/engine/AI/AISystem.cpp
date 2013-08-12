#include "precompiled.h"

#include "engine/AI/AISystem.h"

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
		//TODO: This is still just a skeleton
		sceneSystem->getActorManager();
	}

}
}
