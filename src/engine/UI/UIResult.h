/*
	This object is meant to capture information from a given
	UISystem. For example I guess by the interface if you do
	something there you'd like to figure out what exactly it is
	that you did.

	To be easily reusable in other places the data is stored
	in a simple map with a key => value.
*/
#ifndef __UI_RESULT_H__
#define __UI_RESULT_H__

#include <map>

namespace engine 
{
	namespace UI
	{
		class UIResult
		{
		public:
			UIResult();
			String getValue(String key);
			void setValue(String key, String value);
			~UIResult();
		protected:
			std::map<String,String> _values;
		};
	}
}

#endif