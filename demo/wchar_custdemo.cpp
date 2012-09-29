#include <kisslog.hpp>

class rawlogger_t {
    size_t mLineno;
    kisslog::util::CharUtil<wchar_t> mCharUtil;
   public:
    rawlogger_t():mLineno(0),mCharUtil(){}
    size_t logcount() {
       return mLineno;
    }
    template <kisslog::severity::Severity S>
    void log(std::wstring line) {
           mLineno++;
           std::wcerr << mLineno << mCharUtil.sp_col_sp() << kisslog::severity::asPrefix<S,wchar_t>() << mCharUtil.sp_col_sp() << line;
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

typedef kisslog::logger<rawlogger_t,kisslog::severity::WARNING,wchar_t> warnlogger_t;
typedef kisslog::logger<rawlogger_t,kisslog::severity::DEBUG,wchar_t> debuglogger_t;

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
