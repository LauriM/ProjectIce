#include "precompiled.h"

#include "engine/math/random.h"
#include "engine/EngineSystem.h"
#include "engine/world/WorldSystem.h"
#include "engine/render/RenderSystem.h"

#include "proto/worldstate.pb.h"

int main(){
	randomInit();

	printf("Hello world!\n");

	engine::world::WorldSystem *world = new engine::world::WorldSystem();
	engine::render::RenderSystem *render = new engine::render::RenderSystem(world);

	/* init */
	world->init();
	world->generate(); //Generate a world

	render->init();

	bool quitStatus = false;
	while(quitStatus == false){
		world->update();
		render->update();
		int key = getch();

		//This switch provides "world overview specating"
		switch(key){
			//hjkl
			case 106:
				render->cameraPos.y -= 1;
				break;
			case 107:
				render->cameraPos.y += 1;
				break;
			case 104:
				render->cameraPos.x -= 1;
				break;
			case 108:
				render->cameraPos.x += 1;
				break;
			case 62:
				render->cameraPos.z -= 1;
				break;
			case 60:
				render->cameraPos.z += 1;
				break;
		}
	}

	render->uninit();
	world->uninit();

	/**
	 * Protobuff testing
	 */
	/*
	tileMsg test;
	test.set_posx(15);
	test.set_posy(10);
	test.set_visual("#");
	test.set_roomid(0);

	std::fstream stream;
	stream.open("gamesave", std::ios::out | std::ios::binary);

	test.SerializeToOstream(&stream);

	stream.close();

	std::fstream input;
	input.open("gamesave",std::ios::in | std::ios::binary);

	tileMsg blob;
	blob.ParseFromIstream(&input);

	input.close();

	printf("Tile x: %i tile y: %i [%s]\n",blob.posx(),blob.posy(),blob.visual().c_str());
	*/

	//Clean up the systems
	delete world;
	delete render;

	return 0;
}
