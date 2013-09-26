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
				switch(event.type){
				case sf::Event::Closed:
					window->close();
					return;

				case sf::Event::KeyPressed:
					if(handleKey(&event)){
						return;
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

		//Arrow-keys
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

		//Numpad keys
		if(event->key.code == sf::Keyboard::Numpad1){
			scene->getActorManager()->moveActorRel(scene->getPlayerActor(),vec2(-1,1));
			return true;
		}

		if(event->key.code == sf::Keyboard::Numpad2){
			scene->getActorManager()->moveActorRel(scene->getPlayerActor(),vec2(0,1));
			return true;
		}

		if(event->key.code == sf::Keyboard::Numpad3){
			scene->getActorManager()->moveActorRel(scene->getPlayerActor(),vec2(1,1));
			return true;
		}

		if(event->key.code == sf::Keyboard::Numpad4){
			scene->getActorManager()->moveActorRel(scene->getPlayerActor(),vec2(-1,0));
			return true;
		}

		if(event->key.code == sf::Keyboard::Numpad5){
			//Wait by not moving!
			scene->getActorManager()->moveActorRel(scene->getPlayerActor(),vec2(0,0));
			return true;
		}

		if(event->key.code == sf::Keyboard::Numpad6){
			scene->getActorManager()->moveActorRel(scene->getPlayerActor(),vec2(1,0));
			return true;
		}

		if(event->key.code == sf::Keyboard::Numpad7){
			scene->getActorManager()->moveActorRel(scene->getPlayerActor(),vec2(-1,-1));
			return true;
		}

		if(event->key.code == sf::Keyboard::Numpad8){
			scene->getActorManager()->moveActorRel(scene->getPlayerActor(),vec2(0,-1));
			return true;
		}

		if(event->key.code == sf::Keyboard::Numpad9){
			scene->getActorManager()->moveActorRel(scene->getPlayerActor(),vec2(1,-1));
			return true;
		}


		return false;
	}

}
}
}

#endif
