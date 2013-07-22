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
		public:
			void init(){
			}

			void uninit() {}

			void render(AABB bounds){
				for(int i = 0;i < items.size();++i){
					if(i > items.size() ){
						LOG_WARNING("Scrolling has not been implemented for SelectContainer!");
						return;
					}

					engine::render::drawStringTobounds(bounds,vec2(0,i), items.at(i).substr(0,bounds.size.x));
				}
			}

			void insertItem(String item){
				items.push_back(item);
			}
	};

}
}
}

#endif
