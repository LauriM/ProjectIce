#include "scppt.h"
#include "engine/world/WorldSystem.h"
#include "engine/world/Room.h"
#include "engine/world/Tile.h"
#include "engine/render/UI/Window.h"
#include "engine/player/Player.h"

using namespace engine;

int testFails = 0;
int testOks   = 0;

int main(){
	SCPPT_START;

	PRINTLN("-> Tile");
	{
		world::Tile testTile;
		testTile.setType(world::TILE_TREE);

		SCPPT_COMPARE("Tree blocks movement",testTile.blocks,==,true);
		SCPPT_COMPARE("Tree has HP",testTile.hp,>,0);
	}

	PRINTLN("-> Room");
	{
		world::Room testRoom;
		testRoom.roomType = world::ROOM_TYPE_WATER;
		testRoom.generate();

		SCPPT_COMPARE("Rooms generate something",testRoom.getTile(5,5)->visual,==,'.');
	}

	PRINTLN("-> World");
	SCPPT_COMPARE("World is disabled (bugs)",0,==,1);
	{ /*
		world::WorldSystem *world = new world::WorldSystem();

		world->init();
		world->generate();

		//Lets take random point
		world::Room* tempRoom = world->getRoom(2,2,2);
		world::Tile* tempTile = tempRoom->getTile(5,5);

		char visual = tempTile->visual;
		int  hp     = tempTile->hp;
		bool blocks = tempTile->blocks;

		PRINTLN("Saving world to disk..");
		world->saveToFile("testsave");
		PRINTLN("Save done!");

		//delete world;

		world = new world::WorldSystem();

		world->init();

		PRINTLN("Loading world from disk..");
		world->loadFromFile("testsave");
		PRINTLN("Load done!");

		tempRoom = world->getRoom(2,2,2);
		tempTile = tempRoom->getTile(5,5);

		PRINTLN("Comparing save file");
		SCPPT_COMPARE("Visual",tempTile->visual,==,visual);
		SCPPT_COMPARE("hp",tempTile->hp,==,hp);
		SCPPT_COMPARE("Blocks",tempTile->blocks,==,blocks);
		*/
	}

	PRINTLN("-> Window");
	{
		render::UI::Window window;
		window.setName("asdf");

		window.printDebugInfo();
	}

	PRINTLN("-> Player");
	{
		engine::player::Player player;

		player.init();
	}


	PRINTLN("Tests complete");

	SCPPT_END;

	return 0;
}
