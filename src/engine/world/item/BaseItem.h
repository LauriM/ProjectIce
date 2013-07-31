
#ifndef __BASE_ITEM_H__
#define __BASE_ITEM_H__

#include "precompiled.h"

namespace engine {
namespace world {
namespace item {

	class BaseItem {
	private:
		// TODO lets discuss the properties an item should have
		//      Also how to organize everything
		String _name;
		int _value;

	public:
		BaseItem();

		String getName();
		int getValue();

		void setName(String name);
		void setValue(int value); 
	};

}
}
}

#endif