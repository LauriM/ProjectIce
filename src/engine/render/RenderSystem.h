#ifndef ENGINE_RENDER_RENDERSYSTEM_H
#define ENGINE_RENDER_RENDERSYSTEM_H

#include "engine/world/WorldSystem.h"

namespace engine {
namespace render {

	class RenderSystem : public engine::EngineSystem {
	private:
		engine::world::WorldSystem *worldSystem;

	public:
		RenderSystem(engine::world::WorldSystem *worldSystem);

		virtual bool init();
		virtual void uninit();
		virtual void update();
	};

}
}

#endif
