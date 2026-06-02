#include <iostream>
#include <string>
#include "textFormat.h"

int main() {
	std::shared_ptr<sgt::FormatInterface> formatter = std::make_shared<sgt::TextFormat>();
	std::cout << formatter->format("HI", sgt::LogLevel::ERROR);
	return 0;
}