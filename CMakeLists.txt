cmake_minimum_required(VERSION 3.8)
project(cpp_quickreference)

# cpp11 standard
set(CMAKE_CXX_STANDARD 14)

add_executable(main1 main1.cpp)
add_executable(strategy_pattern strategy_pattern.cpp)
add_executable(boost_version boost_version.cpp)
add_executable(boost_datetime boost_datetime.cpp)

find_package(fmt)
add_executable(fmt_hello fmt_hello.cpp)
target_link_libraries(fmt_hello fmt::fmt)

find_package(gsl)
add_executable(gsl_hello gsl_hello.cpp)
target_link_libraries(gsl_hello gsl)


FIND_PACKAGE(OpenMP REQUIRED)
if(OPENMP_FOUND)
    set(CMAKE_CXX_FLAGS "${OpenMP_CXX_FLAGS}")
    add_executable(omp_hello omp_hello.cpp)
endif()

