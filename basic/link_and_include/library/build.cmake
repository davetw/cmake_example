# This script mainly build a library. For the usage of these command,
# I will give explanation later.

# create a directory in build directory
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# calling the shell to build library for us.
execute_process(COMMAND cmake ${CMAKE_SOURCE_DIR}/library/source
		WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

execute_process(COMMAND make
		WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
