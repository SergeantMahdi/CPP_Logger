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

	 std::string levelToString(const LogLevel& level);
	 std::string getTimeStamp();
}