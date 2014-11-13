remake_include(include)

remake_add_library(
  common lib/*.cpp
  LINK ${Boost_LIBRARIES}
)
remake_add_headers(RECURSE FROM include/sm)
remake_pkg_config_generate(EXTRA_CFLAGS -std=c++0x)

remake_add_test(GOOGLE common_gtest test/*.cpp LINK common)
