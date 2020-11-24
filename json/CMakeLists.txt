cmake_minimum_required(VERSION 3.8)
project(json_example)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(nlohmann_json_hello nlohmann_json_hello.cpp)
target_link_libraries(nlohmann_json_hello ${CONAN_LIBS})