#ifndef ENGINE_WORLD_TILE
#define ENGINE_WORLD_TILE

namespace engine {
namespace world {

	enum TILE_TYPES{
		TILE_VOID = 0,
		TILE_GRASS,
		TILE_ROCK_FLOOR,
		TILE_SOLID_ROCK,
		TILE_TREE,
		TILE_WATER,
	};

	/**
	 * Single tile inside a room
	 */
	class Tile {
	public:
		/**
		 * Create the default void tile
		 */
		Tile(){
			visual = ' ';
			blocks = false;
			hp = 100;
			//add -> color
			//add -> tickFunction (Executed every time entity or actor is in the tile)
		}

		char visual; //Visual displayed on the gameview
		bool blocks; //Does it block movement/visuals
		int hp;      //How many hits it can take before getting destroyed

		void setType(TILE_TYPES type);
	};

}
}

#endif
