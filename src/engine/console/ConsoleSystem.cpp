#include "precompiled.h"

#include "engine/console/ConsoleSystem.h"

namespace engine {
namespace console {

	bool ConsoleSystem::init(){
		LOG_WARNING("ConsoleSystem is currently a stub!");

		//TODO: load the cvars into memory here.

		return true;
	}

	void ConsoleSystem::uninit() {}

	void ConsoleSystem::update() {}

}
}