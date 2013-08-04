
#include "game/items/ArrowItem.h"

namespace game {
namespace items {
	
	ArrowItem::ArrowItem() {
		_name = "Arrow";
		_description = "A simple arrow.";
		_value = 1.0;
		_stackable = true;
	}

	ArrowItem::~ArrowItem() {}

	void ArrowItem::onPickup( actor::ActorBase * aOwner ) {
		return;
	}

	void ArrowItem::onInspect( actor::ActorBase * aOwner ) {
		// oh no, it stabs you in the face!
		aOwner->setHp( aOwner->getHp() - 1 );
		return;
	}

	void ArrowItem::onDrop( actor::ActorBase * aOwner ) {
		return;
	}

}
}