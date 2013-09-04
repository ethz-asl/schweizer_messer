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

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../cmake)
find_package(Eigen REQUIRED)
include_directories(${EIGEN_INCLUDE_DIRS})
add_definitions(${EIGEN_DEFINITIONS})

rosbuild_add_boost_directories()

# Include the custom python export library funciton
include(cmake/add_python_export_library.cmake)

IF(APPLE)
  link_directories( /usr/local/lib )
ENDIF(APPLE)


include_directories("${PROJECT_SOURCE_DIR}/include/numpy_eigen")
# # Auto generate the export module
# TODO: My CMake skills are pretty weak. Figure out how to 
#       autogenerate the source files and compile.
#
# add_custom_target(autogen ALL)
# add_custom_command(TARGET autogen
#                     COMMAND python create_export_module.py
#  		    #COMMAND FILE(GLOB AUTOGEN_CPP RELATIVE ${PROJECT_SOURCE_DIR} "src/autogen_module/*.cpp")
#                     DEPENDS ${PROJECT_SOURCE_DIR}/src/create_export_module.py
#                     WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/src
#                     COMMENT "Autogenerating the python export module")

# # Clean up the auto-generated files on make clean.
# get_directory_property(AMCF ADDITIONAL_MAKE_CLEAN_FILES)
# list(APPEND AMCF ${PROJECT_SOURCE_DIR}/src/autogen_module)
# list(APPEND AMCF ${PROJECT_SOURCE_DIR}/src/autogen_test_module)
# set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES "${AMCF}") 

INCLUDE(src/autogen_files.cmake)
add_python_export_library(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/python/${PROJECT_NAME}
 ${AUTOGEN_FILES}
)
rosbuild_link_boost(${PROJECT_NAME} system)
INCLUDE(src/autogen_test_files.cmake)
add_python_export_library(${PROJECT_NAME}_test ${PROJECT_SOURCE_DIR}/python/${PROJECT_NAME}
  ${AUTOGEN_TEST_FILES}
  )

rosbuild_add_pyunit( test/numpy_eigen_tests.py TIMEOUT 600)

rosbuild_link_boost(${PROJECT_NAME}_test thread system)

