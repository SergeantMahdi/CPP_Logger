# C++ Logger
`cpp-logger` is a small library that is made to make printing and reading logs easier. It also provides you methods to track the number of error in you code. Implementing polymorphism in its structure allows you to customize the structure of your logs.
## Basic Usage

> [!CAUTION]
> This library is implemented with some `C++20` features. Make sure that your project is set to `C++20`.

Copy all the files in the source folder in your project. Include `"formatter.h"` and `"logger.h"` in your target cpp file. Then make an instance of the logger class and pass a raw pointer or unique_pointer of `sgt::JsonFormat`, `sgt::TextFormat` or `your own custom formatter` as the argument.

```CPP
#include "formatter.h"
#include "logger.h"

int main(){
	sgt::Logger logger(std::make_unique<sgt::TextFormat>());
	logger.error("This is message {} from {}", 1, "Matthew");
	// [2026-06-06 08:45:59] [ERROR] This is message 1 from Matthew
}

```
you can also use `sgt::JsonFormat`:
```CPP
int main(){
	sgt::Logger logger(std::make_unique<sgt::JsonFormat>());
	logger.warning("This is message {} from {}", 1, "Matthew");
	/*{
	"timestamp": "2026-06-06 08:47:04",
	"level": "WARNING",
	"message": "This is message 1 from Matthew"
	}*/
}
```

## Keeping the track of errors

You can also see the number of errors occurred.

```CPP

unsigned int errorsOcurred = logger.getErrorCount();
unsigned int warningsOcurred = logger.getWarningCount();
unsigned int criticalsOcurred = logger.getCriticalCount();

```

## Making your own custom formatter
Polymorphism is what gives you the ability to do so. Make your own class and include `"formatInterface.h"` in you class header file then by overriding the `format` method you can customize the structure of the text.<br>

for example:
```CPP
#pragma once
#include "formatInterface.h"

class MyOwnFormatter : public sgt::FormatInterface{
public:
	virtual ~MyOwnFormatter(); // it is recommended to set the destructor virtual
	std::string format(const std::string& text, const LogLevel& level) override;
};
```

inside `"helper.h"` you can find `sgt::LogLevel` enum class with two other functions, `getTimestamp` that returns a string of current date and time and `levelToString` which turns the level name into string.

```CPP
std::cout << sgt::levelToString(sgt::LogLevel::DEBUG) << "\n"; // DEBUG
std::cout << sgt::getTimestamp() << "\n"; // 2026-06-06 08:47:04
```