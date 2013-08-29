#ifndef ENGINE_UI_CONTAINERS_TEXTCONTAINER_H
#define ENGINE_UI_CONTAINERS_TEXTCONTAINER_H

#include "precompiled.h"
#include "engine/UI/ContainerBase.h"
#include "engine/math/AABB.h"

namespace engine {
namespace UI {
namespace containers {

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
				textContent     = "hello world";
			}

			void uninit(){}

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
