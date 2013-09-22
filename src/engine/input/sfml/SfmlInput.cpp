#include "precompiled.h"
#include "engine/input/sfml/SfmlInput.h"

#include <SFML/Window/Keyboard.hpp>

namespace engine {
namespace input {
namespace sfml {

	void SfmlInput::update(){

		//Loop here until we get valid keys from the player

		for(;;){
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
				LOG_INFO("[SfmlInput] Escape pressed!");
				return;
			}
		}
	}

}
}
}
