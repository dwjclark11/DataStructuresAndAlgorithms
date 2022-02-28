#pragma once
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
}; //Node* top = NULL;


void push(struct Node** top, int x)
{
	struct Node* t;

	t = (struct Node*)malloc(sizeof(struct Node));

	if (t == NULL)
		printf("Stack is full\n");
	else
	{
		t->data = x;
		t->next = *top;
		*top = t;
	}
}

int pop(struct Node** top)
{
	int x = -1;

	if (*top == NULL)
		printf("Stack is empty!\n");
	else
	{
		struct Node* t;
		
		t = *top;
		*top = (*top)->next;
		x = t->data;
		free(t);
	}
	return x;
}

void Display(struct Node* top)
{
	struct Node* p = top;

	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}

	printf("\n");
}

int GetTop(struct Node* top)
{
	return top ? top->data : 0;
}

int empty(struct Node* top)
{
	return top ? 0 : 1;
}

int full(struct Node* top)
{
	struct Node* t = (struct Node*)malloc(sizeof(struct Node));
	int r = t ? 1 : 0;
	free(t);

	return r;
}