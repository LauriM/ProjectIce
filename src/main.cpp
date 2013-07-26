#include "precompiled.h"

#include "engine/math/random.h"
#include "engine/EngineSystem.h"
#include "engine/world/WorldSystem.h"
#include "engine/render/RenderSystem.h"
#include "engine/UI/UISystem.h"
#include "engine/UI/Window.h"
#include "engine/player/Player.h"
#include "engine/UI/containers/TextContainer.h"
#include "engine/UI/containers/SelectContainer.h"

int main(){
	randomInit();

	LOG_INFO("----");
	LOG_INFO("engine starting");

	world::WorldSystem *world        = new world::WorldSystem();
	engine::UI::UISystem *ui         = new UI::UISystem();
	render::RenderSystem *render     = new render::RenderSystem(world,ui);

	engine::player::Player *player   = new engine::player::Player();

	/* init */
	world->init();
//	world->loadFromFile("gamesave");
	world->generate(); //Generate a world
//	world->saveToFile("gamesave");

	//lets test saving it...

	render->init();
	ui->init();
	player->init();

	UI::Window welcomeWindow;
	welcomeWindow.setPos(vec2(4,3));
	welcomeWindow.setSize(vec2(35,15));
	welcomeWindow.setName("Welcome to ProjectIce");

	UI::containers::TextContainer *textCont = new UI::containers::TextContainer();
	textCont->init();
	textCont->setText("ProjectIce is an experimental roguelike project developed in C++. This is a early development build. And this string is useless and long to test the word wrapping feature on the textContainer. -- press anykey to continue --");
	textCont->setPressToContinue(true);

	welcomeWindow.setContainer(textCont);

	UI::Window blob;
	blob.setPos(vec2(45,3));
	blob.setSize(vec2(15,15));
	blob.setName("blob");

	UI::containers::SelectContainer *selectCont = new UI::containers::SelectContainer();
	selectCont->insertItem("0 zero");
	selectCont->insertItem("& second");
	selectCont->insertItem("# so on");

	blob.setContainer(selectCont);

	ui->addWindow(welcomeWindow);
	ui->addWindow(blob);

	bool quitStatus = false;
	while(quitStatus == false){
		world->update();
		render->update();
		ui->update();
		int key = getch();

		if(ui->handleInput(key) == true){
			continue; //input was captured by the UISystem
		}

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
			case 27:
				quitStatus = true;
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
	/*
	delete world;
	delete render;
	*/

	return 0;
}
