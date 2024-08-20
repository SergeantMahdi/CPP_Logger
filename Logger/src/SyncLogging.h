#pragma once

#include "LoggingSystem.h"


class SyncLogging : public LoggingSystem {

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
	void setSaveLogInFile(const bool&) override;
	void setFileName(std::string_view) override;

	SyncLogging();
	~SyncLogging();

};