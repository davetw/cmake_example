cmake_minimum_required(VERSION 2.8)

project(Wuthering_Heights)

# Put the content of "read_from" to p0
file(READ read_from p0)
message(${p0})

# Put the content of part* to p*
file(READ Wuthering_Heights/ch1/part1 p1)
file(READ Wuthering_Heights/ch1/part2 p2)

# Create a directory under binary directory
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/ch1 )

# Write p1 to file1. If file1 exist, overwrite the content of file1
file(WRITE ${CMAKE_BINARY_DIR}/ch1/file1 ${p1})

# Append p2 to file1. If file1 exist, write the content at
# buttom of file1. If file1 does not exist, then create file1.
file(APPEND ${CMAKE_BINARY_DIR}/ch1/file1 ${p2})

# GLOB syntax :
# (Quote from offical ducument)
#          *.cxx      - match all files with extension cxx
#          *.vt?      - match all files with extension vta,...,vtz
#          f[3-5].txt - match files f3.txt, f4.txt, f5.txt

# Find all the file names which match part? under
# Wuthering_Heights directory.
file(GLOB_RECURSE p3 Wuthering_Heights part?)

# The finding result is separated by semicolon, I want it being
# separated by \n. Note that double quotes beside by ${p3} is
# necessary, because string(REPLACE) would concatenate members
# of a list, which means ignoring semicolon.
string(REPLACE ";" "\n" p3 "${p3}")
message("file(GLOB_RECURSE part?) =\n" ${p3})
