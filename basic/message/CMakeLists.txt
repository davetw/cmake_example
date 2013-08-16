message("This script shows how to use message()")
message("\tmessage(hello world) = " hello world)
message("\tmessage(hello \" \" world) = " hello " " world)
message("")

message("Doesn't like C++, single quote is just a symbol here.")
message("\tmessage(hello ' ' world) = " hello ' ' world)
message("")

message("shows how message() treats a list. h1 is a list of hello and world.\n"
"Actually, CMake uses semicolon as separator, which means h1 = hello;world")
set(h1 hello world)
message("\tset(h1  hello world)")
message("")

message("message knows to ignore semicolon.")
message("\tmessage($" "{h1}) = " ${h1})
message("\tmessage(hello;world) = " hello;world)
message("")

message("If you use double quote to a list, that list would be treated\n"
" as a single object, which means a string with many semicolons.")
message("\tmessage(\"$" "{h1}\") = " "${h1}")
message("")

message("I am going to show some types of message.")
message("____________________________________________________")
message(STATUS "this is how message(STATUS msg) like like")
message("____________________________________________________")
message(WARNING "this is how message(WARNING msg) like like")
message("____________________________________________________")
message(AUTHOR_WARNING "this is how message(AUTHOR_WARNING msg) like like")
message("____________________________________________________")
message(SEND_ERROR "this is how message(SEND_ERROR msg) like like. it continues but skip gereration")
message("____________________________________________________")
message(FATAL_ERROR "this is how message(FATAL_ERROR msg) like like. it stops")
