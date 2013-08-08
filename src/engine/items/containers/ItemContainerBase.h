
#ifndef __ITEM_CONTAINER_BASE_H__
#define __ITEM_CONTAINER_BASE_H__

#include "engine/actor/ActorBase.h"
#include "engine/items/ItemBase.h"

namespace engine {
namespace items {
namespace containers {
	
	class ItemContainerBase : public ItemBase {
	protected:
		ItemBase * _containedItem;
		int _quantity;
		int _maxQuantity;
	public:

		void setContainedItem(ItemBase * item);
		ItemBase * getContainedItem();

		void setQuantity(int quantity);
		int getQuantity();

		void setMaxQuantity(int max);
		int getMaxQuantity();

		int getTotalValue();

		virtual void onPickup( actor::ActorBase * aOwner ) = 0;
		virtual void onInspect( actor::ActorBase * aOwner ) = 0;
		virtual void onDrop( actor::ActorBase * aOwner ) = 0;
	};

}
}
}

#endif