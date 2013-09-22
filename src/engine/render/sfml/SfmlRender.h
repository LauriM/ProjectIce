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

#define LOADTEXTURE(p_var, p_sprite, p_file) if(! p_var.loadFromFile( p_file ) ){ LOG_ERROR("Failed to load texture: " p_file ) return false; } p_sprite.setTexture(p_var);

	/**
	 * SfmlRender provides 2D tile rendering on windows platform.
	 */
	class SfmlRender : public RenderSystem {
	private:
		scene::SceneSystem *sceneSystem;
		UI::UISystem *uiSystem;

		sf::RenderWindow *window;

		/* Textures used */
		//TODO: somekind of texture manager would be nice
		sf::Texture voidTexture;
		sf::Sprite voidSprite;

		sf::Texture dummyTexture;
		sf::Sprite dummySprite;

		sf::Texture errorTexture;
		sf::Sprite errorSprite;

		sf::Texture floorTexture;
		sf::Sprite floorSprite;

		sf::Texture solidRockTexture;
		sf::Sprite solidRockSprite;

	public:
		SfmlRender(scene::SceneSystem *sceneSystem, UI::UISystem *uiSystem)
			: sceneSystem(sceneSystem)
			, uiSystem(uiSystem)
		{}

		bool init(){
			window = new sf::RenderWindow(sf::VideoMode(800,600), "ProjectIce TODO: add version here");

			setCameraPos( vec3(0, 0, 0) );

			//Load textures
			LOADTEXTURE(voidTexture      , voidSprite      , "./gfx/void.png");
			LOADTEXTURE(dummyTexture     , dummySprite     , "./gfx/dummy.png");
			LOADTEXTURE(errorTexture     , errorSprite     , "./gfx/error.png");
			LOADTEXTURE(floorTexture     , floorSprite     , "./gfx/floor.png");
			LOADTEXTURE(solidRockTexture , solidRockSprite , "./gfx/solid_rock.png");

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