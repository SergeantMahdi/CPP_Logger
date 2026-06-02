#include <formatInterface.h>

namespace sgt {
	class TextFormat : public FormatInterface {
	public:
		virtual ~TextFormat() = default;
		std::string format(const std::string& text, const LogLevel& level) override;


	private:
		std::string levelToString(const LogLevel& level) const override;
		std::string getTimeStamp() override;
	};
}