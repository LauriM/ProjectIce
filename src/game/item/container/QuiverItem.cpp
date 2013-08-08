
#include "game/item/container/QuiverItem.h"

namespace game {
namespace item {
namespace container {

	QuiverItem::QuiverItem() {
		name = "Quiver";
		description = "It holds arrows";
		value = 10.0;
		quantity = 0;
		maxQuantity = 20;
		containedItem = new ArrowItem();
	}

	QuiverItem::~QuiverItem() {	}

	void QuiverItem::onPickup( ) {
		return;
	}

	void QuiverItem::onInspect( ) {
		return;
	}

	void QuiverItem::onDrop( ) {
		return;
	}

}
}
}