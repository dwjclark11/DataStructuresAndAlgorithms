#pragma once

// AVL Tree
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node* lChild;
    struct Node* rChild;
    int height;
    int data;
}; struct Node* root = NULL;

int NodeHeight(struct Node* p)
{
    int hl, hr;
    hl = p && p->lChild ? p->lChild->height : 0;
    hr = p && p->rChild ? p->rChild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

int BalanceFactor(struct Node* p)
{
    int hl, hr;
    hl = p && p->lChild ? p->lChild->height : 0;
    hr = p && p->rChild ? p->rChild->height : 0;

    return hl - hr;
}

struct Node* LLRotation(struct Node* p)
{
    /*
    * Before Rotation
             p
           /   \
         pl     pr
        /  \         
      pll  plr  
                
    After rotation
                pl
              /    \
           pll       p
                    / \
                   plr pr
    */


    struct Node* pl = p->lChild;
    struct Node* plr = p->rChild;

    pl->rChild = p;
    p->lChild = plr;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if (root == p)
        root = pl; 

    return pl;
}

struct Node* LRRotation(struct Node* p)
{
    /*
         Before LR Rotation

         There are 3 pointers to nodes: p, pl, plr
             p
            (A)
        pl /   \
         (B)    ar 
         / \    
        bl (C) plr
           / \
          cl  cr

        After LR Rotation
           (C)
          /   \
        (B)   (A)
        / \   / \
       bl cl cr  ar

    */

    struct Node* pl = p->lChild;
    struct Node* plr = pl->rChild;

    pl->rChild = plr->lChild;
    p->lChild = plr->rChild;

    plr->lChild = pl;
    plr->rChild = p;

    // Update the heights after LR Rotation
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);

    // Check to see if p is the main root
    if (root == p)
        root = plr;

    return plr;
}

struct Node* RRRotation(struct Node* p)
{
    struct Node* pr = p->rChild;
    struct Node* prl = pr->lChild;

    pr->lChild = p;
    p->lChild = prl;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if (root == p)
        root = pr;

    return pr;
}

struct Node* RLRotation(struct Node* p)
{
    return NULL;
}

struct Node* RInsert(struct Node** p, int key)
{
    if (*p == NULL)
    {
        struct Node* t = NULL;
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1;
        t->lChild = t->rChild = NULL;
        *p = t;
        return t;
    }

    if (key < (*p)->data)
        (*p)->lChild = RInsert(&(*p)->lChild, key);
    else if (key > (*p)->data)
        (*p)->rChild = RInsert(&(*p)->rChild, key);

    (*p)->height = NodeHeight(*p);

    // Check the balance factors to see what type of rotation may be needed
    if (BalanceFactor(*p) == 2 && BalanceFactor((*p)->lChild) == 1)
        return LLRotation((*p));
    else if (BalanceFactor(*p) == 2 && BalanceFactor((*p)->lChild) == -1)
        return LRRotation(*p);
    else if (BalanceFactor(*p) == -2 && BalanceFactor((*p)->rChild) == -1)
        return RRRotation(*p);
    else if (BalanceFactor(*p) == -2 && BalanceFactor((*p)->rChild) == 1)
        return RLRotation(*p);


    return *p;
}
