#include <kisslog/rawlogger/streamlogger.hpp>
#ifndef WIN32
#include <kisslog/rawlogger/sysloglogger.hpp>
#endif
#if defined(__GXX_EXPERIMENTAL_CXX0X__) || __cplusplus >= 201103L
#include <kisslog/rawlogger/syslogprotologger.hpp>
#endif
