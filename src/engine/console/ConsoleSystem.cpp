#include "precompiled.h"

#include "engine/console/ConsoleSystem.h"
#include "engine/console/Cvar.h"
#include "engine/util/StringUtil.h"

namespace engine {
namespace console {

	bool ConsoleSystem::init(){
		LOG_WARNING("ConsoleSystem is currently a stub!");

		return true;
	}

	void ConsoleSystem::uninit() {}

	void ConsoleSystem::update() {}

	/**
	 * Loads config file from disk with a specific filename.
	 *
	 * @return bool was the operation succesful
	 */
	bool ConsoleSystem::loadConfig(String filename){
		std::ifstream file;
		file.open( filename.c_str() );

		if(!file.is_open()){
			LOG_ERROR("Can't open file to load configs!");
			return false;
		}

		String line;
		while (std::getline(file, line)){
			//variable=value
			std::vector<String> args = engine::util::explode(line,'=');

			ConsoleSystem::CVarList::iterator it = getCVarList().find(args[0]);

			if(it == getCVarList().end()){
				LOG_ERROR("[ConfigLoader] Incorrect variable name");
				continue;
			}

			if(args.size() > 1){
				//incorrect count of arguments
				it->second->set(args[1]);
				LOG_INFO("[ConfigLoader] Variable loaded.");
				//TODO: Print the variable
			}

		}

		file.close();
		return true;
	}

	/**
	 * Saves current configs to disk with a specific filename.
	 *
	 * The file is created if it doesn't exists.
	 *
	 * @return bool was the operation succesful
	 */
	bool ConsoleSystem::saveConfig(String filename){
		std::ofstream file( filename.c_str() );

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

	/**
	 * Checks all variables for possible cheats that are enabled.
	 */
	bool ConsoleSystem::areCheatsUsed(){
		for(ConsoleSystem::CVarList::iterator it = getCVarList().begin(); it != getCVarList().end(); it++){

			if(it->second->isCheat()){
				if(it->second->isCheat()){
					//found cheat!
					return true;
				}
			}
		}

		return false;
	}

}
}
