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

	PRINTLN("-> DummyActor");
	{
		game::actor::npc::DummyActor* dummy = new game::actor::npc::DummyActor();

		SCPPT_COMPARE("Dummy is alive",dummy->getHp(),>,0);
		SCPPT_COMPARE("Dummy is named dummy",dummy->getName(),==,"Dummy");
	}

	PRINTLN("-> Room Inventory");
	{
		world::Room room;
		room.roomType = world::ROOM_TYPE_DUNGEON;
		for(int i = 0;i <25;++i){
			room.generate();
		}

		inventory::RoomInventory * roomInventory = new inventory::RoomInventory();
		game::item::container::QuiverItem * quiver = new game::item::container::QuiverItem();
		game::item::PotionItem * potion1 = new game::item::PotionItem();
		game::item::PotionItem * potion2 = new game::item::PotionItem();
		game::item::PotionItem * potion3 = new game::item::PotionItem();

		String potionName = potion1->getName();
		String quiverName = quiver->getName();

		roomInventory->setRoomOwner(&room);
		roomInventory->addItem( vec2(0,0), potion1 );
		roomInventory->addItem( vec2(0,0), potion2 );
		roomInventory->addItem( vec2(1,0), potion3 );
		roomInventory->addItem( vec2(0,0), quiver );

		inventory::tyItemVector * itemList1 = roomInventory->getItemListByPosition( vec2(0,0) );
		inventory::tyItemVector * itemList2 = roomInventory->getItemListByPosition( vec2(1,0) );
		SCPPT_COMPARE("Item list is not null",itemList1,!=,NULL);
		SCPPT_COMPARE("Item list size is 3 at(0,0)",itemList1->size(),==,3);
		SCPPT_COMPARE("Item list size is 1 at(1,0)",itemList2->size(),==,1);

		item::ItemBase * item = roomInventory->getItemByPosition( vec2(0,0), potionName );
		SCPPT_COMPARE("Item is not null",item,!=,NULL);
		SCPPT_COMPARE("Item name is Potion",item->getName(),==,potionName);

		bool removed = roomInventory->removeItem( potionName, vec2(0,0) );
		inventory::tyItemVector * itemList3 = roomInventory->getItemListByPosition( vec2(0,0) );
		SCPPT_COMPARE("Was the item removed",removed,==,true);
		SCPPT_COMPARE("Item list size at (0,0) is now 2",itemList3->size(),==,2);

		vec2 foundPosition = vec2(-1,-1);
		item::ItemBase * foundItem = roomInventory->searchForItem(quiverName,&foundPosition);
		SCPPT_COMPARE("The quiver was found",foundItem->getName(),==,quiverName);
		SCPPT_COMPARE("The x value is 0",foundPosition.x,==,0);
		SCPPT_COMPARE("The y value is 0",foundPosition.y,==,0);
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
