cmake_minimum_required(VERSION 2.6)

include(ReMake)

remake_project(
  schweizer-messer
  VERSION 0.0.1
  RELEASE alpha
  SUMMARY "Swiss knife programming tools for robotics."
  AUTHOR "Paul Furgale"
  AUTHOR "Simon Lynen"
  AUTHOR "Ulrich Schwesinger"
  CONTACT "paul.furgale@mavt.ethz.ch"
  HOME "http://github.com/ethz-asl/Schweizer-Messer"
  LICENSE "Revised BSD License (New BSD)"
  README README.md
  PREFIX sm_
  EXTRA_CXX_FLAGS -std=c++0x
  INSTALL /usr
  HEADER_DESTINATION include/sm
)

remake_doc(
  html
)

remake_pack_deb(
  COMPONENT common
  DEPENDS "libboost-system[0-9.]*"
  DESCRIPTION "common"
)
remake_pack_deb(
  COMPONENT common-test
  DEPENDS schweizer-messer-common
  DESCRIPTION "common testing"
)
remake_pack_deb(
  COMPONENT common-dev
  DEPENDS schweizer-messer-common libboost-system-dev
  DESCRIPTION "common development headers"
)

remake_pack_deb(
  COMPONENT random
  DEPENDS schweizer-messer-common
  DESCRIPTION "random"
)
remake_pack_deb(
  COMPONENT random-dev
  DEPENDS schweizer-messer-random schweizer-messer-common-dev
  DESCRIPTION "random development headers"
)

remake_pack_deb(
  COMPONENT timing
  DEPENDS schweizer-messer-common
  DESCRIPTION "timing"
)
remake_pack_deb(
  COMPONENT timing-test
  DEPENDS schweizer-messer-timing schweizer-messer-random
  DESCRIPTION "timing testing"
)
remake_pack_deb(
  COMPONENT timing-dev
  DEPENDS schweizer-messer-timing schweizer-messer-common-dev
  DESCRIPTION "timing development headers"
)

remake_pack_deb(
  COMPONENT boost
  DEPENDS schweizer-messer-common libboost-serialization[0-9.]*
    libboost-thread[0-9.]*
  DESCRIPTION "Boost"
)
remake_pack_deb(
  COMPONENT boost-test
  DEPENDS schweizer-messer-boost
  DESCRIPTION "Boost testing"
)
remake_pack_deb(
  COMPONENT boost-dev
  DEPENDS schweizer-messer-boost schweizer-messer-common-dev
    libboost-serialization-dev libboost-thread-dev
  DESCRIPTION "Boost development headers"
)

remake_pack_deb(
  COMPONENT eigen
  DEPENDS schweizer-messer-random libboost-serialization[0-9.]*
  DESCRIPTION "linear algebra"
)
remake_pack_deb(
  COMPONENT eigen-test
  DEPENDS schweizer-messer-eigen
  DESCRIPTION "linear algebra testing"
)
remake_pack_deb(
  COMPONENT eigen-dev
  DEPENDS schweizer-messer-eigen schweizer-messer-random-dev
    libeigen3-dev libboost-serialization-dev
  DESCRIPTION "linear algebra development headers"
)

remake_pack_deb(
  COMPONENT kinematics
  DEPENDS schweizer-messer-common schweizer-messer-random
    schweizer-messer-boost schweizer-messer-eigen
    libboost-filesystem[0-9.]*
  DESCRIPTION "kinematics"
)
remake_pack_deb(
  COMPONENT kinematics-test
  DEPENDS schweizer-messer-kinematics schweizer-messer-random
  DESCRIPTION "kinematics testing"
)
remake_pack_deb(
  COMPONENT kinematics-dev
  DEPENDS schweizer-messer-kinematics schweizer-messer-common-dev
    schweizer-messer-random-dev schweizer-messer-boost-dev
    schweizer-messer-eigen-dev libboost-filesystem-dev
  DESCRIPTION "kinematics development headers"
)

remake_pack_deb(
  COMPONENT database
  DEPENDS schweizer-messer-common libsqlite3-0
    libboost-serialization[0-9.]* libboost-filesystem[0-9.]*
  DESCRIPTION "database"
)
remake_pack_deb(
  COMPONENT database-test
  DEPENDS schweizer-messer-database schweizer-messer-boost
  DESCRIPTION "database testing"
)
remake_pack_deb(
  COMPONENT database-dev
  DEPENDS schweizer-messer-database schweizer-messer-common-dev
    libsqlite3-dev libboost-serialization-dev libboost-filesystem-dev
  DESCRIPTION "database development headers"
)

remake_pack_deb(
  COMPONENT property-tree
  DEPENDS schweizer-messer-common libboost-filesystem[0-9.]*
  DESCRIPTION "property tree"
)
remake_pack_deb(
  COMPONENT property-tree-test
  DEPENDS schweizer-messer-property-tree
  DESCRIPTION "property tree testing"
)
remake_pack_deb(
  COMPONENT property-tree-dev
  DEPENDS schweizer-messer-property-tree schweizer-messer-common-dev
    libboost-filesystem-dev
  DESCRIPTION "property tree development headers"
)

if(MATLAB_FOUND)
  remake_pack_deb(
    COMPONENT matlab
    DEPENDS schweizer-messer-common
    DESCRIPTION "Matlab"
  )
  remake_pack_deb(
    COMPONENT matlab-test
    DEPENDS schweizer-messer-matlab
    DESCRIPTION "Matlab testing"
  )
  remake_pack_deb(
    COMPONENT matlab-dev
    DEPENDS schweizer-messer-matlab schweizer-messer-common-dev
    DESCRIPTION "Matlab development headers"
  )
