#ifndef ENGINE_ENGINESYSTEM_H
#define ENGINE_ENGINESYSTEM_H

namespace engine {

	class EngineSystem {
	public:
		virtual bool init() = 0;
		virtual void uninit() = 0;
		virtual void update() = 0;
	};
}

#endif
