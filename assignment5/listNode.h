#ifndef _ListNode_H_
#define _ListNode_H_

#pragma once
#include <cstddef>

typedef int Rank; 

template <typename T> struct ListNode { 
   T data; ListNode<T>*  prev; ListNode<T>*  next; 
   ListNode() {} ;
   ListNode ( T e, ListNode<T>*  p = NULL, ListNode<T>*  s = NULL )
      : data ( e ), prev ( p ), next ( s ) {} ;
   ListNode<T>*  insertAsPred ( T const& e ); 
   ListNode<T>*  insertAsSucc ( T const& e )
   {
	   ListNode<T>*  x = new ListNode ( e, this, next ); 
       next->prev = x; next = x; 
       return x; 
   };
};

template <typename T> 
ListNode<T>*  ListNode<T>::insertAsPred ( T const& e ) {
   ListNode<T>*  x = new ListNode ( e, prev, this ); 
   prev->next = x; prev = x;
   return x;
};

#endif