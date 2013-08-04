
#include "engine/items/containers/BaseContainerItem.h"

namespace engine {
namespace items {
namespace containers {
	
	void BaseContainerItem::setContainedItem(BaseItem * item) {
		_containedItem = item;
	}

	BaseItem * BaseContainerItem::getContainedItem() {
		return _containedItem;
	}

	void BaseContainerItem::setQuantity(int quantity) {
		if ( quantity <= _maxQuantity )
			_quantity = quantity;
	}

	int BaseContainerItem::getQuantity() {
		return _quantity;
	}

	void BaseContainerItem::setMaxQuantity(int max) {
		_maxQuantity = max;
	}

	int BaseContainerItem::getMaxQuantity() {
		return _maxQuantity;
	}

	int BaseContainerItem::getTotalValue() {
		return _value * _quantity;
	}

}
}
}