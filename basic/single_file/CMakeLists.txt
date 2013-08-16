# first item is the project name and the second one is language.used in project.
project(hello_world_single CXX)

# compile a executable named exe from hello_world.cpp.
# CMake automatically choose a compiler for you.
add_executable(main.exe hello_world.cpp)
