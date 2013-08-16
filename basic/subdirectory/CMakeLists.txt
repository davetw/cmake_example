cmake_minimum_required(VERSION 2.8)

# a project foo using language c++
project(foo CXX)


# runs CMakeLists.txt under sub-directories with their own variable scope.
# sub1 & sub2 are directories.
add_subdirectory(sub1)
add_subdirectory(sub2)

# collect sources from current directory.
file(GLOB SRC *.cpp)
add_executable(main.exe ${SRC})

# link executable with 2 static libraries, which is defined in subdirectories.
# Just like gcc -lxxx
target_link_libraries(main.exe sub1_lib sub2_lib)
