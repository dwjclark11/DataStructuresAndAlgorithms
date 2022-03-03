#pragma once
#include <iostream>
/*
    This is a simple Queue template class that uses an array
*/
template <typename T>
class Queue_A
{
private:
    int front;
    int rear;
    int size;
    T* Q;
public:
    Queue();
    Queue(int size);

    // Inserts an element at the end
    void push(T x);
    // removes the first element
    T pop();
    // returns the first element
    T get_front();
    // returns the last element
    T get_back();
    // Displays all of the current elements
    void Display();
};

#include "Queue_wArray.inl"


