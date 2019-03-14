cmake_minimum_required(VERSION 2.8.3)
project(sm_common)

find_package(catkin_simple REQUIRED)
catkin_simple()

find_package(Boost REQUIRED COMPONENTS system)
include_directories(${Boost_INCLUDE_DIRS})

# enable warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# enable C++11 support
if(CMAKE_VERSION VERSION_LESS "3.1")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
  set(CMAKE_CXX_STANDARD 11)
endif()

cs_add_library(${PROJECT_NAME}
  src/hash_id.cpp
  src/progress_info.cpp
)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

#############
## Testing ##
#############

if(CATKIN_ENABLE_TESTING)
catkin_add_gtest(${PROJECT_NAME}-test
  test/test_main.cpp
  test/assert_macros.cpp
  test/assert_macros_dbg.cpp
  test/assert_macros_always_assert.cpp
  test/maths.cpp
  test/serialization_macros.cpp
  test/numerical_comparisons.cpp
  test/hash_id.cpp
)
target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
endif()

cs_install()
cs_export(CFG_EXTRAS export_flags.cmake)
