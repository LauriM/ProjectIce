#include "engine/input/InputSystem.h"

#ifndef ENGINE_INPUT_NULL_NULLINPUT_H
#define ENGINE_INPUT_NULL_NULLINPUT_H

namespace engine {
namespace input {
namespace null {

	class NullInput: public InputSystem {
		bool init(){
			return true;
		}

		void uninit() {}
		void update() {}
	};

}
}
}

#endif