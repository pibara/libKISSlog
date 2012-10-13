//  Copyright (c) 2012, Rob J Meijer
//
//
//Permission is hereby granted, free of charge, to any person or organization
//obtaining a copy of the software and accompanying documentation covered by
//this license (the "Software") to use, reproduce, display, distribute,
//execute, and transmit the Software, and to prepare derivative works of the
//Software, and to permit third-parties to whom the Software is furnished to
//do so, all subject to the following:
//
//The copyright notices in the Software and this entire statement, including
//the above license grant, this restriction and the following disclaimer,
//must be included in all copies of the Software, in whole or in part, and
//all derivative works of the Software, unless such copies or derivative
//works are solely in the form of machine-executable object code generated by
//a source language processor.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
//SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
//FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
//ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//DEALINGS IN THE SOFTWARE.

#ifndef KISSLOG_SYSLOGLOGGER_HPP
#define KISSLOG_SYSLOGLOGGER_HPP
#include <kisslog/facility.hpp>
#include <kisslog/severity.hpp>
#include <kisslog/util.hpp>
#include <kisslog/concurrency.hpp>
#include <syslog.h>
#include <string>
#include <locale>

namespace kisslog {
  namespace rawlogger {
    template <typename FacilityType,typename GuardNeededType,typename CharType=char>
    class sysloglogger;

    template <typename FacilityType,typename GuardNeededType>
    class sysloglogger<FacilityType,GuardNeededType,char> {
        std::basic_string<char> mIdent;
        util::CharUtil<char> charutil;
      public:
        sysloglogger(std::basic_string<char> ident):mIdent(ident),charutil() {
          openlog(mIdent.c_str(),LOG_PID, FacilityType::asSyslogFacility());    
        } 
        ~sysloglogger() {
           closelog();
        }

        template <severity::Severity SeverityVal>
        void log(std::string line) {
           threading::guard_if_needed<GuardNeededType> myguard;
           syslog(SeverityVal,"%s",(severity::asPrefix<SeverityVal,char>() + charutil.sp_col_sp() + line).c_str());
        }
    };
#ifdef USE_HIGHLY_EXPERIMENTAL_KISSLOG_CODE //Where did std::wstring_convert go? FIXME
#if defined(__GXX_EXPERIMENTAL_CXX0X__) || __cplusplus >= 201103L
    template <typename FacilityType,typename GuardNeededType>
    class sysloglogger<FacilityType,GuardNeededType,char16_t> {
       std::wstring_convert<std::codecvt_utf8_utf16<char16_t>,char16_t> mConvert;
       sysloglogger<FacilityType,GuardNeededType,char> mCharLogger;
      public:
       sysloglogger(std::basic_string<char16_t> ident):mConvert(),mCharLogger(mConvert.to_bytes(ident)) {}
       template <severity::Severity SeverityVal>
       void log(std::u16string line) {
          mCharLogger.log<SeverityVal>(mConvert.to_bytes(line));
       }
    };

    template <typename FacilityType,typename GuardNeededType>
    class sysloglogger<FacilityType,GuardNeededType,char32_t> {
       std::wstring_convert<std::codecvt_utf8<char32_t>,char32_t> mConvert;
       sysloglogger<FacilityType,GuardNeededType,char> mCharLogger;
      public:
       sysloglogger(std::basic_string<char32_t> ident):mConvert(),mCharLogger(mConvert.to_bytes(ident)) {}
       template <severity::Severity SeverityVal>
       void log(std::u16string line) {
          mCharLogger.log<SeverityVal>(mConvert.to_bytes(line));
       }
    };
#endif
#endif
  }
}
#endif
