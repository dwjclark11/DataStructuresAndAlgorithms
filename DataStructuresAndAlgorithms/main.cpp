#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>

#include "CPP_Style/Stack.h"



int main()
{
	Stack<std::string> stack;

	stack.push("cpp");
	stack.push("and");
	stack.push("linked lists");
	stack.push("using");
	stack.push("implemented");
	stack.push("stack");

	stack.Display();
	stack.pop();
	stack.Display();

	return 0;
}