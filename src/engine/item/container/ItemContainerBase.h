
#ifndef __ITEM_CONTAINER_BASE_H__
#define __ITEM_CONTAINER_BASE_H__

#include "engine/actor/ActorBase.h"
#include "engine/item/ItemBase.h"

namespace engine {
namespace item {
namespace container {
	
	class ItemContainerBase : public ItemBase {
	protected:
		ItemBase * containedItem;
		int quantity;
		int maxQuantity;
	public:

		void setContainedItem(ItemBase * item) {
			containedItem = item;
		}		

		ItemBase * getContainedItem() {
			return this->containedItem;
		}

		void setQuantity(int quantity) {
			if ( quantity > maxQuantity )
				return;
			
			this->quantity = quantity;
		}

		int getQuantity() {
			return quantity;
		}

		void setMaxQuantity(int max) {
			this->maxQuantity = max;
		}

		int getMaxQuantity() {
			return maxQuantity;
		}

		double getTotalValue() {
			return (value * quantity);
		}

		virtual void onPickup( actor::ActorBase * aOwner ) = 0;
		virtual void onInspect( actor::ActorBase * aOwner ) = 0;
		virtual void onDrop( actor::ActorBase * aOwner ) = 0;
	};

}
}
}

#endif