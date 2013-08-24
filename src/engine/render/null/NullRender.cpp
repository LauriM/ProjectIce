#include "engine/render/null/NullRender.h"

namespace engine {
namespace render {
namespace null {

	void NullRender::update(){
		printf("Windows visible %lu \n", uiSystem->windows.size() );
		printf("Actors in room 0,0,0: %lu \n", sceneSystem->getActorManager()->getActorsInRoom(vec3(0,0,0)).size() );
		printf("---\n");

		getchar();
	}
}
}
}
