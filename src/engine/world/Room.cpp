#include "engine/world/Room.h"

namespace engine {
namespace world {

	Tile* Room::getTile(int x,int y){
		//TODO: Add some assertions here! (2013-04-04)
		return &tiles[x * ROOM_WIDTH + y];
	}

	/**
	 * Regenerate the room.
	 *
	 * Input: Reads roomType and builds on top of that.
	 */
	void Room::generate(){
		//Lets get the simple types out from the way first... air and water...

		switch(roomType){
		case ROOM_TYPE_EMPTY:
			//Loop trough all tiles and set them to void
			Tile tempTile;
			tempTile.setType(TILE_VOID);

			for(int i = 0;i < ROOM_WIDTH * ROOM_HEIGHT;++i){
				tiles[i] = tempTile;
			}

			break;
		case ROOM_TYPE_WATER:
			Tile waterTile;
			waterTile.setType(TILE_WATER);

			for(int i = 0;i < ROOM_WIDTH * ROOM_HEIGHT;++i){
				tiles[i] = waterTile;
			}
			break;
		case ROOM_TYPE_GROUND:
			Tile groundTile;
			groundTile.setType(TILE_GRASS);

			for(int i = 0;i < ROOM_WIDTH * ROOM_HEIGHT;++i){
				tiles[i] = groundTile;
			}

		case ROOM_TYPE_DUNGEON:
			Tile rockFloor;
			rockFloor.setType(TILE_ROCK_FLOOR);

			for(int i = 0;i < ROOM_WIDTH * ROOM_HEIGHT;++i){
				tiles[i] = rockFloor;
			}
		}
	}

	/**
	 * Returns direct access to the tile array, useful when raw access needed to the array.
	 */
	Tile* Room::getTileArray(){
		return tiles;
	}

}
}
