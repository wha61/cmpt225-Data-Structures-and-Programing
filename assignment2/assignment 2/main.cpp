#include <iostream>
#include "ArrayUtils.cpp"
#include "Employee.h"
#include "Employee.cpp"

using namespace std;

void testStackUnderflow()
{
    try
    {
        Stack<int> underflow;//empty stack
        int i = 1;
        underflow.push(i);//push one element
        underflow.pop();//pop the only one element
        underflow.pop();//pop again with empty situation
        cout<<"did not catch exception";
    }
    catch(EmptyStackException *e)
    {
        cout<<"caught EmptyStackException";
    }
    cout << endl; 
}
void testStackGrowth() 
{
    Stack<int> testStack;
    for (int i=0; i<9; i++) 
    {
        cout << "Pushing " << i+1 << "th item " << i << " to the stack." << endl;
        if(i==4)
        {
            testStack.push(i);
            cout << "At " << i+1 << "th item, the capacity of stack is: " << testStack.capacity() << endl;
        }
        if(i==8)
        {
            cout << "At " << i+1 << "th item, the capacity of stack is: " << testStack.capacity() << endl;
        }
        testStack.push(i);
    }
    cout << "Printing the elements while poping the testStack" << endl;
    while (testStack.empty() == false) 
    {
        cout << testStack.pop() << " ";
    }   
    cout << endl;
}
void testReverseIntegers() 
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    for(int i = 0; i <12; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    ArrayUtils::reverse(arr, 12);
    for(int j = 0; j<12; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;
}
void testReverseStringss() 
{
    string game[] = {"age","battleblock","csgo", "destiny2", "euro", "fall", "gtaV", "human", "infinity", "jump", "kingdom", "left"};
    for(int i = 0; i <12; i++)
    {
        cout << game[i] << " ";
    }
    cout << endl;
    ArrayUtils::reverse(game, 12);
    for(int j = 0; j<12; j++)
    {
        cout << game[j] << " ";
    }
    cout << endl;
}
void testReverseEmployees()
{
    Employee *employee[12];
    string name[] = {"Amy","Bob","Chad", "Dina", "Eron", "Fox", "Garren", "Harry", "Ivan", "Jack", "Kity", "Larren"};
    int id[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    for(int i = 0; i <12; i++)
    {
        employee[i] = new Employee(name[i],id[i]);
        cout << employee[i]->toString() << " ";
    }
    cout << endl;
    ArrayUtils::reverse(employee,12);
    for(int i = 0; i <12; i++)
    {
        cout << employee[i]->toString() << " ";
    }
    cout << endl;
}
int main() 
{
    cout << "Test for testStackUnderflow() function" << endl;
    testStackUnderflow();
    cout << endl;
    cout << "Test for testStackGrowth() function" << endl;
    testStackGrowth();
    cout << endl;
    cout << "Test for testReverseIntegers() function" << endl;
    testReverseIntegers();
    cout << endl;
    cout << "Test for testReverseStrings() function" << endl;
    testReverseStringss();
    cout << endl;
    cout << "Test for testReverseEmployees() function" << endl;
    testReverseEmployees();
    cout << endl;
}

