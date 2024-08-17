#include "Logger.h"
#include <chrono>
#include <iomanip>
#include <fstream>


Logger* Logger::m_instanceObject = nullptr;
std::mutex Logger::m_queueMutex;

//Make an object instance
Logger* Logger::initLogger()
{
	if (m_instanceObject == nullptr) {
		m_instanceObject = new Logger;
	}
	return m_instanceObject;
}

//Log with file name
void Logger::Log(const LogLevel& level, const std::string& message)
{
	std::cout << Logger::logLevelToString(level) + message + "  | " + formatTime() + "\033[0m \n";

		if (m_logginInFileStatus) {
			std::string str = Logger::logLevelToStringForFile(level) + message + "  | " + formatTime();
			startLogFile(m_loggingFilename, str);
		}
}

void Logger::setLoggingFilename(const std::string& name)
{
	m_loggingFilename = name;
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
void Logger::startLogFile(const std::string& filename, const std::string& message) const
{
	
	m_queue.push(message);

	std::lock_guard<std::mutex> lock(m_queueMutex);

	if (!m_queue.empty()) {
		std::ofstream outputFile(filename + ".log", std::ios::app);
		if (m_logginInFileStatus) {
			if (outputFile.is_open()) {
				outputFile << m_queue.front() << std::endl;
				m_queue.pop();
			}
			else {
				std::cout << "\033[43;30m" << filename << ".log cannot be opened \033[0m" << std::endl;
			}
		}
		else {
			if (outputFile.is_open())
				outputFile.close();
			else
				return;
		}
	}
}

//set the status of logging into a file
void Logger::setLoggingStatus(const bool& loggingStatus)
{
	m_logginInFileStatus = loggingStatus;

}



Logger::Logger()
	:m_logginInFileStatus(false), m_loggingFilename("Log")
{
}

Logger::~Logger(){

	m_logginInFileStatus = false;
	delete m_instanceObject;
}
