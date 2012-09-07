#!/bin/sh -x
g++ -I.. -O3 -Wall -Weffc++ -Wold-style-cast -Wctor-dtor-privacy -Wuninitialized -Winit-self -Wmissing-include-dirs -Wfloat-equal -Wshadow -Wpointer-arith -Wunreachable-code syslogdemo.cpp -std=c++0x -o syslogdemo
g++ -I.. -O3 -Wall -Weffc++ -Wold-style-cast -Wctor-dtor-privacy -Wuninitialized -Winit-self -Wmissing-include-dirs -Wfloat-equal -Wshadow -Wpointer-arith -Wunreachable-code streamdemo.cpp -std=c++0x -o streamdemo
g++ -I.. -O3 -Wall -Weffc++ -Wold-style-cast -Wctor-dtor-privacy -Wuninitialized -Winit-self -Wmissing-include-dirs -Wfloat-equal -Wshadow -Wpointer-arith -Wunreachable-code customdemo.cpp -std=c++0x -o customdemo
