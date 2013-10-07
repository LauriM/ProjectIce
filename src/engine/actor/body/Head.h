#ifndef ENGINE_ACTOR_BODY_HEAD_H
#define ENGINE_ACTOR_BODY_HEAD_H

#include "engine/actor/body/BodyPart.h"

namespace engine {
namespace actor {
namespace body {

	class Head : public BodyPart {
	public:
		Head()
			: wisdom(5)
			, level(1)
			, experience(0)
		{
			type   = TYPE_HEAD;
			blood  = 25;
			weight = 10;
			def	   = 5;
		}

		int wisdom;
		int experience;
		int level;
	};

}
}
}

#endif
