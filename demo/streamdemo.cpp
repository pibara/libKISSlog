#include <kisslog.hpp>

class Foo {
    kisslog::logger_base<char> &mLogger;
  public:
    Foo(kisslog::logger_base<char> &logger):mLogger(logger) {}
    void testlog() {
        mLogger.debug() << "Foo is debug logging" << std::endl;
        mLogger.notice() << "Foo wants you to notice" << std::endl;
        mLogger.crit() << "Foo is in big problems." << std::endl;
    }
};

class Bar {
    kisslog::logger_base<char> &mLogger;
  public:
    Bar(kisslog::logger_base<char> &logger):mLogger(logger) {}
    void testlog() {
        mLogger.debug() << "Bar is debug logging" << std::endl;
        mLogger.notice() << "Bar wants you to notice" << std::endl;
        mLogger.crit() << "Bar is in big problems." << std::endl;
    }
};

typedef kisslog::rawlogger::ostreamlogger<kisslog::threading::MULTI> rawlogger_t;
typedef kisslog::logger<rawlogger_t> warnlogger_t;
typedef kisslog::logger<rawlogger_t,kisslog::severity::DEBUG> debuglogger_t;

int main(int argc,char **argv) {
  rawlogger_t rlogger(std::cerr);
  warnlogger_t foologger(rlogger);
  debuglogger_t barlogger(rlogger);
  Foo foo(foologger);
  Bar bar(barlogger);
  foo.testlog();
  bar.testlog();
};
