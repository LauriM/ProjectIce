#ifndef ENGINE_CONSOLE_CVAR_H
#define ENGINE_CONSOLE_CVAR_H

#include "precompiled.h"

#include <boost/lexical_cast.hpp>
#include "engine/console/ConsoleSystem.h"

namespace engine {
namespace console {

#define CVAR(p_type, p_name, p_def_value) \
		engine::console::CVar<p_type> p_name( #p_name , p_def_value)

#define EXTERN_CVAR(p_type,p_name) \
		extern engine::console::CVar<p_type> p_name

	class CVarBase {
		public:
			CVarBase() {}
			virtual ~CVarBase() {};

			virtual bool set(String value) = 0;
			virtual String get() const = 0;

			virtual const String& getName() = 0;
	};

	template <typename T>
	class CVar : public CVarBase {
		private:
			String name;
			T data;

		public:
			CVar(String name,T data)
				: name(name)
				, data(data)
			{
				ConsoleSystem::getCVarList().insert(ConsoleSystem::CVarList::value_type(name,this));
			}

			virtual bool set(String value){
				data = boost::lexical_cast<T,String>(value);
				return false;
			}

			virtual String get() const {
				return boost::lexical_cast<String,T>(data);
			}

			virtual const String& getName(){
				return name;
			}

			inline T& operator * (){
				return data;
			}

	};

}
}

#endif
