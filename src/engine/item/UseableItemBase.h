
#ifndef __USEABLE_ITEM_H__
#define __USEABLE_ITEM_H__

#include "precompiled.h"

#include "engine/actor/ActorBase.h"
#include "engine/item/ItemBase.h"

namespace engine {
namespace item {
	
	class UseableItemBase : public ItemBase {
	protected:
		String useDescription;
	public:

		void setUseDescription(String d) {
			useDescription = d;
		}

		String getUseDescription() {
			return useDescription;
		}

		virtual void onUse( actor::ActorBase * user, actor::ActorBase * target = 0 ) = 0;
		virtual void onPickup( actor::ActorBase * actor ) = 0;
		virtual void onInspect( actor::ActorBase * actor ) = 0;
		virtual void onDrop( actor::ActorBase * actor ) = 0;
	};

}
}

#endif