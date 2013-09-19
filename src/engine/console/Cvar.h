#ifndef ENGINE_CONSOLE_CVAR_H
#define ENGINE_CONSOLE_CVAR_H

#include "precompiled.h"

#include <boost/lexical_cast.hpp>
#include "engine/console/ConsoleSystem.h"

#define CVAR_CHEAT true
#define CVAR_NORMAL false

namespace engine {
namespace console {

#define CVAR(p_type, p_name, p_def_value, p_is_cheat) \
		engine::console::CVar<p_type> p_name( #p_name , p_def_value, p_is_cheat)

#define EXTERN_CVAR(p_type,p_name) \
		extern engine::console::CVar<p_type> p_name

	class CVarBase {
		public:
			CVarBase() {}
			virtual ~CVarBase() {};

			virtual bool set(String value) = 0;
			virtual String get() const = 0;

			virtual const String& getName() = 0;
			virtual const bool isCheat() = 0;
	};

	template <typename T>
	class CVar : public CVarBase {
		private:
			String name;
			T data;
			T defaultData;
			bool cheat;

		public:
			CVar(String name,T data,bool cheat)
				: name(name)
				, data(data)
				, defaultData(data)
				, cheat(cheat)
			{
				ConsoleSystem::getCVarList().insert(ConsoleSystem::CVarList::value_type(name,this));
			}

			virtual bool set(String value){
				data = boost::lexical_cast<T,String>(value);

				if(cheat){
					if(defaultData != data){ //Cheat has different value than default, so its activated.
						LOG_INFO("[ConfigLoader] Cheats have been activated!");
						//TODO: some kind of global cheat/not cheat status of the game
					}
				}

				return false;
			}

			virtual String get() const {
				return boost::lexical_cast<String,T>(data);
			}

			virtual const String& getName(){
				return name;
			}

			virtual const bool isCheat(){
				return cheat;
			}

			/*
			 * Has the value been changed from the default one
			 * */
			virtual bool isChanged(){
				if(data == defaultData){
					return false;
				}

				return true;
			}

			inline T& operator * (){
				return data;
			}

	};

}
}

#endif
