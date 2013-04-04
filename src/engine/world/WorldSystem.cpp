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

		//FIXME: Randomly segfaulting inside this function!

		for(int x = 0;x < WORLD_WIDTH;++x){
			for(int y = 0;y < WORLD_HEIGHT;++y){
				heightMap[x][y] = WORLD_WATER_LEVEL;
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
				heightMap[x][y] = 0;
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


		//Okey, we have the heightmap, now we need to generate contents for the rooms.

		//TODO: Consider creating contents for rooms lazily.

		//Go trough the heightmap and assign the types.

		for(int x = 0;x < WORLD_WIDTH;++x){
			for(int y = 0;y < WORLD_HEIGHT;++y){

				//Loop from bottom to top, filling the correct values
				for(int z = 0;z < WORLD_DEPTH;++z){

					if(z < heightMap[x][y]){
						//Current depth is under the highest point, add dungeon
						rooms[x][y][z].roomType = ROOM_TYPE_DUNGEON; 
						printf("#");
					}

					if(z == heightMap[x][y]){
						//We are on the same level as the highest point, its ground
						rooms[x][y][z].roomType = ROOM_TYPE_GROUND;
						printf("|");
					}

					if(z == heightMap[x][y]){
						if(z < WORLD_WATER_LEVEL){
							rooms[x][y][z].roomType = ROOM_TYPE_WATER; 
							printf("*");
						}else{
							rooms[x][y][z].roomType = ROOM_TYPE_AIR;
							printf(".");
						}
					}
				}
				printf("\n");
			}
		}
	}

}
}
