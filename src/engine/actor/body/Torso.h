#ifndef ENGINE_ACTOR_BODY_TORSO_H
#define ENGINE_ACTOR_BODY_TORSO_H

#include "engine/actor/body/BodyPart.h"

namespace engine {
namespace actor {
namespace body {

	class Torso : public BodyPart {
	private:
		int stamina;
	public:
		Torso()
			: stamina(5)
		{
			type   = TYPE_TORSO;
			blood  = 150;
			weight = 60;
		}
	};

}
}
}

#endif
