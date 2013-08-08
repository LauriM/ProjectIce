
#include "engine/item/container/ItemContainerBase.h"

namespace engine {
namespace item {
namespace container {
	
	void ItemContainerBase::setContainedItem(ItemBase * item) {
		_containedItem = item;
	}

	ItemBase * ItemContainerBase::getContainedItem() {
		return _containedItem;
	}

	void ItemContainerBase::setQuantity(int quantity) {
		if ( quantity <= _maxQuantity )
			_quantity = quantity;
	}

	int ItemContainerBase::getQuantity() {
		return _quantity;
	}

	void ItemContainerBase::setMaxQuantity(int max) {
		_maxQuantity = max;
	}

	int ItemContainerBase::getMaxQuantity() {
		return _maxQuantity;
	}

	int ItemContainerBase::getTotalValue() {
		return _value * _quantity;
	}

}
}
}