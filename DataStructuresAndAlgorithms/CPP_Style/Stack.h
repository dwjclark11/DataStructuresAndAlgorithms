#pragma once
#include <iostream>
#include <vector>
template <typename T>
class Stack
{
private:
	struct Node
	{
		T data;
		Node* next;
	};

private:
	Node* top;

public:
	Stack();
	~Stack();

	void push(T x);
	T pop();
	void Display();
	void RDisplay();
	bool isEmpty();
	int size();
	T data();
};

template<typename T>
inline Stack<T>::Stack()
{
	top = nullptr;
}

template<typename T>
inline Stack<T>::~Stack()
{
}

template<typename T>
inline void Stack<T>::push(T x)
{
	Node* t = new Node;
	if (!t)
		std::cout << "Stack is full!\n";
	else
	{
		t->data = x;
		t->next = top;
		top = t;
	}
}

template<typename T>
inline T Stack<T>::pop()
{
	if (!top)
		std::cout << "Stack is empty!\n";
	else
	{
		T x = top->data;
		Node* t = top;
		top = top->next;
		delete t;
		return x;
	}

	return T();
}

template<typename T>
inline void Stack<T>::Display()
{
	Node* p = top;
	while (p)
	{
		std::cout << p->data << " ";
		p = p->next;
	}

	//std::cout << std::endl;
}

template<typename T>
inline void Stack<T>::RDisplay()
{
	int len = size();
	std::vector<T> t;
	Node* p = top;
	int i = size() - 1;
	while (p && i >= 0)
	{
		t.push_back(p->data);
		p = p->next;
		i--;
	}

	for (const auto& data : t)
	{
		std::cout << data << " ";
	}
}

template<typename T>
inline bool Stack<T>::isEmpty()
{
	if (!top)
		return true;

	return false;
}

template<typename T>
inline int Stack<T>::size()
{
	Node* p = top;
	int len = 0;

	while (p)
	{
		len++;
		p = p->next;
	}

	return len;
}

template<typename T>
inline T Stack<T>::data()
{
	if (!top)
		return T();
	
	return top->data;
}

