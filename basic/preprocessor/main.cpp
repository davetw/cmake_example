#ifndef FOO
#define FOO not_defined
#endif

// the # mark means double quotes besides arg. thus "arg".
#define STR1(arg) #arg
// it requires two-level call because FOO is not expended while # exist.
// http://stackoverflow.com/questions/1489932/c-preprocessor-and-concatenation
#define STR(arg) STR1(arg)

#include <iostream>

int main()
{
	std::cout << STR(FOO)  << '\n';
	return 0;
}
