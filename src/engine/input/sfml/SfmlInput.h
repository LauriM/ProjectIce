#ifndef SFMLRENDER
//If sfml rendering is NOT used, sfml input should not be used either.
#define ENGINE_INPUT_SFML_SFMLINPUT_H
#endif

#ifndef ENGINE_INPUT_SFML_SFMLINPUT_H
#define ENGINE_INPUT_SFML_SFMLINPUT_H

#include "engine/input/InputSystem.h"
#include "engine/render/sfml/SfmlRender.h"

#define SFMLINPUT

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
		bool handleKey(sf::Event *event);
	};

}
}
}

#endif
