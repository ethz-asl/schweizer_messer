#ifndef SM_LOGGING_LEVELS_HPP
#define SM_LOGGING_LEVELS_HPP

// These allow you to compile-out everything below a certain severity level if necessary
#define SMCONSOLE_SEVERITY_DEBUG 0
#define SMCONSOLE_SEVERITY_INFO 1
#define SMCONSOLE_SEVERITY_WARN 2
#define SMCONSOLE_SEVERITY_ERROR 3
#define SMCONSOLE_SEVERITY_FATAL 4
#define SMCONSOLE_SEVERITY_NONE 5


namespace sm {
    namespace logging {
        
        namespace levels
        {
            enum Level
            {
                Debug,
                Info,
                Warn,
                Error,
                Fatal,

                Count
            };
        }

        typedef levels::Level Level;

    } // namespace logging
} // namespace sm


#endif /* SM_LOGGING_LEVELS_HPP */
