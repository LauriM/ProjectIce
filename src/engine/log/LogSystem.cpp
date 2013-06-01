#include "precompiled.h"
#include "engine/log/LogSystem.h"

namespace engine {
namespace log {

	void insertLog(String logMsg){
		FILE *logFile;
		fopen_s(&logFile,"log.txt","a+");
		fprintf(logFile,"%s\n",logMsg.c_str());
		fflush(logFile);
		fclose(logFile);

		//TODO: Add some kind of ingame log reader thing or just parse with tail (2013-04-08)
	}

}
}
