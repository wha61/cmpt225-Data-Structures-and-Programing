#ifndef _List_H_
#define _List_H_

#pragma once

#include "listNode.h" 
#include "stdio.h"

template <typename T> class List { 
private:
   int _size; ListNode<T>*  header; ListNode<T>*  trailer; 
protected:
   void init();
   int clear();
public:
   List() { init(); } ;
   ~List(); 
   Rank size() const { return _size; }; 
   bool empty() const { return _size <= 0; } ;
   T& operator[] ( Rank r ) const; 
   ListNode<T>* first() const { return header->next; };
   ListNode<T>* last() const { return trailer->prev; } ;
   bool valid ( ListNode<T>* p ) 
   { return p && ( trailer != p ) && ( header != p ); } ;
    ListNode<T>* find ( T const& e ) const
   { return find ( e, _size, trailer ); };
   ListNode<T>* find ( T const& e, int n, ListNode<T>* p ) const; 
   ListNode<T>* search ( T const& e ) const 
   { return search ( e, _size, trailer ); };
    ListNode<T>* search ( T const& e, int n,  ListNode<T>* p ) const;
   ListNode<T>* insertAsFirst ( T const& e )
   {  _size++; return header->insertAsSucc ( e );  };
   ListNode<T>* insertAsLast ( T const& e ); 
   ListNode<T>* insertA ( ListNode<T>* p, T const& e ); 
   ListNode<T>* insertB ( ListNode<T>* p, T const& e ); 
   T remove ( ListNode<T>* p )
   {
	   T e = p->data; 
       p->prev->next = p->next; p->next->prev = p->prev; 
       delete p; _size--; 
        return e; 
   };
}; 

template <typename T> List<T>::~List() 
{ clear(); delete header; delete trailer; } 

template <typename T> void List<T>::init() { 
   header = new ListNode<T>; 
   trailer = new ListNode<T>; 
   header->next = trailer; header->prev = NULL;
   trailer->prev = header; trailer->next = NULL;
   _size = 0; 
}

template <typename T> int List<T>::clear() { 
   int oldSize = _size;
   while ( 0 < _size ) remove ( header->next ); 
   return oldSize;
}

template <typename T> 
T& List<T>::operator[] ( Rank r ) const { 
   ListNode<T>* p = first(); 
   while ( 0 < r-- ) p = p->next;
   return p->data;
}

template <typename T> 
ListNode<T>*  List<T>::find ( T const& e, int n, ListNode<T>*  p ) const {
   while ( 0 < n-- ) 
      if ( e == ( p = p->prev )->data ) return p; 
   return NULL; 
} 

template <typename T> 
ListNode<T>*  List<T>::search ( T const& e, int n, ListNode<T>* p ) const {
   do {
      p = p->prev; n--;  
   } while ( ( -1 < n ) && ( e < p->data ) ); 
   return p; 
} 


template <typename T> ListNode<T>* List<T>::insertAsLast ( T const& e )
{  _size++; return trailer->insertAsPred ( e );  }

template <typename T> ListNode<T>* List<T>::insertA ( ListNode<T>* p, T const& e )
{  _size++; return p->insertAsSucc ( e );  }

template <typename T> ListNode<T>* List<T>::insertB ( ListNode<T>* p, T const& e )
{  _size++; return p->insertAsPred ( e );  } 

#endif