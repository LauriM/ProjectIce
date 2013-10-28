#ifndef ENGINE_ACTOR_ACTORBASE_H
#define ENGINE_ACTOR_ACTORBASE_H

#include "precompiled.h"

#include <vector>

#include "engine/math/vec2.h"
#include "engine/math/vec3.h"
#include "engine/actor/AIState.h"
#include "engine/console/ConsoleSystem.h"
#include "engine/inventory/Inventory.h"
#include "engine/actor/body/BodyPart.h"

#include "engine/actor/body/Torso.h"
#include "engine/actor/body/Leg.h"
#include "engine/actor/body/Head.h"
#include "engine/actor/body/Arm.h"

namespace engine {
namespace actor {

	typedef std::vector<body::BodyPart*> BodyPartContainer;

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

			inventory::Inventory inventory;

			BodyPartContainer bodyParts;

		public:
			ActorBase() {}

			/**
			 *  This is used to handle stuff that should happen every tick. Like timers or stuff.
			 *  AI is handled in the AIsystem, not in this function
			 */
			virtual void update() = 0;

			virtual void onAttack( ActorBase * target ) = 0;

			/**
			 * Add a new bodypart.
			 */
			void addBodyPart(body::BodyPart * part){
				this->bodyParts.push_back(part);
			}

			BodyPartContainer * getBodyParts(){
				return &bodyParts;
			}

			/*
			BodyPartContainer getBodyPartsByType(body::BodyPartType type){
				//TODO: stub
				BodyPartContainer container;

				for(int i = 0; i < bodyParts.size(); ++i){
					if(bodyParts.at(i)->type == type){
						container.push_back(bodyParts.at(i));
					}
				}

				return container;
			}
			*/

			template <typename T>
			BodyPartContainer getBodyPartsByType(){
				BodyPartContainer container;

				T* part;

				for(unsigned int i = 0;i < bodyParts.size(); ++i){
					part = dynamic_cast<T*>(bodyParts.at(i));
					if(part != NULL) {
						container.push_back(part);
					}
				}
				return container;
			}

			/*
			 * Stats getters with counting limb status
			 * These functions should be prefered over manual
			 * searching, because these functions provide limb
			 * status into the final value.
			 */

			/**
			 * returns weight of all limbs combined;
			 */
			int getWeight() {
				int weight = 0;

				for(unsigned int i = 0; i < bodyParts.size(); ++i) {
					weight += bodyParts.at(i)->weight;
				}

				return weight;
			}

			int getSpeed() {
				int speed = 0;

				BodyPartContainer legs = getBodyPartsByType<body::Leg>();
				for(unsigned int i = 0; i < legs.size(); ++i){
					body::Leg* leg = dynamic_cast<body::Leg*>(legs.at(i));
					speed += leg->speed;
				}

				return speed;
			}

			int getWisdom(){
				int wisdom = 0;

				BodyPartContainer heads = getBodyPartsByType<body::Head>();
				for(unsigned int i = 0; i < heads.size(); ++i){
					body::Head* head = dynamic_cast<body::Head*>(heads.at(i));
					wisdom += head->wisdom;
				}

				return wisdom;
			}

			int getStrength() {
				int str = 0;

				BodyPartContainer arms = getBodyPartsByType<body::Head>();
				for(unsigned int i = 0; i < arms.size(); ++i){
					body::Arm* arm = dynamic_cast<body::Arm*>(arms.at(i));
					str += arm->strength;
				}

				return str;
			}

			int getStamina(){
				int stamina = 0;

				BodyPartContainer torsos = getBodyPartsByType<body::Torso>();
				for(unsigned int i = 0; i < torsos.size(); ++i){
					body::Torso* torso = dynamic_cast<body::Torso*>(torsos.at(i));
					stamina += torso->stamina;
				}

				return stamina;
			}

			int getNutrition(){
				int nutrition = 0;

				BodyPartContainer torsos = getBodyPartsByType<body::Torso>();
				for(unsigned int i = 0; i < torsos.size(); ++i){
					body::Torso* torso = dynamic_cast<body::Torso*>(torsos.at(i));
					nutrition += torso->nutrition;
				}

				return nutrition;
			}

			/**
			 * Give certain amount of EXP, calculate possible level ups.
			 */
			void giveExp(int amount){
				//TODO: Move the exp calculations to the HEAD bodypart!

				/*
				exp += amount;

				//TODO: This is really shitty way to calculate level ups
				if(exp > (lvl * 10)){
					exp = 0;
					++lvl;
					CONSOLE_HISTORY_INSERT(getName() + " gained level!");
				}
				*/
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

			inventory::Inventory* getInventory() {
				return &inventory;
			}

			void setInventory(inventory::Inventory* inventory) {
				this->inventory = *inventory;
			}
	};

}
}

#endif
