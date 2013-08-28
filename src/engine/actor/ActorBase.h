#ifndef ENGINE_ACTOR_ACTORBASE_H
#define ENGINE_ACTOR_ACTORBASE_H

#include "precompiled.h"

#include "engine/math/vec2.h"
#include "engine/math/vec3.h"
#include "engine/world/WorldSystem.h"
#include "engine/actor/AIState.h"

namespace engine {
namespace actor {

	/**
	 * Base class for all actors.
	 *
	 * This class contains some stats and variables that every Actor should have.
	 */
	class ActorBase {
		protected:
			engine::world::WorldSystem *world;
			vec2 position; /* Position inside the room */
			vec3 location; /* Room location where actor is */

			/* stats */
			String name;

			char symbol;

			AIState aiState;

			int hp;
			int maxHp;

			int strength;
			int dexterity;
			int constitution;

		public:
			/**
			 *  This is used to handle stuff that should happen every tick. Like timers or stuff.
			 *  AI is handled in the AIsystem, not in this function
			 */
			virtual void update() = 0;

			virtual void onAttack( ActorBase * target ) = 0;

			//Should be called for all the actors
			//
			//NOTE: IF THIS IS NOT SET, THE GAME WILL CRASH
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
				LOG_ERROR("MoveActor is DERECRATED");
				return true;
			}

			/* getters / setters */
			void setName(String newName){
				name = newName;
			}

			String getName(){
				return name;
			}

			vec2 getPosition(){
				return position;
			}

			vec2* getPos(){
				//TODO: this should be deprecrated, it allows modifying the position the "wrong" way.
				return &position;
			}

			vec3 getLocation(){
				return location;
			}

			void setPosition(vec2 pos){
				position = pos;
			}

			void setLocation(vec3 loc){
				location = loc;
			}

			char getSymbol(){
				return symbol;
			}

			AIState getAIState(){
				return aiState;
			}

			void setAIState(AIState state){
				aiState = state;
			}

			int getHp() {
				return hp;
			}

			void setHp(int hp) {
				this->hp = hp;
			}

			int getMaxHp() {
				return maxHp;
			}

			void setMaxHp(int maxHp) {
				this->maxHp = maxHp;
			}

			int getStrength() {
				return strength;
			}

			void setStrength(int strength) {
				this->strength = strength;
			}

			int getDexterity() {
				return dexterity;
			}

			void setDexterity(int dexterity) {
				this->dexterity = dexterity;
			}

			int getConstitution() {
				return constitution;
			}

			void setConstitution(int constitution) {
				this->constitution = constitution;
			}

			/**
			 * Checks for melee attack from actor to different actor. Counts damage.
			 *
			 * If the target is friendly and attack has been cancelled, returns false.
			 *
			 * @param actor The actor that is attacking.
			 * @param target The target that is under attack.
			 *
			 * @return If the attack was done or not.
			 */
			bool attack(actor::ActorBase * const target);
	};

}
}

#endif
