#ifndef ENGINE_ACTOR_AISTATE_H
#define ENGINE_ACTOR_AISTATE_H

namespace engine {
namespace actor {

	/**
	 * State that the AI is currently in.
	 */
	enum AIState {
		AISTATE_SLEEP = 0, //Sleep until woken up
		AISTATE_PLAYER,    //Player charachter, AI is done using the input handling
		AISTATE_PATROL,    //Randomly move around
	};

}
}

#endif
