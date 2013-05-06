#ifndef ENGINE_RENDER_UI_WINDOW_H
#define ENGINE_RENDER_UI_WINDOW_H

#include "precompiled.h"

#include "engine/math/vec2.h"

namespace engine {
namespace render {
namespace UI {

	class Window {
	public:
		String name;
		vec2 pos;
		vec2 size;

		void printDebugInfo();
	};

}
}
}

#endif
