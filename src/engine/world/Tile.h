#ifndef ENGINE_WORLD_TILE
#define ENGINE_WORLD_TILE

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

	//TODO: CLEAN THIS UP ITS A MESS (2013-08-21)

	/**
	 * Single tile inside a room
	 */
	class Tile {
		public:
			/**
			* Create the default void tile
			*/
			Tile(){
				visual                 = ' ';
				blocks                 = false;
				hp                     = 100;
				fgColor                = TB_WHITE;
				bgColor                = TB_BLACK;
				//add -> tickFunction (Executed every time entity or actor is in the tile) (?)
			}

			Tile(TILE_TYPES type){
				Tile();
				setType(type);
			}

			char visual;    //Visual displayed on the gameview
			bool blocks;    //Does it block movement/visuals
			int hp;         //How many hits it can take before getting destroyed
			int fgColor; //Colors
			int bgColor;

			void setType(TILE_TYPES type);

			/* getters & setters */

			void setFgColor(int color){
				fgColor = color;
			}

			void setBgColor(int color){
				bgColor = color;
			}
	};

}
}

#endif
