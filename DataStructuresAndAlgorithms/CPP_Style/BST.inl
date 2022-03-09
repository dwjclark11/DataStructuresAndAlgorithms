#include "BST.h"
#include "Stack.h"

template<typename T>
inline typename BST<T>::Node* BST<T>::InPred(Node* p)
{
	while (p && p->rChild)
		p = p->rChild;

	return p;
}

template<typename T>
inline typename BST<T>::Node* BST<T>::InSucc(Node* p)
{
	while (p && p->lChild)
		p = p->lChild;

	return p;
}

template<typename T>
inline BST<T>::BST()
	: root(nullptr)
{

}

template<typename T>
inline BST<T>::~BST()
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
inline void BST<T>::insert(T key)
{
	struct Node* t = root;
	struct Node* r = nullptr, * p;

	if (!root)
	{
		p = new Node;
		p->data = key;
		p->lChild = p->rChild = nullptr;
		root = p;

		return;
	}

	while (t)
	{
		r = t;
		if (key < t->data)
			t = t->lChild;
		else if (key > t->data)
			t = t->rChild;
		else
			return;
	}

	p = new Node;
	p->data = key;
	p->lChild = p->rChild = nullptr;

	if (key < r->data) r->lChild = p;
	else r->rChild = p;
}

template<typename T>
inline typename BST<T>::Node* BST<T>::rInsert(Node** p, T key)
{
	if (!(*p))
	{
		Node* t = nullptr;
		t = new Node;
		t->data = key;
		t->lChild = t->rChild = nullptr;
		*p = t;
		return t;
	}
	
	if (key < (*p)->data)
		(*p)->lChild = rInsert(&(*p)->lChild, key);
	else if (key > (*p)->data)
		(*p)->rChild = rInsert(&(*p)->rChild, key);

	return *p;
}

template<typename T>
inline typename BST<T>::Node* BST<T>::Search(Node* root, T key)
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
inline void BST<T>::rInsert(T key)
{
	rInsert(&root, key);
}

template<typename T>
inline void BST<T>::InOrder(Node* p)
{
	if (p)
	{
		InOrder(p->lChild);
		std::cout << p->data << " ";
		InOrder(p->rChild);
	}
}

template<typename T>
inline void BST<T>::InOrder()
{
	InOrder(root);
}

template<typename T>
typename BST<T>::Node* BST<T>::Delete(Node* p, T key)
{
	if (!p)
		return nullptr;

	if (!p->lChild && !p->rChild)
	{
		delete p;
		return nullptr;
	}

	if (key < p->data)
		p->lChild = Delete(p->lChild, key);
	else if (key > p->data)
		p->rChild = Delete(p->rChild, key);
	else
	{
		Node* q = nullptr;
		if (Height(p->lChild) > Height(p->rChild))
		{
			q = InPred(p->lChild);
			p->data = q->data;
			p->lChild = Delete(p->lChild, q->data);
		}
		else
		{
			q = InSucc(p->rChild);
			p->data = q->data;
			p->rChild = Delete(p->rChild, q->data);
		}
	}
	return p;
}

template<typename T>
inline void BST<T>::Delete(T key)
{
	Delete(root, key);
}

template<typename T>
inline typename BST<T>::Node* BST<T>::Search(T key)
{
	return Search(root, key);
}

template<typename T>
inline int BST<T>::Height(Node* p)
{
	int x, y;
	if (!p)
		return 0;

	x = Height(p->lChild);
	y = Height(p->rChild);

	return x > y ? x + 1 : y + 1;
}
