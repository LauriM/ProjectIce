#ifndef ENGINE_WORLD_TILE
#define ENGINE_WORLD_TILE

#include "engine/render/Color.h"

namespace engine {
namespace world {

	//Tile types are only used when generating the tiles, tile state can change during runtime
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
			Tile();
			Tile(TILE_TYPES type);

			int type;
			char visual;    //Visual displayed on the gameview
			bool blocks;    //Does it block movement/visuals
			int hp;         //How many hits it can take before getting destroyed
			render::Color fgColor; //Colors
			render::Color bgColor;

			void setType(TILE_TYPES type);

			/* getters & setters */

			void setFgColor(render::Color color);
			void setBgColor(render::Color color);
	};

}
}

#endif
