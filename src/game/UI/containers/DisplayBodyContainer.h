#ifndef GAME_UI_CONTAINERS_DISPLAYBODYCONTAINER_H
#define GAME_UI_CONTAINERS_DISPLAYBODYCONTAINER_H

#include <string>

#include "engine/UI/ContainerBase.h"
#include "engine/math/AABB.h"

#include "engine/actor/ActorBase.h"

namespace game {
namespace UI {
namespace containers {

	class DisplayBodyContainer : public engine::UI::ContainerBase {
		protected:
			engine::actor::ActorBase* actor;

		public:
			DisplayBodyContainer(engine::actor::ActorBase* actor)
				:actor(actor)
			{  }

			void init() { }

			void uninit() {  }
	};

}
}
}

#endif
