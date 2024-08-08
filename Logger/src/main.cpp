#include "Logger.h"


int main() {

	Logger logger = Logger::initLogger();

	logger.Log(LogLevel::INFO, "This is a info message");
	logger.Log(LogLevel::DEBUG, "This is a debug message");


	std::cin.get();
}