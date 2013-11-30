#ifndef ENGINE_ACTOR_BODY_ARM_H
#define ENGINE_ACTOR_BODY_ARM_H

#include "engine/actor/body/BodyPart.h"

namespace engine {
namespace actor {
namespace body {

	class Arm : public BodyPart {
	public:
		Arm()
			: strength(5)
		{
			type   = TYPE_ARM;
			blood  = 50;
			weight = 10;
			name = "Arm";
		}

		int strength;
	};

}
}
}

#endif
