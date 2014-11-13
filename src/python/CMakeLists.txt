remake_include(
  include
  ../common/include
  ../random/include
  ../timing/include
  ../boost/include
  ../eigen/include
  ../kinematics/include
  ../matrix-archive/include
  ../property-tree/include
  ../logging/include
)

remake_python_package(
  NAME sm
  DIRECTORY python/sm
)
remake_python_distribute(
  NAME schweizer-messer
  PACKAGES sm
  COMPONENT python-modules
)

remake_project_get(PYTHON_MODULE_DESTINATION)
remake_add_library(
  python lib/*.cpp
  LINK random timing kinematics matrix_archive property_tree logging
    ${Boost_LIBRARIES} ${PYTHON_LIBRARY}
  INSTALL ${PYTHON_MODULE_DESTINATION}/sm
)
remake_add_headers(RECURSE FROM include/sm)
remake_pkg_config_generate(REQUIRES schweizer-messer-common
  numpy-eigen python)
