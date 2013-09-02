#include "precompiled.h"

#include "engine/actor/ActorBase.h"

namespace engine {
namespace actor {

    bool ActorBase::attack(actor::ActorBase * const target) {
        int dmg = getStrength();

		console::ConsoleSystem::getMsgHistory().push_back(getName() + " attacks " + target->getName());

        target->setHp(target->getHp() - dmg);

        if(target->getHp() < 0){
			console::ConsoleSystem::getMsgHistory().push_back(getName() + " kills " + target->getName());
			//Give exp the amount of the targets HP
			giveExp(target->getMaxHp());
        }

        return true;
    }

}
}