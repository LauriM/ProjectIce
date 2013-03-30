#include "engine/EngineSystem.h"
#include "engine/world/WorldSystem.h"

namespace engine {
namespace world {

	WorldSystem::WorldSystem(){}

	bool WorldSystem::init(){
		printf("World init\n");

		return true;
	}

	void WorldSystem::uninit(){
		printf("uninitting\n");
		return;
	}

	void WorldSystem::update(){
		printf("World tick\n");
		return;
	}

}
}
