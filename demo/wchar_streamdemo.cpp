#include <kisslog.hpp>

class Foo {
    kisslog::logger_base<wchar_t> &mLogger;
  public:
    Foo(kisslog::logger_base<wchar_t> &logger):mLogger(logger) {}
    void testlog() {
        mLogger.debug() << L"Foo is debug logging" << std::endl;
        mLogger.notice() << L"Foo wants you to notice" << std::endl;
        mLogger.crit() << L"Foo is in big problems." << std::endl;
    }
};

class Bar {
    kisslog::logger_base<wchar_t> &mLogger;
  public:
    Bar(kisslog::logger_base<wchar_t> &logger):mLogger(logger) {}
    void testlog() {
        mLogger.debug() << L"Bar is debug logging" << std::endl;
        mLogger.notice() << L"Bar wants you to notice" << std::endl;
        mLogger.crit() << L"Bar is in big problems." << std::endl;
    }
};

typedef kisslog::rawlogger::ostreamlogger<kisslog::threading::MULTI,wchar_t> rawlogger_t;
typedef kisslog::logger<rawlogger_t,kisslog::severity::WARNING,wchar_t> warnlogger_t;
typedef kisslog::logger<rawlogger_t,kisslog::severity::DEBUG,wchar_t> debuglogger_t;

int main(int argc,char **argv) {
  rawlogger_t rlogger(std::wcerr);
  warnlogger_t foologger(rlogger);
  debuglogger_t barlogger(rlogger);
  Foo foo(foologger);
  Bar bar(barlogger);
  foo.testlog();
  bar.testlog();
};
