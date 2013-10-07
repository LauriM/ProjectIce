#ifndef ENGINE_ACTOR_BODY_BODYPART_H
#define ENGINE_ACTOR_BODY_BODYPART_H

#include <vector>

namespace engine {
namespace actor {
namespace body {

	enum BodyPartType {
		TYPE_TORSO = 0,
		TYPE_ARM,
		TYPE_LEGS,
		TYPE_HEAD,
	};

	enum BodyPartAttribute {
		ATR_FIRE = 0,
		ATR_BURNT,
		ATR_COLD,
		ATR_FROZEN,
		ATR_BLEEDING,
		ATR_HEAVYBLEEDING,
		ATR_MINORSTUN,
		ATR_STUN,
		ATR_MAJORSTUN,
		ATR_BRUISED,
		ATR_CRUSHED,
		ATR_NERVEDAMAGE,
		ATR_ROTTING,
	};

	class BodyPart {
	private:
		BodyPart *parent;
		std::vector<BodyPart*> childs;

	public:
		BodyPart()
			: weight(25)
			, type(TYPE_TORSO)
			, blood(150)
			, def(5)
		{}

		BodyPartType type;
		BodyPartAttribute attributes; //Should be bitflags or something funny

		//attributes
		int weight;
		int blood;
		int def;

	};

}
}
}

#endif