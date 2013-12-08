cmake_minimum_required(VERSION 2.8.3)
project(sm_common)

find_package(catkin REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES sm_common
  CATKIN_DEPENDS 
  DEPENDS
)

add_definitions(-std=c++0x -D__STRICT_ANSI__)
include_directories(include)

##################
## Installation ##
##################

## Mark cpp header files for installation
install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.hpp"
  PATTERN ".svn" EXCLUDE
)

#############
## Testing ##
#############

catkin_add_gtest(${PROJECT_NAME}-test
  test/test_main.cpp
  test/maths.cpp
  test/serialization_macros.cpp
  test/numerical_comparisons.cpp
)
