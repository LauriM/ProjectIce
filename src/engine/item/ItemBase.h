#ifndef ENGINE_ITEM_ITEMBASE_H
#define ENGINE_ITEM_ITEMBASE_H

#include "precompiled.h"

namespace engine {
namespace actor {

	class ActorBase;

}

namespace item {

	/**
	 *	An abstract object which represents essentially every item in the engine
	 *  Item's can be a base item, however they'll just be an item with little properties.
	 */
	class ItemBase {
	protected:
		int id;
		bool inInventory;

		String name;
		String description;
		double value;

		char symbol;

		ItemBase()
			:id(-1)
			,inInventory(false)
		{ }

	public:

		friend class ItemManager;

		/** Returns the engine id number of this item
		 * @returns unique integer ID for this instance
		 */
		int getId() {
			return id;
		}

		/** Returns the name of this item (non-unique)
		 * @returns the name
		 */
		String getName() {
			return name;
		}

		/** Returns the description of the item
		 * @returns the description
		 */
		String getDescription() {
			return description;
		}

		/** Returns the symbol representation of this item
		 * @return the symbol
		 */
		char getSymbol() {
			return symbol;
		}

		/** Returns the value (gold, money, whatever) of the item
		 * @return the value
		 */
		double getValue() {
			return value;
		}

		/** Returns a flag indicating if the item is contained inside an inventory
		 * @return the inInventory status
		 */
		bool getInInventory() {
			return inInventory;
		}

		/** Sets this instance's name
		 * @param name the name of the item
		 */
		void setName(String name) {
			this->name = name;
		}

		/** Sets this instance's description
		 * @param description the description
		 */
		void setDescription(String description) {
			this->description = description;
		}

		/** Sets this instance's name value
		 * @param value the value
		 */
		void setValue(double value) {
			this->value = value;
		}

		void setInInventory(bool in) {
			inInventory = in;
		}

		/** The action that is called from the engine when this item is "Picked Up" off the ground.
		 * @param actor the instance of the actor who picks this item up
		 */
		virtual void onPickup( actor::ActorBase * actor ) = 0;

		/** The action that is called when the engine sees an actor is inspecting an item
		 * @param actor the instance of the actor who is inspecting this item
		 */
		virtual void onInspect( actor::ActorBase * actor ) = 0;

		/** The action that is called from the engine when this item is dropped from an inventory
		 * @param actor the instance of the actor who dropped this item
		 */
		virtual void onDrop( actor::ActorBase * actor ) = 0;

		virtual ~ItemBase() {};
	};

}
}

#endif
