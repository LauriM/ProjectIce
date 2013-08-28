#include "precompiled.h"

#include "engine/actor/ActorBase.h"

namespace engine {
namespace actor {

    bool ActorBase::attack(actor::ActorBase * const target) {
        int dmg = getStrength();

        target->setHp(target->getHp() - dmg);

        if(target->getHp() < 0){
            LOG_INFO("KILL! TODO: apply some exp here to the attacker");
        }

        return true;
    }

}
}