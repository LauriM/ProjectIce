#include "engine/math/random.h"
#include "engine/EngineSystem.h"
#include "engine/world/WorldSystem.h"

#include "proto/worldstate.pb.h"

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
					}

					if(z == heightMap[x][y]){
						//We are on the same level as the highest point, its ground
						rooms[x][y][z].roomType = ROOM_TYPE_GROUND;
					}

					if(z == heightMap[x][y]){
						if(z < WORLD_WATER_LEVEL){
							rooms[x][y][z].roomType = ROOM_TYPE_WATER; 
						}else{
							rooms[x][y][z].roomType = ROOM_TYPE_EMPTY;
						}
					}

					//Generate the room based on the roomType set.
					rooms[x][y][z].generate();
				}
			}
		}
	}

	Room* WorldSystem::getRoom(int x,int y,int z){
		//TODO: Add ASSERT here (simple) (2013-04-06)
		return &rooms[x][y][z];
	}

	Room* WorldSystem::getRoom(vec3 pos){
		//TODO: Add ASSERT here (simple) (2013-04-06)
		return &rooms[pos.x][pos.y][pos.z];
	}

	/**
	 * Load the whole world from the disk.
	 */
	void WorldSystem::loadFromFile(String filename){
		LOG_INFO("Loading from savefile...");

		std::fstream input;
		input.open(filename.c_str(),std::ios::in | std::ios::binary);

		worldMsg worldSave;
		worldSave.ParseFromIstream(&input);

		//Go trough rooms and fill the array
		for(int i = 0; i < worldSave.rooms_size(); ++i ){
			roomMsg roomSave = worldSave.rooms(i);

			//Lets get the pointer to the room
			Room *room = &rooms[roomSave.posx()][roomSave.posy()][roomSave.posz()];

			// ** Room Variables ** //
			room->roomType = (ROOM_TYPES)roomSave.roomtype();

			//Insert tiles to the room
			Tile* tileArray = room->getTileArray();
			for(int x = 0; x < roomSave.tiles_size(); ++x ){
				tileMsg tileSave = roomSave.tiles(x);

				// ** Tile variables ** //
				tileArray[x].blocks = tileSave.blocks();
				tileArray[x].hp     = tileSave.hp();
				tileArray[x].visual = tileSave.visual();
				//TODO: The visual is not correctly loaded (Or nothing in the world is correctly loaded?) (2013-04-16)
				//std::snprintf(&tileArray[x].visual,sizeof(char),"%c",tileSave.visual());
			}
		}

		input.close();
		LOG_INFO("Save loaded!");
	}

	/**
	 * Save the world with all the rooms and tile information to a file.
	 */
	void WorldSystem::saveToFile(String filename){
		LOG_INFO("Writing savefile...");
		worldMsg worldSave;

		worldSave.set_age(age);

		//Go trough rooms and add them to the array..
		for(int x = 0;x < WORLD_WIDTH;++x){
			for(int y = 0;y < WORLD_HEIGHT;++y){
				for(int z = 0;z < WORLD_DEPTH;++z){
					roomMsg *room =worldSave.add_rooms();

					room->set_posx(x);
					room->set_posy(y);
					room->set_posy(y);

					// ** Room variables **//
					room->set_roomtype(rooms[x][y][z].roomType);

					//Lets then add all the tiles to the room!

					Tile* tiles = rooms[x][y][z].getTileArray();

					for(int i = 0;i < (ROOM_WIDTH * ROOM_HEIGHT);++i ){
						tileMsg *tile = room->add_tiles();

						// ** Tile variables **
						tile->set_blocks(tiles[i].blocks);
						tile->set_visual(tiles[i].visual);
						tile->set_hp(tiles[i].hp);
					}
				}
			}
		}

		//WorldSave should now be ready... write it to file.
		
		std::fstream stream;
		stream.open(filename.c_str(), std::ios::out | std::ios::binary);

		worldSave.SerializeToOstream(&stream);

		stream.close();
		LOG_INFO("Save file written!");
	} /* savetofile */

}
}
