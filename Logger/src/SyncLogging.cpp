#include "SyncLogging.h"

std::mutex SyncFileLogging::m_queueMutex;
std::mutex SyncFileLogging::m_consoleLoggingMutex;

void SyncFileLogging::writeDataInFile() const
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


void SyncFileLogging::Log(const LogLevel& level, const std::string& message) const
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

void SyncFileLogging::setSaveLogFileStatus(const bool& status)
{
	m_saveFileStatus = status;
	if (m_saveFileStatus) {
		m_fileOutput.open(m_fileName + ".log", std::ios::app);
	}
	else {
		m_fileOutput.close();
	}
}

void SyncFileLogging::setFileName(std::string_view name)
{
	m_fileName = name;
}
SyncFileLogging::SyncFileLogging()
	: m_fileName("SyncLog.log"), m_saveFileStatus(false)
{
}

SyncFileLogging::~SyncFileLogging()
{
	if(m_fileOutput.is_open())
	m_fileOutput.close();

}
