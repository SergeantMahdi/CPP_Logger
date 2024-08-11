#pragma once

#include <iostream>
#include <mutex>
#include <sstream>
#include <string>

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

	static Logger* m_instance;
	bool m_isFileLoggingEnable;
	static std::mutex m_mutex;
	std::string m_LoggingFilename;

private:

	std::string logLevelToString(const LogLevel& level) const;
	std::string logLevelToStringForFile(const LogLevel& level) const;
	std::string formatTime() const;
	void fileLog(const std::string&, const std::string& message) const;

protected:

	Logger();
	~Logger();

public:

	Logger(const Logger&) = delete;
	Logger& operator=(const Logger& other) = delete;
	static Logger* initLogger();
	void setLoggingStatus(const bool&);
	void Log(const LogLevel&, const std::string&);
	template<typename T> void Log(const LogLevel&, const T&);
	void setLoggingFilename(const std::string&);

};

template<typename T>
 void Logger::Log(const LogLevel& level, const T& message)
{
	std::stringstream streamStr;
	streamStr << message;
	Log(level, std::string(streamStr.str()));
}
