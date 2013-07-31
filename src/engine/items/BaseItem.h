
#ifndef __BASE_ITEM_H__
#define __BASE_ITEM_H__

#include "precompiled.h"
#include "engine/player/Player.h"

namespace engine {
namespace world {
namespace item {

	class BaseItem {
	private:

		String _name;
		String _description;
		double _value;
		double _weight;
		int _quantity;

	protected:

		// TODO This class is abstract, don't let people make a BaseItem (later, testing atm)
		//BaseItem();

	public:

		String getName();
		String getDescription();
		double getValue();
		double getWeight();
		int getQuantity();

		void setName(String name);
		void setDescription(String description);
		void setValue(double value);
		void setWeight(double weight);
		void setQuantity(int quantity);

		/*
		LATER Change these to virtual and remove their implementations, the implementation for now
		is just to test
		virtual void onDestroy( player::Player * pOwner ) = 0;
		virtual void onPickup( player::Player * pOwner ) = 0;
		virtual void onDrop( player::Player * pOwner ) = 0;
		virtual void onInspect( player::Player * pOwner ) = 0;
		virtual void onUse( player::Player * pOwner ) = 0;
		*/

		void onDestroy( player::Player * pOwner ) {
			printf( "Player %s destroyed %s!", pOwner->getName().c_str(), _name.c_str() );
		}

		void onPickup( player::Player * pOwner ) {
			printf( "Player %s picked up %s!", pOwner->getName().c_str(), _name.c_str() );
		}

		void onDrop( player::Player * pOwner ) {
			printf( "Player %s dropped %s!", pOwner->getName().c_str(), _name.c_str() );
		}

		void onInspect( player::Player * pOwner ) {
			printf( "Player %s inspected %s!", pOwner->getName().c_str(), _name.c_str() );
		}

		void onUse( player::Player * pOwner ) {
			printf( "Player %s used %s!", pOwner->getName().c_str(), _name.c_str() );
		}

	};

}
}
}

#endif
