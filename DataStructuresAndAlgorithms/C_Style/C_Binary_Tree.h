#pragma once
#include <stdlib.h>
#include <stdio.h>

// Tree Node Structure
struct TNode
{
    struct TNode* l_Child;
    struct TNode* r_Child;
    int data;
};

// C Style Queue 
/*
    This Queue is the same as the Queue in "C_Queue.h"; however, it has been adjusted to 
    be used for the tree Node*
*/

// ===============================================================================================
// Queue Functions
// ===============================================================================================
struct Queue
{
    int size;
    int front;
    int rear;
    TNode** Q;
};

void create(struct Queue* q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (TNode**)malloc(q->size * sizeof(TNode*));
}

void enqueue(struct Queue* q, TNode* x)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("Queue is full");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

TNode* dequeue(struct Queue* q)
{
    TNode* x = NULL;
    if (q->rear == q->front)
        printf("Queue is empty");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }

    return x;
}
// ===============================================================================================



int isEmpty(struct Queue q)
{
	return q.front == q.rear;
}

void CreateTree(struct TNode** root)
{
    struct TNode* p, *t;
    int x;

    // To create a tree we need to use the modified Queue structure
    Queue q;
    create(&q, 100);

    printf("Enter root Value ");
    scanf_s("%d",&x);

    // Create the root node
    *root = (struct TNode*)malloc(sizeof(struct TNode));
    (*root)->data = x;
    (*root)->l_Child = (*root)->r_Child = NULL;

    enqueue(&q, *root);

    while (!isEmpty(q))
    {
        // Set temp node p to the first popped queue Node
        p = dequeue(&q);

        // Get Data for left child
        printf("Enter left child of %d ", p->data);
        scanf_s("%d", &x);
        if (x != -1)
        {
            // Create a new Tree Node
            t = (struct TNode*)malloc(sizeof(struct TNode));
            t->data = x;
            // Set both left and right children to NULL or to be inserted as LEAF Nodes
            t->l_Child = t->r_Child = NULL;
            
            p->l_Child = t;
            // Insert the new node into the Queue
            enqueue(&q, t);
        }

        // Get Data for right child
        printf("Enter right child of %d ", p->data);
        scanf_s("%d", &x);
        if (x != -1)
        {
            // Create a new Tree Node
            t = (struct TNode*)malloc(sizeof(struct TNode));
            t->data = x;
            // Set both left and right children to NULL or to be inserted as LEAF Nodes
            t->l_Child = t->r_Child = NULL;

            p->r_Child = t;
            // Insert the new node into the Queue
            enqueue(&q, t);
        }
    }
}

// This is a recursive function to display all the nodes 
// of the tree according to preorder traversal
void PreOrder_Display(struct TNode* p)
{
    if (p)
    {
        printf("%d ", p->data);
        PreOrder_Display(p->l_Child);
        PreOrder_Display(p->r_Child);
    }
}

void InOrder_Display(struct TNode* p)
{
    if (p)
    {
        InOrder_Display(p->l_Child);
        printf("%d ", p->data);
        InOrder_Display(p->r_Child);
    }
}

void PostOrder_Display(struct TNode* p)
{
    if (p)
    {
        PostOrder_Display(p->l_Child);
        PostOrder_Display(p->r_Child);
        printf("%d ", p->data);
    }
}