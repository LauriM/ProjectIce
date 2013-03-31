#include "engine/EngineSystem.h"
#include "engine/render/RenderSystem.h"

namespace engine {
namespace render {

	RenderSystem::RenderSystem(engine::world::WorldSystem *worldSystem)
	: worldSystem(worldSystem)
	{}

	bool RenderSystem::init(){
		return true;
	}

	void RenderSystem::uninit(){
		return;
	}

	void RenderSystem::update(){
		printf("Render ticks!\n");
		return;
	}

}
}
