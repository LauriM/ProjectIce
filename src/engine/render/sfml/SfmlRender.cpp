#include "precompiled.h"
#include "engine/render/sfml/SfmlRender.h"

#ifdef SFMLRENDER

namespace engine {
namespace render {
namespace sfml {

	void SfmlRender::update(){
		if(!window->isOpen()){
			//Window has been closed! Close the application
			LOG_INFO("[SfmlRender] Main window has been closed");
			//TODO: Closing is not handled correctly!
			return;
		}

		sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

		window->clear(sf::Color::Black);

		sf::RectangleShape box(sf::Vector2f(10,10));

		box.setFillColor(sf::Color::Blue);

		box.setPosition(sf::Vector2f(50,50));

		window->draw(box);


		std::vector<actor::ActorBase *> actors = sceneSystem->getActorManager()->getActorsInRoom(cameraPos);

		for(unsigned int i = 0; i < actors.size();++i){
			dummySprite.setPosition( (actors.at(i)->getPos()->x * 10) , (actors.at(i)->getPos()->y * 10) );
			window->draw(dummySprite);
		}

		window->display();
	}

}
}
}

#endif