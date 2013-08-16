cmake_minimum_required(VERSION 2.8)
project(get_filename)

function(printout arg1 arg2 arg3)
    message("${arg1} of :\n\t\"${arg2}\"\nis : \n\t\"${arg3}\"\n")
endfunction(printout)

set(file1 abc.def)
get_filename_component(abso1 ${file1} ABSOLUTE)
printout("absolute path" ${file1} ${abso1})

get_filename_component(path1 ${abso1} PATH)
printout("path" ${abso1} ${path1})

get_filename_component(path1 ${file1} PATH)
printout("path" ${file1} "${path1}")

get_filename_component(ext1 ${file1} EXT)
printout("extension" ${file1} ${ext1})

get_filename_component(namewe1 ${abso1} NAME_WE)
printout("name without extension" ${abso1} ${namewe1})

get_filename_component(name1 ${abso1} NAME)
printout("name" ${abso1} ${name1})
