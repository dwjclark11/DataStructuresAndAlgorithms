#pragma once
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node* prev;
	struct Node* next;
	int data;
}; 


struct DoublyLinkedList
{
	void Create(int* A, int n, struct Node*& head)
	{
		struct Node* t, * last;
		int i;

		head = (struct Node*)malloc(sizeof(struct Node));
		head->data = A[0];
		head->prev = head->next = NULL;

		last = head;

		for (i = 1; i < n; i++)
		{
			t = (struct Node*)malloc(sizeof(struct Node));
			t->data = A[i];
			t->next = last->next;
			t->prev = last;
			last->next = t;
			last = t;
		}
	}

	void Display(struct Node* p)
	{
		struct Node* temp = p;

		while (temp)
		{
			printf("%d ", temp->data);
			temp = temp->next;

		}
		printf("\n");
	}

	int Length(struct Node* p)
	{
		struct Node* temp = p;
		int len = 0;
		while (temp)
		{
			len++;
			temp = temp->next;

		}

		return len;
	}

	int Insert(int x, int index, struct Node*& head)
	{
		// Check to see if the index is valid
		if (index < 0 || index > Length(head))
			return -1;

		// Create a new node to be inserted
		struct Node* t;
		t = (struct Node*)malloc(sizeof(Node));

		// Set the data to the desired inserted data
		t->data = x;

		// Insert at the front of the list
		if (index == 0)
		{
			t->next = head;
			t->prev = NULL;

			head->prev = t;
			head = t;
		}
		else // Insert at a given index
		{
			int i = 0;
			struct Node* p = head;
			
			for (; i < index - 1; i++)
				p = p->next;

			t->next = p->next;
			t->prev = p;

			// See if p->next is NULL
			if (p->next)
				p->next->prev = t;

			p->next = t;
		}

		return 0;
	}

	int Delete(int index, struct Node*& head)
	{
		// Check to see if the index is valid
		if (index < 0 || index > Length(head))
			return -1;

		// Create a temp node*
		struct Node* p = head;
		
		// Delete the first Node
		if (index == 0)
		{
			head = head->next;
			
			// if head is not NULL
			if (head)
				head->prev = NULL;

			free(p);
		}
		else // Delete at a given index
		{
			int i = 0;
			for (; i < index - 1; i++)
				p = p->next;

			p->prev->next = p->next;

			if(p->next)
				p->next->prev = p->prev;

			free(p);
		}
		
		// Return zero if successful
		return 0;
	}
};

