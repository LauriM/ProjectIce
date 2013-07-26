#include "precompiled.h"

#include "engine/UI/UISystem.h"

namespace engine {
namespace UI {

	UISystem::UISystem() {}

	bool UISystem::init(){
		LOG_INFO("UI starting");
		return true;
	}

	void UISystem::uninit(){
		return;
	}

	void UISystem::update(){
	}

	void UISystem::addWindow(Window window){
		windows.push_back(window);
	}

	bool UISystem::handleInput(int key, engine::UI::UIResult * result ){
		for(int i = 0; i < windows.size();++i){
			windows.at(i).getContainer()->handleInput(key);
		}

		//TODO: check if some of the windows actually capture some input
		return false;
	}
}
}
