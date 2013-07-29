#ifndef ENGINE_LOG_LOGSYSTEM_H
#define ENGINE_LOG_LOGSYSTEM_H

#include "precompiled.h"

#define LOG_INFO(p_msg) engine::log::insertLog("[INFO] " p_msg);
#define LOG_WARNING(p_msg) engine::log::insertLog("[WARNING] " p_msg);
#define LOG_ERROR(p_msg) engine::log::insertLog("[ERROR] " p_msg);

#define LOG_ERROR_F(p_msg,...) {char output[100]; snprintf(output,100,p_msg,__VA_ARGS__);LOG_ERROR(output);}
#define LOG_INFO_F(p_msg,...) {char output[100]; snprintf(output,100,p_msg,__VA_ARGS__);LOG_INFO(output);}
#define LOG_WARNING_F(p_msg,...) {char output[100]; snprintf(output,100,p_msg,__VA_ARGS__);LOG_WARNING(output);}

#ifdef WINDOWS
//Disable debug_f logging if windows, caused some issues
#define DEBUG_NO_LOG_DEBUG
#endif

#ifndef DEBUG_NO_LOG_DEBUG
#define LOG_DEBUG(msg) engine::log::insertLog(msg)
#define LOG_DEBUG_F(p_msg,...) {char output[100]; snprintf(output,100,p_msg,__VA_ARGS__);LOG_DEBUG(output);}
#else
#define LOG_DEBUG(msg)
#define LOG_DEBUG_F(p_msg,...)
#endif

namespace engine {
namespace log {

	void insertLog(String logMsg);

}
}

#endif
