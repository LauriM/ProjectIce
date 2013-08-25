#ifndef ENGINE_CONSOLE_CONSOLESYSTEM_H
#define ENGINE_CONSOLE_CONSOLESYSTEM_H

#include "engine/EngineSystem.h"

namespace engine {
namespace console {

	/**
	 * Console system keeps the CVars in memory and handles loading/saving of config files.
	 *
	 * In future this could be expanded to support small command system
	 */
	class ConsoleSystem : public EngineSystem {
		public:
			bool init();
			void uninit();
			void update();
	};

}
}

#endif