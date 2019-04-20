cmake_minimum_required(VERSION 2.8.3)
project(sm_value_store)

find_package(catkin_simple REQUIRED)

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
