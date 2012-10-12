cmake_minimum_required(VERSION 2.8)
project(libKISSlog_demo)

enable_testing()

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-Wall -Weffc++ -Wold-style-cast -Wctor-dtor-privacy -Wuninitialized -Winit-self -Wmissing-include-dirs -Wfloat-equal -Wshadow -Wpointer-arith -Wunreachable-code)
elseif(MSVC)
    add_definitions("/W4")
endif()

include_directories("../")

add_executable(customdemo customdemo.cpp ../src/kisslog-mt-static.cpp)
add_test(customdemo customdemo)

add_executable(wchar_custdemo wchar_custdemo.cpp ../src/kisslog-mt-static.cpp)
SET_SOURCE_FILES_PROPERTIES(wchar_custdemo.cpp PROPERTIES COMPILE_FLAGS -DKISSLOG_USE_WIDE)
add_test(wchar_custdemo wchar_custdemo)

add_executable(streamdemo streamdemo.cpp ../src/kisslog-mt-static.cpp)
add_test(streamdemo streamdemo)

add_executable(wchar_streamdemo wchar_streamdemo.cpp ../src/kisslog-mt-static.cpp)
add_test(wchar_streamdemo wchar_streamdemo)

if(NOT WIN32)
    add_executable(syslogdemo syslogdemo.cpp ../src/kisslog-mt-static.cpp)
    add_test(syslogdemo syslogdemo)
endif()
