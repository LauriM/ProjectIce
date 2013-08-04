
#ifndef __BASE_CONTAINER_ITEM__
#define __BASE_CONTAINER_ITEM__

#include "engine/actor/ActorBase.h"
#include "engine/items/BaseItem.h"

namespace engine {
namespace items {
namespace containers {
	
	class BaseContainerItem : public BaseItem {
	protected:
		BaseItem * _containedItem;
		int _quantity;
		int _maxQuantity;
	public:

		void setContainedItem(BaseItem * item);
		BaseItem * getContainedItem();

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