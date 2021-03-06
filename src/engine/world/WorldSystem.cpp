#include "precompiled.h"
#include "engine/math/random.h"
#include "engine/EngineSystem.h"
#include "engine/world/WorldSystem.h"
#include "engine/console/Cvar.h"

namespace cvar {
	CVAR(int, debug_heightmap,0,CVAR_CHEAT);
}

namespace engine {
namespace world {

	WorldSystem::WorldSystem(){}

	bool WorldSystem::init(){
		LOG_INFO("World init");

		roomList = new RoomList();

		age = 0; //The world is 0 turns old

		return true;
	}

	void WorldSystem::uninit(){
		delete roomList;
	}

	void WorldSystem::update(){
		++age;
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
						checkWest(heightMap,xi,yi);
					}
					if( xi < (WORLD_WIDTH - 1) ) {
						checkEast(heightMap,xi,yi);
					}
					if( yi > 0 ) {
						checkNorth(heightMap,xi,yi);
					}
					if( yi < (WORLD_HEIGHT - 1) ) {
						checkSouth(heightMap,xi,yi);
					}
				}
			}
		}

		//Print height map if debugging for it is asked
		if(*cvar::debug_heightmap){
			printf("# HEIGHTMAP #\n");
			for(int x = 0;x < WORLD_WIDTH;++x){
				for(int y = 0;y < WORLD_HEIGHT;++y){
					printf(",%i",heightMap[x][y]);
				}
				printf("\n");
			}
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
						getRoom(x,y,z)->roomType = ROOM_TYPE_DUNGEON;
					}

					if(z == heightMap[x][y]){
						//We are on the same level as the highest point, its ground
						getRoom(x,y,z)->roomType = ROOM_TYPE_GROUND;
					}

					if(z == heightMap[x][y]){
						if(z < WORLD_WATER_LEVEL){
							getRoom(x,y,z)->roomType = ROOM_TYPE_WATER;
						}
						if(z > heightMap[x][y]){
							getRoom(x,y,z)->roomType = ROOM_TYPE_EMPTY;
						}
					}

					//Generate the room based on the roomType set.
					getRoom(x,y,z)->generate();
				}
			}
		}
	}

	/**
	 * Flows the "mountains" down.
	 */
	void WorldSystem::checkWest(int heightMap[][WORLD_HEIGHT], int x, int y){
		if( heightMap[x][y] < heightMap[x-1][y] ){
			heightMap[x][y] = heightMap[x-1][y] - 1;
		}
	}

	void WorldSystem::checkEast(int heightMap[][WORLD_HEIGHT], int x, int y){
		if( heightMap[x][y] < heightMap[x+1][y] ){
			heightMap[x][y] = heightMap[x+1][y] - 1;
		}
	}

	void WorldSystem::checkNorth(int heightMap[][WORLD_HEIGHT], int x, int y){
		if( heightMap[x][y] < heightMap[x][y-1]){
			heightMap[x][y] = heightMap[x][y-1] - 1;
		}
	}

	void WorldSystem::checkSouth(int heightMap[][WORLD_HEIGHT], int x, int y){
		if( heightMap[x][y] < heightMap[x][y+1]){
			heightMap[x][y] = heightMap[x][y+1] - 1;
		}
	}

	Room* WorldSystem::getRoom(int x,int y,int z){
		ASSERT_ROOM_XYZ(x,y,z);
		return getRoom(vec3(x,y,z));
	}

	Room* WorldSystem::getRoom(vec3 pos){
		ASSERT_ROOM_XYZ(pos.x,pos.y,pos.z);

		Room *room;

		//TODO: datastorage method for rooms should be optimized!

		//Build the hash thing:
		String posString = boost::lexical_cast<String,int>(pos.x);
		posString += boost::lexical_cast<String,int>(pos.y);
		posString += boost::lexical_cast<String,int>(pos.z);

		//Find the room from the hashmap
		RoomList::iterator iter = roomList->find(posString);

		if(iter == roomList->end()){
			//Could not find the room, lets create it!
			room = new Room();

			roomList->insert(RoomList::value_type(posString,room));
		}else{
			room = iter->second;
		}

		return room;
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


	/**
	 * Update visual data on the location/position given.
	 */
	void WorldSystem::updateVisualOnPosition(vec3 location, vec2 position){
		Room *room = getRoom(location);

		vec2 pos;
		for(pos.x = 0; pos.x < ROOM_WIDTH; ++pos.x){
			for(pos.y = 0; pos.y < ROOM_HEIGHT; ++pos.y){
				if(room->lineOfSight(position,pos)){
					room->applyVisual(pos);
				}
			}
		}
	}

}
}
