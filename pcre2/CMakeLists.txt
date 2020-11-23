cmake_minimum_required(VERSION 3.8)
project(pcre2_example)

set(CMAKE_CXX_STANDARD 14)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(pcre2_hello pcre2_hello.cpp)
target_link_libraries(pcre2_hello ${CONAN_LIBS})
