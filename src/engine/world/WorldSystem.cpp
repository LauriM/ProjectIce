#include "engine/EngineSystem.h"
#include "engine/world/WorldSystem.h"

namespace engine {
namespace world {

	WorldSystem::WorldSystem(){}

	bool WorldSystem::init(){
		printf("World init\n");

		//Init empty world
		Room emptyRoom;

		for(int x = 0;x < WORLD_WIDTH;++x){
			for(int y = 0;y < WORLD_HEIGHT;++y){
				for(int z = 0;z < WORLD_DEPTH;++z){
					rooms[x][y][z] = emptyRoom;
				}
			}
		}

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
