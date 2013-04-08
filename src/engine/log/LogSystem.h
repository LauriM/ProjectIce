#ifndef ENGINE_LOG_LOGSYSTEM_H
#define ENGINE_LOG_LOGSYSTEM_H

#include "precompiled.h"

#define LOG_INFO(p_msg) engine::log::insertLog("[INFO] " p_msg);

namespace engine {
namespace log {

	void insertLog(String logMsg);

}
}

#endif
