
// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "Logger.h"
#include <sstream>
#include <chrono>
#include <iomanip>
#include <string>
#include <fstream>

Logger* Logger::m_instance = nullptr;
std::mutex Logger::m_mutex;

//Make an object instance
Logger* Logger::initLogger()
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_instance == nullptr) {
		m_instance = new Logger;
	}
	return m_instance;
}

//Log with file name
void Logger::Log(const LogLevel& level, const std::string& message)
{
	std::cout << Logger::logLevelToString(level) << message << "  | " << formatTime() << "\033[0m" << std::endl;
		if (m_isFileLoggingEnable) {
		fileLog(m_LoggingFilename, Logger::logLevelToStringForFile(level) + message + "  | " + formatTime());
	}
}

void Logger::setLoggingFilename(const std::string& name)
{
	m_LoggingFilename = name;
}

//Colorful log for console
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

//logLevel for logging into file
std::string Logger::logLevelToStringForFile(const LogLevel& level) const
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

//get the current time
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

//Write in the file
void Logger::fileLog(const std::string& fileName, const std::string& message) const
{
	std::lock_guard<std::mutex> lock(m_mutex);
	std::ofstream outputFile(fileName + ".log", std::ios::app);
	if (m_isFileLoggingEnable) {
		if (outputFile.is_open()) {
			outputFile << message << std::endl;
		}
		else {
			std::cout << "\033[43;30m" << fileName << ".log cannot be opened \033[0m" << std::endl;
		}
	}
	else {
		if (outputFile.is_open())
			outputFile.close();
		else
			return;
	}
}

//set the satus of logging into a file
void Logger::setLoggingStatus(const bool& status)
{
	m_isFileLoggingEnable = status;
}

Logger::Logger()
	:m_isFileLoggingEnable(false), m_LoggingFilename("Log")
{
}

Logger::~Logger(){

	m_isFileLoggingEnable = false;
	delete m_instance;
}
