#include "Binary_Tree.h"

template <typename T>
Tree<T>::Tree()
	: root(nullptr)
	, q()
	, recursive(false)
{

}

template <typename T>
Tree<T>::~Tree()
{

}

template <typename T>
void Tree<T>::CreateTree()
{
	Tree::Node* p = nullptr;
	T x;

	std::cout << "Enter root Value ";
	std::cin >> x;
	root = new Tree::Node;
	root->data = x;
	root->lChild = root->rChild = nullptr;
	q.push_back(&root);

	while (q.size() > 0)
	{
		
		p = *q.pop_front();
		std::cout << "Enter Left Child of " << p->data << ": ";
		std::cin >> x;
		if (x != -1)
		{
			Tree::Node* t = new Tree::Node;
			t->data = x;
			t->lChild = t->rChild = nullptr;
			p->lChild = t;
			q.push_back(&p->lChild);
			t = nullptr;
			q.Display();
		}

		std::cout << "Enter Right Child of " << p->data << ": ";
		std::cin >> x;
		if (x != -1)
		{
			Tree::Node* t = new Tree::Node;
			t->data = x;
			t->lChild = t->rChild = nullptr;
			p->rChild = t;
			q.push_back(&p->rChild);
			t = nullptr;
			q.Display();
		}
	}
}

template <typename T>
void Tree<T>::PreOrder(Tree::Node* p)
{
	if (p)
	{
		std::cout << p->data << " ";
		PreOrder(p->lChild);
		PreOrder(p->rChild);
	}
}

template <typename T>
void Tree<T>::PostOrder(Tree::Node* p)
{
	if (p)
	{
		PostOrder(p->lChild);
		PostOrder(p->rChild);
		std::cout << p->data << " ";
	}
}

template <typename T>
void Tree<T>::InOrder(Tree::Node* p)
{
	if (p)
	{
		InOrder(p->lChild);
		std::cout << p->data << " ";
		InOrder(p->rChild);
	}
}

template <typename T>
void Tree<T>::LevelOrder(Tree::Node* p)
{
	std::cout << p->data << " ";
	// Push the root to the back of the queue
	q.push_back(&p);

	while (q.size() > 0)
	{
		p = *q.pop_front();
		if (p->lChild)
		{
			std::cout << p->lChild->data << " ";
			q.push_back(&p->lChild);
		}

		if (p->rChild)
		{
			std::cout << p->rChild->data << " ";
			q.push_back(&p->rChild);
		}
	}
}

template<typename T>
void Tree<T>::I_PreOrder(Tree::Node* p)
{
	Stack<Node*> st;
	while (p || !st.isEmpty())
	{
		if (p)
		{
			std::cout << p->data << " ";
			st.push(p);
			p = p->lChild;
		}
		else
		{
			p = st.pop();
			p = p->rChild;
		}
	}
}

template<typename T>
void Tree<T>::I_InOrder(Tree::Node* p)
{
	Stack<Node*> st;
	while (p || !st.isEmpty())
	{
		if (p)
		{
			st.push(p);
			p = p->lChild;
		}
		else
		{
			p = st.pop();
			std::cout << p->data << " ";
			p = p->rChild;
		}
	}
}

template<typename T>
void Tree<T>::I_PostOrder(Tree::Node* p)
{
	long temp = 0;
	Stack<Node*> st;
	while (p || !st.isEmpty())
	{
		if (p)
		{
			st.push(p);
			p = p->lChild;
		}
		else
		{
			temp = reinterpret_cast<long>(st.pop());
			
			if (temp > 0)
			{
				st.push(reinterpret_cast<Node*>(-temp));
				p = reinterpret_cast<Node*>(temp)->rChild;
			}
			else
			{
				temp = -temp;
				std::cout << reinterpret_cast<Node*>(temp)->data << " ";
				p = nullptr;
			}
		}
	}
}

template <typename T>
void Tree<T>::PreOrderDisplay()
{
	if (recursive)
		PreOrder(root);
	else
		I_PreOrder(root);
}

template<typename T>
inline void Tree<T>::LevelOrderDisplay()
{
	LevelOrder(root);
}

template <typename T>
void Tree<T>::PostOrderDisplay()
{
	if (recursive)
		PostOrder(root);
	else
		I_PostOrder(root);
}

template <typename T>
void Tree<T>::InOrderDisplay()
{
	if (recursive)
		InOrder(root);
	else
		I_InOrder(root);
}

template <typename T>
int Tree<T>::height(Tree::Node* p)
{
	int x = 0, y = 0;
	if (!p)
		return 0;

	x = height(p->lChild);
	y = height(p->rChild);
	if (x > y)
		return x + 1;
	else
		return y + 1;
}

template <typename T>
int Tree<T>::GetHeight()
{
	// Wrapper for height function
	return height(root);
}
