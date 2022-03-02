#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>

#include "CPP_Style/Stack.h"
#include "CPP_Style/Utils.h"

int main()
{
	std::string exp = "a+b*c-d/e";
	Stack<char> st;
	std::cout << Utils::convertExp(std::move(exp));
	return 0;
}