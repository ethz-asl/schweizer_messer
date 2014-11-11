cmake_minimum_required(VERSION 2.6)

include(ReMake)

remake_project(
  numpy-eigen
  VERSION 0.0.1
  RELEASE alpha
  SUMMARY "Numerical Python bindings for linear algebra."
  AUTHOR "Paul Furgale"
  AUTHOR "Simon Lynen"
  CONTACT "paul.furgale@mavt.ethz.ch"
  HOME "http://github.com/ethz-asl/Schweizer-Messer/tree/master/numpy_eigen"
  LICENSE "Revised BSD License (New BSD)"
  INSTALL /usr
  HEADER_DESTINATION include/numpy_eigen
  PREFIX numpy_eigen_
)

remake_add_directories(
  python
)
remake_doc(
  html
)

remake_pack_deb(
  EXTRA_COMPONENTS python
  DEPENDS python-numpy python2.7-dev libboost-python[0-9.]*
)
remake_pack_deb(
  COMPONENT test
  EXTRA_COMPONENTS test-python
  DEPENDS numpy-eigen
  DESCRIPTION "testing"
)
remake_pack_deb(
  COMPONENT dev
  DEPENDS numpy-eigen-python libboost-python-dev libeigen3-dev
  DESCRIPTION "development headers"
)
remake_pack_deb(
  ARCH all
  COMPONENT doc
  DESCRIPTION "documentation"
)

remake_distribute_deb(
  DISTRIBUTION precise
  SECTION python
  UPLOAD ppa:kralf/asl
  DEPENDS python2.7-dev libboost-python-dev libeigen3-dev python-numpy
    python-nose remake pkg-config doxygen
  PASS CMAKE_BUILD_TYPE NUMPY_EIGEN_GIT_REVISION
)
remake_distribute_deb(
  DISTRIBUTION trusty
  SECTION python
  UPLOAD ppa:kralf/asl
  DEPENDS python2.7-dev libboost-python-dev libeigen3-dev python-numpy
    python-nose remake pkg-config doxygen
  PASS CMAKE_BUILD_TYPE NUMPY_EIGEN_GIT_REVISION
)
