cmake_minimum_required(VERSION 2.8.3)
project(sm_matlab)

find_package(catkin REQUIRED COMPONENTS sm_common sm_random)
include_directories(${catkin_INCLUDE_DIRS})
find_package(Boost REQUIRED COMPONENTS system)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../cmake)
find_package(Eigen REQUIRED)
include_directories(${EIGEN_INCLUDE_DIRS})
find_package(Matlab)  # Don't search with required, so we can continue.
include_directories(${MATLAB_INCLUDE_DIR})

catkin_package(
  INCLUDE_DIRS include  ${catkin_INCLUDE_DIRS}
  LIBRARIES sm_matlab
  CATKIN_DEPENDS sm_common sm_random
  DEPENDS
)

include_directories(include)

##############
## Building ##
##############

if(MATLAB_FOUND)
  add_library(${PROJECT_NAME}
    src/Engine.cpp
  )

  add_executable(sm_matlab_demo demo/demo.cpp)
  target_link_libraries(sm_matlab_demo 
                      ${PROJECT_NAME} 
                      ${MATLAB_LIBRARIES} 
                      ${catkin_LIBRARIES})

  #############
  ## Testing ##
  #############

  ## Add gtest based cpp test target and link libraries
  catkin_add_gtest(${PROJECT_NAME}-test
    test/test_main.cpp
    test/MatlabInterfaceTests.cpp
  )
  if(TARGET ${PROJECT_NAME}-test)
    target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
  endif()
else()
message("Matlab not found, not building sm_matlab")  
endif()
