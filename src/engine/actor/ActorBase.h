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
			~ActorBase();

			/**
			 *  This is used to handle stuff that should happen every tick. Like timers or stuff.
			 *  AI is handled in the AIsystem, not in this function
			 */
			virtual void update() = 0;

			virtual void onAttack( ActorBase * target ) = 0;

			/**
			 * Add a new bodypart.
			 */
			void addBodyPart(body::BodyPart * part);
			void removeBodyPart(body::BodyPart * part);
			void removeAllBodyParts();

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
			 *
			 * All values of these are combined and attributes have been calculated.
			 */
			const int getWeight();
			const int getSpeed();
			const int getWisdom();
			const int getStrength();
			const int getStamina();
			const int getNutrition();

			/* modifiers */

			void addNutrition(int value);
			void giveExp(int amount);
			bool attack(actor::ActorBase * const target);

			/* getters / setters */

			const BodyPartContainer * getBodyParts() const {
				return &bodyParts;
			}

			void setName(String newName){
				name = newName;
			}

			const String getName() const {
				return name;
			}

			const vec2 getPosition() const {
				return position;
			}

			const vec2* getPos() const {
				return &position;
			}

			const vec3 getLocation() const {
				return location;
			}

			void setPosition(vec2 pos){
				position = pos;
			}

			void setLocation(vec3 loc){
				location = loc;
			}

			const char getSymbol() const{
				return symbol;
			}

			const AIState getAIState() const {
				return aiState;
			}

			void setAIState(AIState state){
				aiState = state;
			}

			const inventory::Inventory* getInventory() const {
				return &inventory;
			}

			void setInventory(inventory::Inventory* inventory) {
				this->inventory = *inventory;
			}
	};

}
}

#endif
