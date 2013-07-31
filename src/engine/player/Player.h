#ifndef ENGINE_PLAYER_PLAYER_H
#define ENGINE_PLAYER_PLAYER_H

#include "precompiled.h"

#include "engine/math/vec2.h"
#include "engine/math/vec3.h"

#define PLAYER_DEFAULT_MAXHP 10

namespace engine {
namespace player {

class Player {
	private:
		vec2 position; /* Position inside the room */
		vec3 location; /* Room location where player is */

		/* stats */
		int hp;
		int maxHp;
		String name;

	public:
		void init();
		void update();

		String getName();
};

}
}

#endif
