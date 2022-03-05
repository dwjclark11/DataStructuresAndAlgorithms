#pragma once
// Binary_Tree cpp
#include "Queue.h"
#include "Stack.h"

template<typename T>
class Tree
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
	Queue<Tree::Node**> q;
	bool recursive;
private:
	// Recursive Tree Traversal functions
	void PreOrder(Tree::Node* p);
	void PostOrder(Tree::Node* p);
	void InOrder(Tree::Node* p);

	// Iterative Tree Traversal functions
	void I_PreOrder(Tree::Node* p);
	void I_PostOrder(Tree::Node* p);
	void I_InOrder(Tree::Node* p);

	void LevelOrder(Tree::Node* p);
	int height(Tree::Node* p);
	int count(Tree::Node* p);

public:
	Tree();
	~Tree();

	void CreateTree();

	// Wrapper Display Order Functions
	void InOrderDisplay();
	void PostOrderDisplay();
	void PreOrderDisplay();
	void LevelOrderDisplay();
	// Wrapper for height()
	int GetHeight();
	// Get the number of nodes
	int GetCount();

	//Node* GetRoot() { return root; }
};

#include "Binary_Tree.inl"
