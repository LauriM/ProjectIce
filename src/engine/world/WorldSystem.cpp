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
		return;
	}

	void WorldSystem::update(){
		return;
	}

	void WorldSystem::generate(){
		//First lets generate the heightmap

		int heightMap[WORLD_WIDTH][WORLD_HEIGHT];

		for(int x = 0;x < WORLD_WIDTH;++x){
			for(int y = 0;y < WORLD_HEIGHT;++y){
				heightMap[x][y] = 0;
			}
		}

	}

}
}
