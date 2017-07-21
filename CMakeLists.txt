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
        const_example.cpp
        cpp11_thread.cpp
        weak_semaphore.cpp
        string_token.cpp
        cpp11_class.cpp
        file_io.cpp
        )

add_executable(const_example const_example.cpp)
add_executable(cpp11_thread cpp11_thread.cpp)
add_executable(weak_semaphore weak_semaphore.cpp)
add_executable(string_token  string_token.cpp)
add_executable(cpp11_class  cpp11_class.cpp)
add_executable( file_io  file_io.cpp)