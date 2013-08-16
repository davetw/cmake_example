cmake_minimum_required(VERSION 2.8)

project(external_lib CXX)

include_directories("../include")
file(GLOB SRC *.cpp)
# create a dynamic library
add_library(external_lib SHARED ${SRC})
