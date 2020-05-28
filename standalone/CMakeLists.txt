cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(fancy_standalone
  LANGUAGES CXX
)

# ---- Dependencies ----

include(../build/cmake/CPM.cmake)

CPMAddPackage(
  NAME fancy
  SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/..
)

# ---- Create standalone executable ----

file(GLOB sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)

add_executable(fancy_standalone ${sources})

set_target_properties(fancy_standalone PROPERTIES
  CXX_STANDARD 11
  OUTPUT_NAME "run"
)

target_link_libraries(fancy_standalone fancy)
