#ifndef _SkipList_H_
#define _SkipList_H_

#include "list.h" 
#include "QuadList.h" 
#include <iostream>
#include <limits>

using namespace std;

class SkipList :  public List<Quadlist*>
{
private:
    //QuadNode *head;//pointer to first node
    //QuadNode *tail;//pointer to last node
    int maxLevel;//level of the SkipList

    bool randomLevel();//flip the coin 
    unsigned int seed;
    bool random() {
        srand(seed);
        int ret = rand() % 2;
        seed = rand();
        return ret == 0;
    }
public:
    //constructor
    SkipList() : maxLevel(1){
      
		//Quadlist *newlist = new Quadlist();
		//newlist->sethead(MININT,"");
		//newlist->settrail(MAXINT,"");
		// insertAsFirst(newlist);
    };
    //destructor
    ~SkipList(){
    };
	bool skipSearch (
      ListNode<Quadlist*>* &qlist,
      QuadNode* &p,
      int k );
    Entry& find(int k); // if the map M has an entry with key k, return it;
                    // else, return a reference to a special Entry end.
    Entry& greaterEntry(int k); // findthe es ntry with the lowest key that is greater than k.

    Entry& lessEntry(int k); // finds the entry with the greatest key that is less than k.

    void put(int k, string v); // if there is no entry with key k, insert entry (k, v),
                    // and otherwise set the entry’s value to v.

    void erase(int k); // if the map M has an entry with key k, remove it from M.
                    // Otherwise give an error.

	int size(){return empty() ? 0 : last()->data->size();}; // number of elements in the skip list
	int level() { return List::size(); } //层高 == #Quadlist，不一定要开放
    void print();
};

Entry invalid_entry(0,"invalid_entry");

bool SkipList::randomLevel() {    
    if (seed == 0) {
        seed = (unsigned)time(NULL);
    }
    ::srand(seed);
    int ret = ::rand() % 2;
    seed = ::rand();
    if (ret == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool SkipList::skipSearch (
    ListNode<Quadlist*>* &qlist, 
    QuadNode  * &p, 
    int k ) { 
    while ( true ) {
        while ( p->next && ( p->entry->key <= k ) ) 
            p = p->next; 
        p = p->prev;
        if ( p->prev && ( k == p->entry->key ) ) return true; 
        qlist = qlist->next; 
        if ( !qlist->next ) return false; 
        p = ( p->prev ) ? p->below : qlist->data->first(); 
    }  
}



Entry& SkipList::find(int k){
    if (empty()){
        return invalid_entry;
    } return invalid_entry;
    ListNode<Quadlist*>* qlist = first();
    QuadNode* p = qlist->data->first();
    return skipSearch ( qlist, p, k ) ? *p->entry  : invalid_entry;
}

Entry& SkipList::greaterEntry(int k){
    if (empty()){
        return invalid_entry;
    } return invalid_entry;
    ListNode<Quadlist*>* qlist = first();
    QuadNode* p = qlist->data->first();
    return skipSearch ( qlist, p, k ) ? *p->next->entry  : invalid_entry;
    
}

Entry& SkipList::lessEntry(int k){
    if (empty()){
        return invalid_entry;
    } return invalid_entry;
    ListNode<Quadlist*>* qlist = first();
    QuadNode* p = qlist->data->first();
    return skipSearch ( qlist, p, k ) ? *p->prev->entry  : invalid_entry;  
}

void SkipList::put(int key, string value){
    Entry * e = new Entry( key, value ); 
    Quadlist * newlist;
    if ( empty() ) {
        newlist = new Quadlist();
	    newlist->sethead(MININT,"");
		newlist->settrail(MAXINT,"");
	    insertAsFirst (newlist);
    }
    ListNode<Quadlist*>* qlist = first(); 
    QuadNode* p = qlist->data->first(); 
    if(qlist->data->size() <= 0  && qlist->data->first()->prev  != NULL) 
	    p = qlist->data->first()->prev;
    if ( skipSearch ( qlist, p, key ) ) 
        while ( p->below ) p = p->below;
    qlist = last(); 
    QuadNode* b = qlist->data->insertAfterAbove ( e, p );
  
    while (randomLevel()){
        while ( qlist->data->valid ( p ) && !p->above ) p = p->prev; 
        if ( !qlist->data->valid ( p ) ) { 
            if ( qlist == first() ) 
		    {
                newlist = new Quadlist();
	            newlist->sethead(MININT,"");
		        newlist->settrail(MAXINT,"");
	            insertAsFirst (newlist);
		    }
            p = qlist->prev->data->first()->prev; 
        } else 
            p = p->above; 
        qlist = qlist->prev;
        b = qlist->data->insertAfterAbove ( e, p, b );
    }
}


void SkipList::erase(int key){
    if ( empty() ) {
        throw new noEntryException("No suich entry exist");
    }
    ListNode<Quadlist*>* qlist = first();
    QuadNode * p = qlist->data->first();
    if ( !skipSearch ( qlist, p, key ) ){
        throw new noEntryException("No suich entry exist");
    }
    do { 
        QuadNode* lower = p->below; 
        qlist->data->remove ( p ); 
        p = lower; qlist = qlist->next;
    } while ( qlist->next ); 
    while ( !empty() && first()->data->empty() ) 
        List::remove ( first() ); 
}

void SkipList::print(){
    ListNode<Quadlist*>* qlist = first();
    ListNode<Quadlist*>* l_qlist = last();
    do{
	    QuadNode * p = NULL;
        p= qlist->data->first()->prev; //header
	    do
	    {
		    cout << p->getEntry()->toString()<<"--";
		    p = p->next;
	    }while(p != NULL);
	    cout << endl;
	    qlist = qlist->next;
    }while(qlist != l_qlist->next);
}

#endif