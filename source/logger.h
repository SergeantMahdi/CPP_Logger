#pragma once
#include "formatInterface.h"
#include "helper.h"
#include <mutex>
#include <format>

namespace colors {
	using color_type = const char*;
	inline static constexpr color_type ERROR = "\033[31m";
	inline static constexpr color_type WARNING = "\033[33m";
	inline static constexpr color_type CRITICAL = "\033[43;30m";
	inline static constexpr color_type INFO = "\033[42;30m";
	inline static constexpr color_type DEBUG = "\033[36m";
	inline static constexpr color_type DEFAULT = "\033[m";
}

namespace sgt {
	class Logger
	{
	public:
		Logger(std::unique_ptr<FormatInterface> formatType)
			:m_unique_format(std::move(formatType)) {}
		Logger(const Logger& other) = delete;
		Logger(const Logger&& other) = delete;

		virtual ~Logger() = default;

		template<typename... Args>
		void log(const char* format, const sgt::LogLevel& level, Args&& ...args) {
			std::lock_guard<std::mutex> lock(m_mutex);
			switch (level) {
			case LogLevel::ERROR:
				++m_s_errorCount;
				break;
			case LogLevel::WARNING:
				++m_s_warningCount;
				break;
			case LogLevel::CRITICAL:
				++m_s_criticalCount;
				break;
			}
			std::cout << getFormattedMessage(format, level, std::forward<Args>(args)...) << "\n";
		}

		template<typename... Args>
		void error(const char* format, Args&& ...args) {
			std::lock_guard<std::mutex> lock(m_mutex);
			++m_s_errorCount;
			std::cout << colors::ERROR << getFormattedMessage(format, sgt::LogLevel::ERROR, std::forward<Args>(args)...) << colors::DEFAULT << "\n";
		}

		template<typename... Args>
		void warning(const char* format, Args&& ...args) {
			std::lock_guard<std::mutex> lock(m_mutex);
			++m_s_warningCount;
			std::cout << colors::WARNING << getFormattedMessage(format, sgt::LogLevel::WARNING, std::forward<Args>(args)...) << colors::DEFAULT << "\n";
		}
		template<typename... Args>
		void critical(const char* format, Args&& ...args) {
			std::lock_guard<std::mutex> lock(m_mutex);
			++m_s_criticalCount;
			std::cout << colors::CRITICAL << getFormattedMessage(format, sgt::LogLevel::CRITICAL, std::forward<Args>(args)...) << colors::DEFAULT << "\n";
		}
		template<typename... Args>
		void info(const char* format, Args&& ...args) {
			std::lock_guard<std::mutex> lock(m_mutex);
			std::cout << colors::INFO << getFormattedMessage(format, sgt::LogLevel::INFO, std::forward<Args>(args)...) << colors::DEFAULT << "\n";
		}
		template<typename... Args>
		void debug(const char* format, Args&& ...args) {
			std::lock_guard<std::mutex> lock(m_mutex);
			std::cout << colors::DEBUG << getFormattedMessage(format, sgt::LogLevel::DEBUG, std::forward<Args>(args)...) << colors::DEFAULT << "\n";
		}

		unsigned int getErrorCount() const {
			return m_s_errorCount;
		}
		unsigned int getWarningCount() const {
			return m_s_warningCount;
		}
		unsigned int getCriticalCount() const {
			return m_s_criticalCount;
		}
		//TODO: Add enableWritingFile
		//TODO: Add setFile

	public:
		Logger operator=(const Logger& other) = delete;

	private:
		template<typename... Args>
		inline std::string getFormattedMessage(const char* format, const sgt::LogLevel& level, Args&& ...args) {
			std::string message = std::vformat(format, std::make_format_args(args...));
			std::string formattedMessage = m_unique_format->format(message, level);
			return formattedMessage;
		}

	private:
		// Mutex is for thread-safety
		std::mutex m_mutex;
		// Due the use of polymorphism (interface) formatter needs to be saved inside a pointer
		std::unique_ptr<sgt::FormatInterface> m_unique_format;
		// Counts specific logs
		inline static unsigned int m_s_errorCount = 0;
		inline static unsigned int m_s_warningCount = 0;
		inline static unsigned int m_s_criticalCount = 0;
	};
}