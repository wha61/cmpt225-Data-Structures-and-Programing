#include "Heap.h"

int Heap::left(int index){
   return (2*index + 1);
}
int Heap::right(int index){
   return (2*index + 2);
}
int Heap::parent(int index){
   return ((index - 1)/2);
}

Heap::Heap(){
    //initialize the capacity to be 10
    this->capacity = 10;
    //create a new array
    this->E = new Entry[capacity];
    this->numOfElements = 0;
}
Heap::Heap(int totalSize) {
    this->capacity = totalSize;//default size
    this->E = new Entry[totalSize];
    this->numOfElements = 0;
}
Heap::~Heap(){    
    delete []E;
}
Entry Heap::removeMax(){
    Entry temp = E[0];
    /*swap(&E[0], &E[this->numOfElements-1]);*/
    this->numOfElements--;

    heapify_down(0);
    return temp;
}
void Heap::insert(Entry e){
    if(this->numOfElements == this->capacity){
        int newCap = this->capacity * 2;
        Entry* newE = new Entry[newCap];
        this->capacity = newCap;
        for(int i=0; i< this->numOfElements; i++)
        {
            newE[i] = this->E[i];
        }
        delete[] this->E;
        this->E = newE;
    }
    this->E[this->numOfElements] = e;
    this->numOfElements++;
    heapify_up(this->numOfElements - 1);
}
int Heap::size(){
    return this->numOfElements;
}
bool Heap::empty(){
    return this->numOfElements = 0;
}
void Heap::make(Entry entries[],int n){
    for(int i = 0; i < n; i++){
       E[i] = entries[i];
    }
    this->numOfElements = n;
    for(int i = n-1; i >= 0;i--){
       heapify_down(i);
    }
}
void Heap::swap(Entry* x, Entry* y){
    Entry temp= *x;
    *x = *y;
    *y = temp;
}
void Heap::heapify_down(int index){
    if(empty())
        return;
    if(index<0)
        return;
    while(index < this->numOfElements){
        int l=left(index);
        int r=right(index);
        int max;
        if(r < this->numOfElements && r < this->numOfElements){
            if(E[index].getKey() >= E[l].getKey() && E[index].getKey() >= E[r].getKey())
                max = index;
            else if(E[l].getKey() > E[index].getKey() && E[l].getKey() > E[r].getKey())
                max = l;
            else
                max = r;
        }
        else if(l < this->numOfElements){
            if (this->E[index].getKey() >= this->E[l].getKey())
                max = index;
            else
                max = l; 
        }
        else
            return;

        if(max == index)
            return;
        swap(&E[index],&E[max]);
        index = max;
   }
}
void Heap::heapify_up(int index){
    /*if(index && E[parent(index)].getKey() < E[index].getKey()){
        swap(&E[index], &E[parent(index)]);
        heapify_up(parent(index));
    }*/

    if(index >= this->numOfElements || index <= 0)
        return;
    while(index > 0){
        int p = parent(index);
        int min;
        if (this->E[index].getKey() < this->E[p].getKey())
            min = index;
        else
            min = p;
        if(min == index)
            return;
        swap(&E[index], &E[p]);
        index = p;
    }
}
void Heap::heapsort(){
    for (int i= this->numOfElements; i > 0; i--){
        swap(&E[0], &E[i]);
        this->numOfElements--;
        heapify_down(0);
    }
}
void Heap::print(){
    for(int i = 0; i < this->numOfElements; i++){
       cout << E[i].toString() << " ";
    }
    cout << endl;
}