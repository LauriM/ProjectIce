
#include "engine/items/BaseItem.h"

namespace engine {
namespace world {
namespace item {

	String BaseItem::getName() {
		return _name;
	}

	String BaseItem::getDescription() {
		return _description;
	}

	double BaseItem::getValue() {
		return _value;
	}

	double BaseItem::getWeight() {
		return _weight;
	}

	int BaseItem::getQuantity() {
		return _quantity;
	}

	void BaseItem::setName(String name) {
		_name = name;
	}

	void BaseItem::setDescription(String description) {
		_description = description;
	}

	void BaseItem::setValue(double value) {
		_value = value;
	}

	void BaseItem::setWeight(double weight) {
		_weight = weight;
	}

	void BaseItem::setQuantity(int quantity) {
		_quantity = quantity;
	}

}
}
}
