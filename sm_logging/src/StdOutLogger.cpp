#include <sm/logging/StdOutLogger.hpp>
#include <boost/cstdint.hpp>
#include <sstream>
#ifdef WIN32
#include <windows.h>
#endif
#include <sys/time.h>
#include <iostream>
#include <sm/logging/LoggingEvent.hpp>

namespace sm {
    namespace logging {

        StdOutLogger::StdOutLogger(){}
        StdOutLogger::~StdOutLogger(){}
            

        boost::uint64_t nowMicroseconds()
        {
#ifdef WIN32
            FILETIME fileTime;
            
            LARGE_INTEGER li;
            
            boost::uint64_t nowMs;

            GetSystemTimeAsFileTime(&fileTime);

            li.LowPart = oFileTime.dwLowDateTime;
            li.HighPart = oFileTime.dwHighDateTime;

            nowMs = li.QuadPart; // 100 ns since 16010101T000000
            nowMs /= 10l; // us since 160101T000000
            nowMs -= 11644473600000000l/* us 1970-1601 */; // us since 19700101T000000
            return nowMs;
#else

            struct timeval now;
            gettimeofday(&now, NULL);
            
            return ((boost::uint64_t)now.tv_sec)*1000000l+((boost::uint64_t)now.tv_usec);
#endif

        }
        
        double StdOutLogger::currentTimeSecondsUtcImplementation() const
        {
            return (double)nowMicroseconds() * 1e-6;
        }
        std::string StdOutLogger::currentTimeStringImplementation() const
        {
            std::stringstream ss;
            ss.fill(' ');
            ss.setf(std::ios::fixed,std::ios::floatfield);   // floatfield set to fixed
            ss.precision(6);

            ss << ((double)nowMicroseconds()*1e-6);
            return ss.str();
        }
        void StdOutLogger::logImplementation(const LoggingEvent & event)
        {
            formatter.print(event,std::cout);
            
        }


    } // namespace logging
} // namespace sm
