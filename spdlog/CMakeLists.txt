cmake_minimum_required(VERSION 3.8)
project(sdplog_example)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(spdlog_hello spdlog_hello.cpp)
target_link_libraries(spdlog_hello ${CONAN_LIBS})
