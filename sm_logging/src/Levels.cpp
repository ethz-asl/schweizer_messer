#include "sm/logging.hpp"

#include <string>
#include <boost/algorithm/string.hpp> // for case-insensitive string comparison

/**
 * \brief Returns a Level enum from string
 */
sm::logging::Level sm::logging::levels::fromString(const std::string& level) {

  if (boost::iequals(level, "All")) {
    return Level::All;
  } else if (boost::iequals(level, "Finest")) {
    return Level::Finest;
  } else if (boost::iequals(level, "Verbose")) {
    return Level::Verbose;
  } else if (boost::iequals(level, "Finer")) {
    return Level::Finer;
  } else if (boost::iequals(level, "Trace")) {
    return Level::Trace;
  } else if (boost::iequals(level, "Fine")) {
    return Level::Fine;
  } else if (boost::iequals(level, "Debug")) {
    return Level::Debug;
  } else if (boost::iequals(level, "Info")) {
    return Level::Info;
  } else if (boost::iequals(level, "Warn")) {
    return Level::Warn;
  } else if (boost::iequals(level, "Error")) {
    return Level::Error;
  } else if (boost::iequals(level, "Fatal")) {
    return Level::Fatal;
  } else {
    SM_ERROR_STREAM("Invalid logging level " << level << ", setting to Level::Info");
    return Level::Info;
  }

}
