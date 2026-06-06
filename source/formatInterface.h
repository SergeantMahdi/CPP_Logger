#pragma once
#include <iostream>
#include <helper.h>

namespace sgt {

	class FormatInterface {
	public:
		virtual ~FormatInterface() = default;
		virtual std::string format(const std::string& text, const LogLevel& level) = 0;
	};
}