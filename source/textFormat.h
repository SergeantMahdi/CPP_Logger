#pragma once
#include <formatInterface.h>

namespace sgt {
	class TextFormat : public FormatInterface {
	public:
		virtual ~TextFormat() = default;
		std::string format(const std::string& text, const LogLevel& level) override;
	};
}