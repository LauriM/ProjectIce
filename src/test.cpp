#include "scppt.h"
#include "engine/world/WorldSystem.h"
#include "engine/world/Room.h"
#include "engine/world/Tile.h"
#include "engine/UI/Window.h"
#include "game/actor/player/PlayerActor.h"
#include "engine/scene/SceneSystem.h"

#include "precompiled.h"
#include "engine/math/vec2.h"
#include "game/items/IronItem.h"
#include "game/items/ArrowItem.h"
#include "game/items/containers/QuiverItem.h"

#include <map>

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

		for(int i = 0;i <25;++i){
			testRoom.generate();
		}

		SCPPT_COMPARE("Rooms generate something",testRoom.getTile(5,5)->visual,==,'.');
	}

	PRINTLN("-> Window");
	{
		UI::Window window;
		window.setName("asdf");

		window.printDebugInfo();
	}

	PRINTLN("-> Player");
	{
		game::actor::player::PlayerActor *playerActor = new game::actor::player::PlayerActor();

		playerActor->update();

		SCPPT_COMPARE("Player has positive HP",playerActor->getHp(),>,0);
		SCPPT_COMPARE("Player has a name",playerActor->getName(),!=,"");
	}

	PRINTLN("-> item quiver");
	{
		game::items::containers::QuiverItem * quiver = new game::items::containers::QuiverItem();
		quiver->setQuantity( 1 );
		quiver->setQuantity( quiver->getQuantity() + 2 );
		SCPPT_COMPARE("quiver quantity is correct",quiver->getQuantity(),==,3);
	}

	PRINTLN("-> Scene ");
	{
		engine::scene::SceneSystem *sceneSystem = new engine::scene::SceneSystem();
		SCPPT_COMPARE("Initializing scene", sceneSystem->init(),==,true);
	}

	PRINTLN("Tests complete");

	SCPPT_END;
}
