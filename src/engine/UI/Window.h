#ifndef ENGINE_UI_WINDOW_H
#define ENGINE_UI_WINDOW_H

#include "precompiled.h"

#include "engine/math/vec2.h"

namespace engine {
namespace UI {

	enum WINDOW_CONTENT_TYPE {
		CONTENT_TYPE_TEXT, //Window contains text, will be wrapped (DEFAULT)
		CONTENT_TYPE_LIST, //Window contains list of items, can be selected
		CONTENT_TYPE_CUSTOM, //Window content is fully custom
	};

	class Window {
	protected:
		WINDOW_CONTENT_TYPE type;
		bool visible;
		String name;
		vec2 pos;
		vec2 size;

	public:
		Window();
		//TODO: Overloaded window with parameters

		void printDebugInfo();

		void setType(WINDOW_CONTENT_TYPE newType){
			type = newType;
		}

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

		WINDOW_CONTENT_TYPE getType(){
			return type;
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
