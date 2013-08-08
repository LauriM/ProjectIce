
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

	void IronItem::onPickup(  ) {
		return;
	}

	void IronItem::onDrop(  ) {
		return;
	}

	void IronItem::onInspect(  ) {
		return;
	}

}
}