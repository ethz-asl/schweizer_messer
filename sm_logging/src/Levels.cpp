#include "sm/logging.hpp"

#include <string>
#include <locale> // for case-insensitive string comparison
#include <algorithm>

/**
 * \brief Returns a Level enum from string
 * \param level level as string
 * \return logging level enum
 */
sm::logging::Level sm::logging::levels::fromString(const std::string& level) {

  std::string levelLowercase = std::transform(level.begin(), level.end(), level.begin(), ::tolower);

  if (levelLowercase == "all") {
    return Level::All;
  } else if (levelLowercase == "finest") {
    return Level::Finest;
  } else if (levelLowercase == "verbose") {
    return Level::Verbose;
  } else if (levelLowercase == "finer") {
    return Level::Finer;
  } else if (levelLowercase == "trace") {
    return Level::Trace;
  } else if (levelLowercase == "fine") {
    return Level::Fine;
  } else if (levelLowercase == "debug") {
    return Level::Debug;
  } else if (levelLowercase == "info") {
    return Level::Info;
  } else if (levelLowercase == "warn") {
    return Level::Warn;
  } else if (levelLowercase == "error") {
    return Level::Error;
  } else if (levelLowercase == "fatal") {
    return Level::Fatal;
  } else {
    SM_ERROR_STREAM("Invalid logging level " << level << ", setting to Level::Info");
    return Level::Info;
  }

}
