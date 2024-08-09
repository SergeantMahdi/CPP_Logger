
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
	std::cout << Logger::logLevelToString(level) << message << "  | " << formatTime() << "\033[0m" << std::endl;
}

std::string Logger::logLevelToString(const LogLevel& level) const
{
	switch (level) {
	case LogLevel::DEBUG: return "\033[36m[DEBUG]: ";
	case LogLevel::INFO: return "\033[32m[INFO]: ";
	case LogLevel::WARNING: return "\033[33m[WARNING]: ";
	case LogLevel::ERROR: return "\033[31m[ERROR]: ";
	case LogLevel::CRITICAL: return "\033[43;30m[CRITICAL]: ";
	case LogLevel::FATAL: return "\033[41m[FATAL]: ";
	default: return "\033[32m[DEBUG]: ";
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
