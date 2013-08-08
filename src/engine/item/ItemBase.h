
#ifndef __ITEM_BASE_H__
#define __ITEM_BASE_H__

#include "precompiled.h"
#include "engine/actor/ActorBase.h"

namespace engine {
namespace item {

	class ItemBase {
	protected:

		String name;
		String description;
		double value;
		bool stackable;

	public:

		String getName() {
			return name;
		}

		String getDescription() {
			return description;
		}

		double getValue() {
			return value;
		}

		bool getStackable() {
			return stackable;
		}

		void setName(String name) {
			this->name = name;
		}

		void setDescription(String description) {
			this->description = description;
		}

		void setValue(double value) {
			this->value = value;
		}

		void setStackable(bool stackable) {
			this->stackable = stackable;
		}

		virtual void onPickup( actor::ActorBase * aOwner ) = 0;
		virtual void onInspect( actor::ActorBase * aOwner ) = 0;
		virtual void onDrop( actor::ActorBase * aOwner ) = 0;

		virtual ~ItemBase() {};
	};

}
}

#endif
