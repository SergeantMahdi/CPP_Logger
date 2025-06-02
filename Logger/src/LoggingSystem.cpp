#include "LoggingSystem.h"

#include <format>


void LoggingSystem::Log(const LogLevel& level, const std::string& message) const
{
    std::cout << LogLevelToColorfulString(level) << message << getTime() << "\033[0m \n";

}

std::string LoggingSystem::getTime() const
{
       auto currentTime = std::chrono::system_clock::now();
       auto fullDateTime = std::chrono::system_clock::to_time_t(currentTime);

       char buffer[26];
       if (ctime_s(buffer, sizeof(buffer), &fullDateTime) == 0) {
            
            std::string timeStr(buffer);
            if (!timeStr.empty() && timeStr.back() == '\n') {
                timeStr.pop_back();
            }
          return timeStr;
       } 
       else {
            return "Unknown Time";
       }
    
}


const char* LoggingSystem::LogLevelToColorfulString(const LogLevel& level) const
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

const char* LoggingSystem::LogLevelToNormalString(const LogLevel& level) const
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

