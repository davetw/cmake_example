# It may take a lot of effort to import a library, because each library
# has it's own way to treat source code. I highly recommend to check
# CMake manual for FindQT4. 
# cmake --help-command find_package | less
# cmake --help-module FindQt4 | less

# This example uses QT4 as library, and mainly refer to websites below
# http://www.cmake.org/Wiki/CMake:How_To_Find_Libraries
# http://qt-project.org/quarterly/view/using_cmake_to_build_qt_projects

# The first arg is library name, second arg is minimum version.
# The third arg means CMake would abort when the assigned lib is not found.

cmake_minimum_required(VERSION 2.8)
project(qt_example)

# Actually, This command finds FindXXX.cmake script. If package is
# found, runs script to set up necessary variables for you.
# Note that not every package can be found in this way. You must have
# CMake builtin or external FindXXX scripts on your system.
find_package(Qt4 4.4.3 REQUIRED)
if(NOT ${Qt4_FOUND})
    message(FATAL_ERROR "Finds no Qt4!")
endif(NOT ${Qt4_FOUND})

file(GLOB SRC *.cpp)
file(GLOB HEADERS *.h)

# This sets up the compilation environment. including definations,
# include_dirs and libraries_dirs.
include(${QT_USE_FILE})

# QT4_WRAP_CPP() implements meta-object features for headers which
# contains Q_OBJECT macro. For more detail, please refer to:
# http://harmattan-dev.nokia.com/docs/library/html/qt4/metaobjects.html
QT4_WRAP_CPP(HEADER_MOCS ${HEADERS})

# Executable should also include mocs.
add_executable(main.exe ${SRC} ${HEADER_MOCS})

# Link executable to qt libraries.
target_link_libraries(main.exe ${QT_LIBRARIES})
