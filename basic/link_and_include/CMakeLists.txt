# We may want to link third-party libraries to our project. This
# script shows how to link and include other libraries.

cmake_minimum_required(VERSION 2.8)
project(link_and_include CXX)


# We must have a 3rd-party library first.
# You can skip reading this script, some commands beyonds the scope
# of beginners.
include(library/build.cmake)

# Defines which directory to find the included sources.
# Corresponding to gcc -I
include_directories("library/include")

# Defines which directory to find the libs.
# Corresponding to gcc -L
link_directories(${CMAKE_BINARY_DIR}/lib)

# compile main.cpp into main.exe.
add_executable(main.exe main.cpp)

# Define the name of libraries. In this instance, exe needs dynamic
# library named external_lib.
# Corresponding to gcc -l
target_link_libraries(main.exe external_lib)
