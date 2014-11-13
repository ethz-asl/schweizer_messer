remake_include(
  include
  ../common/include
  ../random/include
)
remake_define(__STRICT_ANSI__ ON)

remake_add_library(
  timing lib/*.cpp
  LINK ${Boost_LIBRARIES}
)
remake_add_headers(RECURSE FROM include/sm)
remake_pkg_config_generate(REQUIRES schweizer-messer-common)

remake_add_test(GOOGLE timing_gtest test/*.cpp LINK timing random)
