cmake_minimum_required (VERSION 3.10)

set(SOURCE_FILES 
  lrucache.cpp
)

add_executable(lrucache
  ${SOURCE_FILES}
)

set_target_properties(lrucache
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
