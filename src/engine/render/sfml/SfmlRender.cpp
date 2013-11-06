#include "precompiled.h"
#include "engine/render/sfml/SfmlRender.h"
#include "engine/console/Cvar.h"
#include "engine/UI/content/DisplayBodyContent.h"

#ifdef SFMLRENDER

namespace cvar {
	CVAR(int,wallhack,0,CVAR_CHEAT);
}

namespace engine {
namespace render {
namespace sfml {

	bool SfmlRender::init() {
		setCameraPos(vec3(0, 0, 0));

		LOADFONT(font, "./gfx/arial.ttf");

		//Load textures
		LOADTEXTURE(voidTexture      , voidSprite      , "./gfx/void.png");
		LOADTEXTURE(dummyTexture     , dummySprite     , "./gfx/dummy.png");
		LOADTEXTURE(errorTexture     , errorSprite     , "./gfx/error.png");
		LOADTEXTURE(floorTexture     , floorSprite     , "./gfx/floor.png");
		LOADTEXTURE(solidRockTexture , solidRockSprite , "./gfx/solid_rock.png");
		LOADTEXTURE(treeTexture      , treeSprite      , "./gfx/tree.png");
		LOADTEXTURE(playerTexture    , playerSprite    , "./gfx/player.png");

		return true;
	}

	void SfmlRender::update(){
		if(!window->isOpen()){
			//Window has been closed! Close the application
			LOG_INFO("[SfmlRender] Main window has been closed");
			//TODO: Closing is not handled correctly!
			return;
		}

		/*
		sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
		*/

		window->clear(sf::Color::Black);

		world::Room *currentRoom = sceneSystem->getWorld()->getRoom(cameraPos);
		vec2 currentPosition     = sceneSystem->getPlayerActor()->getPosition();

		vec2 pos;

		sf::Sprite sprite; //TODO: this may not be optimal

		for(int x = 0;x < ROOM_WIDTH;++x){
			for(int y = 0;y < ROOM_HEIGHT;++y){
				pos.x = (x + 2);
				pos.y = (y + 2);
				//Changing the color
				world::Tile *tile;

				if(*cvar::wallhack) {
					 tile = currentRoom->getTile(x,y);
				} else {
					 tile = currentRoom->getVisual(x,y);
				}

				switch(tile->type){
				case world::TILE_SOLID_ROCK:
					sprite = solidRockSprite;
					break;
				case world::TILE_ROCK_FLOOR:
					sprite = floorSprite;
					break;
				case world::TILE_VOID:
					sprite = voidSprite;
					break;
				case world::TILE_TREE:
					sprite = treeSprite;
					break;
				default:
					sprite = errorSprite;
				}

				sprite.setPosition( (x * TILE_WIDTH_F) , (y * TILE_HEIGHT_F) );
				window->draw(sprite); 
			}

		}

		std::vector<actor::ActorBase *> actors = sceneSystem->getActorManager()->getActorStorage()->getActorsInRoom(cameraPos);

		for(unsigned int i = 0; i < actors.size(); ++i) {
			sprite = dummySprite; //default gfx if not found
			actor::ActorBase *actor = actors.at(i);

			//TODO: Add some kind of linking of player <-> resource on a text file.
			if(actor->getName() == "Player"){
				sprite = playerSprite;
			}

			if(currentRoom->lineOfSight(currentPosition,actor->getPosition() ) ){
				sprite.setPosition( (actor->getPos()->x * TILE_WIDTH_F) , (actor->getPos()->y * TILE_HEIGHT_F) );
				window->draw(sprite);
			}
		}

		/* Render the UI */

		const UI::WindowContainer *winList = uiSystem->getWindowContainer();
		UI::Window *win;
		sf::RectangleShape box;

		for (unsigned int i = 0; i < winList->size(); ++i) {
			win = winList->at(i);

			//TODO: Draw window here
			box.setSize(sf::Vector2f(win->getSize().x * TILE_WIDTH_F, win->getSize().y * TILE_HEIGHT_F));
			box.setOutlineColor(sf::Color::Cyan);
			box.setOutlineThickness(3);
			box.setPosition(sf::Vector2f(win->getPos().x * TILE_WIDTH_F, win->getPos().y * TILE_HEIGHT_F));

			window->draw(box);

			handleWindowContent(win);
		}

		//Not to be confused with the SFML window
		window->display();
	}

	void SfmlRender::handleWindowContent(UI::Window *win) {
		vec2 basePosition(win->getPos().x * TILE_WIDTH, win->getPos().y * TILE_HEIGHT);

		UI::content::DisplayBodyContent *content = dynamic_cast<UI::content::DisplayBodyContent*>( win->getContent() );

		if (content != NULL) {
			displayBodyRender(content,basePosition);
			return;
		}
	}

	void SfmlRender::displayBodyRender(UI::content::DisplayBodyContent *content, const vec2 basePosition) {
		const actor::ActorBase *actor = content->getActor();

		const actor::BodyPartContainer *parts = actor->getBodyParts();

		int count = 0;
		for (unsigned int i = 0; i < parts->size(); ++i) {
			++count;
		}

		sf::Text text;
		text.setFont(font);
		text.setCharacterSize(15);
		text.setColor(sf::Color::Red);
		text.setStyle(sf::Text::Bold);

		char numstr[21]; 
		sprintf_s(numstr, "%d", parts->size());
		text.setString(String("Parts") + numstr);

		text.setPosition( sf::Vector2f( float(basePosition.x + 15), float(basePosition.y + 15)) );
		//text.setPosition(sf::Vector2f(15,15));

		window->draw(text);
	}
}
}
}

#endif