endif(MATLAB_FOUND)

remake_pack_deb(
  COMPONENT matrix-archive
  DEPENDS schweizer-messer-common libboost-filesystem[0-9.]*
  DESCRIPTION "matrix archive"
)
remake_pack_deb(
  COMPONENT matrix-archive-test
  DEPENDS schweizer-messer-matrix-archive
  DESCRIPTION "matrix archive testing"
)
remake_pack_deb(
  COMPONENT matrix-archive-dev
  DEPENDS schweizer-messer-matrix-archive schweizer-messer-common-dev
    libboost-filesystem-dev
  DESCRIPTION "matrix archive development headers"
)

remake_pack_deb(
  COMPONENT opencv-dev
  DEPENDS schweizer-messer-common-dev libopencv-dev
  DESCRIPTION "computer vision development headers"
)

remake_pack_deb(
  COMPONENT logging
  DEPENDS schweizer-messer-common libboost-system[0-9.]*
    libboost-regex[0-9.]*
  DESCRIPTION "logging"
)
remake_pack_deb(
  COMPONENT logging-test
  DEPENDS schweizer-messer-logging
  DESCRIPTION "logging testing"
)
remake_pack_deb(
  COMPONENT logging-dev
  DEPENDS schweizer-messer-logging schweizer-messer-common-dev
    libboost-system-dev libboost-regex-dev
  DESCRIPTION "logging development headers"
)

remake_pack_deb(
  COMPONENT python
  EXTRA_COMPONENTS python-modules
  DEPENDS schweizer-messer-common schweizer-messer-random
    schweizer-messer-timing schweizer-messer-kinematics
    schweizer-messer-matrix-archive schweizer-messer-property-tree 
    schweizer-messer-logging libboost-serialization[0-9.]*
    libboost-python[0-9.]* numpy-eigen
  DESCRIPTION "Python bindings"
)
remake_pack_deb(
  COMPONENT python-dev
  DEPENDS schweizer-messer-python schweizer-messer-common-dev
    libboost-serialization-dev libboost-python-dev numpy-eigen-dev
  DESCRIPTION "Python development headers"
)

remake_set(
  SCHWEIZER_MESSER_PACKAGES
  schweizer-messer-common
  schweizer-messer-random
  schweizer-messer-timing
  schweizer-messer-boost
  schweizer-messer-eigen
  schweizer-messer-kinematics
  schweizer-messer-database
  schweizer-messer-property-tree
  schweizer-messer-matrix-archive
  schweizer-messer-logging
  schweizer-messer-python
)
remake_set(
  SCHWEIZER_MESSER_TEST_PACKAGES
  schweizer-messer-common-test
  schweizer-messer-timing-test
  schweizer-messer-boost-test
  schweizer-messer-eigen-test
  schweizer-messer-kinematics-test
  schweizer-messer-database-test
  schweizer-messer-property-tree-test
  schweizer-messer-matrix-archive-test
  schweizer-messer-logging-test
)
remake_set(
  SCHWEIZER_MESSER_DEV_PACKAGES
  schweizer-messer-common-dev
  schweizer-messer-random-dev
  schweizer-messer-timing-dev
  schweizer-messer-boost-dev
  schweizer-messer-eigen-dev
  schweizer-messer-kinematics-dev
  schweizer-messer-database-dev
  schweizer-messer-property-tree-dev
  schweizer-messer-matrix-archive-dev
  schweizer-messer-opencv-dev
  schweizer-messer-logging-dev
  schweizer-messer-python-dev
)
if(MATLAB_FOUND)
  remake_list_push(
    SCHWEIZER_MESSER_PACKAGES
    schweizer-messer-matlab
  )
  remake_list_push(
    SCHWEIZER_MESSER_TEST_PACKAGES
    schweizer-messer-matlab-test
  )
  remake_list_push(
    SCHWEIZER_MESSER_DEV_PACKAGES
    schweizer-messer-matlab-dev
  )
endif(MATLAB_FOUND)

remake_pack_deb(
  DEPENDS ${SCHWEIZER_MESSER_PACKAGES}
)
remake_pack_deb(
  COMPONENT test
  DEPENDS ${SCHWEIZER_MESSER_TEST_PACKAGES}
  DESCRIPTION "testing"
)
remake_pack_deb(
  COMPONENT dev
  DEPENDS ${SCHWEIZER_MESSER_DEV_PACKAGES}
  DESCRIPTION "development headers"
)
remake_pack_deb(
  ARCH ALL
  COMPONENT doc
  DESCRIPTION "documentation"
)

remake_distribute_deb(
  DISTRIBUTION precise
  SECTION libs
  UPLOAD ppa:kralf/asl
  DEPENDS python2.7-dev libboost-system-dev libboost-serialization-dev
    libboost-thread-dev libboost-filesystem-dev libboost-regex-dev
    libboost-python-dev libeigen3-dev libsqlite3-dev libopencv-dev
    numpy-eigen-dev libgtest-dev remake pkg-config doxygen
  PASS CMAKE_BUILD_TYPE SCHWEIZER_MESSER_GIT_REVISION
)
remake_distribute_deb(
  DISTRIBUTION trusty
  SECTION libs
  UPLOAD ppa:kralf/asl
  DEPENDS python2.7-dev libboost-system-dev libboost-serialization-dev
    libboost-thread-dev libboost-filesystem-dev libboost-regex-dev
    libboost-python-dev libeigen3-dev libsqlite3-dev libopencv-dev
    numpy-eigen-dev libgtest-dev remake pkg-config doxygen
  PASS CMAKE_BUILD_TYPE SCHWEIZER_MESSER_GIT_REVISION
)
