#include "engine/world/Tile.h"

//Some fancy defines

#define DEFINE_TILE(p_type,p_visual,p_blocks,p_hp) case p_type:\
	visual = p_visual;\
	blocks = p_blocks;\
	hp     = p_hp;\
	break;\

namespace engine {
namespace world {

	void Tile::setType(TILE_TYPES type){
		//Good ol' big swith
		//Maybe in future it will be some awesome piece of lua code that reads xml or some shit :D
		
		switch(type){
			//p_type                    , p_visual , p_blocks , p_hp
			DEFINE_TILE(TILE_VOID       , ' '      , false    , 0);
			DEFINE_TILE(TILE_GRASS      , '.'      , false    , 0);
			DEFINE_TILE(TILE_ROCK_FLOOR , '.'      , false    , 0);
			DEFINE_TILE(TILE_SOLID_ROCK , '#'      , true     , 500);
			DEFINE_TILE(TILE_TREE       , 'O'      , false    , 25);
			DEFINE_TILE(TILE_WATER      , '.'      , false    , 0);
		}
	}

}
}
