#ifndef SFMLRENDER
//If sfml rendering is NOT used, sfml input should not be used either.
#define ENGINE_INPUT_SFML_SFMLINPUT_H
#endif

#include "engine/input/InputSystem.h"
#include "engine/render/sfml/SfmlRender.h"

#ifndef ENGINE_INPUT_SFML_SFMLINPUT_H
#define ENGINE_INPUT_SFML_SFMLINPUT_H

//Dont leak this outside of non-sfml builds
#include <SFML/Window/Keyboard.hpp>

namespace engine {
namespace input {
namespace sfml {

	class SfmlInput : public InputSystem {
	private:
		sf::Window *window;
		scene::SceneSystem *scene;

	public:
		SfmlInput(sf::Window *window, scene::SceneSystem *scene)
			: window(window)
			, scene(scene)
		{}

		bool init(){
			return true;
		}

		void uninit() {}
		void update();

	private:
		bool SfmlInput::handleKey(sf::Event *event);
	};

}
}
}

#endif