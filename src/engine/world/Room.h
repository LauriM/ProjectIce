#ifndef ENGINE_WORLD_ROOM_H
#define ENGINE_WORLD_ROOM_H 

#include "precompiled.h"

#include "engine/world/Tile.h"

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

			for(int i = 0;i < ROOM_WIDTH * ROOM_HEIGHT;++i){
				tiles[i] = tempTile;
			}

			//Set the default visual style
			visual = '-';
		}

	private:
		char visual;
		Tile tiles[ROOM_WIDTH * ROOM_HEIGHT];

	public:
		ROOM_TYPES roomType;

		Tile* getTile(int x,int y);

		void generate();
	};
}
}

#endif /* ENGINE_WORLD_ROOM_H */
