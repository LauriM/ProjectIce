#include "precompiled.h"

#include "engine/EngineSystem.h"
#include "engine/render/RenderSystem.h"

namespace engine {
namespace render {

	RenderSystem::RenderSystem(engine::world::WorldSystem *worldSystem)
	: worldSystem(worldSystem)
	{}

	bool RenderSystem::init(){
		initscr();
		if(has_colors() == false){
			endwin();
			printf("Your terminal doesn't support colors...\nFind more modern system/terminal.");
			return false;
		}

		start_color();

		return true;
	}

	void RenderSystem::uninit(){
		clear();
		endwin();
		return;
	}

	void RenderSystem::update(){

		//Render the map..
		vec2 tempPos;
		tempPos.x = 10;
		tempPos.y = 10;
		drawChar(tempPos,'#');
		tempPos.x = 11;
		tempPos.y = 11;
		drawChar(tempPos,'#');
		tempPos.x = 11;
		tempPos.y = 10;
		drawChar(tempPos,'#');

		return;
	}

	void RenderSystem::drawChar(vec2 pos,int character){
		move(pos.y,pos.x);
		printw("%c",character);
	}
}
}
