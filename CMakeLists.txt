cmake_minimum_required(VERSION 3.8)
project(cpp_quickreference)

# cpp11 standard
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        .idea/codeStyleSettings.xml
        .idea/cpp_quickreference.iml
        .idea/misc.xml
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        main.cpp
        )
add_executable(main main.cpp)

# gmp
find_path(GMP_INCLUDE_DIR NAMES gmp.h)
find_library(GMP_LIBRARY NAMES gmp libgmp)
find_library(GMPXX_LIBRARIES NAMES gmpxx libgmpxx)
target_link_libraries(main gmp gmpxx)