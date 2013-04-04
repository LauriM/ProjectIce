#include "engine/world/Room.h"

namespace engine {
namespace world {

	Tile* Room::getTile(int x,int y){
		return &tiles[x * ROOM_WIDTH + y];
	}

}
}
