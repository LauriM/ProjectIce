#include "precompiled.h"

#include "engine/math/random.h"
#include "engine/actor/AISystem.h"
#include "engine/EngineSystem.h"
#include "engine/render/RenderSystem.h"
#include "engine/UI/UISystem.h"
#include "engine/UI/Window.h"
#include "engine/UI/containers/TextContainer.h"
#include "engine/UI/containers/SelectContainer.h"
#include "engine/scene/SceneSystem.h"
#include "engine/console/ConsoleSystem.h"
#include "engine/actor/ActorSystem.h"
#include "engine/actor/ActorManager.h"
#include "engine/console/Cvar.h"

#include "game/actor/player/PlayerActor.h"
#include "game/item/PotionItem.h"
#include "game/actor/npc/DummyActor.h"
#include "game/UI/containers/StatsContainer.h"

#include <cstring>
//#include <boost/filesystem.hpp>

#ifdef TERMRENDER
#include "engine/render/term/TermRender.h"
#include "engine/input/term/TermInput.h"
#endif

#ifdef DEBUGRENDER
#include "engine/render/debug/DebugRender.h"
#include "engine/input/null/NullInput.h"
#endif

#ifdef SFMLRENDER
#include "engine/render/sfml/SfmlRender.h"
#include "engine/input/sfml/SfmlInput.h"
#endif

namespace cvar {
	CVAR(int,developer,0,CVAR_CHEAT);
}

void handleArgs(int argc,char *argv[]);

