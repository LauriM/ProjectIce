#include "precompiled.h"
#include "engine/world/Tile.h"

//Some fancy defines

#define DEFINE_TILE(p_type,p_visual,p_blocks,p_hp,p_fgColor,p_bgColor) case p_type:\
	visual  = p_visual;\
	blocks  = p_blocks;\
	hp      = p_hp;\
	fgColor = p_fgColor;\
	bgColor = p_bgColor;\
	break;\

namespace engine {
namespace world {

	void Tile::setType(TILE_TYPES type){
		//Good ol' big swith
		//Maybe in future it will be some awesome piece of lua code that reads xml or some shit :D

		switch(type){
			//p_type                    , p_visual , p_blocks , p_hp , fg color           , bg color
			DEFINE_TILE(TILE_VOID       , ' '      , false    , 0    , COLOR_WHITE , COLOR_BLACK);
			DEFINE_TILE(TILE_GRASS      , '.'      , false    , 0    , COLOR_WHITE , COLOR_BLACK);
			DEFINE_TILE(TILE_ROCK_FLOOR , '.'      , false    , 0    , COLOR_WHITE , COLOR_BLACK);
			DEFINE_TILE(TILE_SOLID_ROCK , '#'      , true     , 500  , COLOR_WHITE , COLOR_BLACK);
			DEFINE_TILE(TILE_TREE       , 'O'      , true     , 25   , COLOR_GREEN , COLOR_BLACK);
			DEFINE_TILE(TILE_WATER      , '.'      , false    , 0    , COLOR_WHITE , COLOR_BLACK);
		}
	}

}
}
