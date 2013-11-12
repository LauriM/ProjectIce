#include "precompiled.h"

#include "engine/actor/ActorBase.h"

namespace engine {
namespace actor {

	/**
	 * Clear up all stuff!
	 */
	ActorBase::~ActorBase() {
		removeAllBodyParts();
	}

	/**
	 * Remove all bodyparts that the actor may have.
	 */
	void ActorBase::removeAllBodyParts() {
		for (unsigned int i = 0; i < bodyParts.size(); ++i) {
			delete bodyParts.at(i);
		}

		bodyParts.clear();
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
    bool ActorBase::attack(actor::ActorBase * const target) {
        int dmg = getStrength();

		CONSOLE_HISTORY_INSERT(getName() + " attacks " + target->getName());

		//TODO: The attack system should be reimplemented after the bodypart system has been implemented.

		//Debug: removes head on attack!

		BodyPartContainer container = target->getBodyPartsByType<body::Head>();

		for(unsigned int i = 0; i < container.size(); ++i) {
			target->removeBodyPart(container.at(i));
			LOG_INFO("Head removed!");
		}

        return true;
    }

	void ActorBase::addBodyPart(body::BodyPart * part){
		this->bodyParts.push_back(part);
	}

	void ActorBase::removeBodyPart(body::BodyPart * part){
		for(unsigned int i = 0; i < bodyParts.size(); ++i) {
			if(bodyParts.at(i) == part) {
				delete bodyParts.at(i);
				bodyParts.erase(bodyParts.begin() + i);
			}
		}
	}

	const int ActorBase::getWeight() {
		int weight = 0;

		for(unsigned int i = 0; i < bodyParts.size(); ++i) {
			weight += bodyParts.at(i)->weight;
		}

		return weight;
	}

	const int ActorBase::getSpeed() {
		int speed = 0;

		BodyPartContainer legs = getBodyPartsByType<body::Leg>();
		for(unsigned int i = 0; i < legs.size(); ++i){
			body::Leg* leg = dynamic_cast<body::Leg*>(legs.at(i));
			speed += leg->speed;
		}

		return speed;
	}

	const int ActorBase::getWisdom() {
		int wisdom = 0;

		BodyPartContainer heads = getBodyPartsByType<body::Head>();
		for(unsigned int i = 0; i < heads.size(); ++i){
			body::Head* head = dynamic_cast<body::Head*>(heads.at(i));
			wisdom += head->wisdom;
		}

		return wisdom;
	}

	const int ActorBase::getStrength() {
		int str = 0;

		BodyPartContainer arms = getBodyPartsByType<body::Arm>();
		for(unsigned int i = 0; i < arms.size(); ++i){
			body::Arm* arm = dynamic_cast<body::Arm*>(arms.at(i));
			str += arm->strength;
		}

		return str;
	}

	const int ActorBase::getStamina() {
		int stamina = 0;

		BodyPartContainer torsos = getBodyPartsByType<body::Torso>();
		for(unsigned int i = 0; i < torsos.size(); ++i){
			body::Torso* torso = dynamic_cast<body::Torso*>(torsos.at(i));
			stamina += torso->stamina;
		}

		return stamina;
	}

	const int ActorBase::getNutrition() {
		int nutrition = 0;

		BodyPartContainer torsos = getBodyPartsByType<body::Torso>();
		for(unsigned int i = 0; i < torsos.size(); ++i){
			body::Torso* torso = dynamic_cast<body::Torso*>(torsos.at(i));
			nutrition += torso->nutrition;
		}

		return nutrition;
	}

	/**
	 * Add nutrition, negative nutrition to remove.
	 *
	 * Currently removes from all torsos.
	 */
	void ActorBase::addNutrition(int value){
		BodyPartContainer torsos = getBodyPartsByType<body::Torso>();

		if (torsos.size() == 1) {
			//There is only one torso, no need to split anything
			body::Torso* torso = dynamic_cast<body::Torso*>(torsos.at(0));
			torso->nutrition += value;

			return;
		}

		//Multiple torsos, lets split the nutrition added/spent
		for(unsigned int i = 0; i < torsos.size(); ++i){
			body::Torso* torso = dynamic_cast<body::Torso*>(torsos.at(i));
			torso->nutrition += value;
		}
		LOG_WARNING("Nutrition on multiple torsos not implemented!");
	}

}
}
