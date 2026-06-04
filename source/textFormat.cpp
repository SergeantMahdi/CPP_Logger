#include "textFormat.h"
#include <string>
#include <chrono>
#include "helper.h"

std::string sgt::TextFormat::format(const std::string& text, const sgt::LogLevel& level)
{
	std::string formattedText = ("[" + sgt::getTimeStamp() + "] " + "[" + sgt::levelToString(level) + "] " + text);
	return formattedText;
}