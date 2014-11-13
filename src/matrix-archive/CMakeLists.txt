remake_include(
  include
  ../common/include
)

remake_add_library(
  matrix_archive lib/*.cpp
  LINK ${Boost_LIBRARIES}
)
remake_add_headers(RECURSE FROM include/sm)
remake_pkg_config_generate(REQUIRES schweizer-messer-common eigen3)

remake_add_test(GOOGLE matrix_archive_gtest test/*.cpp LINK matrix_archive)
