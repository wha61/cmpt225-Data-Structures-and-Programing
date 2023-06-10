#include "Heap.cpp"
#include <iostream>

using namespace std;

void print(Entry A[], int n) {
    for (int i = 0; i < n; i++)
    cout << A[i].toString() << " ";
    cout << endl;
}
Heap heapsort1(Entry e[],int n){
    Heap temp(n);
    for(int i = 0; i < n; i++){
        temp.insert(e[i]);
    }
    temp.heapsort();
    return temp;
}
Heap heapsort2(Entry e[],int n){
    Heap temp(n);
    temp.make(e, n);
    temp.heapsort();
    return temp;
}

int main(){
    //(1) create an array of 15 random entries, print it out, apply heapsort1, and print it again. 
    Entry e1[15];
    cout << "Random entry heap e1:" << endl;
    print(e1,15);
    cout << endl;
    cout << "After heapsort1, it becomes:" << endl;
    heapsort1(e1,15).print();
    cout << endl << endl;

    //(2) create an array of 15 random entries, print it out, apply heapsort2, and print it again.
    Entry e2[15];
    cout << "Random entry heap e2:" << endl;
    print(e2,15);
    cout << endl;
    cout << "After heapsort2, it becomes:" << endl;
    heapsort2(e2,15).print();
    cout << endl << endl;

    //(3) create an array of 31 random entries, print it out, apply heapsort1, and print it again.
    Entry e3[31];
    cout << "Random entry heap e3:" << endl;
    print(e3,15);
    cout << endl;
    cout << "After heapsort1, it becomes:" << endl;
    heapsort1(e3,31).print();
    cout << endl << endl;

    //(4) create an array of 31 random entries, print it out, apply heapsort2, and print it again.
    Entry e4[31];
    cout << "Random entry heap e4:" << endl;
    print(e4,15);
    cout << endl;
    cout << "After heapsort2, it becomes:" << endl;
    heapsort2(e4,31).print();
    cout << endl << endl;
    return 0;
}