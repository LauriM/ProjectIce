#ifndef ENGINE_UI_CONTAINERS_TEXTCONTAINER_H
#define ENGINE_UI_CONTAINERS_TEXTCONTAINER_H

#include "precompiled.h"
#include "engine/UI/ContainerBase.h"
#include "engine/math/AABB.h"

namespace engine {
namespace UI {
namespace containers{

	/**
	 * This container only displays texts.
	 * Text is also wrapped when needed.
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
				LOG_WARNING("not implemented");

				LOG_DEBUG_F("Window render bounds: %i,%i (%i,%i)",bounds.pos.x,bounds.pos.y,bounds.size.x,bounds.size.y);
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
