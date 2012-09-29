#include <kisslog.hpp>

class rawlogger_t {
    size_t mLineno;
    kisslog::util::CharUtil<char> mCharUtil;
   public:
    rawlogger_t():mLineno(0),mCharUtil(){}
    size_t logcount() {
       return mLineno;
    }
    template <kisslog::severity::Severity S>
    void log(std::string line) {
           mLineno++;
           std::cerr << " : " << kisslog::severity::asPrefix<S,char>() << " : " << line << std::endl;
    }
};

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

typedef kisslog::logger<rawlogger_t> warnlogger_t;
typedef kisslog::logger<rawlogger_t,kisslog::severity::DEBUG> debuglogger_t;

int main(int argc,char **argv) {
  rawlogger_t rlogger;
  warnlogger_t foologger(rlogger);
  debuglogger_t barlogger(rlogger);
  Foo foo(foologger);
  Bar bar(barlogger);
  foo.testlog();
  bar.testlog();
  if (rlogger.logcount() !=4) {
    return 1;
  } 
  return 0;
};
