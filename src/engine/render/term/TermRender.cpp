#include "engine/render/term/TermRender.h"

namespace engine {
namespace render {
namespace term {

	void TermRender::update(){
		tb_cell cell; //temp cell used in rendering

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

		/* RENDER MAP */
		world::Room *currentRoom = sceneSystem->getWorld()->getRoom(cameraPos);

		vec2 pos;
		for(int x = 0;x < ROOM_WIDTH;++x){
			for(int y = 0;y < ROOM_HEIGHT;++y){
				pos.x = (x + 2);
				pos.y = (y + 2);
				//Changing the color
				world::Tile *tile = currentRoom->getTile(x,y);

				cell.ch = tile->visual;
				cell.fg = tile->fgColor;
				cell.bg = tile->bgColor;

				tb_put_cell(x,y,&cell);
			}
		}

		/* RENDER ACTORS */

		std::vector<actor::ActorBase *> actors = sceneSystem->getActorManager()->getActorsInRoom(cameraPos);

		cell.fg = TB_WHITE;
		cell.bg = TB_BLACK;
		for(int i = 0; i < actors.size();++i){
			cell.ch = actors.at(i)->getSymbol();
			tb_put_cell(actors.at(i)->getPos()->x, actors.at(i)->getPos()->y, &cell);
		}

		/* "RENDER" UI */

		uiSystem->windows.size();

		/* RENDER THE ACTUAL STUFF */

		tb_present();

		tb_event event;

		tb_poll_event(&event);
		return;
	}

}
}
}
