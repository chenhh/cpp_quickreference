cmake_minimum_required(VERSION 3.8)
project(abseil_example)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(absl_string_view absl_string_view.cpp)
target_link_libraries(absl_string_view ${CONAN_LIBS})

add_executable(absl_container absl_container.cpp)
target_link_libraries(absl_container ${CONAN_LIBS})