//WARNING: This file is work in progress, don't use yet.
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

#ifndef KISSLOG_SYSLOGPROTOLOGGER_HPP
#define KISSLOG_SYSLOGPROTOLOGGER_HPP
#include <kisslog/facility.hpp>
#include <kisslog/severity.hpp>
#include <kisslog/util.hpp>
#include <kisslog/concurrency.hpp>
#include <syslog.h>
#include <string>


namespace kisslog {
  namespace rawlogger {
    template <typename TransportProtoType,typename FacilityType>
    class syslogprotologger {
        TransportProtoType &mProto;
        int mBasePrio;
        std::string mProtoLinePrefix;
        util::CharUtil<char> charutil;
      public:
        syslogprotologger(TransportProtoType &proto,std::string hostname,std::string appname,std::string pid):
                 mProto(proto),
                 mBasePrio(FacilityType::asSyslogFacility()*8),
                 mProtoLinePrefix(std::string(" ") + hostname + " " + appname + " " + pid + " - - "),
                 charutil() {} 
        template <severity::Severity SeverityVal>
        void log(std::string line) {
           mProto(std::string("<") + std::to_string(mBasePrio + SeverityVal) + ">1 " + charutil.iso_now() + mProtoLinePrefix + line);
        }
    };
  }
}
#endif
