cmake_minimum_required(VERSION 3.8)
project(pprint_example)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(pprint_hello pprint_hello.cpp)
target_link_libraries(pprint_hello ${CONAN_LIBS})
