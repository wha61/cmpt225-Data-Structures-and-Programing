#ifndef _Entry_H_
#define _Entry_H_
#include <string>

using namespace std;

//class Entry
class Entry {
private:
    int key;
    string data;
public:
    //constructer and destructor
    Entry();
    virtual ~Entry();

    //getters
    int getKey();
    string getData();

    //method functions
    void random();
    string toString();
};


#endif
