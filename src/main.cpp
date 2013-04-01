#include "precompiled.h"

#include "engine/EngineSystem.h"
#include "engine/world/WorldSystem.h"
#include "engine/render/RenderSystem.h"

#include "proto/worldstate.pb.h"

int main(){
	printf("Hello world!\n");

	engine::world::WorldSystem *world = new engine::world::WorldSystem();
	engine::render::RenderSystem *render = new engine::render::RenderSystem(world);

	/* init */
	world->init();
	render->init();

	world->generate(); //Generate a world

	/* loop*/
	world->update();
	render->update();
	getch();
	/* end loop*/

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
	return 0;
}
