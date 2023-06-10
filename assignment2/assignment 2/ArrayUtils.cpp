#include "Stack.h"
#include "Stack.cpp"

//ArrayUtils class with single member function(static type) 
class ArrayUtils
{
public:
    template <typename T>
    static T& reverse(T* a, int size);
};

template <typename T>
T& ArrayUtils::reverse(T* a, int size)
{
    Stack<T> stack(size);
    for(int i = 0; i<size; i++)
    {
        stack.push(a[i]);
    }
    for(int i = 0; i<size; i++)
    {
        a[i] = stack.pop();
    }
    return *a;
}
