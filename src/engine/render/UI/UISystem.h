#ifndef ENGINE_RENDER_UI_UISYSTEM_H
#define ENGINE_RENDER_UI_UISYSTEM_H

#include "engine/EngineSystem.h"

#include "engine/render/UI/Window.h"

namespace engine {
namespace render {
namespace UI {

	class UISystem : public EngineSystem {
	public:
		std::vector<Window> windows;

		UISystem();

		virtual bool init();
		virtual void uninit();
		virtual void update();

		void addWindow(Window window);
	};

}
}
}

#endif
