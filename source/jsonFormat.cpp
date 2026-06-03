#include "jsonFormat.h"
#include <chrono>
#include "helper.h"
std::string sgt::JsonFormat::format(const std::string& text, const sgt::LogLevel& level)
{
	std::string formattedText = ("{\n\"timestamp\": \"" + sgt::getTimeStamp() + "\",\n" + "\"level\": \"" + sgt::levelToString(level) + "\",\n" + "\"message\": \"" + text + "\"\n}");
	return formattedText;
}
