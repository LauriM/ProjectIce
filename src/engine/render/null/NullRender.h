#ifndef ENGINE_RENDER_NULL_NULLRENDER_H
#define ENGINE_RENDER_NULL_NULLRENDER_H

#include "engine/render/RenderSystem.h"

#include "engine/scene/SceneSystem.h"
#include "engine/UI/UISystem.h"

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
	public:
		NullRender(scene::SceneSystem *sceneSystem,UI::UISystem *uiSystem)
			: sceneSystem(sceneSystem),
			uiSystem(uiSystem)
		{}

		bool init(){
			printf("NullRendering init!");

			return true;
		}

		void uninit(){
			printf("NullRendering closing!");
		}

		void update();
	};

}
}
}

#endif
