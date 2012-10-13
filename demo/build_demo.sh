#!/bin/sh -x
g++ -I.. -O3 -Wall -Weffc++ -Wold-style-cast -Wctor-dtor-privacy -Wuninitialized -Winit-self -Wmissing-include-dirs -Wfloat-equal -Wshadow -Wpointer-arith -Wunreachable-code syslogdemo.cpp ../src/kisslog-mt-static.cpp -std=c++0x -o syslogdemo
#clang++ -I.. -O3  char16_syslogdemo.cpp ../src/kisslog-mt-static.cpp -std=c++11 -o char16_syslogdemo
g++ -I.. -O3 -Wall -Weffc++ -Wold-style-cast -Wctor-dtor-privacy -Wuninitialized -Winit-self -Wmissing-include-dirs -Wfloat-equal -Wshadow -Wpointer-arith -Wunreachable-code streamdemo.cpp ../src/kisslog-mt-static.cpp -std=c++0x -o streamdemo
g++ -I.. -O3 -Wall -Weffc++ -Wold-style-cast -Wctor-dtor-privacy -Wuninitialized -Winit-self -Wmissing-include-dirs -Wfloat-equal -Wshadow -Wpointer-arith -Wunreachable-code wchar_streamdemo.cpp ../src/kisslog-mt-static.cpp -std=c++0x -o wchar_streamdemo
g++ -I.. -O3 -Wall -Weffc++ -Wold-style-cast -Wctor-dtor-privacy -Wuninitialized -Winit-self -Wmissing-include-dirs -Wfloat-equal -Wshadow -Wpointer-arith -Wunreachable-code customdemo.cpp -std=c++0x -o customdemo
g++ -I.. -O3 -Wall -Weffc++ -Wold-style-cast -Wctor-dtor-privacy -Wuninitialized -Winit-self -Wmissing-include-dirs -Wfloat-equal -Wshadow -Wpointer-arith -Wunreachable-code wchar_custdemo.cpp -std=c++0x -o wchar_custdemo
g++ -I.. -O3 -Wall -Weffc++ -Wold-style-cast -Wctor-dtor-privacy -Wuninitialized -Winit-self -Wmissing-include-dirs -Wfloat-equal -Wshadow -Wpointer-arith -Wunreachable-code protocoldemo.cpp -std=c++0x -o protocoldemo
