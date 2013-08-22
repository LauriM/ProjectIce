#ifndef ENGINE_RENDER_TERM_TERMRENDER_H
#define ENGINE_RENDER_TERM_TERMRENDER_H

#include "engine/scene/SceneSystem.h"
#include "engine/UI/UISystem.h"

#include <termbox.h>

namespace engine {
namespace render {
namespace term {

	/**
	 * TermRender provides default rendering solution. Rendering to console.
	 *
	 * Termbox is used behind the scenes.
	 */
	class TermRender : public RenderSystem {
	private:
		scene::SceneSystem *sceneSystem;
		UI::UISystem *uiSystem;
	public:
		TermRender(scene::SceneSystem *sceneSystem,UI::UISystem *uiSystem)
			: sceneSystem(sceneSystem),
			uiSystem(uiSystem)
		{}

		bool init(){
			int value = tb_init();

			if(value > 0){
				LOG_INFO("Termbox init done!");
				return true;
			}

			LOG_ERROR("couldn't init termbox");
			return false;
		}

		void uninit(){
			tb_shutdown();
		}

		void update(){
			LOG_INFO("termbox update");
		}


	};

}
}
}

#endif
