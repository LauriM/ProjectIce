//If termrender is not enabled, ignore the header
#ifndef TERMRENDER
#define ENGINE_RENDER_TERM_TERMRENDER_H
#endif

#ifndef ENGINE_RENDER_TERM_TERMRENDER_H
#define ENGINE_RENDER_TERM_TERMRENDER_H

#include "engine/render/RenderSystem.h"
#include "engine/render/Color.h"

#include "engine/scene/SceneSystem.h"

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

		uint16_t convertColor(render::Color color);
	public:
		TermRender(scene::SceneSystem *sceneSystem)
			: sceneSystem(sceneSystem)
		{}

		bool init(){
			int value = tb_init();

			if(value > 0){
				LOG_INFO("Termbox init done!");
				return true;
			}

			LOG_ERROR("couldn't init termbox");

			setCameraPos(vec3(0,0,0));

			return false;
		}

		void uninit(){
			tb_shutdown();
		}

		void update();

		void renderUI();

		/*
		tb_cell test;
		test.ch = '@';
		test.fg = TB_RED;
		test.bg = TB_BLACK;

		tb_put_cell(10,10,&test);

		tb_present();

		tb_event event;

		tb_poll_event(&event);
		*/

	};

}
}
}

#endif
