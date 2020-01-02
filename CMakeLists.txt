cmake_minimum_required(VERSION 3.8)
project(cpp_quickreference)

# cpp11 standard
set(CMAKE_CXX_STANDARD 11)

add_executable(main1 main1.cpp)
add_executable(strategy_pattern strategy_pattern.cpp)
add_executable(boost_version boost_version.cpp)
add_executable(boost_datetime boost_datetime.cpp)

FIND_PACKAGE(OpenMP REQUIRED)
if(OPENMP_FOUND)
    set(CMAKE_CXX_FLAGS "${OpenMP_CXX_FLAGS}")
endif()
add_executable(omp_hello omp_hello.cpp)
