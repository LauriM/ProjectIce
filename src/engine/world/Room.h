#ifndef ENGINE_WORLD_ROOM_H
#define ENGINE_WORLD_ROOM_H 

#include "precompiled.h"

#include "engine/world/Tile.h"

namespace engine {
namespace world {

	/**
	* Room contains the layout of the room, with all the tile data.
	*/
	class Room {
	public:
		Room(){
			//Initialize empty room
			Tile tempTile;

			for(int x = 0;x < ROOM_WIDTH;++x){
				for(int y = 0;y < ROOM_HEIGHT;++y){
					tiles[x][y] = tempTile;
				}
			}
		}

		Tile tiles[ROOM_WIDTH][ROOM_HEIGHT];
	};
}
}

#endif /* ENGINE_WORLD_ROOM_H */
