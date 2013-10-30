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
			void addBodyPart(body::BodyPart * part);

			void removeBodyPart(body::BodyPart * part);

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
			int getWeight();
			int getSpeed();
			int getWisdom();
			int getStrength();
			int getStamina();
			int getNutrition();

			/* modifiers */

			void addNutrition(int value);
			void giveExp(int amount);
			bool attack(actor::ActorBase * const target);

			/* getters / setters */

			BodyPartContainer * getBodyParts(){
				return &bodyParts;
			}

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
