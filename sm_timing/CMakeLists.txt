cmake_minimum_required(VERSION 2.8.3)
project(sm_timing)

find_package(catkin_simple REQUIRED)
catkin_simple()

find_package(Boost REQUIRED COMPONENTS system)

add_definitions(-std=c++0x -D__STRICT_ANSI__)

include_directories(${Boost_INCLUDE_DIRS})

##############
## Building ##
##############

cs_add_library(${PROJECT_NAME}
  src/Timer.cpp
  src/NsecTimeUtilities.cpp
)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

#############
## Testing ##
#############

if(CATKIN_ENABLE_TESTING)
  catkin_add_gtest(${PROJECT_NAME}-test
    test/test_main.cpp
    test/TestTimestampCorrector.cpp
    test/TestNsecTimeUtilities.cpp
  )
  if(TARGET ${PROJECT_NAME}-test)
    target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
  endif()
endif()

cs_install()
cs_export(LIBRARIES ${Boost_LIBRARIES})
