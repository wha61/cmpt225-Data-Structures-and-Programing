#ifndef _QuadNode_H_
#define _QuadNode_H_

#include "Entry.cpp"
#include <iostream>

using namespace std;

class QuadNode
{
public:
    Entry* entry;
    QuadNode* prev;
    QuadNode* next;
    QuadNode* below;
    QuadNode* above;
public:
    QuadNode() 
    { 
        entry = new Entry(); 
        prev = NULL; 
        below = NULL; 
        next = NULL; 
        above = NULL; 
    }
    QuadNode(Entry *entry){
        this->entry = entry;
        prev = NULL; 
        below = NULL; 
        next = NULL; 
        above = NULL;
    } 
    Entry* getEntry(){
        return entry;
    }
    void setEntry(Entry *entry){
        this->entry = entry;
    }
    QuadNode* getNext(){
       return next;
    }
    void setNext(QuadNode *next){
        this->next = next;
    }
    QuadNode* getPrevious(){
        return prev;
    }
    void setPrevious(QuadNode *prev){
        this->prev = prev;
    }
    QuadNode* getAbove(){
        return above;
    }
    void setAbove(QuadNode *above){
        this->above = above;
    }
    QuadNode* getBelow(){
        return below;
    }
    void setBelow(QuadNode *below){
        this->below = below;
    }
    virtual ~QuadNode(){
    }
    QuadNode*  insertAsSuccAbove(Entry * e, QuadNode* b = NULL ){
		QuadNode* x = new QuadNode(e);
		x->prev = this;
		x->next = next;
		x->above = NULL;
		x->below = b;
        next->prev = x; next = x; 
        if ( b ) b->above = x;
         return x;
	}
};

#endif

