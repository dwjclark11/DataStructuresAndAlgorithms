#pragma once
#include <stdlib.h>
#include <stdio.h>

struct Node
{
	struct Node* lChild;
	struct Node* rChild;
	int data;
}; 

void insert(struct Node** root, int key)
{
	struct Node* t = *root;
	struct Node* r = NULL, *p;

	if (*root == NULL)
	{
		p = (struct Node*)malloc(sizeof(struct Node));
		p->data = key;
		p->lChild = p->rChild = NULL;
		*root = p;

		return;
	}

	while (t != NULL)
	{
		r = t;
		if (key < t->data)
			t = t->lChild;
		else if (key > t->data)
			t = t->rChild;
		else
			return;
	}

	p = (struct Node*)malloc(sizeof(struct Node));
	p->data = key;
	p->lChild = p->rChild = NULL;

	if (key < r->data) r->lChild = p;
	else r->rChild = p;

}

struct Node* RInsert(struct Node** p, int key)
{

	if (*p == NULL)
	{
		struct Node* t = NULL;
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = key;
		t->lChild = t->rChild = NULL;
		*p = t;
		return t;
	}

	if (key < (*p)->data)
		(*p)->lChild = RInsert(&(*p)->lChild, key);
	else if (key > (*p)->data)
		(*p)->rChild = RInsert(&(*p)->rChild, key);
	
	return *p;
}

int Height(struct Node* p)
{
	int x, y;
	if (p == NULL)
		return 0;

	x = Height(p->lChild);
	y = Height(p->rChild);
	
	return x > y ? x + 1 : y + 1;
}

struct Node* InPre(struct Node* p)
{
	while (p && p->rChild != NULL)
		p = p->rChild;

	return p;
}

struct Node* InSucc(struct Node* p)
{
	while (p && p->lChild != NULL)
		p = p->lChild;

	return p;
}

struct Node* Delete(struct Node** p, int key)
{
	if ((*p) == NULL)
		return NULL;

	if ((*p)->lChild == NULL && (*p)->rChild == NULL)
	{
		free(*p);
		return NULL;
	}

	if (key < (*p)->data)
		(*p)->lChild = Delete(&(*p)->lChild, key);
	else if (key > (*p)->data)
		(*p)->rChild = Delete(&(*p)->rChild, key);
	else
	{
		struct Node* q = NULL;
		if (Height((*p)->lChild) > Height((*p)->rChild))
		{
			q = InPre((*p)->lChild);
			(*p)->data = q->data;
			(*p)->lChild = Delete(&(*p)->lChild, q->data);
		}
		else
		{
			q = InSucc((*p)->rChild);
			(*p)->data = q->data;
			(*p)->rChild = Delete(&(*p)->rChild, q->data);
		}
	}
	return *p;
}

struct Node* search(struct Node* root, int key)
{
	struct Node* t = root;

	while (t != NULL)
	{
		if (key == t->data)
			return t;
		else if (key < t->data)
			t = t->lChild;
		else
			t = t->rChild;
	}

	return NULL;
}

void InOrder(struct Node* p)
{
	if (p)
	{
		InOrder(p->lChild);
		printf("%d ", p->data);
		InOrder(p->rChild);
	}
}