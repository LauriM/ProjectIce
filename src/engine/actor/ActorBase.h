#ifndef ENGINE_ACTOR_ACTORBASE_H
#define ENGINE_ACTOR_ACTORBASE_H

#include "precompiled.h"

#include "engine/math/vec2.h"
#include "engine/math/vec3.h"

namespace engine {
namespace actor {

	class ActorBase {
		protected:
			vec2 position; /* Position inside the room */
			vec3 location; /* Room location where actor is */

			/* stats */
			int hp;
			int maxHp;
			String name;

		public:
			virtual void update() = 0;

			void setName(String newName){
				name = newName;
			}

			String getName(){
				return name;
			}
	};

}
}

#endif
