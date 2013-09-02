#include "precompiled.h"

#include "engine/actor/ActorBase.h"

namespace engine {
namespace actor {

    bool ActorBase::attack(actor::ActorBase * const target) {
        int dmg = getStrength();

		CONSOLE_HISTORY_INSERT(getName() + " attacks " + target->getName());

        target->setHp(target->getHp() - dmg);

        if(target->getHp() < 0){
			CONSOLE_HISTORY_INSERT(getName() + " kills " + target->getName());
			//Give exp the amount of the targets HP
			giveExp(target->getMaxHp());
        }

        return true;
    }

}
}