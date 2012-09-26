#include <kisslog.hpp>

template <typename C>
class MyRawLogger {
    size_t mLineno;
    kisslog::util::CharUtil<C> mCharUtil;
   public:
    MyRawLogger():mLineno(0),mCharUtil(){}
    size_t logcount() {
       return mLineno;
    }
    template <kisslog::severity::Severity S>
    void log(std::basic_string<C> line) {
           mLineno++;
#ifdef KISSLOG_USE_WIDE
           std::wcerr << mLineno << mCharUtil.sp_col_sp() << kisslog::severity::asPrefix<S,C>() << mCharUtil.sp_col_sp() << line;
#else
           std::cerr << mLineno << mCharUtil.sp_col_sp() << kisslog::severity::asPrefix<S,C>() << mCharUtil.sp_col_sp() << line;
#endif
    }
};

template <typename C>
class Foo {
    kisslog::logger_base<C> &mLogger;
  public:
    Foo(kisslog::logger_base<C> &logger):mLogger(logger) {}
    void testlog() {
#ifdef KISSLOG_USE_WIDE
        mLogger.debug() << L"Foo is debug logging" << std::endl;
        mLogger.notice() << L"Foo wants you to notice" << std::endl;
        mLogger.crit() << L"Foo is in big problems." << std::endl;
#else
        mLogger.debug() << "Foo is debug logging" << std::endl;
        mLogger.notice() << "Foo wants you to notice" << std::endl;
        mLogger.crit() << "Foo is in big problems." << std::endl;
#endif
    }
};

template <typename C>
class Bar {
    kisslog::logger_base<C> &mLogger;
  public:
    Bar(kisslog::logger_base<C> &logger):mLogger(logger) {}
    void testlog() {
#ifdef KISSLOG_USE_WIDE
        mLogger.debug() << L"Bar is debug logging" << std::endl;
        mLogger.notice() << L"Bar wants you to notice" << std::endl;
        mLogger.crit() << L"Bar is in big problems." << std::endl;
#else
        mLogger.debug() << "Bar is debug logging" << std::endl;
        mLogger.notice() << "Bar wants you to notice" << std::endl;
        mLogger.crit() << "Bar is in big problems." << std::endl;
#endif
    }
};

#ifdef KISSLOG_USE_WIDE
typedef wchar_t chartype;
#else
typedef char chartype;
#endif

typedef MyRawLogger<chartype> myrawlogger;
typedef kisslog::logger<myrawlogger,kisslog::severity::WARNING,chartype> warnlogger;
typedef kisslog::logger<myrawlogger,kisslog::severity::DEBUG,chartype> debuglogger;

int main(int argc,char **argv) {
  myrawlogger rlogger;
  warnlogger foologger(rlogger);
  debuglogger barlogger(rlogger);
  Foo<chartype> foo(foologger);
  Bar<chartype> bar(barlogger);
  foo.testlog();
  bar.testlog();
  if (rlogger.logcount() !=4) {
    return 1;
  } 
  return 0;
};
