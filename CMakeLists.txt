cmake_minimum_required(VERSION 3.8.2)
project(fancy VERSION 0.1.0)

include_directories(include)
add_executable(fancy source/main.cpp)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)
set(CMAKE_CXX_STANDARD 11)
