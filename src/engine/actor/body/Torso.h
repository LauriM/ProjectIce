#ifndef ENGINE_ACTOR_BODY_TORSO_H
#define ENGINE_ACTOR_BODY_TORSO_H

namespace engine {
namespace actor {
namespace body {

	class Torso : public BodyPart {
	private:
		int stamina;
	public:
		Torso()
			: stamina(5)
		{}
	};

}
}
}

#endif