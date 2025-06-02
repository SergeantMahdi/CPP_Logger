#pragma once

#include "LoggingSystem.h"

class SyncLogging : protected LoggingSystem {

private:

	std::string m_fileName;
	bool m_saveFileStatus;
	static std::mutex m_queueMutex;
	static std::mutex m_consoleLoggingMutex;
	mutable std::queue<std::string> m_messageList;
	mutable std::ofstream m_fileOutput;

private:

	void flushLogQueueToFile() const;

public:

	void Log(const LogLevel&, const std::string&) const override;
	template<typename T>
	void Log(const LogLevel&, const T&) const;

	void enableFileLogging(const bool&) override;
	void setFileName(const std::string&) override;




	SyncLogging();
	~SyncLogging();

};

template<typename T>
 void SyncLogging::Log(const LogLevel& level, const T& message) const
{
	std::stringstream stream;
	stream << message;
	Log(level, stream.str());

}
