cmake_minimum_required(VERSION 3.1)
project(sm_value_store)

find_package(catkin_simple REQUIRED)

set(CMAKE_CXX_STANDARD 17)

catkin_simple()

cs_add_library(${PROJECT_NAME}
  src/ValueStore.cpp
  src/VerboseValueStore.cpp
  src/PrefixedValueStore.cpp
  src/PropertyTreeValueStore.cpp
)

cs_install()
cs_export()

if(CATKIN_ENABLE_TESTING)
  catkin_add_gtest(${PROJECT_NAME}-test
    test/test_main.cpp
    test/ValueStore.cpp
  )
  if(TARGET ${PROJECT_NAME}-test)
    target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
  endif()
endif()
