cmake_minimum_required(VERSION 3.8)
project(cpp_lib_example)

set(CMAKE_CXX_STANDARD 14)

if (MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1)
endif (MSVC)

add_library(mylib_dll MODULE hello.cpp world.cpp)
add_executable(main_dll main.cpp)
#target_link_libraries(main_dll mylib_dll)
