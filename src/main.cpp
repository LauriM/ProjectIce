#include "precompiled.h"

#include "engine/EngineSystem.h"
#include "engine/world/WorldSystem.h"

#include "proto/tile.pb.h"

int main(){
	printf("Hello world!\n");

	engine::world::WorldSystem *world = new engine::world::WorldSystem();

	world->init();
	world->update();
	world->uninit();

	//Lets test protobuffers
	
	tile test;
	test.set_posx(15);
	test.set_posy(10);
	test.set_visual("#");

	std::fstream stream;
	stream.open("gamesave", std::ios::out | std::ios::binary);

	test.SerializeToOstream(&stream);

	return 0;
}
