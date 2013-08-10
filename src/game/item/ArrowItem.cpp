
#include "game/item/ArrowItem.h"

namespace game {
namespace item {

	ArrowItem::ArrowItem() {
		name        = "Arrow";
		description = "A simple arrow.";
		value       = 1.0;
		symbol      = '/';
	}

	ArrowItem::~ArrowItem() {}

	void ArrowItem::onPickup( engine::actor::ActorBase * actor ) {
		return;
	}

	void ArrowItem::onInspect( engine::actor::ActorBase * actor ) {
		return;
	}

	void ArrowItem::onDrop( engine::actor::ActorBase * actor ) {
		return;
	}

}
}
