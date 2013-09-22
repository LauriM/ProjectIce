#ifndef ENGINE_INPUT_INPUTSYSTEM_H
#define ENGINE_INPUT_INPUTSYSTEM_H

namespace engine {
namespace input {

	class InputSystem : public EngineSystem {
	public:
		virtual bool init() = 0;
		virtual void uninit() = 0;
		virtual void update() = 0;
	};

}
}


#endif