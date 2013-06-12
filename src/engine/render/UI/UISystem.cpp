#include "precompiled.h"

#include "engine/render/UI/UISystem.h"

namespace engine {
namespace render {
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
		for(int i = 0; i < windows.size(); ++i){
			windows[i].render();
		}
	}

	void UISystem::addWindow(Window window){
		windows.push_back(window);
	}

}
}
}
