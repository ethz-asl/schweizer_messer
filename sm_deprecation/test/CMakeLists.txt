macro(compile_and_require_output FILE EXPECT IGNORE)
  try_compile(COMPILE_SUCCEEDED
              "${CMAKE_CURRENT_BINARY_DIR}"
              "${CMAKE_CURRENT_SOURCE_DIR}/${FILE}"
              COMPILE_DEFINITIONS "${CMAKE_CXX_FLAGS} -Wall -I${CMAKE_CURRENT_SOURCE_DIR}/../include"
              CMAKE_FLAGS "-DCMAKE_CXX_LINK_EXECUTABLE='echo not linking now...'"
              OUTPUT_VARIABLE OUTPUT)
  if (NOT "${OUTPUT}" MATCHES "${EXPECT}" AND NOT "${OUTPUT}" MATCHES "${IGNORE}")
    message( FATAL_ERROR "Output when compiling ${FILE} did not match expected ${EXPECT}. OUTPUT: ${OUTPUT}" )
  endif ()
endmacro()

if(CPP14_SUPPORTED)
  MESSAGE(STATUS "Testing c++14 behavior")
  set(CMAKE_CXX_FLAGS "-std=c++14")
  compile_and_require_output(test_deprecation.cpp "DEP_TEST_MESSAGE" "SM_DEPRECATION_NOT_SUPPORTED")
endif()

MESSAGE(STATUS "Testing c++11 behavior")
set(CMAKE_CXX_FLAGS "-std=c++11")
compile_and_require_output(test_deprecation.cpp "warning.*foo.*deprecated" "SM_DEPRECATION_NOT_SUPPORTED")
