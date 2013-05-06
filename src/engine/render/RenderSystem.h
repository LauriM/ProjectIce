#ifndef ENGINE_RENDER_RENDERSYSTEM_H
#define ENGINE_RENDER_RENDERSYSTEM_H

#include "engine/world/WorldSystem.h"

#include "engine/math/vec2.h"
#include "engine/math/vec3.h"

namespace engine {
namespace render {

	class RenderSystem : public EngineSystem {
	private:
		world::WorldSystem *worldSystem;

	public:
		vec3 cameraPos; //What section of map is currently visible and should be render.

		RenderSystem(world::WorldSystem *worldSystem);

		virtual bool init();
		virtual void uninit();
		virtual void update();

		void drawChar(vec2 pos,int character);
	};

}
}

#endif
