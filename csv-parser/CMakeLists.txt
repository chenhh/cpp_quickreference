cmake_minimum_required(VERSION 3.8)
project(csv_parser_example)

set(CMAKE_CXX_STANDARD 14)

add_executable(csv_parser_hello csv_parser_hello.cpp)
target_link_libraries(csv_parser_hello pthread)
