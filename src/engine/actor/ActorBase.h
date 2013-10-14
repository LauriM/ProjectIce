#ifndef ENGINE_ACTOR_ACTORBASE_H
#define ENGINE_ACTOR_ACTORBASE_H

#include "precompiled.h"

#include "engine/math/vec2.h"
#include "engine/math/vec3.h"
#include "engine/actor/AIState.h"
#include "engine/console/ConsoleSystem.h"
#include "engine/inventory/Inventory.h"
#include "engine/actor/body/BodyPart.h"

namespace engine {
namespace actor {

	/**
	 * Base class for all actors.
	 *
	 * This class contains some stats and variables that every Actor should have.
	 */
	class ActorBase {
		protected:
			vec2 position; /* Position inside the room */
			vec3 location; /* Room location where actor is */

			/* stats */
			String name;

			char symbol;

			AIState aiState;

			int hp;
			int maxHp;

			int lvl;
			int exp;

			int strength;
			int dexterity;
			int constitution;

			inventory::Inventory inventory;

			body::BodyPart *torso;

		public:
			ActorBase()
				: hp(10)
				, maxHp(10)
				, lvl(1)
				, exp(0)
				, strength(0)
				, dexterity(0)
				, constitution(0)
			{}

			/**
			 *  This is used to handle stuff that should happen every tick. Like timers or stuff.
			 *  AI is handled in the AIsystem, not in this function
			 */
			virtual void update() = 0;

			virtual void onAttack( ActorBase * target ) = 0;

			/**
			 * Give certain amount of EXP, calculate possible level ups.
			 */
			void giveExp(int amount){
				exp += amount;

				//TODO: This is really shitty way to calculate level ups
				if(exp > (lvl * 10)){
					exp = 0;
					++lvl;
					CONSOLE_HISTORY_INSERT(getName() + " gained level!");
				}
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

			inventory::Inventory* getInventory() {
				return &inventory;
			}

			void setInventory(inventory::Inventory* inventory) {
				this->inventory = *inventory;
			}

			body::BodyPart * getTorso(){
				return torso;
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
