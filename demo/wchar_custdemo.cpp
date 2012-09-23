#include <kisslog.hpp>
//The below example code for some reason doesn't log anything when run.
//This is a currenly unresolved bug that needs to be fixed a.s.a.p.
class MyRawLogger {
    size_t mLineno;
   public:
    template <kisslog::severity::Severity S>
    void log(std::wstring line) {
           mLineno++;
           std::wcerr << mLineno << L" : " << kisslog::severity::asPrefix<S,wchar_t>() << L" : " << line;
    }
    size_t logcount() {
      return mLineno;
    }
};

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

typedef MyRawLogger myrawlogger;
typedef kisslog::logger<myrawlogger,kisslog::severity::WARNING,wchar_t> warnlogger;
typedef kisslog::logger<myrawlogger,kisslog::severity::DEBUG,wchar_t> debuglogger;

int main(int argc,char **argv) {
  MyRawLogger rlogger;
  warnlogger foologger(rlogger);
  debuglogger barlogger(rlogger);
  Foo foo(foologger);
  Bar bar(barlogger);
  foo.testlog();
  bar.testlog();
  if (rlogger.logcount() != 4) {
    std::cerr << "wchar support is currently still broken." << std::endl;
    return 1;
  }
  return 0;
};
