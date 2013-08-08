
#include "engine/items/ItemBase.h"

namespace engine {
namespace items {

	String ItemBase::getName() {
		return _name;
	}

	String ItemBase::getDescription() {
		return _description;
	}

	double ItemBase::getValue() {
		return _value;
	}

	bool ItemBase::getStackable() {
		return _stackable;
	}

	void ItemBase::setName(String name) {
		_name = name;
	}

	void ItemBase::setDescription(String description) {
		_description = description;
	}

	void ItemBase::setValue(double value) {
		_value = value;
	}

	void ItemBase::setStackable(bool stackable) {
		_stackable = stackable;
	}

}
}
