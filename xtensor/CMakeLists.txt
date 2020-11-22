cmake_minimum_required(VERSION 3.8)
project(xtensor_example)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(xtensor_hello xtensor_hello.cpp)
target_link_libraries(xtensor_hello ${CONAN_LIBS})