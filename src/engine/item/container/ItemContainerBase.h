
#ifndef __ITEM_CONTAINER_BASE_H__
#define __ITEM_CONTAINER_BASE_H__

#include "engine/actor/ActorBase.h"
#include "engine/item/ItemBase.h"

namespace engine {
namespace item {
namespace container {
	
	/**
	 *	An abstract object which represents and item that is responsible for managing multiple items of the same type.
	 *  Quivers for example will hold arrows as well as a count the quantity
	 */		
	class ItemContainerBase : public ItemBase {
	protected:
		ItemBase * containedItem;
		int quantity;
		int maxQuantity;
	public:

		/** Sets item in which this container will contain
		 * @param item the untracked instance of an item
		 */
		void setContainedItem(ItemBase * item) {
			containedItem = item;
		}		


		ItemBase * getContainedItem() {
			return this->containedItem;
		}

		/** Sets the total items avaliable in this container
		 * @param quantity the quantity
		 */
		void setQuantity(int quantity) {
			if ( quantity > maxQuantity )
				return;
			
			this->quantity = quantity;
		}

		int getQuantity() {
			return quantity;
		}

		/** Sets the total items this container may hold
		 * @param max the max quantity
		 */
		void setMaxQuantity(int max) {
			this->maxQuantity = max;
		}

		int getMaxQuantity() {
			return maxQuantity;
		}

		double getTotalValue() {
			return (value * quantity);
		}

		/** Inhereited method from engine::item::ItemBase
		 * @see engine::item::ItemBase
		 */
		virtual void onPickup( actor::ActorBase * actor ) = 0;

		/** Inhereited method from engine::item::ItemBase
		 * @see engine::item::ItemBase
		 */
		virtual void onInspect( actor::ActorBase * actor ) = 0;

		/** Inhereited method from engine::item::ItemBase
		 * @see engine::item::ItemBase
		 */
		virtual void onDrop( actor::ActorBase * actor ) = 0;
	};

}
}
}

#endif