#include "precompiled.h"

#include "engine/actor/ActorBase.h"

namespace engine {
namespace actor {

    bool ActorBase::attack(actor::ActorBase * const target) {
        int dmg = getStrength();

		CONSOLE_HISTORY_INSERT(getName() + " attacks " + target->getName());

		//TODO: The attack system should be reimplemented after the bodypart system has been implemented.

        return true;
    }

}
}