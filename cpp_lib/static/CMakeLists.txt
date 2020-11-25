cmake_minimum_required(VERSION 3.8)
project(cpp_lib_example)

set(CMAKE_CXX_STANDARD 14)

add_library(mylib_static STATIC hello.cpp world.cpp)
add_executable(main_static main.cpp)
target_link_libraries(main_static mylib_static)
