#pragma once
#include <stdlib.h>
#include <stdio.h>

struct Node
{
	int data;
	struct Node* next;
};

void push_back(int x, struct Node** front, struct Node** rear)
{
	struct Node* t;
	t = (struct Node*)malloc(sizeof(struct Node));

	// Check to see if the heap is full
	if (t == NULL)
		printf("Queue is Full\n");
	else
	{
		t->data = x;
		t->next = NULL;

		if (*front == NULL)
			*front = *rear = t;
		else
		{
			(*rear)->next = t;
			*rear = t;
		}
	}
}

int pop_front(struct Node** front)
{
	int x = -1;
	struct Node* t;
	if (*front == NULL)
		printf("Queue is empty\n");
	else
	{
		x = (*front)->data;
		t = *front;
		*front = (*front)->next;
		free(t);
	}
	return x;
}

void Display(struct Node* front)
{
	struct Node* p = front;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}

	printf("\n");
}