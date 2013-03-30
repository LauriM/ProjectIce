#ifndef ENGINE_WORLD_WORLDSYSTEM_H
#define ENGINE_WORLD_WORLDSYSTEM_H

#include "precompiled.h"

#include "engine/EngineSystem.h"

namespace engine {
namespace world {

	class WorldSystem : public engine::EngineSystem {
	public:
		WorldSystem();

		virtual bool init();
		virtual void uninit();
		virtual void update();
	};

}
}

#endif
