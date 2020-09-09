cmake_minimum_required (VERSION 3.10)

project (lru-cache LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

enable_testing()

add_subdirectory(test)
add_subdirectory(lib/googletest)
