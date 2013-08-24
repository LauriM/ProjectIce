#include "precompiled.h"

#include "engine/math/random.h"
#include "engine/AI/AISystem.h"
#include "engine/EngineSystem.h"
#include "engine/render/RenderSystem.h"
#include "engine/UI/UISystem.h"
#include "engine/UI/Window.h"
#include "engine/UI/containers/TextContainer.h"
#include "engine/UI/containers/SelectContainer.h"
#include "engine/scene/SceneSystem.h"
#include "engine/actor/ActorManager.h"

#include "game/actor/player/PlayerActor.h"
#include "game/item/PotionItem.h"
#include "game/actor/npc/DummyActor.h"
#include "game/UI/containers/StatsContainer.h"

#ifdef TERMRENDER
#include "engine/render/term/TermRender.h"
#endif

#ifdef NULLRENDER
#include "engine/render/null/NullRender.h"
#endif

int main(){
	randomInit();

	LOG_INFO("Engine starting");

	game::actor::player::PlayerActor * playerActor = new game::actor::player::PlayerActor();
	playerActor->setName("Player");
	playerActor->setPosition(vec2(10,10));
	playerActor->setLocation(vec3(0,0,0));

	engine::world::WorldSystem * worldSystem = new engine::world::WorldSystem();
	worldSystem->init();
	worldSystem->generate();
	playerActor->setWorld(worldSystem);

	engine::actor::ActorManager * actorManager = new engine::actor::ActorManager();

	engine::scene::SceneSystem *scene = new engine::scene::SceneSystem(worldSystem,actorManager,playerActor);

	game::item::PotionItem * pi = new game::item::PotionItem();
	scene->addItem(pi);

	engine::UI::UISystem *ui             = new engine::UI::UISystem();
	engine::AI::AISystem *ai             = new engine::AI::AISystem(actorManager,worldSystem);

#ifdef TERMRENDER
	engine::render::RenderSystem *render = new engine::render::term::TermRender(scene,ui);
#endif
#ifdef NULLRENDER
	engine::render::RenderSystem *render = new engine::render::null::NullRender(scene,ui);
#endif

	render->init();
	ui->init();
	ai->init();

	engine::UI::Window welcomeWindow;
	welcomeWindow.setPos(vec2(4,3));
	welcomeWindow.setSize(vec2(35,15));
	welcomeWindow.setName("Welcome to ProjectIce");

	engine::UI::containers::TextContainer *textCont = new engine::UI::containers::TextContainer();
	textCont->init();
	textCont->setText("ProjectIce is an experimental roguelike project developed in C++. This is a early development build. And this string is useless and long to test the word wrapping feature on the textContainer. -- press anykey to continue --");
	textCont->setPressToContinue(true);

	welcomeWindow.setContainer(textCont);
	//	ui->addWindow(welcomeWindow);

	/*
	engine::UI::Window blob;
	blob.setPos(vec2(84,3));
	blob.setSize(vec2(15,15));
	blob.setName("blob");

	engine::UI::containers::SelectContainer *selectCont = new engine::UI::containers::SelectContainer();
	selectCont->insertItem("0 zero");
	selectCont->insertItem("& second");
	selectCont->insertItem("# so on");

	blob.setContainer(selectCont);
	ui->addWindow(blob);
	*/

	engine::UI::Window statsWindow;
	statsWindow.setPos(vec2(84,3));
	statsWindow.setSize(vec2(15,15));
	statsWindow.setName("Stats");

	game::UI::containers::StatsContainer *statsUI = new game::UI::containers::StatsContainer();
	statsUI->setPlayerActor(playerActor);

	statsWindow.setContainer(statsUI);

	ui->addWindow(statsWindow);

	/*
	 * Testing area for the NPC
	 */
	engine::world::Tile voidTile;

	voidTile.setType(engine::world::TILE_TREE);
	for(int x = 7;x < 20;++x){
		for(int y = 7;y < 20;++y){
			worldSystem->getRoom( vec3(0,0,0) )->setTile(x,y,voidTile);
		}
	}

	voidTile.setType(engine::world::TILE_VOID);
	for(int x = 8;x < 19;++x){
		for(int y = 8;y < 19;++y){
			worldSystem->getRoom( vec3(0,0,0) )->setTile(x,y,voidTile);
		}
	}

	//Add some Dummy Ai for testing.

	for(int i = 0;i < 5;++i){
		game::actor::npc::DummyActor * dummy = new game::actor::npc::DummyActor();
		dummy->setWorld( worldSystem );
		dummy->setPosition( vec2(10+i,15) );
		dummy->setLocation( vec3(0,0,0) );

		scene->getActorManager()->insertActorToRoom(dummy);
	}

	game::actor::npc::DummyActor * dummy = new game::actor::npc::DummyActor();
	dummy->setWorld( worldSystem );
	dummy->setPosition( vec2(11,11) );
	dummy->setLocation( vec3(0,0,0) );
	dummy->setAIState(engine::AI::AISTATE_SLEEP);

	scene->getActorManager()->insertActorToRoom(dummy);

	bool quitStatus = false;
	while(quitStatus == false){
		scene->update();
		ai->update();
		render->update();
		ui->update();
	}

	ai->uninit();
	render->uninit();
	scene->uninit();

	return 0;
}
