<h1 align="center"> Logger Library </h1>

This is a simple logger that I made to simplify and also store the debugging information that might be critical in the future.
You can use this library whether for only console logging or save those logging into custom file


> [!CAUTION]
> This library still doesn't contain thread safety and it might cause a problem in complex applications


<h2>Guide</h2>

 <h3> make an instance: </h3>
   
```CPP
#include "Logger.h"
int main(){

Logger* log = Logger::initLogger();

}
```

<h3>To log into console only: </h3> 

```CPP
#include "Logger.h"

int main(){

Logger* log = Logger::initLogger();

log->Log(LogLevel::ERROR, "This is an error log") 
}
```
<h3>To start and stop logging into a file: </h3>

```CPP

int main() {

//make an instance
	Logger* log = Logger::initLogger();

	log->loggingStatus(true); //start logging into the file

	log->Log(LogLevel::ERROR, "This is an error log");

	log->loggingStatus(false); //Stop logging into the file
}
```
<h3>To log in a file with a custom file name:</h3>

```CPP
int main() {

//make an instance
	Logger* log = Logger::initLogger();

	log->loggingStatus(true); //start logging into the file

	std::string filename = "logging";

	log->Log(LogLevel::ERROR, "This is an error log", filename); //start logging into logging.log

	log->loggingStatus(false); //Stop logging into the file
}
```


<h3>All the LogLevels : </h3>

```CPP
enum class LogLevel {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	CRITICAL,
	FATAL
};
```

<h2 align="center">Screenshots</h2>

 <h3> Loggin into the console </h3>
 
![loggingFile](Media/Console-Logging.png)

 <h3> Loggin into a file </h3>
 
![loggingFile](Media/Logging-file.png)


