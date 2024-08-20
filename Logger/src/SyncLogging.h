#pragma once

#include "LoggingSystem.h"


class SyncFileLogging : public LoggingSystem {

private:

	std::string m_fileName;
	bool m_saveFileStatus;
	static std::mutex m_queueMutex;
	static std::mutex m_consoleLoggingMutex;
	mutable std::queue<std::string> m_messageList;
	mutable std::ofstream m_fileOutput;

private:

	void writeDataInFile() const;

public:

	void Log(const LogLevel&, const std::string&) const override;
	template<typename T>
	void Log(const LogLevel&, const T&) const;

	void setSaveLogFileStatus(const bool&) override;
	void setFileName(std::string_view) override;

	SyncFileLogging();
	~SyncFileLogging();

};

template<typename T>
inline void SyncFileLogging::Log(const LogLevel& level, const T& message) const
{
	std::stringstream stream;
	stream << message;
	Log(level, stream.str());

}
