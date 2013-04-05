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

		//Lets get the simple types out from the way first... air,empty and water...
		printf("lol");
	}

}
}
