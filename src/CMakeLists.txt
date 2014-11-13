remake_find_package(
  Boost REQUIRED
  COMPONENTS system filesystem serialization thread regex python
  RESULT_VAR Boost_FOUND
)
remake_find_package(eigen3 CONFIG)
remake_find_package(sqlite3 CONFIG)
remake_find_package(Matlab OPTIONAL)
remake_find_package(numpy-eigen CONFIG)
remake_find_package(PythonLibs)

remake_include(
  ${Boost_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIRS}
  ${NUMPY_EIGEN_INCLUDE_DIRS}
)

remake_add_directories(
  common
  COMPONENT common
)
remake_add_directories(
  random
  COMPONENT random
)
remake_add_directories(
  timing
  COMPONENT timing
)
remake_add_directories(
  boost
  COMPONENT boost
)
remake_add_directories(
  eigen
  COMPONENT eigen
)
remake_add_directories(
  kinematics
  COMPONENT kinematics
)
remake_add_directories(
  property-tree
  COMPONENT property-tree
)
remake_add_directories(
  database
  COMPONENT database
)
remake_add_directories(
  matlab
  COMPONENT matlab
  IF MATLAB_FOUND
)
remake_add_directories(
  matrix-archive
  COMPONENT matrix-archive
)
remake_add_directories(
  opencv
  COMPONENT opencv
)
remake_add_directories(
  logging
  COMPONENT logging
)
remake_add_directories(
  python
  COMPONENT python
)

remake_set(
  SCHWEIZER_MESSER_REQUIRES
  schweizer-messer-common
  schweizer-messer-random
  schweizer-messer-timing
  schweizer-messer-boost
  schweizer-messer-eigen
  schweizer-messer-kinematics
  schweizer-messer-database
  schweizer-messer-property-tree
  schweizer-messer-matrix-archive
  schweizer-messer-opencv
  schweizer-messer-logging
  schweizer-messer-python
)
if(MATLAB_FOUND)
  remake_list_push(
    SCHWEIZER_MESSER_REQUIRES
    schweizer-messer-matlab
  )
endif(MATLAB_FOUND)

remake_component(dev)
remake_pkg_config_generate(REQUIRES ${SCHWEIZER_MESSER_REQUIRES})

remake_component(test)
