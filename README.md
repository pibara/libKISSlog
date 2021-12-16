libKISSlog
==========

The KISSlog library is a simple C++(11) template library for logging in C++. 

For more information check [this](http://pibara.github.io/libKISSlog/) page, or have a look at the
two pieces of demo code streamdemo.cpp and syslogdemo.cpp.

Currently this library status is as follows:

* POSIX + C++98 : OK, tested, uses pthread mutexes and supports syslog.
* POSIX + C++11 : OK, tested, uses std::mutex and supports syslog.
* MS-Windows + C++98: OK, tested. Uses critical section and does not supports syslog.
* MS-Windows + C++11: Should work in theory. Untested. Uses std::mutex and does not supports syslog.

Any help on getting stuff tested for the windows platform would be greatly appreciated.
