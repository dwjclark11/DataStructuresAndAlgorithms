#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>

#include "CPP_Style/Stack.h"
#include "CPP_Style/Utils.h"

int main()
{
	std::string exp = "a+b*c-d/e";
	std::string exp2 = "((a+b)*c)-d^e^f";
	Stack<char> st;
	std::cout << Utils::convertExp(std::move(exp)) << std::endl;
	std::cout << Utils::convertExpAdv(std::move(exp2));
	return 0;
} 