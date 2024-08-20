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
public:

	virtual void Log(const LogLevel&, const std::string&) const;
	virtual std::string getTime() const;
	virtual std::string_view LogLevelToColorfulString(const LogLevel&) const;
	virtual std::string LogLevelToNormalString(const LogLevel&) const;

	virtual void setSaveLogInFile(const bool&) = 0;
	virtual void setFileName(std::string_view) = 0;

	LoggingSystem();
	virtual ~LoggingSystem();
};