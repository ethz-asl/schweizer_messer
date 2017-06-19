#ifndef SM_LOGGING_STDOUT_LOGGER_HPP
#define SM_LOGGING_STDOUT_LOGGER_HPP

#include <sm/logging/Logger.hpp>
#include <sm/logging/Formatter.hpp>

namespace sm {
    namespace logging {
        
        class StdOutLogger : public Logger
        {
        public:
            StdOutLogger();
            ~StdOutLogger() override;
            
            Formatter formatter;
        protected:
            void logImplementation(const LoggingEvent & event) override;
        };

    } // namespace logger
} // namespace sm


#endif /* SM_LOGGING_STDOUT_LOGGER_HPP */
