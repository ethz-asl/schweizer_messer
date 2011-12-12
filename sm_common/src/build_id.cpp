
#include <asrl/build_id.hpp>



namespace asrl {

std::string lib_build_id()
{
  return std::string("lib-asrl: ") + build_id(); 
}

}
