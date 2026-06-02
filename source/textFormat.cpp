#include "textFormat.h"
#include <string>
#include <chrono>

//The format of the message is: [YY-MM-DD HH:MM:SS] [LEVEL] MESSAGE
std::string sgt::TextFormat::format(const std::string& text, const sgt::LogLevel& level)
{
	std::string formattedText = ("[" + getTimeStamp() + "] " + "[" + levelToString(level) + "] " + text);
	return formattedText;
}

std::string sgt::TextFormat::levelToString(const sgt::LogLevel& level) const
{
	switch (level) {
	case sgt::LogLevel::FATAL:
		return "FATAL";
	case sgt::LogLevel::CRITICAL:
		return "CRITICAL";
	case sgt::LogLevel::ERROR:
		return "ERROR";
	case sgt::LogLevel::WARNING:
		return "WARNING";
	case sgt::LogLevel::DEBUG:
		return "DEBUG";
	case sgt::LogLevel::INFO:
		return "INFO";
	default:
		return "INVALID";
	}
}

std::string sgt::TextFormat::getTimeStamp()
{
	std::ostringstream os;
	auto now = std::chrono::system_clock::now();
	auto time = std::chrono::system_clock::to_time_t(now);
	os << std::put_time(std::localtime(&time), "%F %T");
	return os.str();
}
