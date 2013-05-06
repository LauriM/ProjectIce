#include "precompiled.h"

#include "engine/EngineSystem.h"
#include "engine/render/RenderSystem.h"
#include "engine/world/Room.h"
#include "engine/world/Tile.h"

namespace engine {
namespace render {

	RenderSystem::RenderSystem(world::WorldSystem *worldSystem)
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

		cameraPos.x = 0;
		cameraPos.y = 0;
		cameraPos.z = 0;

		return true;
	}

	void RenderSystem::uninit(){
		clear();
		endwin();
		return;
	}

	void RenderSystem::update(){
		clear();

		//Render world position info on top of the screen..
		move(0,0);
		printw("World x: %i y: %i z: %i",cameraPos.x,cameraPos.y,cameraPos.z);

		//Check that the camera is not out of bounds...
		if(cameraPos.x < 0 || cameraPos.x >= WORLD_WIDTH){
			LOG_ERROR("Camera out of bounds! (x)");
			return;
		}

		if(cameraPos.y < 0 || cameraPos.y >= WORLD_HEIGHT){
			LOG_ERROR("Camera out of bounds! (y)");
			return;
		}

		if(cameraPos.z < 0 || cameraPos.z >= WORLD_DEPTH){
			LOG_ERROR("Camera out of bounds! (z)");
			return;
		}

		//Render the map..
		world::Room *currentRoom = worldSystem->getRoom(cameraPos);

		vec2 pos;
		for(int x = 0;x < ROOM_WIDTH;++x){
			for(int y = 0;y < ROOM_HEIGHT;++y){
				pos.x = (x + 2);
				pos.y = (y + 2);
				drawChar(pos,currentRoom->getTile(x,y)->visual);
			}
		}

		return;
	}

	void RenderSystem::drawChar(vec2 pos,int character){
		move(pos.y,pos.x);
		printw("%c",character);
	}
}
}
