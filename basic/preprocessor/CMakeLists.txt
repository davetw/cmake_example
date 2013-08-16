cmake_minimum_required(VERSION 2.6)
project(preprocessor_test CXX)

# equals to define FOO CMAKE_HERE in cpp file.
# Correspond to gcc -D
add_definitions(-DFOO=CMAKE_HERE)
add_executable(main.exe main.cpp)
