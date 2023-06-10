#ifndef _ArrayList_H_
#define _ArrayList_H_
#include <iostream>
#include <string>
using namespace std;

//class ArrayList
template <typename T>
class ArrayList
{
public:
    // an iterator for the Array list(created as a nested class in side ArrayList class)
    class Iterator
    {
    public:
        int index;
        T* t;
        int cap;
    public:
        Iterator(T* v, int i, int j) : t(v), index(i), cap(j){};
        T& operator*();// gives the reference to the object at the iterator’s position.
        Iterator& operator++(); // moves the iterator one forward in the ArrayList
        Iterator& operator--(); // moves the iterator one backwards in the ArrayList
        bool operator==(const Iterator& i); // compares this iterator with the iterator i. Works even if i 
                                      // is an invalid iterator.
        bool operator!=(const Iterator& i);
    };
private:
    T *A; // created array
    int cap; // capacity
    int n; // number of elements 
    int f; // index of the front element
    int r; // index immediately past the rear element
public:
    //constructor
    ArrayList(int capacity = 4);
    //destructor
    ~ArrayList();
    T& operator[](int i); // returns the element at index i of the ArrayList.
                         // note that this is not index i of the underlying array.
    T& front() const;// returns the element at the front of the ArrayList.
    T& back() const;// returns the element at the back of the ArrayList.
    void insertFront(const T& e); // insert at the front of the ArrayList.
                           // Grows underlying array if necessary.
    void insertBack(const T& e); // insert at the back of the ArrayList.
                          // Grows underlying array if necessary.
    void insert(const Iterator& p, const T& e); // insert before the iterator p. This could involve growing
                                  // the underlying array and/or copying elements forward in it.
    void removeFront(); // removes the front element of the ArrayList.
                    // throw an EmptyListException if ArrayList is empty.
    void removeBack(); // removes the back element of the ArrayList.
                      // throw an EmptyListException if ArrayList is empty.
    void remove(const Iterator& p); // removes the element at the iterator p from the ArrayList.
                            // may involve copying of elements.
                            // throw if ArrayList is empty.
    int size(); // number of elements in ArrayList
    bool empty(); // is size = 0?

    Iterator begin() const; // an iterator to the first element
    Iterator end() const; // an iterator to the element after the last element.
};

//class EmptyListException
class EmptyListException
{
private:
    string errorMsg;
public:
    EmptyListException(const string& err)
    { 
        errorMsg = err; 
    }
    string getMessage() const 
    { 
        return errorMsg; 
    }
};

//class InvalidIteratorException
class InvalidIteratorException
{
private:
    string errorMsg;
public:
    InvalidIteratorException(const string& err)
    { 
        errorMsg = err; 
    }
    string getMessage() const 
    { 
        return errorMsg; 
    }
};
#endif