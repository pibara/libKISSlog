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

#ifndef KISSLOG_STREAMLOGGER_HPP
#define KISSLOG_STREAMLOGGER_HPP
#include <kisslog/util.hpp>
#include <kisslog/severity.hpp>
#include <kisslog/concurrency.hpp>
#include <string.h>
#include <string>
#include <iostream>
#include <ctime>

namespace kisslog {
  //Some raw loggers, well one actually, currently.There is only a syslog raw logger now but we could add a stream logger here maybe.
  namespace rawlogger {
    template <typename G, typename C=char>
    class ostreamlogger {
        std::basic_ostream<C> &mStream;
        util::CharUtil<C> charutil;
      public:
        ostreamlogger(std::basic_ostream<C> &stream):mStream(stream),charutil() {}
        template <severity::Severity S>
        void log(std::basic_string<C> line) {
           threading::guard_if_needed<G> myguard;
           mStream << charutil.now() << charutil.sp_col_sp() << severity::asPrefix<S,C>() << charutil.sp_col_sp() << line;
        }
    };
  }
}
#endif