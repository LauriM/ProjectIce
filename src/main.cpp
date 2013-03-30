#include "precompiled.h"

#include "engine/EngineSystem.h"
#include "engine/world/WorldSystem.h"

int main(){
	printf("Hello world!\n");

	engine::world::WorldSystem *world = new engine::world::WorldSystem();

	world->init();
	world->update();
	world->uninit();

	return 0;
}
