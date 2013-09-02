#ifndef NULLRENDER
#define ENGINE_RENDER_NULL_NULLRENDER_H
#endif

#ifndef ENGINE_RENDER_NULL_NULLRENDER_H
#define ENGINE_RENDER_NULL_NULLRENDER_H

#include "engine/render/RenderSystem.h"

#include "engine/scene/SceneSystem.h"
#include "engine/UI/UISystem.h"

/* HEADLESS TESTING SETTINGS */

//How many steps are processed until a rendering is triggered
#define NULLRENDER_STEP 1

//Should simulation wait for input before continuing after render
#define NULLRENDER_PAUSE true

//Should history be printed every tick
#define NULLRENDER_HISTORY true

namespace engine {
namespace render {
namespace null {

	/**
	 * NullRenderer is used for debugging/development purpose. It doesn't add any dependencies like other renderers.
	 * 
	 * NullRenderer can also be used to print information from the world, useful for "headless" testing.
	 */
	class NullRender : public RenderSystem {
	private:
		scene::SceneSystem *sceneSystem;
		UI::UISystem *uiSystem;

		int stepsLeft;
	public:
		NullRender(scene::SceneSystem *sceneSystem,UI::UISystem *uiSystem)
			: sceneSystem(sceneSystem),
			uiSystem(uiSystem),
			stepsLeft(0)
		{}

		bool init(){
			printf("NullRendering init!\n");

			return true;
		}

		void uninit(){
			printf("NullRendering closing!\n");
		}

		void update();
	};

}
}
}

#endif
