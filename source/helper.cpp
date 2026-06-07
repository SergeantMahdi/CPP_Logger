#include <helper.h>
#include <chrono>

 std::string sgt::getTimeStamp()
{
	std::ostringstream os;
	auto now = std::chrono::system_clock::now();
	auto time = std::chrono::system_clock::to_time_t(now);
	os << std::put_time(std::localtime(&time), "%F %T");
	return os.str();
}


const char* sgt::levelToString(const sgt::LogLevel& level)
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