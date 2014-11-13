remake_find_executable(python)
remake_find_package(PythonLibs)
remake_find_package(
  Boost REQUIRED COMPONENTS python
  RESULT_VAR Boost_FOUND
)
remake_find_package(eigen3 CONFIG)

remake_set(NUMPY_EIGEN_MODULE_PATH
  ${CMAKE_CURRENT_BINARY_DIR}/autogen_module)
remake_set(NUMPY_EIGEN_TEST_MODULE_PATH
  ${CMAKE_CURRENT_BINARY_DIR}/autogen_test_module)
remake_set(NUMPY_EIGEN_TYPES int float double uchar long)
remake_set(NUMPY_EIGEN_DIMS 1 2 3 4 5 6 D)

remake_set(numpy_eigen_sources
  ${NUMPY_EIGEN_MODULE_PATH}/numpy_eigen_export_module.cpp)
remake_set(numpy_eigen_test_sources
  ${NUMPY_EIGEN_TEST_MODULE_PATH}/numpy_eigen_test_module.cpp)
foreach(numpy_eigen_rows ${NUMPY_EIGEN_DIMS})
  foreach(numpy_eigen_cols ${NUMPY_EIGEN_DIMS})
    foreach(numpy_eigen_type ${NUMPY_EIGEN_TYPES})
      remake_set(numpy_eigen_source
        import_${numpy_eigen_rows}_${numpy_eigen_cols}_${numpy_eigen_type}.cpp)
      remake_list_push(numpy_eigen_sources
        ${NUMPY_EIGEN_MODULE_PATH}/${numpy_eigen_source})
        
      remake_set(numpy_eigen_test_source
        test_${numpy_eigen_rows}_${numpy_eigen_cols}_${numpy_eigen_type}.cpp)
      remake_list_push(numpy_eigen_test_sources
        ${NUMPY_EIGEN_TEST_MODULE_PATH}/${numpy_eigen_test_source})
    endforeach(numpy_eigen_type)
  endforeach(numpy_eigen_cols)
endforeach(numpy_eigen_rows)

remake_generate_custom(
  numpy-eigen
  ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/bin/create_export_module.py
  INPUT include/numpy_eigen/boost_python_headers.hpp
  SOURCES ${numpy_eigen_sources} ${numpy_eigen_test_sources}
)

remake_python()
remake_project_get(PYTHON_MODULE_DESTINATION)
remake_include(
  include
  include/numpy_eigen
  ${PYTHON_INCLUDE_DIR}
  ${Boost_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIRS}
)

remake_add_library(
  numpy_eigen PREFIX OFF
  GENERATED ${numpy_eigen_sources}
  LINK ${PYTHON_LIBRARY} ${Boost_LIBRARIES}
  INSTALL ${PYTHON_MODULE_DESTINATION}/numpy_eigen
)
remake_add_headers(RECURSE FROM include/numpy_eigen)
remake_add_scripts(bin/*.py)
remake_pkg_config_generate(REQUIRES python eigen3)

remake_add_library(
  numpy_eigen_test PREFIX OFF
  GENERATED ${numpy_eigen_test_sources}
  LINK ${PYTHON_LIBRARY} ${Boost_LIBRARIES}
  COMPONENT test
  INSTALL ${PYTHON_MODULE_DESTINATION}/numpy_eigen/test
)
remake_add_test(
  PYTHON_NOSE numpy_eigen_nose test/tests.py
  MODULE_PATH ../python
  TEST_DEPENDS numpy_eigen numpy_eigen_test
)
