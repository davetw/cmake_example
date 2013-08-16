cmake_minimum_required(VERSION 2.8)

# Simple assignment
set(var1 apple)
message("simple assignment")
message("\tset(var1 apple)")
message("\tvar1 = " var1)
message("\t$" "{var1} = " ${var1})
message("")

# CMake is case-sensitive to variable, but command is case-insensitive.
SET(VAR1 APPLE)
message("case sensitivity")
message("\tSET(VAR1 APPLE)")
message("\t$" "{VAR1} = " ${VAR1})
message("\t$" "{var1} = " ${var1})
message("")

# The variable can hide in another variable.
set(var2 var3)
set(var3 orange)
message("a variable in a variable")
message("\tset(var2 var3)")
message("\tset(var3 orange)")
message("\t$" "{var2} = " ${VAR2})
message("\t$" "{$" "{var2}} = " ${${var2}})
message("")

# Access to envirnment variable. read-only.
message("print $PATH")
message(\t$ENV{PATH})
message("")

# Some built-in variables. For more info, please refer to :
# http://www.cmake.org/Wiki/CMake_Useful_Variables
message("print some built-in variables")
message("\tbinary directory = " ${CMAKE_BINARY_DIR})
message("\tsource directory = " ${CMAKE_SOURCE_DIR})
message("")
message("the variable below have not been setted, but you can set it if needed")
message("\tbuild type = " ${CMAKE_BUILD_TYPE})
message("\tc++ compiler = " ${CMAKE_CXX_COMPILER})
message("\tc++ compiler flags = " ${CMAKE_CXX_FLAGS})
message("")

# The list in CMake is a string with semicolon to separate members.
message("list operations")
set(vec1 item1 item0 item2) # item1 is before item0
message("\tvec1 = ${vec1}")
message("")

message("\tappend vec1 using set()")
set(vec1 ${vec1} item3)
message("\tvec1 = ${vec1}")
message("")

message("\tappend vec1 using list(APPEND)")
list(APPEND vec1 item4)
message("\tvec1 = ${vec1}")
message("")

list(GET vec1 3 out)
message("\tmember 3 of vec1 = " ${out})
message("")

list(LENGTH vec1 out2)
message("\tlength of vec1 = " ${out2})
message("")

list(FIND vec1 "item4" out3)
message("\tfind item4 of vec1 = " ${out3})
list(FIND vec1 "item6" out4)
message("\tfind item6 of vec1 = " ${out4})
message("")

list(SORT vec1)
message("\tsort(vec1) = ${vec1}")
