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

typedef kisslog::rawlogger::ostreamlogger<kisslog::threading::MULTI,char> ostreamrawlogger;
typedef kisslog::logger<ostreamrawlogger,kisslog::severity::WARNING,char> warnlogger;
typedef kisslog::logger<ostreamrawlogger,kisslog::severity::DEBUG,char> debuglogger;

int main(int argc,char **argv) {
  ostreamrawlogger rlogger(std::cerr);
  warnlogger foologger(rlogger);
  debuglogger barlogger(rlogger);
  Foo foo(foologger);
  Bar bar(barlogger);
  foo.testlog();
  bar.testlog();
};
