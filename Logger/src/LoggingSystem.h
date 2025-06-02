#pragma once

#include <iostream>
#include <string>
#include <queue>
#include <mutex>
#include <thread>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <string_view>

static uint32_t allocation = 0;

enum class LogLevel {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	CRITICAL,
	FATAL
};



class LoggingSystem {
protected:

	virtual void Log(const LogLevel&, const std::string&) const;
	virtual std::string getTime() const;
	virtual const char* LogLevelToColorfulString(const LogLevel&) const;
	virtual const char* LogLevelToNormalString(const LogLevel&) const;

	virtual void enableFileLogging(const bool&) = 0;
	virtual void setFileName(const std::string&) = 0;
public:
	LoggingSystem();
	virtual ~LoggingSystem();
};