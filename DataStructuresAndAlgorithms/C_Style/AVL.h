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
    /*
        Before Rotation

            [p]
            (A)
            /  \ [pr]
           al   (B)
               /  \
        [prl] bl  (C)
                  / \
                 cl  cr

        After Rotation

               [pr] 
               (B)
              /   \
      [p]-> (A)   (C)
            / \   / \
           al bl cl  cr
               ^
            [prl]
    */

    struct Node* pr = p->rChild;
    struct Node* prl = pr->lChild;

    pr->lChild = p;
    p->rChild = prl;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if (root == p)
        root = pr;

    return pr;
}

struct Node* RLRotation(struct Node* p)
{

    /*
        Before Rotation

              [p]
              (A)
              / \
             al (B) [pr]
                / \
        [prl] (C)  bl
              / \
             cl  cr

        After Rotation
             [prl]
              (C)
             /   \
       [p] (A)   (B) [pr]
           / \   / \
          al cl  cr br 
    */

    struct Node* pr = p->rChild;
    struct Node* prl = pr->lChild;

    p->rChild = prl->lChild;
    pr->lChild = prl->rChild;

    prl->rChild = pr;
    prl->lChild = p;

    // Update the heights
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);

    if (root == p)
        root = prl;

    return prl;
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

    // Check the key to the current data and call recursively the correct child node
    if (key < (*p)->data)
        (*p)->lChild = RInsert(&(*p)->lChild, key);
    else if (key > (*p)->data)
        (*p)->rChild = RInsert(&(*p)->rChild, key);

    // Update the height of p
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


int Height(struct Node* p)
{
    int x, y;
    if (p == NULL)
        return 0;

    x = Height(p->lChild);
    y = Height(p->rChild);

    return x > y ? x + 1 : y + 1;
}

// Return the InOrder Predecessor of the current Node
struct Node* InPre(struct Node* p)
{
    while (p && p->rChild)
        p = p->rChild;

    return p;
}

// Return the InOrder Successor of the current Node
struct Node* InSucc(struct Node* p)
{
    while (p && p->lChild)
        p = p->lChild;

    return p;
}

struct Node* Delete(struct Node** p, int key)
{
    
    if ((*p) == NULL)
        return NULL;

    if ((*p)->lChild == NULL && (*p)->rChild == NULL)
    {
        // If p is the main root, set the root to NULL
        if (root == (*p))
            root = NULL;

        free(*p);
        return NULL;
    }
    
    // Compare key to data to see what child node needs to be called recursively
    if (key < (*p)->data)
        (*p)->lChild = Delete(&(*p)->lChild, key);
    else if (key > (*p)->data)
        (*p)->rChild = Delete(&(*p)->rChild, key);
    else
    {
        struct Node* q = NULL;

        if (NodeHeight((*p)->lChild) > NodeHeight((*p)->rChild))
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

    // Update the height of p
    (*p)->height = NodeHeight(*p);

    // Check the balance factors to see what type of rotation may be needed
    if (BalanceFactor(*p) == 2 && BalanceFactor((*p)->lChild) == 1)
        return LLRotation((*p));
    else if (BalanceFactor(*p) == 2 && BalanceFactor((*p)->lChild) == -1)
        return LRRotation(*p);
    else if (BalanceFactor(*p) == 2 && BalanceFactor((*p)->lChild) == 0)
        return LLRotation((*p));
    else if (BalanceFactor(*p) == -2 && BalanceFactor((*p)->rChild) == -1)
        return RRRotation(*p);
    else if (BalanceFactor(*p) == -2 && BalanceFactor((*p)->rChild) == 1)
        return RLRotation(*p);
    else if (BalanceFactor(*p) == -2 && BalanceFactor((*p)->rChild) == 0)
        return RRRotation(*p);

    return *p;
}