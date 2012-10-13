//This code curently still doesn't seem to work. FIXME
#define USE_HIGHLY_EXPERIMENTAL_KISSLOG_CODE
#include <kisslog.hpp>

class Foo {
    kisslog::logger_base<char16_t> &mLogger;
  public:
    Foo(kisslog::logger_base<> &logger):mLogger(logger) {}
    void testlog() {
        mLogger.debug() << u"Foo is debug logging" << std::endl;
        mLogger.notice() << u"Foo wants you to notice" << std::endl;
        mLogger.crit() << u"Foo is in big problems." << std::endl;
    }
};

class Bar {
    kisslog::logger_base<char16_t> &mLogger;
  public:
    Bar(kisslog::logger_base<> &logger):mLogger(logger) {}
    void testlog() {
        mLogger.debug() << u"Bar is debug logging" << std::endl;
        mLogger.notice() << u"Bar wants you to notice" << std::endl;
        mLogger.crit() << u"Bar is in big problems." << std::endl;
    }
};
#ifndef WIN32
typedef kisslog::rawlogger::sysloglogger<kisslog::facility::USER,kisslog::threading::MULTI,char16_t> rawlogger_t;
typedef kisslog::logger<rawlogger_t,kisslog::severity::WARNING,char16_t> warnlogger_t;
typedef kisslog::logger<rawlogger_t,kisslog::severity::DEBUG,char16_t> debuglogger_t;
#else
#error Logging to syslog is not supported on the win32 platform.
#endif

int main(int argc,char **argv) {
#ifndef WIN32
  rawlogger_t rlogger(u"demo");
  warnlogger_t foologger(rlogger);
  debuglogger_t barlogger(rlogger);
  Foo foo(foologger);
  Bar bar(barlogger);
  foo.testlog();
  bar.testlog();
#endif
};
