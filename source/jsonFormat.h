#pragma once
#include "formatInterface.h"
namespace sgt {
	class JsonFormat : public sgt::FormatInterface {
	public:
		virtual ~JsonFormat() = default;
		std::string format(const std::string& text, const LogLevel& level) override;
	};
}