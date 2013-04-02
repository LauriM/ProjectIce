#include "engine/math/random.h"
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
				heightMap[x][y] = 1; //Default height
			}
		}

		//Random amount of mountains
		int mountainCount = randomRange(5,10);

		for(int i = 0;i < mountainCount;i++){
			int height = randomRange(-2,5);

			int x = randomRange(0,WORLD_WIDTH);
			int y = randomRange(0,WORLD_HEIGHT);

			heightMap[x][y] = heightMap[x][y] + height;

			if(heightMap[x][y] < 0){
				heightMap[x][y] = 2;
			}

			//Okey, mountain point is set, lets now "flow" it down

			//int startX = x; //move the x/y points to different vars
			//int startY = y;

			for(x = 1;x < WORLD_WIDTH - 1;++x){
				for(y = 1;y < WORLD_HEIGHT - 1;++y){
					//Check if surrounding tiles are bigger

					if(heightMap[x][y] < heightMap[x-1][y]){
						heightMap[x][y] = heightMap[x-1][y] - 1;
						//If current tile is lower than next tile set it same expect one lower
					}

					if(heightMap[x][y] < heightMap[x+1][y]){
						heightMap[x][y] = heightMap[x+1][y] - 1;
						//If current tile is lower than next tile set it same expect one lower
					}

					if(heightMap[x][y] < heightMap[x][y-1]){
						heightMap[x][y] = heightMap[x][y-1] - 1;
						//If current tile is lower than next tile set it same expect one lower
					}

					if(heightMap[x][y] < heightMap[x][y+1]){
						heightMap[x][y] = heightMap[x][y+1] - 1;
						//If current tile is lower than next tile set it same expect one lower
					}
				}
			}
		}

		for(int x = 0;x < WORLD_WIDTH;++x){
			for(int y = 0;y < WORLD_HEIGHT;++y){
				printf(",%i",heightMap[x][y]);
			}
			printf("\n");
		}

	}

}
}
