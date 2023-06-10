#ifndef _Heap_H_
#define _Heap_H_
#include "Entry.cpp"
#include <iostream>
using namespace std;

class Heap{
private:
    //array implementation of heap
    Entry* E;//hold entry element
    int capacity;
    int numOfElements;

    //basic function for a max heap class
    int left(int index);
    int right(int index);
    int parent(int index);

public:
    //constructor
    Heap();
    Heap(int size);

    //destructor
    ~Heap();

    //member functions 
    Entry removeMax(); // returns the maximum entry in the heap, and deletes it.
    void insert(Entry e); // inserts the entry e into the heap.
    int size(); // number of elements in Heap
    bool empty(); // is size = 0?
    void make(Entry entries[],int n); // does the linear bottom-up makeHeap operation
                                      // to make the heap have all of the n entries in the
                                      // array. Throws away anything already in the heap.                                
    void swap(Entry* x, Entry* y);
    void heapify_down(int index);
    void heapify_up(int index);
    void heapsort();
    void print();
};

#endif