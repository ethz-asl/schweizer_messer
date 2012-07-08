cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
#set(ROS_BUILD_TYPE RelWithDebInfo)

rosbuild_init()

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#uncomment if you have defined messages
#rosbuild_genmsg()
#uncomment if you have defined services
#rosbuild_gensrv()

#common commands for building c++ executables and libraries
#rosbuild_add_library(${PROJECT_NAME} src/example.cpp)
#target_link_libraries(${PROJECT_NAME} another_library)
#rosbuild_add_boost_directories()
#rosbuild_link_boost(${PROJECT_NAME} thread)
#rosbuild_add_executable(example examples/example.cpp)
#target_link_libraries(example ${PROJECT_NAME})

#--------------------------#
# Documentation
SET(DOCSOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/doc)


FIND_PACKAGE(Doxygen REQUIRED)
IF(DOXYGEN)
  Set(DOCSOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/doc)
  SET(DOXYGEN_IMAGE_DIRS "\"${DOCSOURCE_DIR}/figs/\"")
  SET(DOXYGEN_SOURCE_DIRS "\"${CMAKE_CURRENT_SOURCE_DIR}/../sm_boost/include/\" \"${CMAKE_CURRENT_SOURCE_DIR}/../sm_common/include/\" \"${CMAKE_CURRENT_SOURCE_DIR}/../sm_database/include/\" \"${CMAKE_CURRENT_SOURCE_DIR}/../sm_eigen/include/\" \"${CMAKE_CURRENT_SOURCE_DIR}/../sm_kinematics/include/\" \"${CMAKE_CURRENT_SOURCE_DIR}/../sm_opencv/include/\" \"${CMAKE_CURRENT_SOURCE_DIR}/../sm_pose_graph/include/\" \"${CMAKE_CURRENT_SOURCE_DIR}/../sm_property_tree/include/\" \"${CMAKE_CURRENT_SOURCE_DIR}/../sm_python/include/\" \"${CMAKE_CURRENT_SOURCE_DIR}/../sm_random/include/\" \"${CMAKE_CURRENT_SOURCE_DIR}/../sm_timing/include/\"")

  Set(HTML_DIR ${CMAKE_CURRENT_SOURCE_DIR}/doc/html)
  SET(DOXYGEN_QUIET YES)
  MAKE_DIRECTORY(${HTML_DIR})
  SET( HAVE_DOT YES )
  
  CONFIGURE_FILE(${DOCSOURCE_DIR}/doxygen.config.in ${DOCSOURCE_DIR}/doxygen.config IMMEDIATE)
  
  ADD_CUSTOM_TARGET(doc ALL ${DOXYGEN} --silent ${DOCSOURCE_DIR}/doxygen.config)
ENDIF(DOXYGEN)

#-------------------------#
