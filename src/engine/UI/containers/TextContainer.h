#ifndef ENGINE_UI_CONTAINERS_TEXTCONTAINER_H
#define ENGINE_UI_CONTAINERS_TEXTCONTAINER_H

#include "precompiled.h"
#include "engine/UI/ContainerBase.h"

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

			void render(){
				LOG_WARNING("not implemented");
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
