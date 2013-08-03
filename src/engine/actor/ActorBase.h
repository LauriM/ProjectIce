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

			/**
			 * Move actor to certain direction, check collisions and enemies.
			 *
			 * Vec2 contains x/y movement changes that should be done.
			 *
			 * Returns if the move was valid.
			 */
			bool MoveActor(vec2 movement){
				//TODO: implement collision checks.
				//TODO: implement room change.

				position.x += movement.x;
				position.y += movement.y;

				return true;
			}

			/* getters / setters */
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
