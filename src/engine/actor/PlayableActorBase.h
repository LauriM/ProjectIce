#ifndef __PLAYABLE_ACTOR_BASE_H__
#define __PLAYABLE_ACTOR_BASE_H__

#include "engine/actor/ActorBase.h"

namespace engine {
namespace actor {
	
	/*
		PlayableActorBase is meant to be extended by actors that represent something playable, this includes
		NPC's and controller characters like the player
	*/
	class PlayableActorBase : public ActorBase {
	protected:

		int hp;
		int maxHp;

		int strength;
		int dexterity;
		int constitution;

	public:

		int getHp() { 
			return hp;
		}

		void setHp(int hp) {
			this->hp = hp;
		}

		int getMaxHp() {
			return maxHp;
		}

		void setMaxHp(int maxHp) {
			this->maxHp = maxHp;
		}

		int getStrength() {
			return strength;
		}

		void setStrength(int strength) {
			this->strength = strength;
		}

		int getDexterity() {
			return dexterity;
		}

		void setDexterity(int dexterity) {
			this->dexterity = dexterity;
		}

		int getConstitution() {
			return constitution;
		}

		void setConstitution(int constitution) {
			this->constitution = constitution;
		}

		virtual void update() = 0;
		virtual void onAttack( ActorBase * target ) = 0;

	};

}
}

#endif
