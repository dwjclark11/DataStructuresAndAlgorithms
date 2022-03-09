#include "AVL.h"
#include "Stack.h"

#include <iostream>

template<typename T>
inline int AVL<T>::NodeHeight(Node* p)
{
	int hl, hr;

	hl = p && p->lChild ? p->lChild->height : 0;
	hr = p && p->rChild ? p->rChild->height : 0;

	return hl > hr ? hl + 1 : hr + 1;
}

template<typename T>
inline int AVL<T>::BalanceFactor(Node* p)
{
	int hr, hl;
	hl = p && p->lChild ? p->lChild->height : 0;
	hr = p && p->rChild ? p->rChild->height : 0;

	return hl - hr;
}

template<typename T>
inline typename AVL<T>::Node* AVL<T>::LLRotation(Node* p)
{
	/*
		Before Rotation
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


	Node* pl = p->lChild;
	Node* plr = p->rChild;

	pl->rChild = p;
	p->lChild = plr;

	p->height = NodeHeight(p);
	pl->height = NodeHeight(pl);

	if (root == p)
		root = pl;

	return pl;
}

template<typename T>
inline typename AVL<T>::Node* AVL<T>::LRRotation(Node* p)
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

	Node* pl = p->lChild;
	Node* plr = pl->rChild;

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

template<typename T>
inline typename AVL<T>::Node* AVL<T>::RRRotation(Node* p)
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

	Node* pr = p->rChild;
	Node* prl = pr->lChild;

	pr->lChild = p;
	p->rChild = prl;

	p->height = NodeHeight(p);
	pr->height = NodeHeight(pr);

	if (root == p)
		root = pr;

	return pr;
}

template<typename T>
inline typename AVL<T>::Node* AVL<T>::RLRotation(Node* p)
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

	Node* pr = p->rChild;
	Node* prl = pr->lChild;

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

template<typename T>
inline typename AVL<T>::Node* AVL<T>::Pred(Node* p)
{
	while (p && p->rChild)
		p = p->rChild;

	return p;
}

template<typename T>
inline typename AVL<T>::Node* AVL<T>::Succ(Node* p)
{
	while (p && p->lChild)
		p = p->lChild;

	return p;
}

template<typename T>
inline AVL<T>::AVL()
	: root(nullptr)
{
}

template<typename T>
inline AVL<T>::~AVL()
{
	// This is the same as post order except delete instead of print
	long temp = 0;
	Stack<Node*> st;
	while (root || !st.isEmpty())
	{
		if (root)
		{
			st.push(root);
			root = root->lChild;
		}
		else
		{
			temp = reinterpret_cast<long>(st.pop());

			if (temp > 0)
			{
				st.push(reinterpret_cast<Node*>(-temp));
				root = reinterpret_cast<Node*>(temp)->rChild;
			}
			else
			{
				temp = -temp;
				delete reinterpret_cast<Node*>(temp);
				root = nullptr;
				std::cout << "Deleted\n";
			}
		}
	}
}

template<typename T>
inline typename AVL<T>::Node* AVL<T>::Insert(Node** p, T key)
{
	if (!*p)
	{
		Node* t = nullptr;
		t = new Node;
		t->data = key;
		t->height = 1;
		t->lChild = t->rChild = nullptr;

		*p = t;
		return t;
	}

	// Check the key to data to know where to insert
	if (key < (*p)->data)
		(*p)->lChild = Insert(&(*p)->lChild, key);
	else if (key > (*p)->data)
		(*p)->rChild = Insert(&(*p)->rChild, key);

	// Update the height of p
	(*p)->height = NodeHeight(*p);

	// Get the Balance factors of p and its children
	int bfp = BalanceFactor(*p);
	int bfpl = BalanceFactor((*p)->lChild);
	int bfpr = BalanceFactor((*p)->rChild);

	// Check balance factors to see what type of rotation may be needed
	if (bfp == 2 && bfpl == 1)
		return LLRotation(*p);
	else if (bfp == 2 && bfpl == -1)
		return LRRotation(*p);
	else if (bfp == -2 && bfpr == -1)
		return RRRotation(*p);
	else if (bfp == -2 && bfpr == 1)
		return RLRotation(*p);

	return *p;
}

template<typename T>
inline typename AVL<T>::Node* AVL<T>::Insert(T key)
{
	return Insert(&root, key);
}

template<typename T>
inline typename AVL<T>::Node* AVL<T>::Delete(T key)
{
	return Delete(&root, key);
}

template<typename T>
inline typename AVL<T>::Node* AVL<T>::Delete(Node** p, T key)
{
	if (!p)
		return nullptr;

	if (!(*p)->lChild && !(*p)->rChild)
	{
		// if p is the root, set to nullptr
		if (root == *p)
			root = nullptr;

		delete *p;

		return nullptr;
	}

	// Compare key to data to see what child node needs to be called recursively
	if (key < (*p)->data)
		(*p)->lChild = Delete(&(*p)->lChild, key);
	else if (key > (*p)->data)
		(*p)->rChild = Delete(&(*p)->rChild, key);
	else
	{
		Node* q = nullptr;

		if (NodeHeight((*p)->lChild) > NodeHeight((*p)->rChild))
		{
			q = Pred((*p)->lChild);
			(*p)->data = q->data;
			(*p)->lChild = Delete(&(*p)->lChild, q->data);
		}
		else
		{
			q = Succ((*p)->rChild);
			(*p)->data = q->data;
			(*p)->rChild = Delete(&(*p)->rChild, q->data);
		}
	}

	// Update the height of p
	(*p)->height = NodeHeight(*p);

	// Check the balance factors to see what type of rotation may be needed
		// Get the Balance factors of p and its children
	int bfp = BalanceFactor(*p);
	int bfpl = BalanceFactor((*p)->lChild);
	int bfpr = BalanceFactor((*p)->rChild);

	// Check balance factors to see what type of rotation may be needed
	if (bfp == 2 && bfpl == 1)
		return LLRotation(*p);
	else if (bfp == 2 && bfpl == -1)
		return LRRotation(*p);
	else if (bfp == -2 && bfpr == -1)
		return RRRotation(*p);
	else if (bfp == -2 && bfpr == 1)
		return RLRotation(*p);
	else if (bfp == 2 && bfpr == 0)
		return LLRotation(*p);
	else if (bfp == -2 && bfpr == 0)
		return RRRotation(*p);

	return *p;
}

template<typename T>
inline void AVL<T>::InOrder(Node* p)
{
	if (p)
	{
		InOrder(p->lChild);
		std::cout << p->data << " ";
		InOrder(p->rChild);
	}
}


template<typename T>
inline typename AVL<T>::Node* AVL<T>::Search(T key)
{
	Node* t = root;

	while (t)
	{
		if (key == t->data)
			return t;
		else if (key < t->data)
			t = t->lChild;
		else
			t = t->rChild;
	}

	return nullptr;
}

template<typename T>
inline void AVL<T>::InOrder()
{
	InOrder(root);
}
