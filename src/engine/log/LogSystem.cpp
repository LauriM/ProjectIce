#include "precompiled.h"
#include "engine/log/LogSystem.h"
#include "engine/console/Cvar.h"

namespace cvar {
	CVAR(int, logtofile,1,CVAR_NORMAL);
}

namespace engine {
namespace log {

	void insertLog(String logMsg){

		if(*cvar::logtofile){
			FILE *logFile;
			logFile = fopen("log.txt","a+");
			fprintf(logFile,"%s\n",logMsg.c_str());
			fflush(logFile);
			fclose(logFile);
		}

//if nullrender is enabled, just add stuff there
#ifdef NULLRENDER
	printf("%s\n", logMsg.c_str() );
#endif

		//TODO: Add some kind of ingame log reader thing or just parse with tail (2013-04-08)
		//TODO: globally open the file
	}

}
}
