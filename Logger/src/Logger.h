#pragma once

#include <iostream>
#include <mutex>
#include <sstream>
#include <string>
#include <queue>
#include <thread>
#include <vector>


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

	static Logger* m_instanceObject;
	bool m_logginInFileStatus;
	std::string m_loggingFilename;

	static std::mutex m_consoleMutex;
	static std::mutex m_queueMutex;

	mutable std::queue<std::string> m_queue;

private:

	std::string logLevelToString(const LogLevel& level) const;
	std::string logLevelToStringForFile(const LogLevel& level) const;

	void startLogFile(const std::string&, const std::string&) const;

	std::string formatTime() const;

protected:

	Logger();
	~Logger();

public:

	Logger(const Logger&) = delete;
	Logger& operator=(const Logger& other) = delete;

	static Logger* initLogger();

	void setLoggingStatus(const bool&);

	void Log(const LogLevel&, const std::string&); //Strings
	template<typename T> void Log(const LogLevel&, const T&); //Other Types
	void setLoggingFilename(const std::string&);

};

template<typename T> //change the type of data to string
inline void Logger::Log(const LogLevel& level, const T& message)
{
	std::stringstream streamStr;
	streamStr << message;
	Log(level, std::string(streamStr.str()));
}


