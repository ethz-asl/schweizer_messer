#include <sm/logging/Logger.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>

namespace sm {
    namespace logging {

        Logger::Logger(){}
        Logger::~Logger(){}
            

        double Logger::currentTimeSecondsUtc() const
        {
            std::chrono::system_clock::time_point t = currentTimeImplementation();
            boost::int64_t us = std::chrono::duration_cast<std::chrono::microseconds>( t.time_since_epoch() ).count();
            // \todo
            return (double)us/1000000.0;
        }

        std::string Logger::currentTimeString() const
        {
            double cts = currentTimeSecondsUtc();
            std::stringstream ss;
            ss.fill(' ');
            ss.setf(std::ios::fixed,std::ios::floatfield);   // floatfield set to fixed
            ss.precision(6);

            ss << cts;
            return ss.str();

        }

        std::chrono::system_clock::time_point Logger::currentTime() const {
            return currentTimeImplementation();
        }

            
        void Logger::log(const LoggingEvent & event)
        {
            logImplementation(event);
        }

        
        std::chrono::system_clock::time_point Logger::currentTimeImplementation() const
        {
            return std::chrono::system_clock::now();
            
        }



    } // namespace logging
} // namespace sm
