// !!!!!!!!!!!!!!!!!!!!!!! This is a generated file, do not edit manually

/*
 * Copyright (c) 2008, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#if (SMCONSOLE_MIN_SEVERITY > SMCONSOLE_SEVERITY_DEBUG)
#define SM_DEBUG(...)
#define SM_DEBUG_STREAM(args)
#define SM_DEBUG_NAMED(name, ...)
#define SM_DEBUG_STREAM_NAMED(name, args)
#define SM_DEBUG_COND(cond, ...)
#define SM_DEBUG_STREAM_COND(cond, args)
#define SM_DEBUG_COND_NAMED(cond, name, ...)
#define SM_DEBUG_STREAM_COND_NAMED(cond, name, args)
#define SM_DEBUG_ONCE(...)
#define SM_DEBUG_STREAM_ONCE(args)
#define SM_DEBUG_ONCE_NAMED(name, ...)
#define SM_DEBUG_STREAM_ONCE_NAMED(name, args)
#define SM_DEBUG_THROTTLE(rate, ...)
#define SM_DEBUG_STREAM_THROTTLE(rate, args)
#define SM_DEBUG_THROTTLE_NAMED(rate, name, ...)
#define SM_DEBUG_STREAM_THROTTLE_NAMED(rate, name, args)
#else
#define SM_DEBUG(...) SM_LOG(::sm::logging::levels::Debug, SMCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define SM_DEBUG_STREAM(args) SM_LOG_STREAM(::sm::logging::levels::Debug, SMCONSOLE_DEFAULT_NAME, args)
#define SM_DEBUG_NAMED(name, ...) SM_LOG(::sm::logging::levels::Debug, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define SM_DEBUG_STREAM_NAMED(name, args) SM_LOG_STREAM(::sm::logging::levels::Debug, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, args)
#define SM_DEBUG_COND(cond, ...) SM_LOG_COND(cond, ::sm::logging::levels::Debug, SMCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define SM_DEBUG_STREAM_COND(cond, args) SM_LOG_STREAM_COND(cond, ::sm::logging::levels::Debug, SMCONSOLE_DEFAULT_NAME, args)
#define SM_DEBUG_COND_NAMED(cond, name, ...) SM_LOG_COND(cond, ::sm::logging::levels::Debug, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define SM_DEBUG_STREAM_COND_NAMED(cond, name, args) SM_LOG_STREAM_COND(cond, ::sm::logging::levels::Debug, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, args)
#define SM_DEBUG_ONCE(...) SM_LOG_ONCE(::sm::logging::levels::Debug, SMCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define SM_DEBUG_STREAM_ONCE(args) SM_LOG_STREAM_ONCE(::sm::logging::levels::Debug, SMCONSOLE_DEFAULT_NAME, args)
#define SM_DEBUG_ONCE_NAMED(name, ...) SM_LOG_ONCE(::sm::logging::levels::Debug, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define SM_DEBUG_STREAM_ONCE_NAMED(name, args) SM_LOG_STREAM_ONCE(::sm::logging::levels::Debug, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, args)
#define SM_DEBUG_THROTTLE(rate, ...) SM_LOG_THROTTLE(rate, ::sm::logging::levels::Debug, SMCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define SM_DEBUG_STREAM_THROTTLE(rate, args) SM_LOG_STREAM_THROTTLE(rate, ::sm::logging::levels::Debug, SMCONSOLE_DEFAULT_NAME, args)
#define SM_DEBUG_THROTTLE_NAMED(rate, name, ...) SM_LOG_THROTTLE(rate, ::sm::logging::levels::Debug, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define SM_DEBUG_STREAM_THROTTLE_NAMED(rate, name, args) SM_LOG_STREAM_THROTTLE(rate, ::sm::logging::levels::Debug, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, args)
#endif

#if (SMCONSOLE_MIN_SEVERITY > SMCONSOLE_SEVERITY_INFO)
#define SM_INFO(...)
#define SM_INFO_STREAM(args)
#define SM_INFO_NAMED(name, ...)
#define SM_INFO_STREAM_NAMED(name, args)
#define SM_INFO_COND(cond, ...)
#define SM_INFO_STREAM_COND(cond, args)
#define SM_INFO_COND_NAMED(cond, name, ...)
#define SM_INFO_STREAM_COND_NAMED(cond, name, args)
#define SM_INFO_ONCE(...)
#define SM_INFO_STREAM_ONCE(args)
#define SM_INFO_ONCE_NAMED(name, ...)
#define SM_INFO_STREAM_ONCE_NAMED(name, args)
#define SM_INFO_THROTTLE(rate, ...)
#define SM_INFO_STREAM_THROTTLE(rate, args)
#define SM_INFO_THROTTLE_NAMED(rate, name, ...)
#define SM_INFO_STREAM_THROTTLE_NAMED(rate, name, args)
#else
#define SM_INFO(...) SM_LOG(::sm::logging::levels::Info, SMCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define SM_INFO_STREAM(args) SM_LOG_STREAM(::sm::logging::levels::Info, SMCONSOLE_DEFAULT_NAME, args)
#define SM_INFO_NAMED(name, ...) SM_LOG(::sm::logging::levels::Info, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define SM_INFO_STREAM_NAMED(name, args) SM_LOG_STREAM(::sm::logging::levels::Info, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, args)
#define SM_INFO_COND(cond, ...) SM_LOG_COND(cond, ::sm::logging::levels::Info, SMCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define SM_INFO_STREAM_COND(cond, args) SM_LOG_STREAM_COND(cond, ::sm::logging::levels::Info, SMCONSOLE_DEFAULT_NAME, args)
#define SM_INFO_COND_NAMED(cond, name, ...) SM_LOG_COND(cond, ::sm::logging::levels::Info, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define SM_INFO_STREAM_COND_NAMED(cond, name, args) SM_LOG_STREAM_COND(cond, ::sm::logging::levels::Info, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, args)
#define SM_INFO_ONCE(...) SM_LOG_ONCE(::sm::logging::levels::Info, SMCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define SM_INFO_STREAM_ONCE(args) SM_LOG_STREAM_ONCE(::sm::logging::levels::Info, SMCONSOLE_DEFAULT_NAME, args)
#define SM_INFO_ONCE_NAMED(name, ...) SM_LOG_ONCE(::sm::logging::levels::Info, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define SM_INFO_STREAM_ONCE_NAMED(name, args) SM_LOG_STREAM_ONCE(::sm::logging::levels::Info, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, args)
#define SM_INFO_THROTTLE(rate, ...) SM_LOG_THROTTLE(rate, ::sm::logging::levels::Info, SMCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define SM_INFO_STREAM_THROTTLE(rate, args) SM_LOG_STREAM_THROTTLE(rate, ::sm::logging::levels::Info, SMCONSOLE_DEFAULT_NAME, args)
#define SM_INFO_THROTTLE_NAMED(rate, name, ...) SM_LOG_THROTTLE(rate, ::sm::logging::levels::Info, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define SM_INFO_STREAM_THROTTLE_NAMED(rate, name, args) SM_LOG_STREAM_THROTTLE(rate, ::sm::logging::levels::Info, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, args)
#endif

#if (SMCONSOLE_MIN_SEVERITY > SMCONSOLE_SEVERITY_WARN)
#define SM_WARN(...)
#define SM_WARN_STREAM(args)
#define SM_WARN_NAMED(name, ...)
#define SM_WARN_STREAM_NAMED(name, args)
#define SM_WARN_COND(cond, ...)
#define SM_WARN_STREAM_COND(cond, args)
#define SM_WARN_COND_NAMED(cond, name, ...)
#define SM_WARN_STREAM_COND_NAMED(cond, name, args)
#define SM_WARN_ONCE(...)
#define SM_WARN_STREAM_ONCE(args)
#define SM_WARN_ONCE_NAMED(name, ...)
#define SM_WARN_STREAM_ONCE_NAMED(name, args)
#define SM_WARN_THROTTLE(rate, ...)
#define SM_WARN_STREAM_THROTTLE(rate, args)
#define SM_WARN_THROTTLE_NAMED(rate, name, ...)
#define SM_WARN_STREAM_THROTTLE_NAMED(rate, name, args)
#else
#define SM_WARN(...) SM_LOG(::sm::logging::levels::Warn, SMCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define SM_WARN_STREAM(args) SM_LOG_STREAM(::sm::logging::levels::Warn, SMCONSOLE_DEFAULT_NAME, args)
#define SM_WARN_NAMED(name, ...) SM_LOG(::sm::logging::levels::Warn, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define SM_WARN_STREAM_NAMED(name, args) SM_LOG_STREAM(::sm::logging::levels::Warn, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, args)
#define SM_WARN_COND(cond, ...) SM_LOG_COND(cond, ::sm::logging::levels::Warn, SMCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define SM_WARN_STREAM_COND(cond, args) SM_LOG_STREAM_COND(cond, ::sm::logging::levels::Warn, SMCONSOLE_DEFAULT_NAME, args)
#define SM_WARN_COND_NAMED(cond, name, ...) SM_LOG_COND(cond, ::sm::logging::levels::Warn, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define SM_WARN_STREAM_COND_NAMED(cond, name, args) SM_LOG_STREAM_COND(cond, ::sm::logging::levels::Warn, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, args)
#define SM_WARN_ONCE(...) SM_LOG_ONCE(::sm::logging::levels::Warn, SMCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define SM_WARN_STREAM_ONCE(args) SM_LOG_STREAM_ONCE(::sm::logging::levels::Warn, SMCONSOLE_DEFAULT_NAME, args)
#define SM_WARN_ONCE_NAMED(name, ...) SM_LOG_ONCE(::sm::logging::levels::Warn, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define SM_WARN_STREAM_ONCE_NAMED(name, args) SM_LOG_STREAM_ONCE(::sm::logging::levels::Warn, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, args)
#define SM_WARN_THROTTLE(rate, ...) SM_LOG_THROTTLE(rate, ::sm::logging::levels::Warn, SMCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define SM_WARN_STREAM_THROTTLE(rate, args) SM_LOG_STREAM_THROTTLE(rate, ::sm::logging::levels::Warn, SMCONSOLE_DEFAULT_NAME, args)
#define SM_WARN_THROTTLE_NAMED(rate, name, ...) SM_LOG_THROTTLE(rate, ::sm::logging::levels::Warn, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define SM_WARN_STREAM_THROTTLE_NAMED(rate, name, args) SM_LOG_STREAM_THROTTLE(rate, ::sm::logging::levels::Warn, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, args)
#endif

#if (SMCONSOLE_MIN_SEVERITY > SMCONSOLE_SEVERITY_ERROR)
#define SM_ERROR(...)
#define SM_ERROR_STREAM(args)
#define SM_ERROR_NAMED(name, ...)
#define SM_ERROR_STREAM_NAMED(name, args)
#define SM_ERROR_COND(cond, ...)
#define SM_ERROR_STREAM_COND(cond, args)
#define SM_ERROR_COND_NAMED(cond, name, ...)
#define SM_ERROR_STREAM_COND_NAMED(cond, name, args)
#define SM_ERROR_ONCE(...)
#define SM_ERROR_STREAM_ONCE(args)
#define SM_ERROR_ONCE_NAMED(name, ...)
#define SM_ERROR_STREAM_ONCE_NAMED(name, args)
#define SM_ERROR_THROTTLE(rate, ...)
#define SM_ERROR_STREAM_THROTTLE(rate, args)
#define SM_ERROR_THROTTLE_NAMED(rate, name, ...)
#define SM_ERROR_STREAM_THROTTLE_NAMED(rate, name, args)
#else
#define SM_ERROR(...) SM_LOG(::sm::logging::levels::Error, SMCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define SM_ERROR_STREAM(args) SM_LOG_STREAM(::sm::logging::levels::Error, SMCONSOLE_DEFAULT_NAME, args)
#define SM_ERROR_NAMED(name, ...) SM_LOG(::sm::logging::levels::Error, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define SM_ERROR_STREAM_NAMED(name, args) SM_LOG_STREAM(::sm::logging::levels::Error, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, args)
#define SM_ERROR_COND(cond, ...) SM_LOG_COND(cond, ::sm::logging::levels::Error, SMCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define SM_ERROR_STREAM_COND(cond, args) SM_LOG_STREAM_COND(cond, ::sm::logging::levels::Error, SMCONSOLE_DEFAULT_NAME, args)
#define SM_ERROR_COND_NAMED(cond, name, ...) SM_LOG_COND(cond, ::sm::logging::levels::Error, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define SM_ERROR_STREAM_COND_NAMED(cond, name, args) SM_LOG_STREAM_COND(cond, ::sm::logging::levels::Error, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, args)
#define SM_ERROR_ONCE(...) SM_LOG_ONCE(::sm::logging::levels::Error, SMCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define SM_ERROR_STREAM_ONCE(args) SM_LOG_STREAM_ONCE(::sm::logging::levels::Error, SMCONSOLE_DEFAULT_NAME, args)
#define SM_ERROR_ONCE_NAMED(name, ...) SM_LOG_ONCE(::sm::logging::levels::Error, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define SM_ERROR_STREAM_ONCE_NAMED(name, args) SM_LOG_STREAM_ONCE(::sm::logging::levels::Error, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, args)
#define SM_ERROR_THROTTLE(rate, ...) SM_LOG_THROTTLE(rate, ::sm::logging::levels::Error, SMCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define SM_ERROR_STREAM_THROTTLE(rate, args) SM_LOG_STREAM_THROTTLE(rate, ::sm::logging::levels::Error, SMCONSOLE_DEFAULT_NAME, args)
#define SM_ERROR_THROTTLE_NAMED(rate, name, ...) SM_LOG_THROTTLE(rate, ::sm::logging::levels::Error, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define SM_ERROR_STREAM_THROTTLE_NAMED(rate, name, args) SM_LOG_STREAM_THROTTLE(rate, ::sm::logging::levels::Error, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, args)
#endif

#if (SMCONSOLE_MIN_SEVERITY > SMCONSOLE_SEVERITY_FATAL)
#define SM_FATAL(...)
#define SM_FATAL_STREAM(args)
#define SM_FATAL_NAMED(name, ...)
#define SM_FATAL_STREAM_NAMED(name, args)
#define SM_FATAL_COND(cond, ...)
#define SM_FATAL_STREAM_COND(cond, args)
#define SM_FATAL_COND_NAMED(cond, name, ...)
#define SM_FATAL_STREAM_COND_NAMED(cond, name, args)
#define SM_FATAL_ONCE(...)
#define SM_FATAL_STREAM_ONCE(args)
#define SM_FATAL_ONCE_NAMED(name, ...)
#define SM_FATAL_STREAM_ONCE_NAMED(name, args)
#define SM_FATAL_THROTTLE(rate, ...)
#define SM_FATAL_STREAM_THROTTLE(rate, args)
#define SM_FATAL_THROTTLE_NAMED(rate, name, ...)
#define SM_FATAL_STREAM_THROTTLE_NAMED(rate, name, args)
#else
#define SM_FATAL(...) SM_LOG(::sm::logging::levels::Fatal, SMCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define SM_FATAL_STREAM(args) SM_LOG_STREAM(::sm::logging::levels::Fatal, SMCONSOLE_DEFAULT_NAME, args)
#define SM_FATAL_NAMED(name, ...) SM_LOG(::sm::logging::levels::Fatal, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define SM_FATAL_STREAM_NAMED(name, args) SM_LOG_STREAM(::sm::logging::levels::Fatal, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, args)
#define SM_FATAL_COND(cond, ...) SM_LOG_COND(cond, ::sm::logging::levels::Fatal, SMCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define SM_FATAL_STREAM_COND(cond, args) SM_LOG_STREAM_COND(cond, ::sm::logging::levels::Fatal, SMCONSOLE_DEFAULT_NAME, args)
#define SM_FATAL_COND_NAMED(cond, name, ...) SM_LOG_COND(cond, ::sm::logging::levels::Fatal, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define SM_FATAL_STREAM_COND_NAMED(cond, name, args) SM_LOG_STREAM_COND(cond, ::sm::logging::levels::Fatal, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, args)
#define SM_FATAL_ONCE(...) SM_LOG_ONCE(::sm::logging::levels::Fatal, SMCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define SM_FATAL_STREAM_ONCE(args) SM_LOG_STREAM_ONCE(::sm::logging::levels::Fatal, SMCONSOLE_DEFAULT_NAME, args)
#define SM_FATAL_ONCE_NAMED(name, ...) SM_LOG_ONCE(::sm::logging::levels::Fatal, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define SM_FATAL_STREAM_ONCE_NAMED(name, args) SM_LOG_STREAM_ONCE(::sm::logging::levels::Fatal, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, args)
#define SM_FATAL_THROTTLE(rate, ...) SM_LOG_THROTTLE(rate, ::sm::logging::levels::Fatal, SMCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define SM_FATAL_STREAM_THROTTLE(rate, args) SM_LOG_STREAM_THROTTLE(rate, ::sm::logging::levels::Fatal, SMCONSOLE_DEFAULT_NAME, args)
#define SM_FATAL_THROTTLE_NAMED(rate, name, ...) SM_LOG_THROTTLE(rate, ::sm::logging::levels::Fatal, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define SM_FATAL_STREAM_THROTTLE_NAMED(rate, name, args) SM_LOG_STREAM_THROTTLE(rate, ::sm::logging::levels::Fatal, std::string(SMCONSOLE_NAME_PREFIX) + "." + name, args)
#endif

