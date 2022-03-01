#pragma once
#include "Stack.h"

struct Utils
{
	// This is a function that checks if the parenthesis are matching
	static int isBalanced(const char* exp, Stack<char> st)
	{
		for (int i = 0; exp[i] != '\0'; i++)
		{
			if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
				st.push(exp[i]);
			else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
			{
				if (st.isEmpty())
					return 0;
				if (st.data() == '(' && exp[i] == ')')
					st.pop();
				else if (st.data() == '[' && exp[i] == ']')
					st.pop();
				else if (st.data() == '{' && exp[i] == '}')
					st.pop();
				else
					return 0;
			}
		}

		return st.isEmpty() ? 1 : 0;
	}
};