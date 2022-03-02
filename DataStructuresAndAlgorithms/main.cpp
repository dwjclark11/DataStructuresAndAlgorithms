#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>

#include "CPP_Style/Stack.h"
#include "CPP_Style/Utils.h"

int main()
{
	std::string exp = "a+b*c-d/e";
	std::string exp2 = "2+3*4-8/2";
	Stack<char> st;
	std::cout << Utils::convertExp(std::move(exp)) << std::endl;
	//std::cout << Utils::convertExpAdv(std::move(exp2)) << std::endl;
	std::cout << Utils::evalPostfix(Utils::convertExpAdv(std::move(exp2)));
	return 0;
} 