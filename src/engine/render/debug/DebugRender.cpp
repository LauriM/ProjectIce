#include "precompiled.h"

#include "engine/render/debug/DebugRender.h"

//Only compile debugrender if its in use
#ifdef DEBUGRENDER

namespace engine {
namespace render {
namespace debug {

	void DebugRender::update(){
		stepsLeft--;

		if(stepsLeft < 0){

			uiSystem->windows.size(); //these are not unused
			sceneSystem->getActorManager();

			if(DEBUGRENDER_HISTORY == true){
				console::ConsoleSystem::MsgHistory hist = console::ConsoleSystem::getMsgHistory();

				if(DEBUGRENDER_CLS == true){
					system("cls");
				}

				for(unsigned int i = 0; i < hist.size(); ++i){
					printf("%s\n",hist[i].c_str() );
				}
			}

			//printf("Windows visible %ui \n", uiSystem->windows.size() );
			//printf("Actors in room 0,0,0: %ui \n", sceneSystem->getActorManager()->getActorsInRoom(vec3(0,0,0)).size() );
			printf("---\n");

			stepsLeft = DEBUGRENDER_STEP;

			if(DEBUGRENDER_PAUSE == true){
				getchar();
			}
		}
	}
}
}
}

#endif
