remake_include(
  include
  ../common/include
)

remake_add_library(
  property_tree lib/*.cpp
  LINK ${Boost_LIBRARIES}
)
remake_add_headers(RECURSE FROM include/sm)
remake_pkg_config_generate(REQUIRES schweizer-messer-common)

remake_add_test(GOOGLE property_tree_gtest test/*.cpp LINK property_tree)
