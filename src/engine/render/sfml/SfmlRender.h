#ifndef SFMLRENDER
//If the sfmlrender is NOT defined, dont use this header
#define ENGINE_RENDER_SFML_SFMLRENDER_H
#endif

#ifndef ENGINE_RENDER_SFML_SFMLRENDER_H
#define ENGINE_RENDER_SFML_SFMLRENDER_H

#include "engine/render/RenderSystem.h"
#include "engine/render/Color.h"

#include "engine/scene/SceneSystem.h"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>

#define TILE_WIDTH 10
#define TILE_HEIGHT 10
#define TILE_WIDTH_F 10.f
#define TILE_HEIGHT_F 10.f

namespace engine {
namespace render {
namespace sfml {

#define LOADTEXTURE(p_var, p_sprite, p_file) if(! p_var.loadFromFile( p_file ) ){ LOG_ERROR("Failed to load texture: " p_file ) return false; } p_sprite.setTexture(p_var); LOG_INFO("[sfml] Loaded: " p_file);
#define LOADFONT(p_var, p_file) if(! p_var.loadFromFile( p_file ) ){ LOG_ERROR("Failed to load font: " p_file ) return false; } LOG_INFO("[sfml] Loaded: " p_file);

	/**
	 * SfmlRender provides 2D tile rendering on windows platform.
	 */
	class SfmlRender : public RenderSystem {
	private:
		scene::SceneSystem *sceneSystem;

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

		sf::Texture treeTexture;
		sf::Sprite treeSprite;

		sf::Texture playerTexture;
		sf::Sprite playerSprite;

		//Fonts
		sf::Font font;

	public:
		SfmlRender(scene::SceneSystem *sceneSystem)
			: sceneSystem(sceneSystem)
		{
			window = new sf::RenderWindow(sf::VideoMode(1200,800), "ProjectIce TODO: add version here");
		}

		bool init();

		void uninit() {}
		void update();

		/* getters & setters*/

		sf::Window* getWindow(){
			return window;
		}

	private:

		void renderRoom();
		void renderHud();
	};

}
}
}

#endif