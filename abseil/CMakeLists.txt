cmake_minimum_required(VERSION 3.8)
project(abseil_example)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(string_view string_view.cpp)
target_link_libraries(string_view ${CONAN_LIBS})