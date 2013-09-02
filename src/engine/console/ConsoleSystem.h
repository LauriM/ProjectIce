#ifndef ENGINE_CONSOLE_CONSOLESYSTEM_H
#define ENGINE_CONSOLE_CONSOLESYSTEM_H

#include <boost/unordered_map.hpp>

#include "engine/EngineSystem.h"

namespace engine {
namespace console {

	class CVarBase;

	/**
	 * Console system keeps the CVars in memory and handles loading/saving of config files.
	 *
	 * Also keeps list of the recent message history in the memory.
	 *
	 * In future this could be expanded to support small command system
	 */
	class ConsoleSystem : public EngineSystem {
	public:
		typedef boost::unordered_map<String,CVarBase*> CVarList;
		typedef std::vector<String> MsgHistory;

		bool init();
		void uninit();
		void update();

		inline static CVarList& getCVarList(){
			static CVarList staticCVarMap;
			return staticCVarMap;
		}

		inline static MsgHistory& getMsgHistory(){
			static MsgHistory staticMsgHistory;
			return staticMsgHistory;
		}

		bool loadConfig(String filename);
		bool saveConfig(String filename);

	};

}
}

#endif