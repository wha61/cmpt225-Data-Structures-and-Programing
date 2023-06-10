#ifndef _Entry_H_
#define _Entry_H_

#include <string>
#include <iostream>
#include <limits.h>
#include <time.h>
#include <cstdlib>

using namespace std;

#define MAXINT (int)(0x7fffffff)
#define MININT (int)(0x80000000)

//class Entry
class Entry {
public:
    int key;
    string data;
public:
    //constructer and destructor
    Entry();
    Entry(int k, string data);
    virtual ~Entry();

    //getters
    int getKey();
    string getData();

    //method functions
    void random();
    string toString();

    //
    void print();
};

class noEntryException
{
private:
    string errorMsg;
public:
    noEntryException(const string& err)
    { 
        errorMsg = err; 
    }
    string getMessage() const 
    { 
        return errorMsg; 
    }
};

#endif