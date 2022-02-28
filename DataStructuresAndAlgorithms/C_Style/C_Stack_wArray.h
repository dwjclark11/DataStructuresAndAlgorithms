#pragma once
#include <stdio.h>
#include <stdlib.h>

struct Stack
{
	int size;
	int top;
	int* S;
};

void Create(struct Stack* st)
{
	printf("Enter Size\n");
	scanf_s("%d", &st->size);

	// Initially the stack is empty, set the size to -1
	st->top = -1; 
	// Create an array on the heap of the given size * sizeof(int)
	st->S = (int*)malloc(st->size * sizeof(int));
}

void Display(struct Stack st)
{
	int i;
	
	for (i = st.top; i >= 0; i--)
		printf("%d ", st.S[i]);

	printf("\n");
}

void push(struct Stack* st, int x)
{
	if (st->top == st->size - 1)
		printf("Stack Overflow\n");
	else
	{
		st->top++;
		st->S[st->top] = x;
	}
}

int pop(struct Stack* st)
{
	int x = -1;

	if (st->top == -1)
		printf("Stack Underflow");
	else
	{
		// Assign x to the value at top, then decrement the top pointer
		x = st->S[st->top--];
	}

	// If x == -1, the stack is empty 
	return x;
}

int peek(struct Stack st, int index)
{
	int x = -1;
	if (st.top - index + 1 < 0)
		printf("Invalid Index\n");
	
	x = st.S[st.top - index + 1];

	return x;
}

int isEmpty(struct Stack st)
{
	if (st.top == -1)
		return 1;

	return 0;
}

int isFull(struct Stack st)
{
	if (st.top == st.size - 1)
		return 1;

	return 0;
}

int top(struct Stack st)
{
	if (!isEmpty(st))
		return st.S[st.top];

	return -1;
}