#include "engine/math/random.h"
#include "engine/EngineSystem.h"
#include "engine/world/WorldSystem.h"

namespace engine {
namespace world {

	WorldSystem::WorldSystem(){}

	bool WorldSystem::init(){
		LOG_INFO("World init");

		age = 0; //The world is 0 turns old

		//Init empty world
		Room emptyRoom;

		for(int x = 0;x < WORLD_WIDTH;++x){
			for(int y = 0;y < WORLD_HEIGHT;++y){
				for(int z = 0;z < WORLD_DEPTH;++z){
					rooms[x][y][z] = emptyRoom;
				}
			}
		}

		//create player
		playerActor = new game::actor::player::PlayerActor();

		playerActor->setName("Player");

		return true;
	}

	void WorldSystem::uninit(){
		return;
	}

	void WorldSystem::update(){
		playerActor->update();
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

			int x = randomRange(0,WORLD_WIDTH-1); //without -1 it will overwrite the memory..
			int y = randomRange(0,WORLD_HEIGHT-1);

			heightMap[x][y] = heightMap[x][y] + height;

			if(heightMap[x][y] < 0){
				heightMap[x][y] = 0;
			}

			//Okey, mountain point is set, lets now "flow" it down

			//int startX = x; //move the x/y points to different vars
			//int startY = y;

			for( int xi = 0; xi < WORLD_WIDTH; xi++ ) {
				for ( int yi = 0; yi < WORLD_HEIGHT; yi++ ) {

					// Stay in the bounds!
					if( xi > 0 ) {
						_checkWest(heightMap,xi,yi);
					}
					if( xi < (WORLD_WIDTH - 1) ) {
						_checkEast(heightMap,xi,yi);
					}
					if( yi > 0 ) {
						_checkNorth(heightMap,xi,yi);
					}
					if( yi < (WORLD_HEIGHT - 1) ) {
						_checkSouth(heightMap,xi,yi);
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
					}

					if(z == heightMap[x][y]){
						//We are on the same level as the highest point, its ground
						rooms[x][y][z].roomType = ROOM_TYPE_GROUND;
					}

					if(z == heightMap[x][y]){
						if(z < WORLD_WATER_LEVEL){
							rooms[x][y][z].roomType = ROOM_TYPE_WATER;
						}
						if(z > heightMap[x][y]){
							rooms[x][y][z].roomType = ROOM_TYPE_EMPTY;
						}
					}

					//Generate the room based on the roomType set.
					rooms[x][y][z].generate();
				}
			}
		}
	}

	/**
	 * Flows the "mountains" down.
	 */
	void WorldSystem::_checkWest(int heightMap[][WORLD_HEIGHT], int x, int y){
		if( heightMap[x][y] < heightMap[x-1][y] ){
			heightMap[x][y] = heightMap[x-1][y] - 1;
		}
	}

	void WorldSystem::_checkEast(int heightMap[][WORLD_HEIGHT], int x, int y){
		if( heightMap[x][y] < heightMap[x+1][y] ){
			heightMap[x][y] = heightMap[x+1][y] - 1;
		}
	}

	void WorldSystem::_checkNorth(int heightMap[][WORLD_HEIGHT], int x, int y){
		if( heightMap[x][y] < heightMap[x][y-1]){
			heightMap[x][y] = heightMap[x][y-1] - 1;
		}
	}

	void WorldSystem::_checkSouth(int heightMap[][WORLD_HEIGHT], int x, int y){
		if( heightMap[x][y] < heightMap[x][y+1]){
			heightMap[x][y] = heightMap[x][y+1] - 1;
		}
	}

	Room* WorldSystem::getRoom(int x,int y,int z){
		ASSERT_ROOM_XYZ(x,y,z);
		return &rooms[x][y][z];
	}

	Room* WorldSystem::getRoom(vec3 pos){
		ASSERT_ROOM_XYZ(pos.x,pos.y,pos.z);
		return &rooms[pos.x][pos.y][pos.z];
	}

	/**
	 * Load the whole world from the disk.
	 */
	void WorldSystem::loadFromFile(String filename){
		LOG_WARNING("Reading from file not implemented");
	}

	/**
	 * Save the world with all the rooms and tile information to a file.
	 */
	void WorldSystem::saveToFile(String filename){
		LOG_WARNING("Writing to save file not implemented");
	}

}
}
