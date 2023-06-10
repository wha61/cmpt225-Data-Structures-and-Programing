#include "Entry.h"

static unsigned int seed = 0;
   
Entry::Entry(){
    //create a random entry
    random();
}
Entry::Entry(int key, string data){
    this->key = key;
    this->data = data;
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
	  if (seed == 0) {
        seed = (unsigned)time(NULL);
    }
    ::srand(seed);
    
    key = ::rand() % 100;
	seed = ::rand();
    //create random three lowercase letters
    data = "";
    for(int i = 0; i < 3; i++){
        char letter = 'a' + rand() % 26;
        data += letter;
    }
}
string Entry::toString(){
    //convert int key to string
    string stringTypeOfKey;
	if(key ==  MININT){
        stringTypeOfKey = "-inf";
    } 
	else if(key == MAXINT){
        stringTypeOfKey = "inf";
    } 
	else{
        stringTypeOfKey = to_string((long long)key);
    }
    return stringTypeOfKey;
}
void Entry::print(){
    cout << this->toString() << endl; 
}
