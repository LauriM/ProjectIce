
#include "engine/actor/ActorBodyLimb.h"

namespace engine {
namespace actor {

	ActorBodyLimb::ActorBodyLimb( ActorBodyLimb * pparent, String name ) {
		attachToParent(pparent);
		this->name = name;
	}

	ActorBodyLimb::~ActorBodyLimb() {
		std::vector<ActorBodyLimb*>::iterator bodyPartIterator;
		for( bodyPartIterator = children.begin(); bodyPartIterator != children.end(); ++bodyPartIterator ) {
			ActorBodyLimb * severed = (*bodyPartIterator);
			delete severed;
		}
	}

	void ActorBodyLimb::attachToParent( ActorBodyLimb * pparent ) {
		if ( pparent ) {
			this->parent = pparent;
			pparent->children.push_back( this );
		}
		return;
	}

	String ActorBodyLimb::getName() {
		return this->name;
	}

	ActorBodyLimb * ActorBodyLimb::getParent() {
		return this->parent;
	}

	std::vector<ActorBodyLimb*> ActorBodyLimb::getDirectChildren() {
		return this->children;
	}

	std::vector<ActorBodyLimb*> ActorBodyLimb::getAllChildren() {
		std::vector<ActorBodyLimb*> allChildren;
		std::vector<ActorBodyLimb*>::iterator childIterator;
		for ( childIterator = children.begin(); childIterator == children.end(); ++childIterator ) {
			std::vector<ActorBodyLimb*> childrenOfChild;
			childrenOfChild = (*childIterator)->getAllChildren();
			allChildren.insert( allChildren.end(), childrenOfChild.begin(), childrenOfChild.end() );
		}
		return allChildren;
	}

}
}
