remake_python_package(
  NAME numpy_eigen
  DIRECTORY numpy_eigen
)
remake_python_distribute(PACKAGES numpy_eigen)

remake_python_package(
  NAME numpy_eigen.test
  DIRECTORY numpy_eigen/test
)
remake_python_distribute(
  NAME numpy-eigen-test
  PACKAGES numpy_eigen.test
  COMPONENT test-python
)
