#include "precompiled.h"

#include "engine/render/null/NullRender.h"

//Only compile nullrender if its in use
#ifdef NULLRENDER

namespace engine {
namespace render {
namespace null {

	void NullRender::update(){
		stepsLeft--;

		if(stepsLeft < 0){

			uiSystem->windows.size(); //these are not unused
			sceneSystem->getActorManager();

			//printf("Windows visible %ui \n", uiSystem->windows.size() );
			//printf("Actors in room 0,0,0: %ui \n", sceneSystem->getActorManager()->getActorsInRoom(vec3(0,0,0)).size() );
			printf("---\n");

			stepsLeft = NULLRENDER_STEP;

			if(NULLRENDER_PAUSE == true){
				getchar();
			}
		}
	}
}
}
}

#endif
