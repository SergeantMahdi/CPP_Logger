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

	static Logger* m_instance;
	bool m_enableLoggingFile;
	static std::mutex m_mutex;
	std::string m_filename;

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
	void loggingStatus(const bool&);
	void Log(const LogLevel&, const std::string&);
	void setFilename(const std::string&);

};

