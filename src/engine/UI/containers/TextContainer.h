#ifndef ENGINE_UI_CONTAINERS_TEXTCONTAINER_H
#define ENGINE_UI_CONTAINERS_TEXTCONTAINER_H

#include "precompiled.h"
#include "engine/UI/ContainerBase.h"
#include "engine/math/AABB.h"

namespace engine {
namespace UI {
namespace containers{

	//TODO: Add wrapping by words, not just by characthers.

	/**
	 * This container only displays texts.
	 * Text is also wrapped when string is too long.
	 */
	class TextContainer : public ContainerBase {
		protected:
			String textContent;

		public:
			void init(){
				textContent = "hello world";
			}

			void uninit(){}

			void render(AABB bounds){
				LOG_DEBUG_F("Window render bounds: %i,%i (%i,%i)",bounds.pos.x,bounds.pos.y,bounds.size.x,bounds.size.y);

				if(textContent.length() < bounds.size.x){
					//String is shorter than the width, lets just print it.
					engine::render::drawStringTobounds(bounds,vec2(0,0),textContent);
					return;
				}

				//String is longer, we need to split it.
				int i                = 0;
				int currentCharsLeft = 1;

				while(currentCharsLeft > 0){
					currentCharsLeft = textContent.length() - (i * bounds.size.x);

					if(currentCharsLeft < bounds.size.x ){
						//Its the last line, and its not full lenght... so lets just print the last chars.
						engine::render::drawStringTobounds(bounds,vec2(0,i),textContent.substr(0 + (i * bounds.size.x),currentCharsLeft));
						return;
					}else{
						engine::render::drawStringTobounds(bounds,vec2(0,i),textContent.substr(0 + (i * bounds.size.x),bounds.size.x));
					}

					++i;
				}

			}

			String getText(){
				return textContent;
			}

			void setText(String text){
				textContent = text;
			}
	};

}
}
}

#endif
