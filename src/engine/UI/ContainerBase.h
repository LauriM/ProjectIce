#ifndef ENGINE_UI_CONTAINERBASE_H
#define ENGINE_UI_CONTAINERBASE_H

#include "engine/math/AABB.h"

namespace engine {
namespace UI {

	/**
	 * Base class for containers that are inside the window
	 */
	class ContainerBase {
		protected:
			bool closed; /* is the container stopped? if so, kill the window */

		public:
			virtual ~ContainerBase() {};

			virtual void init()   = 0;
			virtual void uninit() = 0;

			/* getters / setters */

			bool getClosed(){
				return closed;
			}
	};

}
}

#endif
