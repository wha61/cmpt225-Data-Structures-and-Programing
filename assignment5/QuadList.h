#ifndef _QuadList_H_
#define _QuadList_H_

#pragma once

#include "QuadNode.h" 

class Quadlist {
private:
   int _size; QuadNode* header; QuadNode* trailer;
protected:
   void init(); 
   int clear();
public:
   Quadlist() { init(); };
   ~Quadlist() { clear(); delete header; delete trailer; };
   int size() const { return _size; } ;
   bool empty() const { return _size <= 0; } ;
   QuadNode* first() const { return header->next; };
   //QuadNode* first() const { return header; }
   QuadNode* last() const {return trailer->prev; };
   //QuadNode* last() const { return trailer; }
   void sethead(int key, string data){header->entry->key = key; header->entry->data = data;};
   void settrail(int key, string data){trailer->entry->key = key; trailer->entry->data = data;};
   bool valid (QuadNode* p )
   { return p && ( trailer != p ) && ( header != p ); };
   Entry* remove ( QuadNode* p ); ;
   QuadNode*  insertAfterAbove ( Entry * e,  QuadNode* p,  QuadNode* b = NULL )
   {  _size++; return p->insertAsSuccAbove ( e, b );  } ;
};

void Quadlist::init() { 
   header = new  QuadNode;
   trailer = new QuadNode; 
   header->next = trailer; header->prev = NULL; 
   trailer->prev = header; trailer->next = NULL; 
   header->above = trailer->above = NULL; 
   header->below = trailer->below = NULL;
   _size = 0; 
} 

Entry * Quadlist::remove ( QuadNode* p ) { 
   p->prev->next = p->next; p->next->prev = p->prev; _size--;
   Entry* e = p->entry; delete p; 
   return e; 
}

int Quadlist::clear() {
   int oldSize = _size;
   while ( 0 < _size ) remove ( header->next ); 
   return oldSize;
}

//QuadNode* Quadlist::insertAfterAbove (Entry * e,  QuadNode* p, QuadNode* b = NULL )
#endif