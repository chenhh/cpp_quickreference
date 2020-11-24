cmake_minimum_required(VERSION 3.8)
project(cpp_util_example)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1)

add_library(mylib SHARED hello.cpp world.cpp)
add_executable(main main.cpp)
target_link_libraries(main mylib)
