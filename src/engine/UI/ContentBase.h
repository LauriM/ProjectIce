#ifndef ENGINE_UI_CONTAINERBASE_H
#define ENGINE_UI_CONTAINERBASE_H

#include "engine/math/AABB.h"

namespace engine {
namespace UI {

	/**
	 * Base class for containers that are inside the window
	 */
	class ContentBase {
		public:
			virtual ~ContentBase() {};
	};

}
}

#endif
