cmake_minimum_required(VERSION 3.8)
project(omp_example)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_FLAGS "${OpenMP_CXX_FLAGS}")
add_executable(omp_hello omp_hello.cpp)
target_link_libraries(omp_hello ${CONAN_LIBS})
