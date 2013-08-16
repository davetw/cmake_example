# This is a frequently used command. you should check CMake manual.
# Please remember that command syntax keeps the same for all find_XXX
# commands, although I use different syntax for each find_XXX command.
# "cmake --help-command find_XXXX |less" for more detail.

# find_XXX(OUT_VAR key_word) store to OUT_VAR as CACHE. Beware if you
# are using it in functions. CACHE variables is globally visible.
# I am sorry for that there is no documents about cache variable.

cmake_minimum_required(VERSION 2.8)

# Search vim on your system, if finds no vim, try finding vi instead.
# Store the result to VI.
find_program(VI vim NAMES vi)

# If finds no program the content of variable would be ${VAR}-NOTFOUND.
if(${VI} STREQUAL VI-NOTFOUND)
	message("finds no vi")
else()
	message("vi : " ${VI})
endif()

# I want to find hosts file now. Set up possible directory for various OS.
file(TO_CMAKE_PATH W_path $ENV{SystemRoot})
set(hosts_path /etc ${W_path}/system32/drivers/etc)

# find command finds things according to priority of
# HINTS > CMake Default > PATHS. On condition HINTS and PATHS are
# undefined, then CMake search CMake default paths.
find_file(HOSTS hosts PATHS ${hosts_path})
message("Find hosts as : " ${HOSTS} )

# These two command are used in the same way as find_file() or find_program().
# find_path()
# find_library()
