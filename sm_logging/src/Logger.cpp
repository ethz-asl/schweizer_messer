#include <sm/logging/Logger.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>

namespace sm {
    namespace logging {

        Logger::Logger(){}
        Logger::~Logger(){}
            

        double Logger::currentTimeSecondsUtc() const
        {
            Time t = currentTimeImplementation();
#ifdef __APPLE__
            boost::int64_t us = boost::chrono::duration_cast<boost::chrono::microseconds>( t.time_since_epoch() ).count();
#else
            boost::int64_t us = std::chrono::duration_cast<std::chrono::microseconds>( t.time_since_epoch() ).count();
#endif
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

        Logger::Time Logger::currentTime() const {
            return currentTimeImplementation();
        }

            
        void Logger::log(const LoggingEvent & event)
        {
            logImplementation(event);
        }

        
        Logger::Time Logger::currentTimeImplementation() const
        {
            return Clock::now();
            
        }



    } // namespace logging
} // namespace sm
