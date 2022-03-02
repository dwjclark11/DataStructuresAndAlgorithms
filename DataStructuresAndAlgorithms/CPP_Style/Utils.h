#pragma once
#include "Stack.h"

struct Utils
{
	// This is a function that checks if the parenthesis are matching
	static int isBalanced(const char* exp, Stack<char> st);
	// Takes a char and checks to see if it is an operand
	static int isOperand(char x);
	// Set the precendece of the current character
	static int precedence(char x);
	// Convert an infix expression to postfix --> Not Associative
	static std::string convertExp(const std::string& infix);

	// These are used for infix expressions with brackets etc, also uses Associativity
	static int outPrecedence(char x);
	static int inPrecedence(char x);
	static std::string convertExpAdv(const std::string& infix);
};