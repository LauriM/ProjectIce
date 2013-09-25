
#include "engine/body/BodyMember.h"

namespace engine {
namespace body {

	BodyMember::BodyMember( BodyMember * pparent, String name ) {
		attachToParent(pparent);
		this->name = name;
	}

	BodyMember::~BodyMember() {
		std::vector<BodyMember*>::iterator bodyPartIterator;
		for( bodyPartIterator = children.begin(); bodyPartIterator != children.end(); ++bodyPartIterator ) {
			BodyMember * severed = (*bodyPartIterator);
			delete severed;
		}
	}

	void BodyMember::attachToParent( BodyMember * pparent ) {
		if ( pparent ) {
			this->parent = pparent;
			pparent->children.push_back( this );
		}
		return;
	}

	String BodyMember::getName() {
		return this->name;
	}

	BodyMember * BodyMember::getParent() {
		return this->parent;
	}

	std::vector<BodyMember*> BodyMember::getDirectChildren() {
		return this->children;
	}

	std::vector<BodyMember*> BodyMember::getAllChildren() {
		std::vector<BodyMember*> allChildren;
		std::vector<BodyMember*>::iterator childIterator;
		for ( childIterator = children.begin(); childIterator == children.end(); ++childIterator ) {
			std::vector<BodyMember*> childrenOfChild;
			childrenOfChild = (*childIterator)->getAllChildren();
			allChildren.insert( allChildren.end(), childrenOfChild.begin(), childrenOfChild.end() );
		}
		return allChildren;
	}

}
}
