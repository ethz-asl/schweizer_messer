cmake_minimum_required(VERSION 2.8.3)
project(sm_common)

find_package(catkin REQUIRED)
include_directories(${catkin_INCLUDE_DIRS})
find_package(Boost REQUIRED COMPONENTS system)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++0x -D__STRICT_ANSI__")

include_directories(include)

catkin_package(
  INCLUDE_DIRS include ${catkin_INCLUDE_DIRS}
  LIBRARIES
  CATKIN_DEPENDS 
  DEPENDS
)

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
