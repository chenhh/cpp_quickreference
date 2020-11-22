cmake_minimum_required(VERSION 3.8)
project(fmt_example)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(fmt_hello fmt_hello.cpp)
target_link_libraries(fmt_hello ${CONAN_LIBS})