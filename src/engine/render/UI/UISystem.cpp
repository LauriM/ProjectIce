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
		return;
	}

}
}
}
