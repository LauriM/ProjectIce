#include "engine/world/Room.h"
#include "engine/math/random.h"

namespace engine {
namespace world {

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

			for(int i = 0;i < (ROOM_WIDTH * ROOM_HEIGHT);++i){
				tiles[i] = tempTile;
			}

			for(int i = 0;i < (ROOM_WIDTH * ROOM_HEIGHT);++i){
				if(randomRange(0,1)){
					tiles[i] = Tile(TILE_SOLID_ROCK);
				}
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

}
}
