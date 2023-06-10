#ifndef _STACK_H_
#define _STACK_H_
#include <iostream>
#include <string>

using namespace std;
//Stack class
template <typename T>
class Stack
{
private:
    T* A;//array holding the stack
    int cap;//capacity
    int t;//index of top element(equals to the size - 1)
public:
    Stack(int capacity = 4);//constructor
                            //take capacity as the arguement and default it to 4
    virtual ~Stack();//destructor

    T& pop();// returns and removes the top of the stack.
             // (Or throws an EmptyStackException if the stack is empty) 
    void push(T&); // pushes the argument onto the stack.
    bool empty(); // returns true if the stack is empty.
    int size(); // returns the number of elements in the stack.
    int capacity(); // returns the current capacity of the stack.
};
//EmptyStackException class, created in the same file
class EmptyStackException
{
private:
    string errorMsg;
public:
    EmptyStackException(const string& err)
    { 
        errorMsg = err; 
    }
    string getMessage() const 
    { 
        return errorMsg; 
    }
};
#endif
