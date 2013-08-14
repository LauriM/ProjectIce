
#ifndef __ITEM_BASE_H__
#define __ITEM_BASE_H__

#include "precompiled.h"

#include "engine/actor/ActorBase.h"

namespace engine {
namespace item {

	class ItemBase {
	protected:
		int id;

		String name;
		String description;
		double value;

		char symbol;

		ItemBase() {
			id = -1;
		}

	public:

		friend class ItemManager;

		int getId() {
			return id;
		}

		String getName() {
			return name;
		}

		String getDescription() {
			return description;
		}

		char getSymbol() {
			return symbol;
		}

		double getValue() {
			return value;
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

		virtual void onPickup( actor::ActorBase * actor ) = 0;
		virtual void onInspect( actor::ActorBase * actor ) = 0;
		virtual void onDrop( actor::ActorBase * actor ) = 0;

		virtual ~ItemBase() {};
	};

}
}

#endif
