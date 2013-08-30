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

	Tile::Tile(){
		visual                 = ' ';
		blocks                 = false;
		hp                     = 100;
		fgColor                = render::C_WHITE;
		bgColor                = render::C_BLACK;
		//add -> tickFunction (Executed every time entity or actor is in the tile) (?)
	}

	Tile::Tile(TILE_TYPES type){
		Tile();
		setType(type);
	}

	void Tile::setType(TILE_TYPES type){
		//Good ol' big swith
		//Maybe in future it will be some awesome piece of lua code that reads xml or some shit :D

		switch(type){
			//p_type                    , p_visual , p_blocks , p_hp , fg color , bg color
			DEFINE_TILE(TILE_VOID       , ' '      , false    , 0    , render::C_WHITE , render::C_BLACK);
			DEFINE_TILE(TILE_GRASS      , '.'      , false    , 0    , render::C_GREEN , render::C_BLACK);
			DEFINE_TILE(TILE_ROCK_FLOOR , '.'      , false    , 0    , render::C_WHITE , render::C_BLACK);
			DEFINE_TILE(TILE_SOLID_ROCK , '#'      , true     , 500  , render::C_WHITE , render::C_BLACK);
			DEFINE_TILE(TILE_TREE       , 'O'      , true     , 25   , render::C_GREEN , render::C_BLACK);
			DEFINE_TILE(TILE_WATER      , '.'      , false    , 0    , render::C_BLUE  , render::C_BLACK);
		}
	}

	void Tile::setFgColor(render::Color color){
		fgColor = color;
	}

	void Tile::setBgColor(render::Color color){
		bgColor = color;
	}

}
}
