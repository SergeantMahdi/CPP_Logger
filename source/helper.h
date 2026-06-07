#pragma once
#include <iostream>
namespace sgt {
	enum class LogLevel : int {
		FATAL,
		CRITICAL,
		ERROR,
		WARNING,
		INFO,
		DEBUG,
	};

	const char* levelToString(const LogLevel& level);
	 std::string getTimeStamp();
}