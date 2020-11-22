cmake_minimum_required(VERSION 3.8)
project(boost_example)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(boost_version boost_version.cpp)
target_link_libraries(boost_version ${CONAN_LIBS})

add_executable(boost_datetime boost_datetime.cpp)
target_link_libraries(boost_datetime ${CONAN_LIBS})