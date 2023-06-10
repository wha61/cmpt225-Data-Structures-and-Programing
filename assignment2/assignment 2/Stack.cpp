#include "Stack.h"

template <typename T>
Stack<T>::Stack(int capacity)
{
    this->A = new T[capacity];
    this->cap = capacity;
    this->t = -1;//initialize t to -1 so that the stack is empty
}
template <typename T>
Stack<T>::~Stack()
{
    delete[] this->A;
}
template <typename T>
T& Stack<T>::pop()
{
    if (empty())
    {
        throw new EmptyStackException("Pop from empty stack");
    }
    t--;
    return A[t+1];
}
template <typename T>
void Stack<T>::push(T& a)
{
    if(this->size() == this->capacity())
    {
        int newCap = cap*2;
        T *newA = new T[newCap];
        cap = newCap;
        for(int i=0; i<t+1; i++)
        {
            newA[i] = A[i];
        }
        delete[] A;
        A = newA;
    }
    A[t+1] = a;
    t++;
}
template <typename T>
bool Stack<T>::empty()
{
    return (t<0);
}
template <typename T>
int Stack<T>::size()
{
    return (t+1);
}
template <typename T>
int Stack<T>::capacity()
{
    return cap;
}

