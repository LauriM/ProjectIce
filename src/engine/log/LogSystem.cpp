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

#ifdef NULLRENDER
#define PRINT_ENABLED
#endif

#ifdef SFMLRENDER
#define PRINT_ENABLED
#endif

#ifdef PRINT_ENABLED
	printf("%s\n", logMsg.c_str() );

#undef PRINT_ENABLED
#endif

		//TODO: Add some kind of ingame log reader thing or just parse with tail (2013-04-08)
		//TODO: globally open the file
	}

}
}
