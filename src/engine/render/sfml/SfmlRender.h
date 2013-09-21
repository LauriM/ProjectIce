#ifndef SFMLRENDER
//If the sfmlrender is NOT defined, dont use this header
#define ENGINE_RENDER_SFML_SFMLRENDER_H
#endif

#ifndef ENGINE_RENDER_SFML_SFMLRENDER_H
#define ENGINE_RENDER_SFML_SFMLRENDER_H

#include "engine/render/RenderSystem.h"
#include "engine/render/Color.h"

#include "engine/scene/SceneSystem.h"
#include "engine/UI/UISystem.h"

#include <SFML/Graphics.hpp>

namespace engine {
namespace render {
namespace sfml {

	/**
	 * SfmlRender provides 2D tile rendering on windows platform.
	 */
	class SfmlRender : public RenderSystem {
	private:
		scene::SceneSystem *sceneSystem;
		UI::UISystem *uiSystem;

		sf::RenderWindow *window;

	public:
		SfmlRender(scene::SceneSystem *sceneSystem, UI::UISystem *uiSystem)
			: sceneSystem(sceneSystem)
			, uiSystem(uiSystem)
		{}

		bool init(){
			window = new sf::RenderWindow(sf::VideoMode(800,600), "ProjectIce TODO: add version here");

			setCameraPos( vec3(0, 0, 0) );

			return true;
		}

		void uninit(){
		}

		void update();

	};

}
}
}

#endif