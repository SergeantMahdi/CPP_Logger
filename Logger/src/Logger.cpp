#include "Logger.h"
#include <sstream>
#include <chrono>
#include <iomanip>
#include <string>


Logger& Logger::initLogger()
{
	static Logger Log;
	return Log;
}

void Logger::Log(const LogLevel& level, const std::string& message)
{
#if level == LogLevel::DEBUG
	std::cout << Logger::logLevelToString(level) << message << std::setw(30) << formatTime() << std::endl;

#elif level == LogLevel::INFO
	std::cout << Logger::logLevelToString(level) << message << std::setw(10) << formatTime() << std::endl;


#elif level == LogLevel::WARNING
	std::cout << Logger::logLevelToString(level) << message << std::setw(10) << formatTime() << std::endl;


#elif level == LogLevel::ERROR
	std::cout << Logger::logLevelToString(level) << message << std::setw(10) << formatTime() << std::endl;


#elif level == LogLevel::FATAL
	std::cout << Logger::logLevelToString(level) << message << std::setw(10) << formatTime() << std::endl;

#endif
}

std::string Logger::logLevelToString(const LogLevel& level) const
{
	switch (level) {
	case LogLevel::DEBUG: return "[DEBUG]: ";
	case LogLevel::INFO: return "[INFO]: ";
	case LogLevel::WARNING: return "[WARNING]: ";
	case LogLevel::ERROR: return "[ERROR]: ";
	case LogLevel::FATAL: return "[FATAL]: ";
	default: return "[DEBUG]: ";
	}
}

std::string Logger::formatTime() const
{
	std::ostringstream oss;
	tm newTime;
	auto now = std::chrono::system_clock::now();
	auto timeT = std::chrono::system_clock::to_time_t(now);
	localtime_s(&newTime, &timeT);
	oss << std::put_time(&newTime, "%Y-%m-%d %H:%M:%S");
	return oss.str();
}

Logger::Logger()
{
}

Logger::~Logger()
{
}
