#include "engine/world/Room.h"

namespace engine {
namespace world {

	Tile* Room::getTile(int x,int y){
		//TODO: Add some assertions here! (2013-04-04)
		return &tiles[x * ROOM_WIDTH + y];
	}

}
}
