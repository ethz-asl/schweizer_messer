remake_include(
  include
  ../common/include
  ../random/include
)

remake_add_library(
  eigen lib/*.cpp
  LINK random ${Boost_LIBRARIES}
)
remake_add_headers(RECURSE FROM include/sm)
remake_pkg_config_generate(REQUIRES schweizer-messer-random eigen3)

remake_add_test(GOOGLE eigen_gtest test/*.cpp LINK eigen)
