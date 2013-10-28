#ifndef ENGINE_ACTOR_BODY_BODYPART_H
#define ENGINE_ACTOR_BODY_BODYPART_H

#include <vector>

namespace engine {
namespace actor {
namespace body {

	enum BodyPartType {
		TYPE_INVALID = 0,
		TYPE_TORSO,
		TYPE_ARM,
		TYPE_LEG,
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
	public:
		BodyPart *parent;
		std::vector<BodyPart*> childs;

		BodyPart()
			: parent(this) //default to itself, addchild should handle change of this correctly
			, weight(25)
			, type(TYPE_INVALID)
			, blood(150)
			, def(8)
		{}

		BodyPartType type;
		BodyPartAttribute attributes; //Should be bitflags or something funny

		//attributes
		int weight;
		int blood;
		int def;

		void addChild(BodyPart * part){
			part->parent = this;
			this->childs.push_back(part);
		}
	};

}
}
}

#endif