#include <kisslog.hpp>

class Foo {
    kisslog::logger_base &mLogger;
  public:
    Foo(kisslog::logger_base &logger):mLogger(logger) {}
    void testlog() {
        mLogger.debug() << "Foo is debug logging" << std::endl;
        mLogger.notice() << "Foo wants you to notice" << std::endl;
        mLogger.crit() << "Foo is in big problems." << std::endl;
    }
};

class Bar {
    kisslog::logger_base &mLogger;
  public:
    Bar(kisslog::logger_base &logger):mLogger(logger) {}
    void testlog() {
        mLogger.debug() << "Bar is debug logging" << std::endl;
        mLogger.notice() << "Bar wants you to notice" << std::endl;
        mLogger.crit() << "Bar is in big problems." << std::endl;
    }
};

typedef kisslog::rawlogger::sysloglogger<kisslog::facility::USER,kisslog::threading::SINGLE> syslograwlogger;
typedef kisslog::logger<syslograwlogger,kisslog::severity::WARNING> warnlogger;
typedef kisslog::logger<syslograwlogger,kisslog::severity::DEBUG> debuglogger;

int main(int argc,char **argv) {
  syslograwlogger rlogger("demo");
  warnlogger foologger(rlogger);
  debuglogger barlogger(rlogger);
  Foo foo(foologger);
  Bar bar(barlogger);
  foo.testlog();
  bar.testlog();
};