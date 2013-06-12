#include "engine/render/UI/Window.h"

namespace engine {
namespace render {
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

	void Window::setPos(vec2 newPos){
		//TODO: asserts
		pos = newPos;
	}

	void Window::setSize(vec2 newSize){
		//TODO: asserts
		size = newSize;
	}

	void Window::setName(String newName){
		name = newName;
	}

	bool Window::isVisible(){
		return visible;
	}

	String Window::getName(){
		return name;
	}

	vec2 Window::getPos(){
		return pos;
	}

	vec2 Window::getSize(){
		return size;
	}

}
}
}
