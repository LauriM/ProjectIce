#include "engine/world/Room.h"
#include "engine/math/random.h"
#include "engine/math/AABB.h"

namespace engine {
namespace world {

	Room::Room(){
		//Initialize empty room
		roomType = ROOM_TYPE_EMPTY;

		Tile tempTile;
		tempTile.setType(TILE_VOID);

		for(int i = 0;i < (ROOM_WIDTH * ROOM_HEIGHT);++i){
			tiles[i] = tempTile;
		}
	}

	Tile* Room::getTile(vec2 pos){
		return getTile(pos.x,pos.y);
	}

	Tile* Room::getTile(int x,int y){
		ASSERT_TILE_XY(x,y);

		return &tiles[(x * ROOM_HEIGHT) + y];
	}

	void Room::setTile(vec2 pos,Tile tile){
		setTile(pos.x,pos.y,tile);
	}

	void Room::setTile(int x,int y,Tile tile){
		ASSERT_TILE_XY(x,y);
		tiles[(x * ROOM_HEIGHT) + y] = tile;
	}

	/**
	 * Regenerate the room.
	 *
	 * Input: Reads roomType and builds on top of that.
	 */
	void Room::generate(){
		//Lets get the simple types out from the way first... air and water...

		Tile tempTile;

		switch(roomType){
		case ROOM_TYPE_EMPTY:
			//Loop trough all tiles and set them to void
			tempTile.setType(TILE_VOID);

			for(int i = 0;i < (ROOM_WIDTH * ROOM_HEIGHT);++i){
				tiles[i] = tempTile;
			}

			break;
		case ROOM_TYPE_WATER:
			tempTile.setType(TILE_WATER);

			for(int i = 0;i < (ROOM_WIDTH * ROOM_HEIGHT);++i){
				tiles[i] = tempTile;
			}

			break;
		case ROOM_TYPE_GROUND:
			tempTile.setType(TILE_GRASS);

			for(int i = 0;i < (ROOM_WIDTH * ROOM_HEIGHT);++i){
				tiles[i] = tempTile;
			}

			for(int i = 0;i < (ROOM_WIDTH * ROOM_HEIGHT);++i){
				if(randomRange(0,10) > 8){
					tiles[i] = Tile(TILE_TREE);
				}
			}

			break;
		case ROOM_TYPE_DUNGEON:
			tempTile.setType(TILE_ROCK_FLOOR);

			//reset room
			for(int i = 0;i < (ROOM_WIDTH * ROOM_HEIGHT);++i){
				tiles[i] = tempTile;
			}

			//Base with random amounts of rock
			for(int i = 0;i < (ROOM_WIDTH * ROOM_HEIGHT);++i){
				if(randomRange(0,10) > 1){
					tiles[i] = Tile(TILE_SOLID_ROCK);
				}
			}

			//Insert the random rooms
			int roomCount = randomRange(2,6);

			while(roomCount > 0){
				AABB room;
				//first size, then position, so we are sure it wont go over the limits
				room.size.x = randomRange(2,5);
				room.size.y = randomRange(2,5);

				room.pos.x = randomRange(0,(ROOM_WIDTH  - room.size.x));
				room.pos.y = randomRange(0,(ROOM_HEIGHT - room.size.y));

				//Room stuff is ok, lets draw it in
				for(int x = room.pos.x;x < room.size.x;++x){
					for(int y = room.pos.y;y < room.size.y;++y){
						setTile(x,y,Tile(TILE_ROCK_FLOOR));
					}
				}

				--roomCount;
			}

			break;
		}
	}

	/**
	 * Returns direct access to the tile array, useful when raw access needed to the array.
	 */
	Tile* Room::getTileArray(){
		return tiles;
	}

	/**
	 * Prints the room layout to the cmd. Used for debugging.
	 */
	void Room::printLayout(){
		for(int y = 0;y < ROOM_HEIGHT;++y){
			for(int x = 0;x < ROOM_WIDTH;++x){
				printf("%c",getTile(x,y)->visual);
			}
			printf("\n");
		}
	}

}
}
