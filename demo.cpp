#include <loglite.hpp>

class Foo {
    loglite::logger_base &mLogger;
  public:
    Foo(loglite::logger_base &logger):mLogger(logger) {}
    void testlog() {
        mLogger.debug() << "Foo is debug logging" << std::endl;
        mLogger.notice() << "Foo wants you to notice" << std::endl;
        mLogger.crit() << "Foo is in big problems." << std::endl;
    }
};

class Bar {
    loglite::logger_base &mLogger;
  public:
    Bar(loglite::logger_base &logger):mLogger(logger) {}
    void testlog() {
        mLogger.debug() << "Bar is debug logging" << std::endl;
        mLogger.notice() << "Bar wants you to notice" << std::endl;
        mLogger.crit() << "Bar is in big problems." << std::endl;
    }
};

typedef loglite::rawlogger::sysloglogger<loglite::facility::USER,loglite::threading::SINGLE> syslograwlogger;
typedef loglite::logger<syslograwlogger,loglite::severity::WARNING> warnlogger;
typedef loglite::logger<syslograwlogger,loglite::severity::DEBUG> debuglogger;

int main(int argc,char **argv) {
  syslograwlogger rlogger("demo");
  warnlogger foologger(rlogger);
  debuglogger barlogger(rlogger);
  Foo foo(foologger);
  Bar bar(barlogger);
  foo.testlog();
  bar.testlog();
};
