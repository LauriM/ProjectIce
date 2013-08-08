
#include "game/item/IronItem.h"

namespace game {
namespace item {
	
	IronItem::IronItem() {

		name = "Iron";
		description = "A normal piece of iron.";
		value = 10.0;
		stackable = false;
	}

	IronItem::~IronItem() {}

	void IronItem::onPickup( engine::actor::ActorBase * aOwner ) {
		return;
	}

	void IronItem::onDrop( engine::actor::ActorBase * aOwner ) {
		return;
	}

	void IronItem::onInspect( engine::actor::ActorBase * aOwner ) {
		return;
	}

}
}