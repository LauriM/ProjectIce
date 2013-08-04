
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
		bool _stackable;

	public:

		String getName();
		String getDescription();
		double getValue();
		bool getStackable();

		void setName(String name);
		void setDescription(String description);
		void setValue(double value);
		void setStackable(bool stackable);

		virtual void onPickup( actor::ActorBase * aOwner ) = 0;
		virtual void onInspect( actor::ActorBase * aOwner ) = 0;
		virtual void onDrop( actor::ActorBase * aOwner ) = 0;

		virtual ~BaseItem() {};
	};

}
}

#endif
