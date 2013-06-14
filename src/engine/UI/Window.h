#ifndef ENGINE_UI_WINDOW_H
#define ENGINE_UI_WINDOW_H

#include "precompiled.h"

#include "engine/math/vec2.h"

namespace engine {
namespace UI {

	class Window {
	protected:
		bool visible;
		String name;
		vec2 pos;
		vec2 size;

	public:
		Window();
		//TODO: Overloaded window with parameters

		void printDebugInfo();

		void setPos(vec2 newPos){
			//TODO: asserts
			pos = newPos;
		}

		void setSize(vec2 newSize){
			//TODO: asserts
			size = newSize;
		}

		void setName(String newName){
			name = newName;
		}

		void setVisible(bool newValue){
			visible = newValue;
		}

		bool isVisible(){
			return visible;
		}

		String getName(){
			return name;
		}

		vec2 getPos(){
			return pos;
		}

		vec2 getSize(){
			return size;
		}
	};

}
} /* namespaces */

#endif
