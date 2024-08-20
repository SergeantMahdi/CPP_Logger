#include "LoggingSystem.h"



void LoggingSystem::Log(const LogLevel& level, const std::string& message) const
{
    std::cout << LogLevelToColorfulString(level) << message << getTime() << "\033[0m \n";

}

std::string LoggingSystem::getTime() const
{
    std::stringstream stream;
    auto currentTime = std::chrono::system_clock::now();
    auto stampTime = std::chrono::system_clock::to_time_t(currentTime);
    tm newTime;
    localtime_s(&newTime, &stampTime);

    stream << std::put_time(&newTime, " %Y/%m/%d %H:%M:%S");

    return stream.str();
}


std::string_view LoggingSystem::LogLevelToColorfulString(const LogLevel& level) const
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

std::string LoggingSystem::LogLevelToNormalString(const LogLevel& level) const
{
    switch (level) {
    case LogLevel::DEBUG: return "[DEBUG]: ";
    case LogLevel::INFO: return "[INFO]: ";
    case LogLevel::WARNING: return "[WARNING]: ";
    case LogLevel::ERROR: return "[ERROR]: ";
    case LogLevel::CRITICAL: return "[CRITICAL]: ";
    case LogLevel::FATAL: return "[FATAL]: ";
    default: return "[DEBUG]: ";
    }
}

LoggingSystem::LoggingSystem()
{
}

LoggingSystem::~LoggingSystem()
{
}

