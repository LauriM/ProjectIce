#ifndef ENGINE_WORLD_TILE
#define ENGINE_WORLD_TILE

namespace engine {
namespace world {

	/**
	 * Single tile inside a room
	 */
	class Tile {
	public:
		Tile(){
			visual = ' ';
		}

		char visual;
	};

}
}

#endif
