cmake_minimum_required(VERSION 2.8.3)
project(test)

find_package(catkin REQUIRED COMPONENTS sm_common sm_boost)
find_package(Boost REQUIRED COMPONENTS system filesystem)
find_package(Sqlite3 REQUIRED)
include_directories(${SQLITE3_DIRECTORIES})

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES sm_common
  CATKIN_DEPENDS 
  DEPENDS
)

include_directories(include)

##############
## Building ##
##############

add_library(${PROJECT_NAME}
  src/Database.cpp
)

target_link_libraries(${PROJECT_NAME} ${SQLITE3_LIBRARIES}
                                      ${catkin_LIBRARIES}))

##################
## Installation ##
##################

install(TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

## Mark cpp header files for installation
install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.hpp"
  PATTERN ".svn" EXCLUDE
)

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
catkin_add_gtest(${PROJECT_NAME}-test   
  test/test_main.cpp
  test/SerializedMap.cpp)
if(TARGET ${PROJECT_NAME}-test)
  target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME} 
                                             ${SQLITE3_LIBRARIES}
                                             ${catkin_LIBRARIES})
endif()