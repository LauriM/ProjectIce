#ifndef ENGINE_ACTOR_ACTORBASE_H
#define ENGINE_ACTOR_ACTORBASE_H

#include "precompiled.h"

#include "engine/math/vec2.h"
#include "engine/math/vec3.h"
#include "engine/world/WorldSystem.h"

namespace engine {
namespace actor {

	class ActorBase {
		protected:
			engine::world::WorldSystem *world;
			vec2 position; /* Position inside the room */
			vec3 location; /* Room location where actor is */

			/* stats */
			int hp;
			int maxHp;
			String name;

		public:
			virtual void update() = 0;

			//Should be called for all the actors
			void setWorld(engine::world::WorldSystem *newWorld){
				world = newWorld;
			}

			/**
			 * Move actor to certain direction, check collisions and enemies.
			 *
			 * Vec2 contains x/y movement changes that should be done.
			 *
			 * Returns if the move was valid.
			 */
			bool MoveActor(vec2 movement){
				//TODO: implement check that the "world" is not invalid

				vec2 newPos;
				newPos.x = position.x + movement.x;
				newPos.y = position.y + movement.y;

				if(!world->getRoom(location)->getTile(newPos.x,newPos.y)->blocks){
					position = newPos;
					return true;
				}

				LOG_DEBUG("actor collides with tile");
				return false; //collided
			}

			/* getters / setters */
			void setName(String newName){
				name = newName;
			}

			String getName(){
				return name;
			}

			vec2* getPos(){
				return &position;
			}

			int getHp() {
				return hp;
			}

			void setHp(int ihp) {
				hp = ihp;
			}
	};

}
}

#endif
