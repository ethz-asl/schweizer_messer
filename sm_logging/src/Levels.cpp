#include "sm/logging.hpp"

#include <string>
#include <boost/algorithm/string.hpp> // for case-insensitive string comparison

/**
 * \brief Returns a Level enum from string
 */
sm::logging::Level sm::logging::levels::fromString(const std::string& l) {
  
//   enum Level
//   {
//       All,
//       Finest,
//       Verbose,
//       Finer,
//       Trace,
//       Fine,
//       Debug,
//       Info,
//       Warn,
//       Error,
//       Fatal,
// 
//       Count
//   };

  if (boost::iequals(l, "All")) {
    return Level::All;
  } else if (boost::iequals(l, "Finest")) {
    return Level::Finest;
  } else if (boost::iequals(l, "Verbose")) {
    return Level::Verbose;
  } else if (boost::iequals(l, "Finer")) {
    return Level::Finer;
  } else if (boost::iequals(l, "Trace")) {
    return Level::Trace;
  } else if (boost::iequals(l, "Fine")) {
    return Level::Fine;
  } else if (boost::iequals(l, "Debug")) {
    return Level::Debug;
  } else if (boost::iequals(l, "Info")) {
    return Level::Info;
  } else if (boost::iequals(l, "Warn")) {
    return Level::Warn;
  } else if (boost::iequals(l, "Error")) {
    return Level::Error;
  } else if (boost::iequals(l, "Fatal")) {
    return Level::Fatal;
  } else {
    SM_ERROR_STREAM("Invalid logging level " << l << ", setting to Level::Info");
    return Level::Info;
  }

}