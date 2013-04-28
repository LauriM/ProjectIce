#ifndef ENGINE_WORLD_ROOM_H
#define ENGINE_WORLD_ROOM_H 

#include "precompiled.h"

#include "engine/world/Tile.h"

#define ASSERT_TILE_XY(p_x,p_y) ASSERT_TILE_X(p_x) ASSERT_TILE_Y(p_y)

#define ASSERT_TILE_X(p_x) assert(p_x >= 0); assert(p_x < ROOM_WIDTH);
#define ASSERT_TILE_Y(p_y) assert(p_y >= 0); assert(p_y < ROOM_HEIGHT);

namespace engine {
namespace world {

	enum ROOM_TYPES{
		ROOM_TYPE_EMPTY   = 0, //void, air or uninitialiazed tile
		ROOM_TYPE_GROUND  = 1,
		ROOM_TYPE_WATER   = 2,
		ROOM_TYPE_DUNGEON = 3,
	};

	/**
	* Room contains the layout of the room, with all the tile data.
	*/
	class Room {
	public:
		Room(){
			//Initialize empty room
			roomType = ROOM_TYPE_EMPTY;

			Tile tempTile;
			tempTile.setType(TILE_VOID);

			for(int i = 0;i < (ROOM_WIDTH * ROOM_HEIGHT);++i){
				tiles[i] = tempTile;
			}
		}

	private:
		Tile tiles[ROOM_WIDTH * ROOM_HEIGHT];

	public:
		//Roomtype also used as visual
		ROOM_TYPES roomType;

		//TODO: added get tile by vec2 (2013-04-06)
		Tile* getTile(int x,int y);
		Tile* getTileArray();

		void generate();
	};
}
}

#endif /* ENGINE_WORLD_ROOM_H */
