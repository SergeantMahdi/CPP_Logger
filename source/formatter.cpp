#include <formatter.h>
#include <chrono>
#include "helper.h"

std::string sgt::JsonFormat::format(const std::string& text, const sgt::LogLevel& level)
{
	std::string formattedText = ("{\n\"timestamp\": \"" + sgt::getTimeStamp() + "\",\n" + "\"level\": \"" + sgt::levelToString(level) + "\",\n" + "\"message\": \"" + text + "\"\n}");
	return formattedText;
}

std::string sgt::TextFormat::format(const std::string& text, const sgt::LogLevel& level)
{
	std::string formattedText = ("[" + sgt::getTimeStamp() + "] " + "[" + sgt::levelToString(level) + "] " + text);
	return formattedText;
}