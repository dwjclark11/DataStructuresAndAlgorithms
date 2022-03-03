#pragma once
#include "Stack.h"

template <typename T>
class Queue_S
{
private:
	Stack<T> s1;
	Stack<T> s2;

public:
	Queue_S();
	~Queue_S();

	void enqueue(T x);
	T dequeue();

	void Display();
};

template<typename T>
inline Queue_S<T>::Queue_S()
{

}

template<typename T>
inline Queue_S<T>::~Queue_S()
{

}

template<typename T>
inline void Queue_S<T>::enqueue(T x)
{
	s1.push(x);
}

template<typename T>
inline T Queue_S<T>::dequeue()
{
	if (s2.isEmpty())
	{
		if (s1.isEmpty())
		{
			std::cout << "Queue is empty\n";
			return T();
		}
			

		while (!s1.isEmpty())
		{
			s2.push(s1.pop());
		}
	}
	
	return s2.pop();
}

template<typename T>
inline void Queue_S<T>::Display()
{
	if (!s2.isEmpty())
	{
		//std::cout << "Stack 2:\n";
		s2.Display();
	}
		

	if (!s1.isEmpty())
	{
		//std::cout << "Stack 1:\n";
		s1.RDisplay();
	}
}
