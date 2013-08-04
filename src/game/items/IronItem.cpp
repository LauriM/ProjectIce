
#include "game/items/IronItem.h"

namespace game {
namespace items {
	
	IronItem::IronItem() {

		_name = "Iron";
		_description = "A normal piece of iron.";
		_value = 10.0;
		_stackable = false;
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