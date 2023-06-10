#include "ArrayList.h"

//implementation of iterator class
template <typename T>
T& ArrayList<T>::Iterator::operator*()
{
    if(index < 0)
      return this->t[index%cap+cap];
	else
	  return this->t[index%cap];
}
template <typename T>
typename ArrayList<T>::Iterator& ArrayList<T>::Iterator::operator++()
{
    Iterator* temp = this;
    index++;
    return *temp;
}
template <typename T>
typename ArrayList<T>::Iterator& ArrayList<T>::Iterator::operator--()
{
    Iterator* temp = this;
    index--;
    return *temp;
}
template <typename T>
bool ArrayList<T>::Iterator::operator==(const Iterator& i)
{
    return this->t == i.t && this->index == i.index;
}
template <typename T>
bool ArrayList<T>::Iterator::operator!=(const Iterator& i)
{
	return this->t != i.t || this->index != i.index+1;
}

//implementation of ArrayList class 
template <typename T>
ArrayList<T>::ArrayList(int capacity)
{
    this->cap = 4;
    this->A = new T[capacity];
    this->n = 0;
    this->f = -1;
    this->r = 0; 
}
template <typename T>
ArrayList<T>::~ArrayList()
{
    delete[] this->A;
}
template <typename T>
T& ArrayList<T>::operator[](int i)
{
    return this->A[i];
}
template <typename T>
T& ArrayList<T>::front() const
{ 
    int pos = this->f + 1;
	if(pos < 0)
    {  
        pos = pos % cap+cap;
    }
	else
    {
        pos = pos % cap;
    }
	return this->A[pos];
}
template <typename T>
T& ArrayList<T>::back() const
{
    int pos = this->r - 1;
	if(pos < 0)
    {
        pos = pos % cap + cap;
    }
	else 
    {
        pos = pos % cap;
    }
	return this->A[r];
}
template <typename T>
void ArrayList<T>::insertFront(const T& e)
{
    if(this->n == this->cap)
    {
        int newCap = this->cap * 2;
        T* newArray = new T[newCap];
        this->cap= newCap;
        for(int i = f+1; i < r; i++)
		{
			int pos = i;
			if(i < 0) 
            {
                pos = pos % cap + cap;
            }
			else
            {
			    pos = pos % cap;
            }
			newArray[pos] = this->A[pos];
		}
        delete[] A;
        this->A = newArray;
    }
    if(this->f < 0)
        this->A[cap + f % cap] = e;
	else
		this->A[f % cap] = e;
	this->f = f - 1;
    this->n++;
}
template <typename T>
void ArrayList<T>::insertBack(const T& e)
{
    if(this->n == this->cap)
    {
        int newCap = this->cap * 2;
        T* newArray = new T[newCap];
        this->cap= newCap;
        for(int i = f+1; i < r; i++)
		{
			int pos = i;
			if(i < 0) 
            {
                pos = pos % cap + cap;
            }
			else
            {
			    pos = pos % cap;
            }
			newArray[pos] = this->A[pos];
		}
        delete[] A;
        this->A = newArray;
    }
    this->A[r % cap] = e;
    this->r = r + 1;
    this->n++;
}
template <typename T>
void ArrayList<T>::insert(const Iterator& p, const T& e) 
{
    if(this->n == this->cap)
    {
        int newCap = this->cap * 2;
        T* newArray = new T[newCap];
        this->cap= newCap;
        for(int i = f+1; i < r; i++)
		{
			int pos = i;
			if(i < 0) 
            {
                pos = pos % cap + cap;
            }
			else
            {
			    pos = pos % cap;
            }
			newArray[pos] = this->A[pos];
		}
        delete[] A;
        this->A = newArray;
    }
    int insert_pos = p.index;
	T* tmpArray = new T[r-insert_pos];
	for(int i = insert_pos; i < r; i++)
	{
		int pos1 = i;
		if(pos1 < 0) 
			pos1 = pos1 % cap + cap;
		else
			pos1 = pos1 % cap;
		tmpArray[i-insert_pos] = this->A[pos1];
	}
	for(int j = insert_pos; j < r; j++)
	{
		int pos2 = j+1;
		if(pos2 < 0)
			pos2 = pos2 % cap + cap;
		else
			 pos2 = pos2 % cap;
		this->A[pos2] = tmpArray[j-insert_pos];
	}
	int pos3 = p.index;
	if(pos3 < 0) 
			pos3 = pos3 % cap + cap;
	else
		    pos3 = pos3 % cap;
	this->A[pos3] = e;
	this->r += 1;
    n++;
	delete [] tmpArray;
}
template <typename T>
void ArrayList<T>::removeFront()
{
    if (empty())
    {
        throw new EmptyListException("Remove from empty ArrayList");
    }
    this->f += 1;
    this->n--;
}
template <typename T>
void ArrayList<T>::removeBack()
{
    if (empty())
    {
        throw new EmptyListException("Remove from empty ArrayList");
    }
    this->r = r-1;
    this->n--;
}
template <typename T>
void ArrayList<T>::remove(const Iterator& p)
{
    if (empty())
    {
        throw new EmptyListException("Remove from empty ArrayList");
    }
    	int remove_pos = p.index;
	T* tmpArray = new T[r-remove_pos-1];
	for(int i = remove_pos+1; i < r; i++)
	{
		int pos1 = i;
		if(pos1< 0) 
			pos1 = pos1%cap+cap;
		else
			pos1 = pos1%cap;
		tmpArray[i-remove_pos-1] = this->A[pos1];
	}
	for(int i = remove_pos+1; i < r; i ++)
	{
		int pos2 = i-1;
		if(pos2 < 0)
			pos2 = pos2%cap+cap;
		else
			 pos2 = pos2%cap;
		this->A[pos2] = tmpArray[i-remove_pos-1];
	}
	this->r -= 1;
    n--;
	delete [] tmpArray;
}
template <typename T>
int ArrayList<T>::size()
{
    return this->n;
}
template <typename T>
bool ArrayList<T>::empty()
{
    return (this->n == 0);
}
template <typename T>
typename ArrayList<T>::Iterator ArrayList<T>::begin() const
{
    return Iterator(this->A, f+1, cap);
}
template <typename T>
typename ArrayList<T>::Iterator ArrayList<T>::end() const
{
    return Iterator(this->A, r-1, cap);
}
