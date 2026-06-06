# C++ Logger
Using this logger gives you the benefit of separating and colorizing your logs in the console and also keep the track of number of errors that occur in the scope. Also you'll be able to customize the message format with your own derived class. <br>

## Basic Usage

> [!CAUTION]
> Please use C++20 for this library otherwise you won't be able to use it.

Copy all the files in the source folder in your project. Include `"formatter.h"` and `"logger.h"` in your target cpp file. Then make an instance of the logger class and pass a raw pointer or unique_pointer of `sgt::JsonFormat`/`sgt::TextFormat` or your own custom formatter as the argument.

```CPP
#include "formatter.h"
#include "logger.h"

int main(){
	sgt::Logger logger(std::make_unique<sgt::TextFormat>());
	logger.error("This is message {} from {}", 1, "Matthew");
	// [2026-06-06 08:45:59] [DEBUG] This is message 1 from Matthew
}

```
you can also use `sgt::JsonFormat`:
```CPP
int main(){
	sgt::Logger logger(std::make_unique<sgt::JsonFormat>());
	logger.error("This is message {} from {}", 1, "Matthew");
	/*{
	"timestamp": "2026-06-06 08:47:04",
	"level": "DEBUG",
	"message": "This is message 1 from Matthew"
	}*/
}
```

## Keeping the track of errors

You can also see the number of errors occurred.

```CPP

unsigned int errorsOcurred = logger.getErrorCounbt();
unsigned int warningsOcurred = logger.getWarningCounbt();
unsigned int criticalsOcurred = logger.getCriticalCounbt();

```

## Making your own custom formatter
Polymorphism is what gives you the ability to do such a thing. Make you own class and inside header file add `"formatInterface.h"` and override the `format` public method.<br>
for example:
```CPP
#pragma once
#include "formatInterface.h"

class MyOwnFormatter : public FormatInterface{
public:
	virtual ~MyOwnFormatter() // it is recommended to set the destructor virtual
	std::string format(const std::string& text, const LogLevel& level) override;
};
```

inside `"helper.h"` you can find `sgt::LogLevel` with two other functions `getTimestamp` that returns a string of current date and time and `levelToString` which turns the level into string.

```CPP
std::cout << sgt::levelToString(sgt::LogLevel::DEBUG) << "\n"; // DEBUG
std::cout << sgt::getTimestamp() << "\n"; // 2026-06-06 08:47:04
```