int main(int argc, char *argv[]){
	randomInit();

	if(argc == 2){
		handleArgs(argc,argv);
	}

	LOG_INFO("Engine starting");

#ifdef DEBUG
	//If this is debug build, enable developer by default
	*cvar::developer = 1;
#endif

	if(*cvar::developer){
		LOG_INFO("Developer mode enabled!");
		printf("Developer mode is enabled!\n");
	}

	engine::console::ConsoleSystem *consoleSystem = new engine::console::ConsoleSystem();
	consoleSystem->init();
	//Config loader planner: First try to read from the same directory, after that try to read from cfg location (~/. or %appdata%)
	if(!consoleSystem->loadConfig("config.cfg")){
		//cfg loading from the run directory failed. Testing out the platform depended default directory


	String cfgDirectory;

#ifdef WINDOWS
		cfgDirectory = getenv("APPDATA");
		const String cfgFolder = "\\ProjectIce\\";
		const String cfgFilename = "ProjectIce.cfg";
#endif

#ifdef LINUX
		cfgDirectory = "~/";
		const String cfgFolder = ".projectice/";
		const String cfgFilename = "ProjectIce.cfg";
#endif

		if(!consoleSystem->loadConfig(cfgDirectory + cfgFolder + cfgFilename) ){
			LOG_INFO("No config files found, creating one to default directory.");

			//TODO: Create the folder here! Make sure it works on all platforms.

			//if(boost::filesystem::create_directory(cfgDirectory + cfgFolder)){
				consoleSystem->saveConfig(cfgDirectory + cfgFolder + cfgFilename);
		//	}else{
			//	LOG_ERROR("Could not create the directory! Your system permissions are fucked up.");
		//	}
		}
	}

	if(consoleSystem->areCheatsUsed()){
		LOG_INFO("! CHEATS IN USE !");
	}

	game::actor::player::PlayerActor * playerActor = new game::actor::player::PlayerActor();
	playerActor->setName("Player");
	playerActor->setPosition(vec2(10,10));
	playerActor->setLocation(vec3(0,0,0));

	engine::world::WorldSystem * worldSystem = new engine::world::WorldSystem();
	worldSystem->init();
	worldSystem->generate();

	engine::actor::ActorSystem * actorSystem = new engine::actor::ActorSystem();

	engine::actor::ActorManager * actorManager = new engine::actor::ActorManager(actorSystem,worldSystem);

	engine::scene::SceneSystem *scene = new engine::scene::SceneSystem(worldSystem,actorManager,playerActor);

	game::item::PotionItem * pi = new game::item::PotionItem();
	worldSystem->getRoom(vec3(0,0,0))->getInventory()->addItem(pi);

	engine::UI::UISystem *ui    = new engine::UI::UISystem();
	engine::actor::AISystem *ai = new engine::actor::AISystem(actorManager);

#ifdef TERMRENDER
	engine::render::RenderSystem *render = new engine::render::term::TermRender(scene,ui);
	engine::input::InputSystem   *input  = new engine::input::term::TermInput(scene);
#endif
#ifdef DEBUGRENDER
	engine::render::RenderSystem *render = new engine::render::debug::DebugRender(scene,ui);
	engine::input::InputSystem   *input  = new engine::input::null::NullInput();
#endif
#ifdef SFMLRENDER
	engine::render::sfml::SfmlRender *sfmlRender = new engine::render::sfml::SfmlRender(scene,ui);
	engine::render::RenderSystem *render = sfmlRender;

	engine::input::InputSystem *input = new engine::input::sfml::SfmlInput(sfmlRender->getWindow(), scene);
#endif

	render->init();
	ui->init();
	input->init();
	ai->init();

	engine::UI::Window welcomeWindow;
	welcomeWindow.setPos(vec2(4,3));
	welcomeWindow.setSize(vec2(35,15));
	welcomeWindow.setName("Welcome to ProjectIce");

	engine::UI::containers::TextContainer *textCont = new engine::UI::containers::TextContainer();
	textCont->init();
	textCont->setText("ProjectIce is an experimental roguelike project developed in C++. This is a early development build. And this string is useless and long to test the word wrapping feature on the textContainer. -- press anykey to continue --");

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
	 * Testing area for the NPCs
	 */
	engine::world::Tile voidTile;

	//force it to dungeon also
	LOG_INFO("Building testing area");
	worldSystem->getRoom( vec3(0,0,0) )->roomType = engine::world::ROOM_TYPE_DUNGEON;
	worldSystem->getRoom( vec3(0,0,0) )->generate();

	//Add some Dummy Ai for testing.

	for(int i = 0;i < 5;++i){
		game::actor::npc::DummyActor * dummy = new game::actor::npc::DummyActor();
		dummy->setPosition( vec2(10+i,15) );
		dummy->setLocation( vec3(0,0,0) );

		scene->getActorManager()->getActorSystem()->insertActorToRoom(dummy);
	}

	game::actor::npc::DummyActor * dummy = new game::actor::npc::DummyActor();
	dummy->setPosition( vec2(11,11) );
	dummy->setLocation( vec3(0,0,0) );
	dummy->setAIState(engine::actor::AISTATE_SLEEP);

	scene->getActorManager()->getActorSystem()->insertActorToRoom(dummy);

	worldSystem->getRoom( vec3(0,0,0) )->printLayout();

	//printf("CvarCount: %lu\n",engine::console::ConsoleSystem::getCVarList().size());

//	consoleSystem->saveConfig("config.cfg");

	bool quitStatus = false;
	while(quitStatus == false){
		scene->update();
		ai->update();
		ui->update();
		render->update();
		input->update();
	}

	ai->uninit();
	render->uninit();
	scene->uninit();
	consoleSystem->uninit();

	return 0;
}

void handleArgs(int argc, char *argv[]){
	if(std::strcmp(argv[1],"-createconfig") == 0){
		//Create console system just to save default cvar settings
		engine::console::ConsoleSystem *consoleSystem = new engine::console::ConsoleSystem();

		consoleSystem->saveConfig("./config.cfg");
		printf("Default config created into ./config.cfg\n");
		printf("Exitting...\n");
		exit(0);
	}

	if(std::strcmp(argv[1],"-help") == 0){
		printf("/-(ProjectIce special commands)--------------\\\n");
		printf("| -createconfig | create default configs     |\n");
		printf("| -help         | show this help             |\n");
		printf("| -version      | shows version information  |\n");
		printf("\\--------------------------------------------/");
		exit(0);
	}

	if(std::strcmp(argv[1],"-version") == 0){

#ifdef DEBUG
	printf("Development build");
#else
	printf("Release build");
#endif

		exit(0);
	}

	printf("Invalid command.\n");
	exit(1);
}
