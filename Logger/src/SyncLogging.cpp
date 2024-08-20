#include "SyncLogging.h"

std::mutex SyncLogging::m_queueMutex;
std::mutex SyncLogging::m_consoleLoggingMutex;

void SyncLogging::writeDataInFile() const
{
	while (!m_messageList.empty()) {
		if (m_fileOutput.is_open()) {
			m_fileOutput << m_messageList.front() << std::endl;
			m_messageList.pop();
		}
		else {
			std::cout << "\033[43;30m[CRITICAL]: Cannot Open the file \033[0m \n";
		}
	}

}


void SyncLogging::Log(const LogLevel& level, const std::string& message) const
{

	
		std::lock_guard<std::mutex> lock(m_consoleLoggingMutex);
		std::cout << LogLevelToColorfulString(level) << message << getTime() << "\033[0m \n";
	
	if (m_saveFileStatus) {

		std::lock_guard<std::mutex> lock(m_queueMutex);
		std::string formattedMessage = LogLevelToNormalString(level) + message + getTime();
		m_messageList.push(formattedMessage);

		writeDataInFile();
	}
}

void SyncLogging::setSaveLogFileStatus(const bool& status)
{
	m_saveFileStatus = status;
	if (m_saveFileStatus) {
		m_fileOutput.open(m_fileName + ".log", std::ios::app);
	}
	else {
		m_fileOutput.close();
	}
}

void SyncLogging::setFileName(std::string_view name)
{
	m_fileName = name;
}
SyncLogging::SyncLogging()
	: m_fileName("Log"), m_saveFileStatus(false)
{
}

SyncLogging::~SyncLogging()
{
	if(m_fileOutput.is_open())
	m_fileOutput.close();

}
