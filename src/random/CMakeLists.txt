remake_include(include)

remake_add_library(random lib/*.cpp)
remake_add_headers(RECURSE FROM include/sm)
remake_pkg_config_generate(REQUIRES schweizer-messer-common)
