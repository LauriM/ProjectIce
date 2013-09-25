#ifndef DEBUGRENDER
#define ENGINE_RENDER_DEBUG_DEBUGRENDER_H
#endif

#ifndef ENGINE_RENDER_DEBUG_DEBUGRENDER_H
#define ENGINE_RENDER_DEBUG_DEBUGRENDER_H

#include "engine/render/RenderSystem.h"

#include "engine/scene/SceneSystem.h"
#include "engine/UI/UISystem.h"

/* HEADLESS TESTING SETTINGS */

//How many steps are processed until a rendering is triggered
#define DEBUGRENDER_STEP 1

//Should simulation wait for input before continuing after render
#define DEBUGRENDER_PAUSE true

//Should history be printed every tick
#define DEBUGRENDER_HISTORY true

//Should the cls be used on every tick or not
#define DEBUGRENDER_CLS false

namespace engine {
namespace render {
namespace debug {

	/**
	 * DebugRenderer is used for debugging/development purpose. It doesn't add any dependencies like other renderers.
	 * 
	 * DebugRenderer can also be used to print information from the world, useful for "headless" testing.
	 */
	class DebugRender : public RenderSystem {
	private:
		scene::SceneSystem *sceneSystem;
		UI::UISystem *uiSystem;

		int stepsLeft;
	public:
		DebugRender(scene::SceneSystem *sceneSystem,UI::UISystem *uiSystem)
			: sceneSystem(sceneSystem),
			uiSystem(uiSystem),
			stepsLeft(0)
		{}

		bool init(){
			printf("DebugRendering init!\n");

			return true;
		}

		void uninit(){
			printf("DebugRendering closing!\n");
		}

		void update();
	};

}
}
}

#endif
