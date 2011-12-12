cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
#set(ROS_BUILD_TYPE RelWithDebInfo)
#set(ROS_BUILD_TYPE Debug)
set(ROS_BUILD_TYPE RelWithDebInfo)

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
#rosbuild_add_library(numpy_eigen src/dummy.cpp)
#target_link_libraries(numpy_eigen another_library)
rosbuild_add_boost_directories()
#rosbuild_link_boost(numpy_eigen thread)
#rosbuild_add_executable(example examples/example.cpp)
#target_link_libraries(example numpy_eigen)

#target_link_libraries(test/spline_tests numpy_eigen)

#rosbuild_link_boost(test/spline_tests thread)


rosbuild_find_ros_package(numpy_eigen)
include(${numpy_eigen_PACKAGE_PATH}/cmake/add_python_export_library.cmake)

add_python_export_library(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/python/${PROJECT_NAME}
                           src/numpy_eigen_export_module.cpp
                          )

add_python_export_library(${PROJECT_NAME}_test ${PROJECT_SOURCE_DIR}/python/${PROJECT_NAME}
                           src/numpy_eigen_test_module.cpp
                          )

rosbuild_add_pyunit( test/numpy_eigen_tests.py)


