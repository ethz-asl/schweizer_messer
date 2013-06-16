#ifndef SM_LOGGER_HPP
#define SM_LOGGER_HPP

#include <string>
#include <chrono>

namespace sm {
    namespace logging {
        
        struct LoggingEvent;
        
        class Logger
        {
        public:
            Logger();
            virtual ~Logger();
            
            double currentTimeSecondsUtc() const;
            std::string currentTimeString() const;
            std::chrono::system_clock::time_point currentTime() const;

            void log(const LoggingEvent & event);
        protected:
            virtual std::chrono::system_clock::time_point currentTimeImplementation() const;
            virtual void logImplementation(const LoggingEvent & event) = 0;
        };

    } // namespace logging
} // namespace sm


#endif /* SM_LOGGER_HPP */
