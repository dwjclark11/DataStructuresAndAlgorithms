#pragma once

template <typename T>
class AVL
{
public:
	struct Node
	{
		Node* lChild;
		Node* rChild;
		int height;

		T data;
	};

private:
	Node* root;

private:
	int NodeHeight(Node* p);
	int BalanceFactor(Node* p);

	// Rotations for inserting and deleting nodes
	Node* LLRotation(Node* p);
	Node* LRRotation(Node* p);
	Node* RRRotation(Node* p);
	Node* RLRotation(Node* p);

	// Inorder predecessor and successor functions
	Node* Pred(Node* p);
	Node* Succ(Node* p);

	Node* Insert(Node** p, T key);
	Node* Delete(Node** p, T key);
	void InOrder(Node* p);

public:
	AVL();
	~AVL();

	Node* Insert(T key);
	Node* Delete(T key);
	Node* Search(T key);
	void InOrder();
};

#include "AVL.inl"