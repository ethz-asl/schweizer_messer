#ifndef SM_LOGGER_HPP
#define SM_LOGGER_HPP

#include <string>
#ifdef __APPLE__
#include <boost/chrono.hpp>
#else
#include <chrono>
#endif
namespace sm {
    namespace logging {
        
        struct LoggingEvent;
        
        class Logger
        {
        public:
#ifdef __APPLE__
            typedef boost::chrono::system_clock Clock;
#else
            typedef std::chrono::system_clock Clock;
#endif
            typedef Clock::time_point Time;
            typedef Clock::duration Duration;


            Logger();
            virtual ~Logger();
            
            double currentTimeSecondsUtc() const;
            std::string currentTimeString() const;
            Time currentTime() const;

            void log(const LoggingEvent & event);
        protected:
            virtual Time currentTimeImplementation() const;
            virtual void logImplementation(const LoggingEvent & event) = 0;
        };

    } // namespace logging
} // namespace sm


#endif /* SM_LOGGER_HPP */
