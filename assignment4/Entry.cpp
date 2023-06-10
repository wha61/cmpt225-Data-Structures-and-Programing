#include "Entry.h"
#include <time.h>
   
Entry::Entry(){
    //create a random entry
    random();
}
Entry::~Entry(){
}
int Entry::getKey(){
    return this->key;
}
string Entry::getData(){
    return this->data;
}
void Entry::random(){
    //create random key
    key = rand() % 100;

    //create random three lowercase letters
    data = "";
    for(int i = 0; i < 3; i++){
        char letter = 'a' + rand() % 26;
        data += letter;
    }
}
string Entry::toString(){
    //convert int key to string
    string stringTypeOfKey = to_string(key);
    //combine string together
    string result = "(" + stringTypeOfKey + ", " + data + ")";
    return result;
}

