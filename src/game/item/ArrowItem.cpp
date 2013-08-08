
#include "game/item/ArrowItem.h"

namespace game {
namespace item {

	ArrowItem::ArrowItem() {
		name = "Arrow";
		description = "A simple arrow.";
		value = 1.0;
		stackable = true;
	}

	ArrowItem::~ArrowItem() {}

	void ArrowItem::onPickup( engine::actor::ActorBase * aOwner ) {
		return;
	}

	void ArrowItem::onInspect( engine::actor::ActorBase * aOwner ) {
		// oh no, it stabs you in the face!
		aOwner->setHp( aOwner->getHp() - 1 );
		return;
	}

	void ArrowItem::onDrop( engine::actor::ActorBase * aOwner ) {
		return;
	}

}
}
