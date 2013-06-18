# Helpful function for adding python export libraries in ROS.
# Usage:
# 
# rosbuild_find_ros_package(numpy_eigen)
# include(${numpy_eigen_PACKAGE_PATH}/cmake/add_python_export_library.cmake)
# add_python_export_library(${PROJECT_NAME}_python ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}
#                           src/file1.cpp
#                           src/file2.cpp
#                          )
#
#
# Set the path for the output python files. This should be the path
# with the __init__.py file. The standard for ROS (where python message
# definitions live) is ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}

MACRO(add_python_export_library TARGET_NAME PYTHON_MODULE_DIRECTORY )

  rosbuild_add_boost_directories()
  # Find Python
  FIND_PACKAGE(PythonLibs 2.7 REQUIRED)
  INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_DIRS})

  IF(APPLE)
    # The apple framework headers don't include the numpy headers for some reason.
    GET_FILENAME_COMPONENT(REAL_PYTHON_INCLUDE ${PYTHON_INCLUDE_DIRS} REALPATH)
    IF( ${REAL_PYTHON_INCLUDE} MATCHES Python.framework)
      message("Trying to find extra headers for numpy from ${REAL_PYTHON_INCLUDE}.")
      message("Looking in ${REAL_PYTHON_INCLUDE}/../../Extras/lib/python/numpy/core/include/numpy")
      FIND_PATH(NUMPY_INCLUDE_DIR arrayobject.h
	${REAL_PYTHON_INCLUDE}/../../Extras/lib/python/numpy/core/include/numpy
	${REAL_PYTHON_INCLUDE}/numpy
	)
      IF(${NUMPY_INCLUDE_DIR} MATCHES NOTFOUND)
	message("Unable to find numpy include directories: ${NUMPY_INCLUDE_DIR}")
      ELSE()
	message("Found headers at ${NUMPY_INCLUDE_DIR}")
	INCLUDE_DIRECTORIES(${NUMPY_INCLUDE_DIR})
	INCLUDE_DIRECTORIES(${NUMPY_INCLUDE_DIR}/..)
      ENDIF()
    ENDIF()
  ENDIF(APPLE)


  # message("Target files: ${ARGN}")
  # Create the target and assign source files
  rosbuild_add_library( ${TARGET_NAME}
      ${ARGN}
    )

  # Link your python project to the main library and to Python
  target_link_libraries( ${TARGET_NAME}
    ${PYTHON_LIBRARY}
    )

  # Link against boost::python
  rosbuild_link_boost(${TARGET_NAME} python )

  # On OSX and Linux, the python library must end in the extension .so. Build this
  # filename here.
  get_property(PYLIB_OUTPUT_FILE TARGET ${TARGET_NAME} PROPERTY LOCATION)
  get_filename_component(PYLIB_OUTPUT_NAME ${PYLIB_OUTPUT_FILE} NAME_WE)
  set(PYLIB_SO_NAME ${PYLIB_OUTPUT_NAME}.so)

  # Cause the library to be output in the correct directory.
  add_custom_command(TARGET ${TARGET_NAME}
    POST_BUILD
    COMMAND cp -v ${PYLIB_OUTPUT_FILE} ${PYTHON_MODULE_DIRECTORY}/${PYLIB_SO_NAME}
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMENT "Copying library files to python directory" )

  get_directory_property(AMCF ADDITIONAL_MAKE_CLEAN_FILES)
  list(APPEND AMCF ${PYTHON_MODULE_DIRECTORY}/${PYLIB_SO_NAME})
  set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES "${AMCF}") 

ENDMACRO()

