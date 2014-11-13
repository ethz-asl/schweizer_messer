remake_include(
  include
  ../common/include
  ../random/include
  ../boost/include
  ../eigen/include
)

remake_add_library(
  kinematics lib/*.cpp
  LINK ${Boost_LIBRARIES}
)
remake_add_headers(RECURSE FROM include/sm)
remake_pkg_config_generate(REQUIRES schweizer-messer-common
  schweizer-messer-random schweizer-messer-boost schweizer-messer-eigen)
  
remake_add_test(GOOGLE kinematics_gtest test/*.cpp LINK kinematics random)
