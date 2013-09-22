#ifndef SFMLRENDER
//If sfml rendering is NOT used, sfml input should not be used either.
#define ENGINE_INPUT_SFML_SFMLINPUT_H
#endif

#include "engine/input/InputSystem.h"

#ifndef ENGINE_INPUT_SFML_SFMLINPUT_H
#define ENGINE_INPUT_SFML_SFMLINPUT_H

namespace engine {
namespace input {
namespace sfml {

	class SfmlInput : public InputSystem {
		bool init(){
			return true;
		}

		void uninit() {}
		void update();
	};

}
}
}

#endif