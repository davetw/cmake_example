# This script mainly build a library. For the usage of these command,
# I will give explanation later.

# create a directory in build directory
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# calling the shell to build library for us.
# NOTE that I am going to build library in configure stage of main.exe
execute_process(COMMAND cmake ${CMAKE_SOURCE_DIR}/library/source
		WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

execute_process(COMMAND make
		WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
