#include <sm/logging/Logger.hpp>


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


    } // namespace logging
} // namespace sm
