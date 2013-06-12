#ifndef ENGINE_RENDER_UI_WINDOW_H
#define ENGINE_RENDER_UI_WINDOW_H

#include "precompiled.h"

#include "engine/math/vec2.h"

namespace engine {
namespace render {
namespace UI {

	class Window {
	private:
		bool visible;
		String name;
		vec2 pos;
		vec2 size;

	public:
		Window();
		//TODO: Overloaded window with parameters

		void setPos(vec2 newPos);
		void setSize(vec2 newSize);
		void setName(String newName);

		void printDebugInfo();

		bool isVisible();
		String getName();
		vec2 getPos();
		vec2 getSize();
	};

}
}
}

#endif
