#include "Utils.h"

int Utils::isBalanced(const char* exp, Stack<char> st)
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

int Utils::isOperand(char x)
{
	switch (x)
	{
		case '+': return 0; break;
		case '-': return 0; break;
		case '*': return 0; break;
		case '/': return 0; break;
		case '^': return 0; break;
		case '(': return 0; break;
		case '{': return 0; break;
		case '[': return 0; break;
		case ')': return 0; break;
		case '}': return 0; break;
		case ']': return 0; break;
		default: return 1; break;
	}
}

int Utils::precedence(char x)
{
	if (x == '+' || x == '-')
		return 1;
	else if (x == '*' || x == '/')
		return 2;
	else
		return 0;
}

std::string Utils::convertExp(const std::string& infix)
{
	Stack<char> st;
	std::string postfix = "";

	int i = 0;

	while (infix[i] != '\0')
	{
		if (isOperand(infix[i]))
			postfix += infix[i++];	
		else
		{
			if (precedence(infix[i]) > precedence(st.data()))
				st.push(infix[i++]);
			
			else
				postfix += st.pop();
		}
	}

	while (!st.isEmpty())
		postfix += st.pop();
	

	return postfix;
}

int Utils::outPrecedence(char x)
{
	switch (x)
	{
	case '+': return 1; break;
	case '-': return 1; break;
	case '*': return 3; break;
	case '/': return 3; break;
	case '^': return 6; break;
	case '(': return 7; break;
	case '{': return 7; break;
	case '[': return 7; break;
	case ')': return 0; break;
	case '}': return 0; break;
	case ']': return 0; break;
	default: return 0; break;
	}
}

int Utils::inPrecedence(char x)
{
	switch (x)
	{
	case '+': return 2; break;
	case '-': return 2; break;
	case '*': return 4; break;
	case '/': return 4; break;
	case '^': return 5; break; // R-L associative precedence decreases inside the stack
	case '(': return 0; break;
	case '{': return 0; break;
	case '[': return 0; break;
	default: return 0; break;
	}
}

std::string Utils::convertExpAdv(const std::string& infix)
{
	Stack<char> st;
	std::string postfix = "";

	int i = 0;

	while (infix[i] != '\0')
	{
		if (isOperand(infix[i]))
			postfix += infix[i++];
		else
		{
			if (outPrecedence(infix[i]) > inPrecedence(st.data()))
				st.push(infix[i++]);
			else
			{
				if (inPrecedence(st.data()) > 0)
					postfix += st.pop();
				else
				{
					st.pop();
					i++;
				}
			}
		}
	}

	while (!st.isEmpty())
	{
		if (inPrecedence(st.data()) > 0)
			postfix += st.pop();
		else
			st.pop();
	}
		
	return postfix;
}

int Utils::evalPostfix(const std::string& postfix)
{
	Stack<int> st;
	int x1, x2, r;
	for (int i = 0; postfix[i] != '\0'; i++)
	{
		if (isOperand(postfix[i]))
			st.push(postfix[i] - '0'); // we must subtract '0' [48] to get the correct integer
		else
		{
			x2 = st.pop(); x1 = st.pop();
			switch (postfix[i])
			{
			case '+': r = x1 + x2; break;
			case '-': r = x1 - x2; break;
			case '*': r = x1 * x2; break;
			case '/': r = x1 / x2; break;
			}
			st.push(r);
		}
	}

	return st.pop();
}

