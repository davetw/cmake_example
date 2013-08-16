cmake_minimum_required(VERSION 2.8)

# Regular expression table:
# (Quote from offical documents)
#          ^         Matches at beginning of a line
#          $         Matches at end of a line
#          .         Matches any single character
#          [ ]       Matches any character(s) inside the brackets
#          [^ ]      Matches any character(s) not inside the brackets
#           -        Matches any character in range on either side of a dash
#          *         Matches preceding pattern zero or more times
#          +         Matches preceding pattern one or more times
#          ?         Matches preceding pattern zero or once only
#          |         Matches a pattern on either side of the |
#          ()        Saves a matched subexpression, which can be referenced 
#                    in the REGEX REPLACE operation. Additionally it is saved
#                    by all regular expression-related commands, including 
#                    e.g. if( MATCHES ), in the variables CMAKE_MATCH_(0..9).


set(match_input aaa.cpp aab.cpp aac.cpp)
message("match_list = aaa.cpp aab.cpp aac.cpp")

# This function only returns the first MATCH hit.
string(REGEX MATCH aa*.cpp
       match_out ${match_input})
message("REGEX MATCH aa*.cpp : ${match_out}")

# This function returns every MATCH hits.
string(REGEX MATCHALL a+[a-z].cpp
       matchall_out ${match_input})
message("REGEX MATCHALL a+[a-z].cpp : ${matchall_out}")
message("")

# Replace a word with another word.
set(replace_input function_var macro_var)
message("replace_input : function_var macro_var")
# if there is no double quote besides inputs, semicolons would disappear.
string(REPLACE "var" "variable" replace_out "${replace_input}")
message("REPLACE \"var\" \"variable\" : ${replace_out}")
message("")

# Transform a string to upper or lower case. Don't accpet list of strings.
set(word "Banana Durian Coconut")
string(TOUPPER ${word} upper_out)
message("TOUPPER ${word} : " ${upper_out})
string(TOLOWER ${word} lower_out)
message("TOLOWER ${word} : " ${lower_out})
message("")

# Determine the length of a string
set(length_input "learning cmake is not that hard")
string(LENGTH ${length_input} length_out)
message("length of \"${length_input}\" : " ${length_out})
message("")

# Get substring.
set(sub_input abcdefghij)
set(sub_start 5)
set(sub_length 3)
string(SUBSTRING ${sub_input} ${sub_start} ${sub_length} sub_out)
message("substring ${sub_start}.${sub_length} of \"${sub_input}\" : "${sub_out})
message("")

# Find the position of certain keyword through a string. Return -1 if failed.
set(find_input "apple and pineapple")
set(key_word_t "e an")
set(key_word_f "eean")
string(FIND ${find_input} ${key_word_t} find_out)
message("find position of \"${key_word_t}\" on \"${find_input}\" : ${find_out}")
string(FIND ${find_input} ${key_word_f} find_out)
message("find position of \"${key_word_f}\" on \"${find_input}\" : ${find_out}")

