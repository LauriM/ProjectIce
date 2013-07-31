
#include "engine/items/BaseItem.h"

namespace engine {
namespace items {

	String BaseItem::getName() {
		return _name;
	}

	String BaseItem::getDescription() {
		return _description;
	}

	double BaseItem::getValue() {
		return _value;
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

}
}
