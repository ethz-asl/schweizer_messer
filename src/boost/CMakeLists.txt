remake_include(include)

remake_add_library(
  boost lib/*.cpp
  LINK ${Boost_LIBRARIES}
)
remake_add_headers(RECURSE FROM include/sm)
remake_pkg_config_generate(REQUIRES schweizer-messer-common)

remake_add_test(GOOGLE boost_gtest test/*.cpp LINK boost)
