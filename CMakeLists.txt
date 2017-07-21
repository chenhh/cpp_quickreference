cmake_minimum_required(VERSION 3.8)
project(cpp_quickreference)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        .idea/codeStyleSettings.xml
        .idea/cpp_quickreference.iml
        .idea/misc.xml
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        const_example.cpp)

add_executable(const_example const_example.cpp)
