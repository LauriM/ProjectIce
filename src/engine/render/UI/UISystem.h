#ifndef ENGINE_RENDER_UI_UISYSTEM_H
#define ENGINE_RENDER_UI_UISYSTEM_H

#include "engine/EngineSystem.h"

namespace engine {
namespace render {
namespace UI {

	class UISystem : public EngineSystem {
	private:
		//All the windows..
	public:
		UISystem();

		virtual bool init();
		virtual void uninit();
		virtual void update();

		//TODO: Add window
		//TODO: render
		//TODO: Get windows, etc
	};

}
}
}

#endif
