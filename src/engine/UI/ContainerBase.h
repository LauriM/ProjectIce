#ifndef ENGINE_UI_CONTAINERBASE_H
#define ENGINE_UI_CONTAINERBASE_H

#include "engine/math/AABB.h"

namespace engine {
namespace UI {

	/**
	 * Base class for containers that are inside the window
	 */
	class ContainerBase {
		public:
			virtual ~ContainerBase() {};

			virtual void init()   = 0;
			virtual void uninit() = 0;
			virtual void render(AABB bounds) = 0;
	};

}
}

#endif
