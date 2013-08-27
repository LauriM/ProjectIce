#include "precompiled.h"

#include "engine/console/ConsoleSystem.h"
#include "engine/console/Cvar.h"

namespace engine {
namespace console {

	bool ConsoleSystem::init(){
		LOG_WARNING("ConsoleSystem is currently a stub!");

		//TODO: load the cvars into memory here.

		return true;
	}

	void ConsoleSystem::uninit() {}

	void ConsoleSystem::update() {}
	
	/**
	 * Loads config file from disk with a specific filename.
	 *
	 * @return bool was the operation succesfull
	 */
	bool loadConfig(String filename){
		std::ifstream file;
		file.open( filename.c_str() );

		if(!file.is_open()){
			LOG_ERROR("Can't open file to load configs!");
			return false;
		}

		LOG_WARNING("not yet implemented!");

		file.close();
		return true;
	}

	/**
	 * Saves current configs to disk with a specific filename.
	 *
	 * @return bool was the operation succesfull
	 */
	bool ConsoleSystem::saveConfig(String filename){
		std::ofstream file;
		file.open( filename.c_str() );

		if(!file.is_open()){
			LOG_ERROR("Can't open config file for saving");
			return false;
		}

		for(ConsoleSystem::CVarList::iterator it = getCVarList().begin(); it != getCVarList().end(); it++){
			String output = "";

			output += it->second->getName();
			output += "=";
			output += it->second->get();

			file << output << "\n";
		}

		file.close();

		LOG_INFO("Configs written to disk");
		return true;
	}

}
}