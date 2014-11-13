remake_include(
  include
  ../common/include
  ../boost/include
)

remake_add_library(
  database lib/*.cpp
  LINK ${Boost_LIBRARIES} ${SQLITE3_LIBRARIES}
)
remake_add_headers(RECURSE FROM include/sm)
remake_pkg_config_generate(REQUIRES schweizer-messer-common sqlite3)

remake_add_test(GOOGLE database_gtest test/*.cpp LINK database boost)
