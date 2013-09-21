#include "precompiled.h"
#include "engine/render/sfml/SfmlRender.h"

namespace engine {
namespace render {
namespace sfml {

	void SfmlRender::update(){
		if(!window->isOpen()){
			//Window has been closed! Close the application
			LOG_INFO("[SfmlRender] Main window has been closed");
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
		//TODO: do some rendering here

		window->display();
	}

}
}
}