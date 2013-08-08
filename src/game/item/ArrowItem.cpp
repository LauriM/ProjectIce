
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

	void ArrowItem::onPickup( ) {
		return;
	}

	void ArrowItem::onInspect( ) {

	}

	void ArrowItem::onDrop( ) {
		return;
	}

}
}
