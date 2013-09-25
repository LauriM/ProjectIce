#include "precompiled.h"
#include "engine/input/sfml/SfmlInput.h"

#ifdef SFMLINPUT

#include <SFML/Window/Keyboard.hpp>

namespace engine {
namespace input {
namespace sfml {

	void SfmlInput::update(){

		//Loop here until we get valid keys from the player

		sf::Event event;

		//Loop as long as we get some real commands
		for(;;){
			while(window->pollEvent(event)){
				LOG_INFO("Event");
				switch(event.type){
				case sf::Event::Closed:
					window->close();
					return;

				case sf::Event::KeyPressed:
					if(handleKey(&event)){
						LOG_INFO("valid key pressed");
						return;
					}else{
						LOG_INFO("invalid key pressed");
					}

					break;
				}
			}

//			window->display();
		}
	}

	/**
	 * Returns true if a correct key was pressed and handled
	 */
	bool SfmlInput::handleKey(sf::Event *event){

		if(event->key.code == sf::Keyboard::Up){
			scene->getActorManager()->moveActorRel(scene->getPlayerActor(),vec2(0,-1));
			return true;
		}

		if(event->key.code == sf::Keyboard::Down){
			scene->getActorManager()->moveActorRel(scene->getPlayerActor(),vec2(0,1));
			return true;
		}

		if(event->key.code == sf::Keyboard::Left){
			scene->getActorManager()->moveActorRel(scene->getPlayerActor(),vec2(-1,0));
			return true;
		}

		if(event->key.code == sf::Keyboard::Right){
			scene->getActorManager()->moveActorRel(scene->getPlayerActor(),vec2(1,0));
			return true;
		}

		return false;
	}

}
}
}

#endif
