cmake_minimum_required(VERSION 4.2.3)

set(Project_Name "cpp-logger")
set(Project_Version 1.0.0)
project(
	${Project_Name}
	VERSION ${Project_Version}
	LANGUAGES C CXX
)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)



# CORE
set(Core_App "Core")
add_executable(${Core_App})

set(Core_Executables 
# ALL *.CPP Files Goes here
examples/main.cpp
)

target_sources(${Core_App} PRIVATE ${Core_Executables})


# LIBRARY
set(Logger_Lib "Logger")
add_library(${Logger_Lib} STATIC)

set(Logger_Executables 
# ALL *.CPP Files Goes here
source/helper.cpp
source/formatter.cpp

)

set(Logger_Headers
# ALL *.H Files Goes here
source/formatInterface.h
source/helper.h
source/logger.h
source/formatter.h
)

target_sources(
${Logger_Lib} 
PRIVATE ${Logger_Executables}
PUBLIC FILE_SET HEADERS  FILES ${Logger_Headers}
)


# LINK

target_link_libraries(${Core_App} PRIVATE ${Logger_Lib})
target_include_directories(${Logger_Lib} PUBLIC source/)