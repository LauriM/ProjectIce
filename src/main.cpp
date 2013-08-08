#include "precompiled.h"

#include "engine/math/random.h"
#include "engine/EngineSystem.h"
#include "engine/render/RenderSystem.h"
#include "engine/UI/UISystem.h"
#include "engine/UI/Window.h"
#include "engine/UI/containers/TextContainer.h"
#include "engine/UI/containers/SelectContainer.h"
#include "engine/scene/SceneSystem.h"

int main(){
	randomInit();

	LOG_INFO("----");
	LOG_INFO("engine starting");

	engine::scene::SceneSystem *scene = new engine::scene::SceneSystem();
	scene->init();

	engine::UI::UISystem *ui          = new engine::UI::UISystem();
	engine::render::RenderSystem *render      = new engine::render::RenderSystem(scene,ui);

	render->init();
	ui->init();

	engine::UI::Window welcomeWindow;
	welcomeWindow.setPos(vec2(4,3));
	welcomeWindow.setSize(vec2(35,15));
	welcomeWindow.setName("Welcome to ProjectIce");

	engine::UI::containers::TextContainer *textCont = new engine::UI::containers::TextContainer();
	textCont->init();
	textCont->setText("ProjectIce is an experimental roguelike project developed in C++. This is a early development build. And this string is useless and long to test the word wrapping feature on the textContainer. -- press anykey to continue --");
	textCont->setPressToContinue(true);

	welcomeWindow.setContainer(textCont);

	engine::UI::Window blob;
	blob.setPos(vec2(84,3));
	blob.setSize(vec2(15,15));
	blob.setName("blob");

	engine::UI::containers::SelectContainer *selectCont = new engine::UI::containers::SelectContainer();
	selectCont->insertItem("0 zero");
	selectCont->insertItem("& second");
	selectCont->insertItem("# so on");

	blob.setContainer(selectCont);

//	ui->addWindow(welcomeWindow);
	ui->addWindow(blob);

	bool quitStatus = false;
	while(quitStatus == false){
		scene->update();
		render->update();
		ui->update();
		//int key = getch();
	}

	render->uninit();
	scene->uninit();

	return 0;
}
