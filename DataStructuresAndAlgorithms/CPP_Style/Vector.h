#pragma once

template <typename T>
class Vector
{
private:
	// Length is the number of elements currently in the vector
	int mLength;
	// Capacity is the actual size of the array that has been allocated
	int mCapacity;

	// A pointer to the allocated memory
	T* A;

	void swap(T& x, T& y);

public:
	Vector();
	Vector(int size);
	~Vector();
	void push_back(T value);
	void insert(int index, T val);
	void pop_back();
	T at(int index);
	void sort();


	inline const int size() const { return mLength; };
	inline const int capacity() const { return mCapacity; }

	bool isSorted();
	void display();

	T &operator[](int index);
};

#include "Vector.inl"