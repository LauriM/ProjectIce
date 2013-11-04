#ifndef ENGINE_UI_UISYSTEM_H
#define ENGINE_UI_UISYSTEM_H


#include "engine/EngineSystem.h"
#include "engine/UI/Window.h"

namespace engine {
namespace UI {

	typedef std::vector<UI::Window*> WindowContainer;

	class UISystem : public EngineSystem {
		public:
			WindowContainer windows;

			UISystem();
			
			//TODO: removing windows or containers from memory is not handled!

			virtual bool init();
			virtual void uninit();
			virtual void update();

			void addWindow(Window *window);

			/* Getters & setters */

			const WindowContainer *getWindowContainer() {
				return &windows;
			}
	};

}
}

#endif
