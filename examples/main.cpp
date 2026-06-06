#include <iostream>
#include "formatter.h"
#include "logger.h"

int main() {
	sgt::Logger textLogger(std::make_unique<sgt::TextFormat>());
	textLogger.error("This library is made by {} contributer: {}", 1, "Matthew");
	textLogger.warning("This library is made by {} contributer: {}", 1, "Matthew");
	textLogger.critical("This library is made by {} contributer: {}", 1, "Matthew");
	textLogger.info("This library is made by {} contributer: {}", 1, "Matthew");
	textLogger.debug("This library is made by {} contributer: {}", 1, "Matthew");

	sgt::Logger jsonLogger(std::make_unique<sgt::JsonFormat>());
	jsonLogger.error("[FORMAT: {}] This library is made by {} contributer: {}", "Json", 1, "Matthew");
	jsonLogger.warning("[FORMAT: {}] This library is made by {} contributer: {}", "Json", 1, "Matthew");
	jsonLogger.critical("[FORMAT: {}] This library is made by {} contributer: {}", "Json", 1, "Matthew");
	jsonLogger.info("[FORMAT: {}] This library is made by {} contributer: {}", "Json", 1, "Matthew");
	jsonLogger.debug("[FORMAT: {}] This library is made by {} contributer: {}","Json", 1, "Matthew");

}