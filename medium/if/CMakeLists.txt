# This example is about 100 lines, because if() does a great role of judgement.
# if() can judge from existance of everything to string comparison. It is
# necessary to take more time to learn than other topic. For more information,
# please refer to "cmake --help-command if"

cmake_minimum_required(VERSION 2.8)

project(if_guide)

# A simple if statement, the formal way.
set(cond1 TRUE)
if(${cond1})
	message("This is a valid if statement")
endif(${cond1}) # the end of this if statement.

# A simple if-else statement, the formal way.
set(cond2 FALSE)
if(${cond2})
	message("unreachable")
else(${cond2})
	message("This is a valid if-else statement")
endif(${cond2})

# A simple if-else statement. the informal way. Though it is a
# valid CMake script, I think it is easy confusing maintainers
# when nested if structure.
set(cond3 FALSE)
if(${cond3})
	message("unreachable")
else()
	message("This is a valid if-else statement in a lazy way")
endif()

# shows how to use elseif().
set(cond4 FALSE)
if(${cond4})
	message("unreachable")
elseif(TRUE)
	message("This is a valid if-elseif statement")
else(${cond4})
	message("unreachable")
endif(${cond4})

# Shows the synonyms and anonyms of true.
set(true_list TRUE true ON Y 1 YES)
set(false_list FALSE false N NO OFF IGNORE XXX-NOTFOUND)

# Check whether the condition is accepted by if().
foreach(loop_var ${true_list} ${false_list})
	if(${loop_var})
		message("if(${loop_var}) goes to THEN block")
	else(${loop_var})
		message("if(${loop_var}) goes to ELSE block")
	endif(${loop_var})
endforeach(loop_var)

# Boolean operations are accepted by if()
if(NOT FALSE)
	message("(NOT FALSE) is true")
endif()

if(TRUE OR FALSE)
	message("(TRUE OR FALSE) is true")
endif()

if(TRUE AND FALSE)
	message("unreachable")
else()
	message("(TRUE AND FALSE) is false")
endif()

# complex condition
if(NOT (TRUE AND NOT FALSE) OR (FALSE OR FALSE))
	message("unreachable")
else()
	message("(NOT (TRUE AND NOT FALSE) OR (FALSE OR FALSE)) is false")
endif()

# check if something exist
if(DEFINED cond1)
	message("variable cond1 is defined")
endif(DEFINED cond1)

if(EXISTS ${CMAKE_SOURCE_DIR}/CMakeLists.txt)
	message("file exists : ${CMAKE_SOURCE_DIR}/CMakeLists.txt")
endif(EXISTS ${CMAKE_SOURCE_DIR}/CMakeLists.txt)

# string comparison
if(NOT Apple STREQUAL apple)
	message("Apple is NOT STREQUAL apple")
endif(NOT Apple STREQUAL apple)

if(Banana STRLESS banana)
	message("Banana is STRLESS banana")
endif(Banana STRLESS banana)

# regular expression match
if(Candy MATCHES C?n*)
	message("Candy is MATCHES C?n*")
endif(Candy MATCHES C?n*)

# version comparison
if(2.8.4 VERSION_LESS 2.8.4.2)
	message("2.8.4 is VERSION_LESS 2.8.4.2")
endif(2.8.4 VERSION_LESS 2.8.4.2)


if(NOT(2.8.4 VERSION_EQUAL 2.8.4.2))
	message("2.8.4 is NOT VERSION_EQUAL 2.8.4.2")
endif(NOT(2.8.4 VERSION_EQUAL 2.8.4.2))

# number comparison
if(4 LESS 5)
	message("4 is LESS 5")
endif(4 LESS 5)

if(5.1 GREATER 5)
	message("5.1 is GREATER 5")
endif(5.1 GREATER 5)
