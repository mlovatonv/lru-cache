cmake_minimum_required (VERSION 3.10)

include(GoogleTest)

set(SOURCE_FILES 
  lrucache-tests.cpp
)

add_executable(tests
  ${SOURCE_FILES}
)

target_include_directories(tests
  PUBLIC 
    ../src
    ../lib/googletest/googletest/include
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

target_link_libraries(tests
  PUBLIC 
    gtest
    gtest_main
)

gtest_discover_tests(tests)
