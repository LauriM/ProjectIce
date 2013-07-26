/*
	Peter Sjors!
*/

#include "precompiled.h"

#include "engine/UI/UIResult.h"

namespace engine 
{
	namespace UI 
	{
		UIResult::UIResult() { /* I'm alive! */ }
		UIResult::~UIResult() 
			{ /* remember that scene in star wars when luke was in that garbage disposal.
			     that's what this'll be like minus the survival. */ }

		String UIResult::getValue(String key)
		{
			return _values[key];
		}

		void UIResult::setValue(String key, String value)
		{
			_values[key] = value;
		}

	}
}