#ifndef ASRL_BUILD_ID
#define ASRL_BUILD_ID

#include <string>

namespace asrl {
	inline const char * build_id() {
	  std::string subversion_revision("$Rev: 5139 $");

#ifdef NDEBUG
	  return (std::string("[R] " __DATE__ ", " __TIME__ " " ) + subversion_revision.substr(1,subversion_revision.size()-2)).c_str();
#else
		  return (std::string("[D] " __DATE__ ", " __TIME__ " " ) + subversion_revision.substr(1,subversion_revision.size()-2)).c_str();
#endif
	}

	std::string lib_build_id();
}

#endif
