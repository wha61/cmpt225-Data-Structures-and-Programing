#include <iostream>
#include "ArrayList.h"
#include "ArrayList.cpp"

using namespace std;

void testArrayListUnderflow()
{
    //first try-catch block to test removeFront() function
    try
    {   
        ArrayList<int> underflow;
        int intNumber = 1;
        underflow.insertFront(intNumber);
        underflow.removeFront();
        underflow.removeFront();
        cout << "did not catch exception" << endl;
    }
    catch(EmptyListException *e)
    {
        cout << "caught EmptyListException" << endl;
    }
    //second try-catch block to test removeBack() function
    try
    {
        ArrayList<int> underflow;
        int intNumber = 1;
        underflow.insertFront(intNumber);
        underflow.removeBack();
        underflow.removeBack();
        cout << "did not catch exception" << endl;
    }
    catch(EmptyListException *e)
    {
        cout << "caught EmptyListException" << endl;
    }
    //third try-catch block to test remove(p) function
    try
    {
        ArrayList<int> underflow;
        int intNumber = 1;
        underflow.insertFront(intNumber);
        underflow.remove(underflow.begin());
        underflow.remove(underflow.begin());
        cout << "did not catch exception" << endl;
    }
    catch(EmptyListException *e)
    {
        cout << "caught EmptyListException" << endl;
    }
} 
void testIntegerIterator()
{
    ArrayList<int> intTest;
    for(int i = 0; i < 6; i++)
    {
        intTest.insertBack(i);
    }
    for(ArrayList<int>::Iterator iter = intTest.begin(); iter != intTest.end(); ++iter) 
    {
        cout << *iter << " ";
    }
    cout << endl;
    for(int i = 0; i < 3; i++)
    {
        intTest.removeFront();
    }
    for(int i = 0; i < 3; i++)
    {
        intTest.insertBack(i);
    }
    for(ArrayList<int>::Iterator iter = intTest.begin(); iter != intTest.end(); ++iter) 
    {
        cout << *iter << " ";
    }
    cout << endl;
}
void testStringIterator()
{
    ArrayList<string> stringTest;
    stringTest.insertBack("a");
    stringTest.insertBack("b");
    stringTest.insertBack("c");
    stringTest.insertBack("d");
    stringTest.insertBack("e");
    stringTest.insertBack("f");
	for(ArrayList<string>::Iterator iter = stringTest.begin();  iter != stringTest.end();  ++iter) 
    {
        cout << *iter << " ";
    }
    cout << endl;
    for(int i = 0; i < 3; i++)
    {
        stringTest.removeFront();
    }
    stringTest.insertBack("a");
    stringTest.insertBack("b");
    stringTest.insertBack("c");
	for(ArrayList<string>::Iterator iter = stringTest.begin();  iter != stringTest.end();  ++iter) 
    {
        cout << *iter << " ";
    }
    cout << endl;
}
void testInsertAndRemoveFunction()
{
    ArrayList<string> stringTest;
    stringTest.insertBack("a");
    stringTest.insertBack("b");
    stringTest.insertBack("c");
    stringTest.insertBack("d");
    stringTest.insertBack("e");
    stringTest.insertBack("f");
    ArrayList<string>::Iterator insert_iter =  ++stringTest.begin();
	stringTest.insert(insert_iter, "g");
	for(ArrayList<string>::Iterator iter = stringTest.begin();  iter != stringTest.end();  ++iter) 
    {
        cout << *iter << " ";
    }
    cout << endl;
	stringTest.remove(insert_iter);
	for(ArrayList<string>::Iterator iter = stringTest.begin();  iter != stringTest.end();  ++iter) 
    {
        cout << *iter << " ";
    }
    cout << endl;
}

int main()
{
    //test testArrayListUnderflow()
    cout << "test for testArrayListUnderflow()" << endl;
    testArrayListUnderflow();
    cout << endl;
    //test testIntegerIterator()
    cout << "test for testIntegerIterator()" << endl;
    testIntegerIterator();
    cout << endl;
    //test testStringIterator()
    cout << "test for testStringIterator())" << endl;
    testStringIterator();
    cout << endl;
    //test testInsertAndRemoveFunction()
    cout << "test for testInsertAndRemoveFunction()" << endl;
    testInsertAndRemoveFunction();
    cout << endl;
    
    return 0;
}