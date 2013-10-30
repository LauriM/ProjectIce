#include "precompiled.h"

#include "engine/actor/ActorBase.h"

namespace engine {
namespace actor {

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

}
}
