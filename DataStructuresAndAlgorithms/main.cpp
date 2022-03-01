#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>

#include "CPP_Style/Stack.h"
#include "CPP_Style/Utils.h"

int main()
{
	const char* exp = "{([a+b]*[c-d])}";
	Stack<char> st;
	std::cout << Utils::isBalanced(exp, st);
	return 0;
}