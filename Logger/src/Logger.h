#pragma once
#include <iostream>


enum class LogLevel {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	CRITICAL,
	FATAL
};

class Logger {
private:

	std::string logLevelToString(const LogLevel& level) const;
	std::string formatTime() const;
public:

	Logger& operator=(const Logger& other) = delete;
	static Logger& initLogger();
	void Log(const LogLevel& level, const std::string& message) ;

	Logger();
	~Logger();
};

