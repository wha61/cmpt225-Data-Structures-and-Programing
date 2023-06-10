#include "AVLTree.cpp"
#include <iostream>
using namespace std;

int main()
{
    //insert 7 entries into an AVL Tree, then print the tree
    int entry1[7] = {1,2,3,4,5,6,7};
    AVLTree avlTree1;
    for(int i=0;i<7;i++){
        avlTree1.put(entry1[i]);
    }
    avlTree1.print();
    cout << endl << endl;

    //Delete an entry from the tree, and print it again
    avlTree1.erase(5);
    avlTree1.print();
    cout << endl << endl;

    //Do one find of an element in the tree, printing the result
    avlTree1.find(7)->print(avlTree1.find(7));
    cout << endl << endl;

    // one find of an element not in the tree, printing the result.
    avlTree1.find(5)->print(avlTree1.find(5));
    cout << endl << endl;

    int entry2[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; //generate 15 entries
    AVLTree avlTree2;
    for(int i=0;i<15;i++){
        avlTree2.put(entry2[i]);
    }
    //Print the tree.
    avlTree2.print();
    cout << endl << endl;

    //Delete five of them and print the tree again
    for(int i = 1; i < 6; i++){
        avlTree2.erase(i);
    }
    avlTree2.print();

    return 0;
}

