#pragma once
#include <iostream>


enum class LogLevel {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	FATAL
};

class Logger {
private:

	 void setColor(const int&);

	 void resetColor();

public:
	
	static Logger& initLogger();

	Logger& operator=(const Logger& other) = delete;

	void Log(const LogLevel& level, const std::string& message) ;

	std::string logLevelToString(const LogLevel& level) const;

	std::string formatTime() const;

	Logger();
	~Logger();
};

