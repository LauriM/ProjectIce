#ifndef ENGINE_UI_CONTAINERS_SELECTCONTAINER_H
#define ENGINE_UI_CONTAINERS_SELECTCONTAINER_H

#include <string>

#include "precompiled.h"
#include "engine/UI/ContainerBase.h"
#include "engine/math/AABB.h"

namespace engine {
namespace UI {
namespace containers {

	class SelectContainer : public ContainerBase {
		protected:
			std::vector<String> items;
			int currentItem;

		public:
			void init(){
				currentItem = 0;
			}

			void uninit() {}

			void insertItem(String item){
				items.push_back(item);
			}

			void handleInput(int key){
				LOG_INFO("SelectContainer got input");
			}
	};

}
}
}

#endif
