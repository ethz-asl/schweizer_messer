remake_include(
  include
  ../common/include
  ${MATLAB_INCLUDE_DIR}
)

remake_add_library(
  matlab lib/*.cpp
  LINK ${Boost_LIBRARIES} ${MATLAB_LIBRARIES}
)
remake_add_headers(RECURSE FROM include/sm)
remake_pkg_config_generate(REQUIRES schweizer-messer-common eigen3)

remake_add_test(GOOGLE matlab_gtest test/*.cpp LINK matlab)
