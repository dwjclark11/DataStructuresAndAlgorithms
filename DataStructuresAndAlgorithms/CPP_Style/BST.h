#pragma once
#include <iostream>

template <typename T>
class BST
{
public:
	struct Node
	{
		Node* lChild;
		Node* rChild;

		T data;
	};

private:
	Node* root;

private:
	Node* InPred(Node* p);
	Node* InSucc(Node* p);
	Node* Delete(Node* p, T key);
	void InOrder(Node* p);

	Node* rInsert(Node** p, T key);
	Node* Search(Node* root, T key);
	int Height(Node* p);

public:
	BST();
	~BST();

	void insert(T key);

	void rInsert(T key);
	void InOrder();
	void Delete(T key);
	
	Node* Search(T key);
};

#include "BST.inl"
