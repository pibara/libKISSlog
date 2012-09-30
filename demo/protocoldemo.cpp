#include <kisslog.hpp>
#include <sys/types.h>
#include <unistd.h>

class Foo {
    kisslog::logger_base<> &mLogger;
  public:
    Foo(kisslog::logger_base<> &logger):mLogger(logger) {}
    void testlog() {
        mLogger.debug() << "Foo is debug logging" << std::endl;
        mLogger.notice() << "Foo wants you to notice" << std::endl;
        mLogger.crit() << "Foo is in big problems." << std::endl;
    }
};

class Bar {
    kisslog::logger_base<> &mLogger;
  public:
    Bar(kisslog::logger_base<> &logger):mLogger(logger) {}
    void testlog() {
        mLogger.debug() << "Bar is debug logging" << std::endl;
        mLogger.notice() << "Bar wants you to notice" << std::endl;
        mLogger.crit() << "Bar is in big problems." << std::endl;
    }
};
#if defined(__GXX_EXPERIMENTAL_CXX0X__) || __cplusplus >= 201103L
typedef kisslog::rawlogger::syslogprotologger<kisslog::proto::cerr,kisslog::facility::USER> rawlogger_t;
typedef kisslog::logger<rawlogger_t> warnlogger_t;
typedef kisslog::logger<rawlogger_t,kisslog::severity::DEBUG> debuglogger_t;
#else
#error Logging to syslog protocols currently only supported for C++11.
#endif

int main(int argc,char **argv) {
#if defined(__GXX_EXPERIMENTAL_CXX0X__) || __cplusplus >= 201103L
  kisslog::proto::cerr protocol;
  rawlogger_t rlogger(protocol,"localhost","kisslogdemo",std::to_string(getpid()));
  warnlogger_t foologger(rlogger);
  debuglogger_t barlogger(rlogger);
  Foo foo(foologger);
  Bar bar(barlogger);
  foo.testlog();
  bar.testlog();
#endif
};
