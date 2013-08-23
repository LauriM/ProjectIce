#include "scppt.h"
#include "engine/world/WorldSystem.h"
#include "engine/world/Room.h"
#include "engine/world/Tile.h"
#include "engine/UI/Window.h"
#include "game/actor/player/PlayerActor.h"
#include "game/actor/npc/DummyActor.h"
#include "engine/scene/SceneSystem.h"
#include "engine/AI/AISystem.h"

#include "precompiled.h"
#include "engine/math/vec2.h"

#include "game/item/PotionItem.h"
#include "game/item/container/QuiverItem.h"
#include "engine/inventory/RoomInventory.h"
#include "engine/item/ItemManager.h"

#include "engine/inventory/RoomInventory.h"

#include <map>
#include <vector>

using namespace engine;

int testFails = 0;
int testOks   = 0;

int main(){
	SCPPT_START;

	PRINTLN("-> termbox")
	{
		SCPPT_COMPARE("tb init ok",tb_init(), == , 0);
		tb_shutdown();
	}

	PRINTLN("-> Vec2");
	{
		vec2 v1 = vec2(2, 3);
		vec2 v2 = vec2(5, 10);

		SCPPT_COMPARE("Vec2 equality #1",v1 == v2,==,false);
		SCPPT_COMPARE("Vec2 equality #2",v2 == v1,==,false);
		SCPPT_COMPARE("Vec2 equality #3",v1 == v1,==,true);

		SCPPT_COMPARE("Vec2 inquality #1",v1 != v1,==,false);
		SCPPT_COMPARE("Vec2 inquality #2",v1 != v2,==,true);
		SCPPT_COMPARE("Vec2 inquality #3",v2 != v1,==,true);
		SCPPT_COMPARE("Vec2 inquality #4",vec2(2, 3) != vec2(2, 5),==,true);
		SCPPT_COMPARE("Vec2 inquality #5",vec2(2, 3) != vec2(5, 3),==,true);

		SCPPT_COMPARE("Vec2 addition #1",v1 + v2,==,vec2(7, 13));
		SCPPT_COMPARE("Vec2 addition #2",v2 + v1,==,vec2(7, 13));

		SCPPT_COMPARE("Vec2 subtraction #1",v1 - v2,==,vec2(-3, -7));
		SCPPT_COMPARE("Vec2 subtraction #2",v2 - v1,==,vec2(3, 7));

		SCPPT_COMPARE("Vec2 dot product #1",v1 * v2,==,40);
		SCPPT_COMPARE("Vec2 dot product #2",v2 * v1,==,40);

		SCPPT_COMPARE("Vec2 scalar multiplication",v1 * 5,==,vec2(10, 15));
		SCPPT_COMPARE("Vec2 scalar division",v2 / 2,==,vec2(2, 5));

		SCPPT_COMPARE("Vec2 copy constructor",vec2(v1),==,v1);
	}

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

	PRINTLN("-> DummyActor");
	{
		game::actor::npc::DummyActor* dummy = new game::actor::npc::DummyActor();

		SCPPT_COMPARE("Dummy is alive",dummy->getHp(),>,0);
		SCPPT_COMPARE("Dummy is named dummy",dummy->getName(),==,"Dummy");
	}

	PRINTLN("-> Inventory Manager");
	{
		item::ItemManager * itemManager = item::ItemManager::getInstance();
		SCPPT_COMPARE( "Brand new item manager", itemManager->getActiveItemCount(), ==, 0 );

		std::vector<game::item::PotionItem*> potions;
		for( int x = 0; x < 5; x++ ) {
			game::item::PotionItem * pot = new game::item::PotionItem();
			itemManager->trackItem( pot );
			potions.push_back( pot );
		}
		SCPPT_COMPARE( "5 Potions registered with the engine", itemManager->getActiveItemCount(), ==, 5 );
		SCPPT_COMPARE( "1st Potions id is 0", potions.at(0)->getId(), ==, 0 );
		SCPPT_COMPARE( "2nd Potions id is 1", potions.at(1)->getId(), ==, 1 );
		SCPPT_COMPARE( "3rd Potions id is 2", potions.at(2)->getId(), ==, 2 );
		SCPPT_COMPARE( "4th Potions id is 3", potions.at(3)->getId(), ==, 3 );
		SCPPT_COMPARE( "5th Potions id is 4", potions.at(4)->getId(), ==, 4 );
		SCPPT_COMPARE( "Potion #2 removed", itemManager->untrackItem( potions.at(1) ), ==, true )
		SCPPT_COMPARE( "Potion #2 id is now -1", potions.at(1)->getId(), ==, -1 );
		game::item::PotionItem * newPotion1 = new game::item::PotionItem();
		itemManager->trackItem(newPotion1);
		SCPPT_COMPARE( "New Potion #1 id should now be 1", newPotion1->getId(), ==, 1 );
		game::item::PotionItem * newPotion2 = new game::item::PotionItem();
		itemManager->trackItem(newPotion2);
		SCPPT_COMPARE( "New Potion #2 id should now be 5", newPotion2->getId(), ==, 5 );
		SCPPT_COMPARE( "6 (7 - 1) Potions registered with the engine", itemManager->getActiveItemCount(), ==, 6 );
		itemManager->untrackItem( potions.at(3) );
		itemManager->untrackItem( potions.at(4) );
		SCPPT_COMPARE( "4 (6 - 2) Potions registered with the engine", itemManager->getActiveItemCount(), ==, 4 );
		SCPPT_COMPARE( "ID 3 is not in use", itemManager->isIDTracked(3), ==, false );
		SCPPT_COMPARE( "ID 4 is not in use", itemManager->isIDTracked(4), ==, false );
		SCPPT_COMPARE( "ID 5 is in use", itemManager->isIDTracked(5), ==, true );
		SCPPT_COMPARE( "ID -1 is crap", itemManager->isIDTracked(-1), ==, false );
		SCPPT_COMPARE( "ID 100 is too large", itemManager->isIDTracked(100), ==, false );
	}

	PRINTLN("-> Room Inventory")
	{
		// --- START --- Test INIT
		item::ItemManager * itemManager = item::ItemManager::getInstance();
		std::vector<game::item::PotionItem*> potions;
		for( int x = 0; x < 4; x++ ) {
			game::item::PotionItem * pot = new game::item::PotionItem();
			itemManager->trackItem( pot );
			potions.push_back( pot );
		}
		game::item::ArrowItem * arrow = new game::item::ArrowItem();
		//itemManager->trackItem( arrow );
		world::Room testRoom;
		testRoom.roomType = world::ROOM_TYPE_WATER;
		for(int i = 0;i <25;++i){
			testRoom.generate();
		}
		inventory::RoomInventory * roomInventory = new inventory::RoomInventory(&testRoom);
		if (roomInventory) {} // stop complaining about unused variables

		roomInventory->addItemToPosition( vec2(0,0), potions.at(0) );
		roomInventory->addItemToPosition( vec2(0,0), potions.at(1) );
		roomInventory->addItemToPosition( vec2(0,0), potions.at(2) );
		// --- END --- Test INIT

		SCPPT_COMPARE( "(0,0) has 3 items.", roomInventory->getItemCountAtPosition( vec2(0,0) ), ==, 3 );
		SCPPT_COMPARE( "(0,1) has 0 items.", roomInventory->getItemCountAtPosition( vec2(0,1) ), ==, 0 );
		SCPPT_COMPARE( "Cannot add untracked items.", roomInventory->addItemToPosition( vec2(0,0), arrow ), ==, false );
		SCPPT_COMPARE( "(0,0) has 3 items.", roomInventory->getItemCountAtPosition( vec2(0,0) ), ==, 3 );

		itemManager->trackItem( arrow );
		roomInventory->addItemToPosition( vec2(0,0), arrow );
		SCPPT_COMPARE( "(0,0) has 4 items.", roomInventory->getItemCountAtPosition( vec2(0,0) ), ==, 4 );

		itemManager->untrackItem( potions.at(0) );
		roomInventory->deleteItemByPosition( vec2(0,0), potions.at(0)->getId() );
		SCPPT_COMPARE( "(0,0) has 3 items.", roomInventory->getItemCountAtPosition( vec2(0,0) ), ==, 3 );

		engine::inventory::typeItemList * potRM = roomInventory->getItemListByName( potions.at(1)->getName() );
		SCPPT_COMPARE( "There are 2 potions in the room", potRM->size(), ==, 2 );

		roomInventory->addItemToPosition( vec2(1,0), potions.at(0) );
		SCPPT_COMPARE( "(1,0) has 1 items.", roomInventory->getItemCountAtPosition( vec2(1,0) ), ==, 1 );
		potRM = roomInventory->getItemListByName( potions.at(1)->getName() );
		SCPPT_COMPARE( "There are 3 potions in the room", potRM->size(), ==, 3 );

		SCPPT_COMPARE( "There are 4 items in the room", roomInventory->getItemCount(), ==, 4 );
		SCPPT_COMPARE( "Remove a tracked item from the inventory", roomInventory->getItemCount(), ==, 4 );

		itemManager->trackItem( potions.at(0) );
		bool deleted = roomInventory->deleteItemByPosition( vec2(0,0), potions.at(0)->getId() );
		SCPPT_COMPARE( "Cannot remove tracked items from inventory", deleted, ==, false );

	}

	/*
	  Idea for unit tests about initting the systems

	{
		PRINTLN("-> Scene");
		engine::scene::SceneSystem *scene = new engine::scene::SceneSystem(worldSystem,NULL);

		SCPPT_COMPARE("Scene init ok",scene->init(),==,true);

		PRINTLN("-> AIsystem")
		engine::AI::AISystem *ai = new engine::AI::AISystem(scene);

		SCPPT_COMPARE("Aisystem init ok",ai->init(),==,true);
	}
	*/

	PRINTLN("Tests complete");

	SCPPT_END;
}
