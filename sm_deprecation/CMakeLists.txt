cmake_minimum_required(VERSION 2.8.3)
project(sm_deprecation)

find_package(catkin_simple REQUIRED)
catkin_simple()

set(CPP14_SUPPORTED OFF)

MESSAGE(STATUS "Using ${CMAKE_CXX_COMPILER_ID} compiler with version ${CMAKE_CXX_COMPILER_VERSION}.")

# Most versions are taken from : http://en.cppreference.com/w/cpp/compiler_support

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  # using Clang
  if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "3.3")
    message(FATAL_ERROR "Your clang compiler has version ${CMAKE_CXX_COMPILER_VERSION}, while version 3.3 or later is required")
  endif ()
  if (NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS "3.5") # 3.4 supports c++14 but with the --std=c++1y flag.
    set(CPP14_SUPPORTED ON)
  endif ()
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
  # using AppleClang
  if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "5.1")
    message(FATAL_ERROR "Your XCode environment has version ${CMAKE_CXX_COMPILER_VERSION}, while version 5.1 or later is required")
  endif ()
  if (NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS "5.2") # TODO replace this guesswork with a correct number
    set(CPP14_SUPPORTED ON)
  endif ()
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  # using GCC
  if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "4.8.2")
    message(FATAL_ERROR "Your g++ compiler has version ${CMAKE_CXX_COMPILER_VERSION}, while version 4.8.2 or later is required")
  endif ()
  if (NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS "4.9")
    set(CPP14_SUPPORTED ON)
  endif ()
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  # using MSVC
  if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "19.0.23506")
    message(FATAL_ERROR "Your Microsoft Visual C++ compiler has version ${CMAKE_CXX_COMPILER_VERSION}, while version MSVC 2015 Update 1+ is required")
  endif ()
  if (NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS "19.1") # TODO replace this guesswork with a correct number
    set(CPP14_SUPPORTED ON)
  endif ()
endif ()

if(CPP14_SUPPORTED)
  MESSAGE(STATUS "Found compiler with c++14 support! Going to test std c++14 deprecation!")
endif()

add_subdirectory(test)

cs_install()
cs_export()
