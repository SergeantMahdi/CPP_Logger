#include <formatter.h>
#include <chrono>
#include "helper.h"
#include <cstring>

std::string sgt::JsonFormat::format(const std::string& text, const sgt::LogLevel& level)
{
	std::string timestamp = sgt::getTimeStamp();
	const char* levelString = sgt::levelToString(level);
	std::string formattedText;
	// 47 is the number of characters that is used for formatting beside our variables
	formattedText.reserve(timestamp.size() + std::strlen(levelString) + text.size() + 47 );
	formattedText.append("{\n\"timestamp\": \"");
	formattedText.append(timestamp);
	formattedText.append("\",\n\"level\": \"");
	formattedText.append(levelString); 
	formattedText.append("\",\n\"message\": \"");
	formattedText.append(text);
	formattedText.append("\"\n}");
	return formattedText;
}

std::string sgt::TextFormat::format(const std::string& text, const sgt::LogLevel& level)
{
	std::string timestamp = sgt::getTimeStamp();
	const char* levelString = sgt::levelToString(level);
	std::string formattedText;
	// 6 is the number of characters that is used for formatting beside our variables
	formattedText.reserve(timestamp.size() + std::strlen(levelString) + text.size() + 6);
	formattedText.append("[");
	formattedText.append(timestamp);
	formattedText.append("] [");
	formattedText.append(levelString);
	formattedText.append("] ");
	formattedText.append(text);
	return formattedText;
}