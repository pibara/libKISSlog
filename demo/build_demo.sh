#!/bin/sh
g++ -I.. -O3 syslogdemo.cpp -std=c++0x -o syslogdemo
g++ -I.. -O3 streamdemo.cpp -std=c++0x -o streamdemo
g++ -I.. -O3 customdemo.cpp -std=c++0x -o customdemo
