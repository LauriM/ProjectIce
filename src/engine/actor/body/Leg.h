#ifndef ENGINE_ACTOR_BODY_LEG_H
#define ENGINE_ACTOR_BODY_LEG_H

#include "engine/actor/body/BodyPart.h"

namespace engine {
namespace actor {
namespace body {

	class Leg : public BodyPart {
	public:
		Leg()
			: speed(5)
		{
			type   = TYPE_LEG;
			blood  = 70;
			weight = 15;
		}

		int speed;
	};

}
}
}

#endif
