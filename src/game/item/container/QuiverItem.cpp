
#include "game/item/container/QuiverItem.h"

namespace game {
namespace item {
namespace container {

	QuiverItem::QuiverItem() {
		_name = "Quiver";
		_description = "It holds arrows";
		_value = 10.0;
		_quantity = 0;
		_maxQuantity = 20;
		_containedItem = new ArrowItem();
	}

	QuiverItem::~QuiverItem() {	}

	void QuiverItem::onPickup( engine::actor::ActorBase * aOwner ) {
		return;
	}

	void QuiverItem::onInspect( engine::actor::ActorBase * aOwner ) {
		return;
	}

	void QuiverItem::onDrop( engine::actor::ActorBase * aOwner ) {
		return;
	}

}
}
}