#ifndef ENGINE_UI_UISYSTEM_H
#define ENGINE_UI_UISYSTEM_H


#include "engine/EngineSystem.h"
#include "engine/UI/Window.h"

namespace engine {
namespace UI {

	typedef std::vector<UI::Window> WindowContainer;

	class UISystem : public EngineSystem {
		public:
			WindowContainer windows;

			UISystem();

			virtual bool init();
			virtual void uninit();
			virtual void update();

			void addWindow(Window window);

			/* Getters & setters */

			WindowContainer *getWindowContainer() {
				return &windows;
			}
	};

}
}

#endif
