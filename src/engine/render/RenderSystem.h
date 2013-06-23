#ifndef ENGINE_RENDER_RENDERSYSTEM_H
#define ENGINE_RENDER_RENDERSYSTEM_H

#include "engine/world/WorldSystem.h"
#include "engine/UI/UISystem.h"

#include "engine/math/vec2.h"
#include "engine/math/vec3.h"

namespace engine {
namespace render {

	class RenderSystem : public EngineSystem {
	private:
		world::WorldSystem *worldSystem;
		UI::UISystem *uiSystem;

		void drawChar(vec2 pos,int character);
	public:
		vec3 cameraPos; //What section of map is currently visible and should be render.

		RenderSystem(world::WorldSystem *worldSystem,UI::UISystem *uiSystem);
		~RenderSystem() {};

		virtual bool init();
		virtual void uninit();
		virtual void update();

		/**
		 * Draw charachter to bounds. 0,0 is on aabb,s position.
		 *
		 * Checks in place so the draw wont go outside of the window.
		 */
		void drawCharTobounds(AABB bounds,vec2 pos,int character);
	};

}
}

#endif
