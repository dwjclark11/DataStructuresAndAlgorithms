#include "Vector.h"
#include <iostream>

template<typename T>
inline void Vector<T>::swap(T& x, T& y)
{
	T temp;
	temp = x;
	x = y;
	y = temp;
}

template<typename T>
inline Vector<T>::Vector()
{
	mCapacity = 10;
	mLength = 0;

	A = new T[mCapacity];

}

template<typename T>
inline Vector<T>::Vector(int size)
{

}

template<typename T>
inline Vector<T>::~Vector()
{
	delete[] A;
}

template<typename T>
inline void Vector<T>::push_back(T value)
{
	insert(mLength, value);
}

template<typename T>
inline void Vector<T>::insert(int index, T val)
{
	// If the length is the size of the capacity, we must make a new array
	if (mLength == mCapacity)
	{
		T* newArray;
		// We double the size of the capacity, because this takes time so we do not want to do it too early
		newArray = new T[mCapacity * 2];

		// Copy all of the elements into the new array
		for (int i = 0; i < mLength; i++)
			newArray[i] = A[i];

		// Deallocate all the elements in the old array
		delete[] A;

		// Set A to the new Array
		A = newArray;

		newArray = nullptr;

		// Change the capacity to match the new array capacity
		mCapacity *= 2;
	}

	// Check to see if the index is a valid position
	if (index >= 0 && index <= mLength)
	{
		// Shift all the elements to make space for the insert
		for (int i = mLength; i > index; i--)
			A[i] = A[i - 1];

		// After all the elements have been shifted, insert the new element at the index
		if (mLength == 0)
			A[0] = val;
		else
			A[index] = val;

		// Increase the length of the array
		mLength++;
	}

	std::cout << "Length: " << mLength << std::endl;
}

template<typename T>
inline void Vector<T>::pop_back()
{
	if (mLength < 1)
	{
		std::cout << "Vector is Empty!\n";
		return;
	}

	A[mLength - 1] = T();
	mLength--;
}

template<typename T>
inline T Vector<T>::at(int index)
{
	// If the array index is valid, return the element
	if (index >= 0 && index < mLength)
		return A[index];

	// return empty 
	return T();
}

template<typename T>
inline void Vector<T>::sort()
{
	for (int i = 0; i < mLength; i++)
	{
		for (int j = i + 1; j < mLength; j++)
		{
			if (A[i] > A[j])
				swap(A[i], A[j]);
		}
	}
}

template<typename T>
inline bool Vector<T>::isSorted()
{
	for (int i = 0; i < mLength - 1; i++)
	{
		if (A[i] > A[i + 1])
			return false;
	}

	return true;
}

template<typename T>
inline void Vector<T>::display()
{
	for (int i = 0; i < mLength; i++)
		std::cout << A[i] << ", ";

	std::cout << std::endl;
}

template<typename T>
inline T& Vector<T>::operator[](int index)
{
	if (index > mCapacity || index > mLength)
	{
		std::cout << "Index is out of bounds" << std::endl;
		return A[0]; // return the first element
	}

	return A[index];
}
