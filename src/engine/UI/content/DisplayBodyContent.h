#ifndef ENGINE_UI_CONTAINERS_DISPLAYBODYCONTENT_H
#define ENGINE_UI_CONTAINERS_DISPLAYBODYCONTENT_H

#include <string>

#include "engine/UI/ContentBase.h"
#include "engine/math/AABB.h"

#include "engine/actor/ActorBase.h"

namespace engine {
namespace UI {
namespace content {

	class DisplayBodyContent : public ContentBase {
		protected:
			actor::ActorBase* actor;

		public:
			DisplayBodyContent (actor::ActorBase* actor)
				:actor(actor)
			{  }

			void init() { }

			void uninit() {  }
	};

}
}
}

#endif
