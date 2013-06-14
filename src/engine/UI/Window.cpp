#include "engine/UI/Window.h"

namespace engine {
namespace UI {

	Window::Window(){
		visible = true;
		pos = vec2(0,0);
		size = vec2(10,10);
		name = "null";
	}

	void Window::printDebugInfo(){
		LOG_INFO("Outputting debug info to stdout! Debugging to game interface not supported yet.");

		printf("Window %s Pos [%i,%i] Size [%i,%i]\n", name.c_str(), pos.x, pos.y, size.x, size.y);
	}

}
}
