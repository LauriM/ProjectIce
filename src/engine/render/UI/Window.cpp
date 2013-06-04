#include "engine/render/UI/Window.h"

namespace engine {
namespace render {
namespace UI {

	void Window::printDebugInfo(){
		LOG_INFO("Outputting debug info to stdout! Debugging to game interface not supported yet.");

		printf("Window %s Pos [%i,%i] Size [%i,%i]\n", name.c_str(), pos.x, pos.y, size.x, size.y);
	}

}
}
}
