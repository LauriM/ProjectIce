
#include "game/item/IronItem.h"

namespace game {
namespace item {

	IronItem::IronItem() {
		name        = "Iron";
		description = "A normal piece of iron.";
		value       = 10.0;
		symbol      = '*';
	}

	IronItem::~IronItem() {}

	void IronItem::onPickup( engine::actor::ActorBase * actor  ) {
		return;
	}

	void IronItem::onDrop( engine::actor::ActorBase * actor  ) {
		return;
	}

	void IronItem::onInspect( engine::actor::ActorBase * actor  ) {
		return;
	}

}
}
