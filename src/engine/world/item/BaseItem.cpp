
#include "engine/world/item/BaseItem.h"

namespace engine {
namespace world {
namespace item {

	BaseItem::BaseItem() {}

	String BaseItem::getName() {
		return _name;
	}

	int BaseItem::getValue() {
		return _value;
	}

	void BaseItem::setName(String name) {
		_name = name;
	}

	void BaseItem::setValue(int value) {
		_value = value;
	}

}
}
}