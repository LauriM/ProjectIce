
#include "game/item/ArrowItem.h"

namespace game {
namespace item {

	ArrowItem::ArrowItem() {
		_name = "Arrow";
		_description = "A simple arrow.";
		_value = 1.0;
		_stackable = true;
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
