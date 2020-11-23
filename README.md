# cpp_quickreference
c++常用函式庫的範例

# Linux:
- mkdir build && cd build
- conan install .. --pr=\<profile\>
- cmake ..
- make -j4

# library
- 函式庫以conan管理
- 如果conan中不存在函式庫時，linux中將函式庫安裝在/opt/cpplib中, windows將函式庫安裝在d:\cpplib中。