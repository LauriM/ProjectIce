#ifndef ENGINE_UI_CONTAINERS_DISPLAYBODYCONTAINER_H
#define ENGINE_UI_CONTAINERS_DISPLAYBODYCONTAINER_H

#include <string>

#include "engine/UI/ContainerBase.h"
#include "engine/math/AABB.h"

#include "engine/actor/ActorBase.h"

namespace engine {
namespace UI {
namespace containers {

	class DisplayBodyContainer : public ContainerBase {
		protected:
			actor::ActorBase* actor;

		public:
			DisplayBodyContainer(actor::ActorBase* actor)
				:actor(actor)
			{  }

			void init() { }

			void uninit() {  }
	};

}
}
}

#endif
