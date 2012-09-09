cmake_minimum_required(VERSION 2.8)
project(libKISSlog_demo)

enable_testing()

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-Wall -Weffc++ -Wold-style-cast -Wctor-dtor-privacy -Wuninitialized -Winit-self -Wmissing-include-dirs -Wfloat-equal -Wshadow -Wpointer-arith -Wunreachable-code)
elseif(MSVC)
    add_definitions("/W4")
endif()

include_directories("../")

add_executable(customdemo customdemo.cpp ../kisslog-mt-static.cpp)
add_test(customdemo customdemo)

add_executable(streamdemo streamdemo.cpp ../kisslog-mt-static.cpp)
add_test(streamdemo streamdemo)

if(NOT WIN32)
    add_executable(syslogdemo syslogdemo.cpp ../kisslog-mt-static.cpp)
    add_test(syslogdemo syslogdemo)
endif()
