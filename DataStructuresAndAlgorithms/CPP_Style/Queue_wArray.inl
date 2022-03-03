#include "Queue_wArray.h"

template<typename T>
inline Queue<T>::Queue()
{
    front = rear = -1;
    size = 10;
    Q = new T[size];
}

template<typename T>
inline Queue<T>::Queue(int size)
{
    front = rear = -1;
    this->size = 10;
    Q = new T[this->size];
}

template<typename T>
inline void Queue<T>::push(T x)
{
    if ((rear + 1) % size == front)
        std::cout << "Queue is Full\n";
    else
    {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
}

template<typename T>
inline T Queue<T>::pop()
{
    if (front == rear)
        std::cout << "Queue is empty\n";
    else
    {
        front = (front + 1) % size;
        return Q[front];
    }

    return T();
}

template<typename T>
inline T Queue<T>::get_front()
{
    T first = Q[front + 1];
    return first;
}

template<typename T>
inline T Queue<T>::get_back()
{
    T back = Q[rear];

    return  back;
}

template<typename T>
inline void Queue<T>::Display()
{
    int i = front + 1;
    do
    {
        std::cout << Q[i] << " ";
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);


    std::cout << std::endl;
}