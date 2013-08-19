#include "engine/actor/ActorBase.h"
#include "engine/combat/Combat.h"

namespace engine {
namespace combat {

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
	bool attackActor(actor::ActorBase * actor, actor::ActorBase * target){
		int dmg = actor->getStrength();

		target->setHp(target->getHp() - dmg);

		if(target->getHp() < 0){
			LOG_INFO("KILL! TODO: apply some exp here to the attacker");
		}

		//TODO: actually use the boolean to return something else
		return true;
	}

}
}
