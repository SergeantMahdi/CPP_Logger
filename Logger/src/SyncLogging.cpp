#include "SyncLogging.h"

std::mutex SyncLogging::m_queueMutex;
std::mutex SyncLogging::m_consoleLoggingMutex;


void SyncLogging::flushLogQueueToFile() const
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
	//TODO: Reduce the allocation

	
		std::lock_guard<std::mutex> lock(m_consoleLoggingMutex);
		std::cout << LogLevelToColorfulString(level) << message << " | " << getTime() << "\033[0m \n";
	
	if (m_saveFileStatus) {

		std::lock_guard<std::mutex> lock(m_queueMutex);
		std::string formattedMessage = LogLevelToNormalString(level) + message + " | " + getTime() + "\n";
		m_messageList.push(formattedMessage);

		flushLogQueueToFile();
	}
}

void SyncLogging::enableFileLogging(const bool& status)
{
	m_saveFileStatus = status;
	if (m_saveFileStatus) {
		m_fileOutput.open(m_fileName, std::ios::app);
	}
	else {
		m_fileOutput.close();
	}
}

void SyncLogging::setFileName(const std::string& name)
{
	m_fileName = name + ".log";
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
