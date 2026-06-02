#include <concepts>
#include <iostream>

namespace sgt {
	enum class LogLevel : int {
		FATAL,
		CRITICAL,
		ERROR,
		WARNING,
		INFO,
		DEBUG,
	};


	class FormatInterface {
	public:
		virtual ~FormatInterface() = default;
		virtual std::string format(const std::string& text, const LogLevel& level) = 0;

	private:
		virtual std::string levelToString(const LogLevel& level) const = 0;
		virtual std::string getTimeStamp() = 0;
	};
}