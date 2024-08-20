<h1 align="center"> Logger Library </h1>

![Header](Media/Header.png)

This is a simple logger that I made to simplify and also store the debugging information that might be critical in the future.
You can use this library whether for only console logging or save those logging into custom file



> [!NOTE]
> NEW UPDATE: The structure has been change, read the doc for the usage of loggingsystem

> [!NOTE]
> NOTE: Thread Safety is added

<h2>Guide</h2>

 <h3> make an instance: </h3>
   
```CPP
#include "SyncLogging.h"
int main(){

SyncLogging logger;

}
```

<h3>To log into console only: </h3> 

```CPP
#include "SyncLogging.h"

int main(){

SyncLogging logger;

logger.Log(LogLevel::ERROR, "This is an error log") 
}
```
<h3>To start and stop logging into a file: </h3>

```CPP

int main() {

//make an instance
	SyncLogging logger;

	logger.setSaveLogFileStatus(true); //start logging into the file

	logger.Log(LogLevel::ERROR, "This is an error log"); //default filename is Log.log

	logger.setSaveLogFileStatus(false); //Stop logging into the file
}
```
<h3>To log in a file with a custom file name:</h3>

```CPP
int main() {

//make an instance
	SyncLogging logger;

	logger.setFileName("Logging"); // add your custom name for log file
	logger.setSaveLogFileStatus(true); //start logging into the file
	logger.Log(LogLevel::ERROR, "This is an error log"); //default filename is Log.log
	logger.setSaveLogFileStatus(false); //Stop logging into the file
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


