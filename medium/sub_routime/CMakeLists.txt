cmake_minimum_required(VERSION 2.8)

# To include another cmake scripts.
include(included.cmake)

# Function can view parent's variable scope, but changes made
# here DOES NOT effect parent runtine. Define FCT_NAME() here.
set(fct_var invisible)
function(FCT_NAME arg1 arg2)
	set(fct_var visible)
	message("here is the function")
	message("\targ1 : " ${arg1})
	message("\targ2 : " ${arg2})
endfunction(FCT_NAME)

# Make a function call.
FCT_NAME(apple orange)
message("\tfct_var is "${fct_var})
message("")

# Macro can view parent's variable scope, and changes made
# here DOES effect parent runtine. Define MACRO_NAME() here.
set(macro_var invisible)
macro(MACRO_NAME arg1 arg2)
	set(macro_var visible)
	message("here is the macro")
	message("\targ1 : " ${arg1})
	message("\targ2 : " ${arg2})
endmacro(MACRO_NAME)

# Make a macro call
MACRO_NAME(banana lemon)
message("\tmacro_var is "${macro_var})
message("")

# Runs each member of a list or lists.
set(list1 item0 item2 item3)
foreach(loop_var item1 ${list1} item4)
	message("loop_var : " ${loop_var})
endforeach(loop_var)
message("")
