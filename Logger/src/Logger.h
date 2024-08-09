#pragma once
#include <iostream>
#include <mutex>

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
	bool m_enableLoggingFile;
	mutable std::mutex m_mutex;

private:

	std::string logLevelToString(const LogLevel& level) const;
	std::string logLevelToStringForFile(const LogLevel& level) const;
	std::string formatTime() const;
	void fileLog(const std::string&, const std::string& message) const;
	 Logger();
	~Logger();
	Logger(const Logger&) = delete;
	Logger& operator=(const Logger& other) = delete;
public:
	static Logger& initLogger();
	void loggingStatus(const bool&);

	void Log(const LogLevel& , const std::string& , const std::string&);
	void Log(const LogLevel&, const std::string&);

};

