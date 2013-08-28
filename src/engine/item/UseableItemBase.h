#ifndef ENGINE_ITEM_USEABLEITEM_H
#define ENGINE_ITEM_USEABLEITEM_H

#include "precompiled.h"

#include "engine/actor/ActorBase.h"
#include "engine/item/ItemBase.h"

namespace engine {
namespace item {
	
	/**
	 *	An abstract object which is used to give the instance of an item definitions and
	 *  properties of items which are to be "Useable", such as potions, drinks, etc.
	 */	
	class UseableItemBase : public ItemBase {
	protected:
		String useDescription;
	public:

		/** Sets the use description of the current instance
		 * @param d description
		 */
		void setUseDescription(String d) {
			useDescription = d;
		}

		/** Get a description of what happens when the instance of the item is used
		 * @returns useDescription the desription of item usage
		 */
		String getUseDescription() {
			return useDescription;
		}

		/** The action that is called from the engine when this item is "Picked Up" off the ground.
		 * @param actor the instance of the actor who actually used the item
		 * @param target the instance of the actor who the action of using this item should affect
		 */
		virtual void onUse( actor::ActorBase * user, actor::ActorBase * target = 0 ) = 0;

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

#endif