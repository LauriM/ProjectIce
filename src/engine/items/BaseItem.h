
#ifndef __BASE_ITEM_H__
#define __BASE_ITEM_H__

#include "precompiled.h"
#include "engine/actor/ActorBase.h"

namespace engine {
namespace items {

	class BaseItem {
	protected:

		String _name;
		String _description;
		double _value;

	public:

		String getName();
		String getDescription();
		double getValue();

		void setName(String name);
		void setDescription(String description);
		void setValue(double value);

		virtual void onDestroy( actor::ActorBase * aOwner ) = 0;
		virtual void onPickup( actor::ActorBase * aOwner ) = 0;
		virtual void onDrop( actor::ActorBase * aOwner ) = 0;
		virtual void onInspect( actor::ActorBase * aOwner ) = 0;
		virtual void onUse( actor::ActorBase * aOwner ) = 0;

		virtual ~BaseItem() {}

	};

}
}

#endif
