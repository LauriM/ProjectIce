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

	void UISystem::addWindow(Window *window){
		windows.push_back(window);
	}

}
}
