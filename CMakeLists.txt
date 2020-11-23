cmake_minimum_required(VERSION 3.8)
project(cpp_quickreference)

# boost example
add_subdirectory(boost)
add_subdirectory(fmt)
add_subdirectory(xtensor)
add_subdirectory(openmp)
add_subdirectory(design_pattern)
add_subdirectory(spdlog)
add_subdirectory(pprint)
add_subdirectory(csv-parser)
add_subdirectory(cpp_util)
add_subdirectory(pcre2)
# cpp11 standard
#set(CMAKE_CXX_STANDARD 14)

#add_executable(main1 main1.cpp)
#add_executable(strategy_pattern design_pattern/strategy_pattern.cpp)
#add_executable(boost_version boost/boost_version.cpp)
#add_executable(boost_datetime boost/boost_datetime.cpp)
#
#find_package(fmt)
#add_executable(fmt_hello fmt/fmt_hello.cpp)
#target_link_libraries(fmt_hello fmt::fmt)
#
#find_package(gsl)
#add_executable(gsl_hello gsl/gsl_hello.cpp)
## the gslcblas can be replaced to other blas library.
## e.g. altas, openblas, mkl
#target_link_libraries(gsl_hello gsl gslcblas)
#
#
#FIND_PACKAGE(OpenMP REQUIRED)
#if (OPENMP_FOUND)
#    set(CMAKE_CXX_FLAGS "${OpenMP_CXX_FLAGS}")
#    add_executable(omp_hello openmp/omp_hello.cpp)
#endif ()

#find_package(xtensor REQUIRED)
#target_include_directories(xtensor_hello PUBLIC ${xtensor_INCLUDE_DIRS})
#INCLUDE_DIRECTORIES(/usr/local/include)

#INCLUDE_DIRECTORIES(C:/msys64/usr/local/include)
#set(CMAKE_REQUIRED_INCLUDES /usr/local/include/xtl  /usr/local/include/xtensor)
#get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
#foreach(dir ${dirs})
#    message(STATUS "dir='${dir}'")
#endforeach()
#LINK_DIRECTORIES(/usr/local/lib)
#add_executable(xtensor_hello xtensor/xtensor_hello.cpp)
#target_link_libraries(xtensor_hello fmt::fmt)
#target_link_libraries(xtensor_hello PUBLIC xtensor)