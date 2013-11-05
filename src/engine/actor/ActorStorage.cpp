#include "engine/actor/ActorStorage.h"

namespace engine {
namespace actor {

	void ActorStorage::removeActor(ActorBase* actor){
		for(unsigned int i = 0;i < actors.size();++i){
			if(actors.at(i) == actor){
				actors.erase( actors.begin() + i);
				delete actor;
				LOG_INFO("actor removed!");
			}
		}
	}

	/**
	 * Insert actor to the manager.
	 * @param actor actor to be inserted
	 */
	void ActorStorage::insertActorToRoom(ActorBase* actor){
		actors.push_back(actor);
	}

	/**
	 * Adds actor to the remove queue.
	 *
	 * @param actor pointer to the actor to be removed.
	 */
	void ActorStorage::deleteActor(ActorBase* actor) {
		removeQueue.push_back(actor);
	}

	/**
	 * Remove actors queue for remove
	 */
	void ActorStorage::handleRemoveQueue() {
		for(unsigned int i = 0;i < removeQueue.size();++i){
			removeActor(removeQueue.at(i));
		}
	}

	std::vector<ActorBase *> ActorStorage::getActorsInRoom(const vec3 location){
		std::vector<ActorBase *> output;

		for(unsigned int i = 0;i < actors.size();++i){
			vec3 loc = actors.at(i)->getLocation();
			if(loc == location){
				output.push_back(actors.at(i));
			}
		}

		return output;
	}

}
}