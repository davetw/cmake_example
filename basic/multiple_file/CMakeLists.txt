project(hello_world_multi CXX)

# Collect files with cpp suffix to SRC.
# Note that GLOB is not regular expression, but a more simpler one.
# supports * ? [3-5]
file(GLOB SRC *.cpp)

# ${SRC} is a list of sources.
# In this instance, ${SRC} = foo.cpp;bar.cpp
add_executable(main.exe ${SRC})
