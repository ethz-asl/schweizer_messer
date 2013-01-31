#include <sm/logging/Logger.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>

namespace sm {
    namespace logging {

        Logger::Logger(){}
        Logger::~Logger(){}
            

        double Logger::currentTimeSecondsUtc() const
        {
            return currentTimeSecondsUtcImplementation();
        }

        std::string Logger::currentTimeString() const
        {
            return currentTimeStringImplementation();
        }
            
        void Logger::log(const LoggingEvent & event)
        {
            logImplementation(event);
        }



        boost::uint64_t epochMicroseconds()
        {
            const static boost::posix_time::ptime UNIX_EPOCH( boost::gregorian::date(1970,1,1));
            boost::posix_time::ptime pt = boost::posix_time::microsec_clock::universal_time();
            boost::posix_time::time_duration duration( pt - UNIX_EPOCH );
            return duration.total_microseconds();
        }

        
        double Logger::currentTimeSecondsUtcImplementation() const
        {
            
            return (double)epochMicroseconds() * 1e-6;

        }

        std::string Logger::currentTimeStringImplementation() const
        {
            std::stringstream ss;
            ss.fill(' ');
            ss.setf(std::ios::fixed,std::ios::floatfield);   // floatfield set to fixed
            ss.precision(6);

            ss << ((double)epochMicroseconds()*1e-6);
            return ss.str();
        }


    } // namespace logging
} // namespace sm
