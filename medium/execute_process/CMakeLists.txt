# This example shows how to execute external commands.

cmake_minimum_required(VERSION 2.8)

function(find_shell_command_and_run com arg)
	# Unset variable to make sure ${COM} is undefined or find_program would
	# fail. 
	unset(COM CACHE)
	# Check whether program exists before execute.
	find_program(COM ${com})
	if(${COM} STREQUAL COM-NOTFOUND)
		message(FATAL_ERROR "finds no ${com} command in your shell")
	else()
	# execute a command of shell, and direct output to a variable.
	# Of course, you can choose not to direct result.
	# OUTPUT_STRIP_TRAILING_WHITESPACE removes redundant whitespaces or \n
		execute_process(COMMAND ${COM} ${arg}
				OUTPUT_VARIABLE com_out
				OUTPUT_STRIP_TRAILING_WHITESPACE)
		message("${COM} ${arg} : \n\t" "${com_out}")
	endif()
endfunction(find_shell_command_and_run)

find_shell_command_and_run(pwd "")
find_shell_command_and_run(date -u)

# You can use ${CMAKE_COMMAND} to replace  cmake here.
# CMAKE_COMMAND is a builtin variable which represents cmake itself in full
# path name. find_program(${CMAKE_COMMAND}) is meanless.
find_shell_command_and_run(cmake --version)
