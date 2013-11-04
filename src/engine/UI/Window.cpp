#include "engine/UI/Window.h"

namespace engine {
namespace UI {

	Window::Window()
		: content(NULL)
		, visible(true)
		, pos( vec2(0,0) )
		, size( vec2(10,10) )
		, name("null")
	{}

}
}
